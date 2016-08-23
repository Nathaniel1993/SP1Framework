// This is the main file for the game logic and function

#include "combat.h"
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Ai.h"
#include "guide.h"
#include "map.h"
#include "Dice.h"
#include <fstream>
#include <mmsystem.h>

using namespace std;
double  g_dElapsedTime;
double  g_dDeltaTime;
bool    g_abKeyPressed[K_COUNT];
bool	diceRoll = false;
char MapSize[80][31];
bool ScoreTracker = false;
int Score = 0;
int keys = 4;
int numkey=0;


double aiBounceTime1;
double aiBounceTime2;
double bossBounceTime;

// Game specific variables here
extern int g_MapNo;
WORD color;
SGameChar   g_sChar;
//SGameEnemy  g_sEnemy;// Enemy
EnemyStruct Enemy;
AiBounceTime Bounce;
SGameBoss g_sBoss;
SGameKeys	g_sKeys[4];
SGameKeys	g_sDoor;
EGAMESTATES g_eGameState = S_SPLASHSCREEN;
double  g_dBounceTime; // this is to prevent key bouncing, so we won't trigger keypresses more than once

					   // Console object
Console g_Console(80, 31, "SP1 Framework");

//--------------------------------------------------------------
// Purpose  : Initialisation function
//            Initialize variables, allocate memory, load data from file, etc. 
//            This is called once before entering into your main loop
// Input    : void
// Output   : void
//--------------------------------------------------------------
void init(void)
{
	// Set precision for floating point output
	g_dElapsedTime = 0.0;
	g_dBounceTime = 0.0;


	Bounce.aiBounceTime1 = 0.0;
	Bounce.aiBounceTime2 = 0.0;
	Bounce.aiBounceTime3 = 0.0;
	Bounce.aiBounceTime4 = 0.0;
	Bounce.aiBounceTime5 = 0.0;
	Bounce.aiBounceTime6 = 0.0;
	Bounce.bossBounceTime = 0.0;

	// sets the initial state for the game
	g_eGameState = S_SPLASHSCREEN;
	PlaySound(TEXT("splash.wav"), NULL, SND_ASYNC | SND_LOOP);
	g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 2;
	g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 2;
	
	Enemy.g_sEnemy.m_cLocation.X = 18; // enemy spawn location
	Enemy.g_sEnemy.m_cLocation.Y = 24;

	Enemy.g_sEnemy2.m_cLocation.X = 18; // enemy spawn location
	Enemy.g_sEnemy2.m_cLocation.Y = 10;
	
	g_sBoss.m_cLocation.X = 20;
	g_sBoss.m_cLocation.Y = 25;

	g_sChar.m_bActive = true;
	// sets the width, height and the font name to use in the console
	g_Console.setConsoleFont(0, 16, L"Consolas");
}

//--------------------------------------------------------------
// Purpose  : Reset before exiting the program
//            Do your clean up of memory here
//            This is called once just before the game exits
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void shutdown(void)
{
	// Reset to white text on black background
	colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

	g_Console.clearBuffer();
}

//--------------------------------------------------------------
// Purpose  : Getting all the key press states
//            This function checks if any key had been pressed since the last time we checked
//            If a key is pressed, the value for that particular key will be true
//
//            Add more keys to the enum in game.h if you need to detect more keys
//            To get other VK key defines, right click on the VK define (e.g. VK_UP) and choose "Go To Definition" 
//            For Alphanumeric keys, the values are their ascii values (uppercase).
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void getInput(void)
{
	g_abKeyPressed[K_UP] = isKeyPressed(VK_UP);
	g_abKeyPressed[K_DOWN] = isKeyPressed(VK_DOWN);
	g_abKeyPressed[K_LEFT] = isKeyPressed(VK_LEFT);
	g_abKeyPressed[K_RIGHT] = isKeyPressed(VK_RIGHT);
	g_abKeyPressed[K_SPACE] = isKeyPressed(VK_SPACE);
	g_abKeyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
	g_abKeyPressed[K_ENTER] = isKeyPressed(VK_RETURN);
	g_abKeyPressed[K_LEFTCONTROL] = isKeyPressed(VK_LCONTROL);
	g_abKeyPressed[K_ONE] = isKeyPressed(0x31);
	g_abKeyPressed[K_TWO] = isKeyPressed(0x32);
	g_abKeyPressed[K_THREE] = isKeyPressed(0x33);
	g_abKeyPressed[K_FOUR] = isKeyPressed(0x34);
	g_abKeyPressed[K_FIVE] = isKeyPressed(0x35);

}


//--------------------------------------------------------------
// Purpose  : Update function
//            This is the update function
//            double dt - This is the amount of time in seconds since the previous call was made
//
//            Game logic should be done here.
//            Such as collision checks, determining the position of your game characters, status updates, etc
//            If there are any calls to write to the console here, then you are doing it wrong.
//
//            If your game has multiple states, you should determine the current state, and call the relevant function here.
//
// Input    : dt = deltatime
// Output   : void
//--------------------------------------------------------------
void update(double dt)
{
	// get the delta time
	g_dElapsedTime += dt;
	g_dDeltaTime = dt;

	switch (g_eGameState)
	{
	case S_SPLASHSCREEN: splashScreenWait(); // game logic for the splash screen
		break;
	case S_GUIDE: guide();
		break;
	case S_GAME: gameplay(); // gameplay logic when we are in the game
		break;
	/*case S_DICE: dice();
		break;
	case S_COMBATEASY: combatEasy();
		break;
	case S_COMBATMEDIUM: combatMedium();
		break;
	case S_COMBATHARD: combatHard();
		break;*/
	}
}
//--------------------------------------------------------------
// Purpose  : Render function is to update the console screen
//            At this point, you should know exactly what to draw onto the screen.
//            Just draw it!
//            To get an idea of the values for colours, look at console.h and the URL listed there
// Input    : void
// Output   : void
//--------------------------------------------------------------
void render()
{
	clearScreen();      // clears the current screen and draw from scratch 
	switch (g_eGameState)
	{
	case S_SPLASHSCREEN: renderSplashScreen();
		break;
	case S_GUIDE: loadguide();
		break;
	case S_GAME: renderGame();
		break;
	/*case S_DICE: renderdice();
		break;
	case S_COMBATEASY: rendercombatEasy();
		break;
	case S_COMBATMEDIUM: rendercombatMedium();
		break;
	case S_COMBATHARD: rendercombatHard();
		break;*/
	}
	renderFramerate();  // renders debug information, frame rate, elapsed time, etc
	renderToScreen();   // dump the contents of the buffer to the screen, one frame worth of game
}

void splashScreenWait()    // waits for time to pass in splash screen
{
	if (g_abKeyPressed[K_ENTER])
	{
	g_eGameState = S_GAME;
	loadmap1();
	PlaySound(TEXT("Map1.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	if (g_abKeyPressed[K_LEFTCONTROL])
	{
	g_eGameState = S_GUIDE;
	}
}

void gameplay()            // gameplay logic
{
	processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit
	moveCharacter();   // moves the character, collision detection, physics, etc
	if (ScoreTracker == true)
	{
		Score++;
		MapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] = ' ';
		ScoreTracker = false;
	}
}
void moveCharacter()
{
	bool bSomethingHappened = false;
	if (g_dBounceTime > g_dElapsedTime)
		return;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Updating the location of the character based on the key press
	// providing a beep sound whenver we shift the character
	if (g_abKeyPressed[K_UP] && g_sChar.m_cLocation.Y > 0)
	{
		if (MapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] != '#')
		{
			if (MapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'F')
			{
				if (MapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 2] != '#'&&MapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 2] != 'A')
				{
					MapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 2] = 'F';
					MapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] = ' ';
					g_sChar.m_cLocation.Y--;
					bSomethingHappened = true;
				}
			}
			else if (MapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == '.')
			{
				ScoreTracker = true;
			}
			else
			{
				g_sChar.m_cLocation.Y--;
				bSomethingHappened = true;
			}
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X > 0)
	{
		if (MapSize[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] != '#'&& MapSize[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] != 'A')
		{
			if (MapSize[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == 'F')
			{
				if (MapSize[g_sChar.m_cLocation.X - 2][g_sChar.m_cLocation.Y] != '#'&&MapSize[g_sChar.m_cLocation.X - 2][g_sChar.m_cLocation.Y] != 'A')
				{
					MapSize[g_sChar.m_cLocation.X - 2][g_sChar.m_cLocation.Y] = 'F';
					MapSize[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] = ' ';
					g_sChar.m_cLocation.X--;
					bSomethingHappened = true;
				}
			}

			else if (MapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == '.')
			{
				ScoreTracker = true;
			}
			else
			{
				g_sChar.m_cLocation.X--;
				bSomethingHappened = true;
			}
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (g_abKeyPressed[K_DOWN] && g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1)
	{
		if (MapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] != '#')
		{
			if (MapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == 'F')
			{
				if (MapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 2] != '#'&&MapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 2] != 'A')
				{
					MapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 2] = 'F';
					MapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] = ' ';
					g_sChar.m_cLocation.Y++;
					bSomethingHappened = true;
				}
			}
			else if (MapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == '.')
			{
				ScoreTracker = true; 
			}
			else
			{
				g_sChar.m_cLocation.Y++;
				bSomethingHappened = true;
			}
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (g_abKeyPressed[K_RIGHT] && g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1)
	{
		if (MapSize[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] != '#')
		{
			if (MapSize[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == 'F')
			{
				if (MapSize[g_sChar.m_cLocation.X + 2][g_sChar.m_cLocation.Y] != '#'&&MapSize[g_sChar.m_cLocation.X + 2][g_sChar.m_cLocation.Y] != 'A')
				{
					MapSize[g_sChar.m_cLocation.X + 2][g_sChar.m_cLocation.Y] = 'F';
					MapSize[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] = ' ';
					g_sChar.m_cLocation.X++;
					bSomethingHappened = true;
				}
			}
			else if (MapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == '.')
			{
				ScoreTracker = true;
			}
			else
			{
				g_sChar.m_cLocation.X++;
				bSomethingHappened = true;
			}
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (g_abKeyPressed[K_SPACE])
	{
		g_sChar.m_bActive = !g_sChar.m_bActive;
		bSomethingHappened = true;

	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (bSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < numkey; i++)
	{
		if (g_sChar.m_cLocation.X == g_sKeys[i].m_cLocation.X && g_sChar.m_cLocation.Y == g_sKeys[i].m_cLocation.Y && g_sKeys[i].m_bActive == true)
		{
			keys--;
			g_sKeys[i].m_bActive = false;
		}
	}
}

void processUserInput()
{
	// quits the game if player hits the escape key
	if (g_abKeyPressed[K_ESCAPE])
		g_bQuitGame = true;
}

void clearScreen()
{
	// Clears the buffer with this colour attribute
	g_Console.clearBuffer(0x00);
}

void renderSplashScreen()  // renders the splash screen
{
	COORD c;
	for (int y = 0; y < 31; y++)
	{
		c.Y = y;
		for (int x = 0; x < 80; x++)
		{
			if (MapSize[x][y] == 'i')
			{
				MapSize[x][y] = ' ';
			}
			c.X = x;
			g_Console.writeToBuffer(c, MapSize[x][y]);
		}
	}
	COORD l;
	l.Y = 26;
	l.X = 20;
	g_Console.writeToBuffer(l, "Press <Enter> key to start game", 0x0B);
	l.Y = 27;
	l.X = 20;
	g_Console.writeToBuffer(l, "Press <Left Control> key to open guide", 0x0B);
	l.Y = 28;
	l.X = 20;
	g_Console.writeToBuffer(l, "Press <Esc> key in game to quit", 0x0B);
}

void loadsplashscreen()
{
	ifstream file("mainmenu.txt");
	int width = 0;
	int height = 0;
	if (file.is_open())
	{
		while (height < 31)
		{
			while (width < 80)
			{
				file >> MapSize[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}
}

void renderGame()
{
	renderMap();
	renderCharacter();  // renders the character into the buffer
	moveCharacter();
	
	
	renderKeys();
	openDoor();
}

void renderMap()
{
	bool start = true;
	bool check = false;
	bool cleared = false;
	// Set up sample colours, and output shadings
	const WORD colors[] = {
		0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
		0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	};
	rendermap1();
	if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X == 0 && g_sChar.m_cLocation.Y == 2)
	{
		clearScreen();
		loadmap2();
		PlaySound(TEXT("splash"), NULL, SND_ASYNC | SND_LOOP);
		g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 1;
		g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 3;
	}
	else if (g_sChar.m_cLocation.X == 39 && g_sChar.m_cLocation.Y == 0)
	{
		PlaySound(TEXT("Map1.wav"), NULL, SND_ASYNC | SND_LOOP);
		loadmap3();
		g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 42;
		g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 1;
 	}
}

void renderCharacter()
{
	// Draw the location of the character
	WORD charColor = 0x0C;
	if (g_sChar.m_bActive)
	{
		charColor = 0x0A;
	}
	g_Console.writeToBuffer(g_sChar.m_cLocation, (char)1, charColor);
}

void renderFramerate()
{
	COORD c;
	// displays the framerate
	std::ostringstream ss;
	ss << std::fixed << std::setprecision(3);
	ss << 1.0 / g_dDeltaTime << "fps";
	c.X = g_Console.getConsoleSize().X - 9;
	c.Y = 0;
	g_Console.writeToBuffer(c, ss.str());

	// displays the elapsed time
	ss.str("");
	ss << g_dElapsedTime << "secs";
	c.X = 0;
	c.Y = 0;
	g_Console.writeToBuffer(c, ss.str());

	ss.str("");
	ss << Score << "points";
	c.X = 40;
	c.Y = 0;
	g_Console.writeToBuffer(c, ss.str());
}
void renderToScreen()
{
	// Writes the buffer to the console, hence you will see what you have written
	g_Console.flushBufferToConsole();
}

void renderKeys()
{
	for (int i = 0; i < numkey; i++)
	{
		if (g_sKeys[i].m_bActive == false)
		{
			g_Console.writeToBuffer(g_sKeys[i].m_cLocation,' ', 0x0f);
		}
	}
}

void openDoor()
{
	if (keys == 0)
	{
		MapSize[g_sDoor.m_cLocation.X][g_sDoor.m_cLocation.Y] = ' ';
	}
}
