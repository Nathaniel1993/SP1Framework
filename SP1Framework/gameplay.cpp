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

bool encounter = false;

extern bool    ScoreTracker;
extern bool    g_abKeyPressed[K_COUNT];
extern bool	   diceRoll;
extern bool    mapLoader;
extern bool	   launchDice;
extern bool splashScreenload;

extern int g_MapNo;
extern int Score;
extern int keys;
extern int numkey;

extern char mapSize[80][31];

extern double  g_dElapsedTime;
extern double  g_dDeltaTime;
extern double  g_dBounceTime;
extern double  bossBounceTime;

extern WORD color;
extern SGameChar g_sChar;
extern EnemyStruct Enemy;
extern AiBounceTime Bounce;
extern SGameBoss g_sBoss;
extern SGameKeys	g_sKeys[4];
extern SGameKeys	g_sDoor;
extern EGAMESTATES g_eGameState;

int encounterCheck1 = 0;
int encounterCheck2 = 0;
int encounterCheck3 = 0;
int encounterCheck4 = 0;
int encounterCheck5 = 0;
int encounterCheck6 = 0;

void splashScreenWait()    // waits for time to pass in splash screen
{
	if (splashScreenload == true)
	{
		loadSplashscreen();
		splashScreenload = false;
	}

	if (g_abKeyPressed[K_ENTER])
	{
		g_eGameState = S_GAME;
		g_MapNo = 1;
		mapLoader = true;
	}
	if (g_abKeyPressed[K_LEFTCONTROL])
	{
		g_eGameState = S_GUIDE;
	}
}

void gameplay()            // gameplay logic
{
	processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit
	if (mapLoader == true)
	{
		switch (g_MapNo)
		{
		case 1: loadMap1();
			break;
		case 2: loadMap2();
			break;
		case 3: loadMap3();
			break;
		}
		mapLoader = false;
	}
	moveCharacter();   // moves the character, collision detection, physics, etc
	if (g_MapNo == 1)
	{
		AiEnemy();
		AiEnemy2();
		AiEnemy3();
	}
	if (g_MapNo == 2)
	{
		AiEnemy4();
		AiEnemy5();
		AiEnemy6();
	}
	if (g_MapNo == 3)
	{
		BossAi();
		healthAi();
	}
	if (ScoreTracker == true)
	{
		Score++;
		mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] = ' ';
		ScoreTracker = false;
	}
	if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X == 0 && g_sChar.m_cLocation.Y == 2)
	{
		g_MapNo = 2;
		keys = 4;
		mapLoader = true;
		PlaySound(TEXT("splash"), NULL, SND_ASYNC | SND_LOOP);
		g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 1;
		g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 3;
		
	}
	else if (g_sChar.m_cLocation.X == 39 && g_sChar.m_cLocation.Y == 0)
	{
		g_MapNo = 3;
		keys = 4;
		mapLoader = true;
		PlaySound(TEXT("Map1.wav"), NULL, SND_ASYNC | SND_LOOP);
		g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 42;
		g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 3;
	}
	if (encounter == true)
	{
		g_eGameState = S_DICE;
		launchDice = true;
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
		if (mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] != '#')
		{
			if (mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'F')
			{
				if (mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 2] != '#' && mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 2] != 'A')
				{
					mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 2] = 'F';
					mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] = ' ';
					g_sChar.m_cLocation.Y--;
					bSomethingHappened = true;
				}
			}
			else if (mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == '.')
			{
				ScoreTracker = true;
			}
			else if (mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == 'K')
			{
				keys--;
				mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] = ' ';
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
		if (mapSize[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] != '#' && mapSize[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] != 'A')
		{
			if (mapSize[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == 'F')
			{
				if (mapSize[g_sChar.m_cLocation.X - 2][g_sChar.m_cLocation.Y] != '#' && mapSize[g_sChar.m_cLocation.X - 2][g_sChar.m_cLocation.Y] != 'A')
				{
					mapSize[g_sChar.m_cLocation.X - 2][g_sChar.m_cLocation.Y] = 'F';
					mapSize[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] = ' ';
					g_sChar.m_cLocation.X--;
					bSomethingHappened = true;
				}
			}
			else if (mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == '.')
			{
				ScoreTracker = true;
			}
			else if (mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == 'K')
			{
				keys--;
				mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] = ' ';
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
		if (mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] != '#')
		{
			if (mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == 'F')
			{
				if (mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 2] != '#' && mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 2] != 'A')
				{
					mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 2] = 'F';
					mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] = ' ';
					g_sChar.m_cLocation.Y++;
					bSomethingHappened = true;
				}
			}
			else if (mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == '.')
			{
				ScoreTracker = true;
			}
			else if (mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == 'K')
			{
				keys--;
				mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] = ' ';
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
		if (mapSize[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] != '#')
		{
			if (mapSize[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == 'F')
			{
				if (mapSize[g_sChar.m_cLocation.X + 2][g_sChar.m_cLocation.Y] != '#' && mapSize[g_sChar.m_cLocation.X + 2][g_sChar.m_cLocation.Y] != 'A')
				{
					mapSize[g_sChar.m_cLocation.X + 2][g_sChar.m_cLocation.Y] = 'F';
					mapSize[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] = ' ';
					g_sChar.m_cLocation.X++;
					bSomethingHappened = true;
				}
			}
			else if (mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == '.')
			{
				ScoreTracker = true;
			}
			else if (mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == 'K')
			{
				keys--;
				mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] = ' ';
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