// This is the main file for the game logic and function

#include "quiz.h"
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Ai.h"
#include "guide.h"
#include "Dice.h"
#include <fstream>
#include <mmsystem.h>
#include "loadfile.h"
#include "postgame.h"
#include "HighScore.h"
#include "RenderHighScore.h"

using namespace std;
double  g_dElapsedTime;
double  g_dDeltaTime;
double GameTime;
bool    g_abKeyPressed[K_COUNT];
bool ScoreTracker = false;
bool splashScreenload = true;
bool torchPossession = false;
extern bool mapDraw;
bool mapLoader = false; 
int Score = 0;
int numkey=0;
extern char mapSize[80][31];
bool launchVicScreen = false;
bool launchDefScreen = false;;


double aiBounceTime1;
double aiBounceTime2;
double bossBounceTime;

// Game specific variables here
extern int g_MapNo;
WORD color;
SGameChar   g_sChar;
SGameChar HealthBar;
bool hitTarget[9];
//SGameEnemy  g_sEnemy;// Enemy
EnemyStruct Enemy;
AiBounceTime Bounce;
SGameBoss g_sBoss;
SGameKeys	g_sKeys[4];
SGameKeys	g_sDoor;
Teleporters g_A, g_B, g_C, g, g_D;
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
	srand(time(NULL));
	// Set precision for floating point output
	g_dElapsedTime = 0.0;
	g_dBounceTime = 0.0;

	/*---------------------file load------------------------------*/
	loadSplashscreen();

	/*-----------------------------------------------------------*/
	// sets the initial state for the game
	g_eGameState = S_SPLASHSCREEN;
	PlaySound(TEXT("splash.wav"), NULL, SND_ASYNC | SND_LOOP);
	g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 2;
	g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 2;
	//
	//Enemy.g_sEnemy.m_cLocation.X = 18; // enemy spawn location
	//Enemy.g_sEnemy.m_cLocation.Y = 25;

	//Enemy.g_sEnemy2.m_cLocation.X = 18; // enemy spawn location
	//Enemy.g_sEnemy2.m_cLocation.Y = 10;

	//Enemy.g_sEnemy3.m_cLocation.X = 59; // enemy spawn location
	//Enemy.g_sEnemy3.m_cLocation.Y = 15;
	//
	//Enemy.g_sEnemy4.m_cLocation.X = 15; // enemy spawn location
	//Enemy.g_sEnemy4.m_cLocation.Y = 27;

	//Enemy.g_sEnemy5.m_cLocation.X = 46; // enemy spawn location
	//Enemy.g_sEnemy5.m_cLocation.Y = 18;

	//Enemy.g_sEnemy6.m_cLocation.X = 33; // enemy spawn location
	//Enemy.g_sEnemy6.m_cLocation.Y = 18;


	g_sBoss.m_cLocation.X = 20;
	g_sBoss.m_cLocation.Y = 25;

	trapSpawn();

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
	g_abKeyPressed[K_H] = isKeyPressed(0x68);
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
	GameTime += dt;
	switch (g_eGameState)
	{
	case S_SPLASHSCREEN: splashScreenWait(); // game logic for the splash screen
		break;
	case S_GUIDE: guide();
		break;
	case S_GAME: gameplay(); // gameplay logic when we are in the game
		break;
	case S_DICE: dice();
		break;
	case S_QUIZEASY: quizEasy();
		break;
	case S_QUIZMEDIUM: quizMedium();
		break;
	case S_QUIZHARD: quizHard();
		break;
	case S_DEFEAT: defeatScreen();
		break;
	case S_VICTORY: victoryScreen();
		break;
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
	case S_SPLASHSCREEN: renderSplashscreen();
		break;
	case S_GUIDE: loadguide();
		break;
	case S_HIGHSCORE: renderScore();
		break;
	case S_GAME: renderGame();
		break;
	case S_DICE: renderdice();
		break;
	case S_QUIZEASY: renderquizEasy();
		break;
	case S_QUIZMEDIUM: renderquizMedium();
		break;
	case S_QUIZHARD: renderquizHard();
		break;
	case S_DEFEAT: renderDefeatScreen();
		break;
	case S_VICTORY: renderVictoryScreen();
		break;
	}
	renderFramerate();  // renders debug information, frame rate, elapsed time, etc
	renderToScreen();   // dump the contents of the buffer to the screen, one frame worth of game
}








