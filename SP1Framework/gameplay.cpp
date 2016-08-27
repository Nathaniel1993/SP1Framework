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
#include "HighScore.h"

bool encounter = false;

extern double GameTime;
extern bool    ScoreTracker;
extern bool    g_abKeyPressed[K_COUNT];
extern bool	   diceRoll;
extern bool    mapLoader;
extern bool	   launchDice;
extern bool splashScreenload;

extern int g_MapNo;
extern int Score;
int keys = 4;
extern int numkey;
bool TeleportActive = false;

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
extern Teleporters g_A, g_B, g_C, g, g_D;

int encounterCheck[6] = { 0, };

void splashScreenWait()    // waits for time to pass in splash screen
{
	if (splashScreenload == true)
	{
		loadSplashscreen();
		splashScreenload = false;
	}

	if (g_abKeyPressed[K_ENTER])
	{
		Score = 0;
		enemiesSpawn1();
		GameTime = 0;
		for (int a = 0; a < 6; a++)
		{
			encounterCheck[a] = 0;
		}
		g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 2;
		g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 2;
		g_eGameState = S_GAME;
		g_MapNo = 1;
		mapLoader = true;
	}
	if (g_abKeyPressed[K_LEFTCONTROL])
	{
		g_eGameState = S_GUIDE;
	}
	if (g_abKeyPressed[K_H])
	{
		g_eGameState = S_HIGHSCORE;
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
		for (int a = 0; a < 3; a++)
		{
			EnemiesAi(Enemies[a]);
		}
	}
	if (g_MapNo == 2)
	{
		for (int a = 3; a < 6; a++)
		{
			EnemiesAi(Enemies[a]);
		}
	}
	if (g_MapNo == 3)
	{
		BossAi();
		damageBoss();
		healthAi();
		bossHealthAi();
	}
	if (ScoreTracker == true)
	{
		Score++;
		mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] = ' ';
		ScoreTracker = false;
	}
	if (mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == 'X')
	{
		if (g_MapNo == 1)
		{
			enemiesSpawn2();
			g_MapNo = 2;
			keys = 4;
			mapLoader = true;
			PlaySound(TEXT("splash"), NULL, SND_ASYNC | SND_LOOP);
			g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 1;
			g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 3;

		}
		else if (g_MapNo == 2)
		{
			g_MapNo = 3;
			keys = 4;
			mapLoader = true;
			PlaySound(TEXT("Map1.wav"), NULL, SND_ASYNC | SND_LOOP);
			g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 42;
			g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 3;
		}
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
		if (mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] != '#' && mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] != '|')
		{
			if (mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'F')
			{
				if (mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 2] != '#' 
					&& mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 2] != 'A'
					&& mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 2] != '|')
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
		if (mapSize[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] != '#' && mapSize[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] != '|')
		{
			if (mapSize[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == 'F')
			{
				if (mapSize[g_sChar.m_cLocation.X - 2][g_sChar.m_cLocation.Y] != '#' 
					&& mapSize[g_sChar.m_cLocation.X - 2][g_sChar.m_cLocation.Y] != 'A'
					&& mapSize[g_sChar.m_cLocation.X - 2][g_sChar.m_cLocation.Y] != '|')
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
		if (mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] != '#'&& mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] != '|')
		{
			if (mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == 'F')
			{
				if (mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 2] != '#' 
					&& mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 2] != 'A'
					&& mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 2] != '|')
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
		if (mapSize[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] != '#' && mapSize[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] != '|')
		{
			if (mapSize[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == 'F')
			{
				if (mapSize[g_sChar.m_cLocation.X + 2][g_sChar.m_cLocation.Y] != '#' 
					&& mapSize[g_sChar.m_cLocation.X + 2][g_sChar.m_cLocation.Y] != 'A'
					&& mapSize[g_sChar.m_cLocation.X + 2][g_sChar.m_cLocation.Y] != '|')
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
	if (mapSize[g_A.m_cLocation.X - 4][g_A.m_cLocation.Y + 1] == 'F' && mapSize[g_A.m_cLocation.X + 4][g_A.m_cLocation.Y + 1] == 'F'
		||mapSize[g_A.m_cLocation.X + 4][g_A.m_cLocation.Y + 1] == 'F' && mapSize[g_A.m_cLocation.X][g_A.m_cLocation.Y + 3] == 'F'
		|| mapSize[g_A.m_cLocation.X - 4][g_A.m_cLocation.Y + 1] == 'F' && mapSize[g_A.m_cLocation.X][g_A.m_cLocation.Y + 3] == 'F')
	{
		TeleportActive = true;
		g_Console.writeToBuffer(g_A.m_cLocation, 'A', 0x0A);
	}
	else
	{
		TeleportActive = false;
	}

	if (TeleportActive == true 
		&& mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y]=='A'
		&& mapSize[g_A.m_cLocation.X - 4][g_A.m_cLocation.Y + 1] == 'F' && mapSize[g_A.m_cLocation.X + 4][g_A.m_cLocation.Y + 1] == 'F')
	{
		g_sChar.m_cLocation.X = g_B.m_cLocation.X+1;
		g_sChar.m_cLocation.Y = g_B.m_cLocation.Y;
	}

	if (TeleportActive == true
		&& mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == 'A'
		&mapSize[g_A.m_cLocation.X + 4][g_A.m_cLocation.Y + 1] == 'F' && mapSize[g_A.m_cLocation.X][g_A.m_cLocation.Y + 3] == 'F')
	{
		g_sChar.m_cLocation.X = g_C.m_cLocation.X+1;
		g_sChar.m_cLocation.Y = g_C.m_cLocation.Y-1;
	}
	 if (TeleportActive == true
		&& mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == 'A'
		&& mapSize[g_A.m_cLocation.X - 4][g_A.m_cLocation.Y + 1] == 'F' && mapSize[g_A.m_cLocation.X][g_A.m_cLocation.Y + 3] == 'F')
	{
		g_sChar.m_cLocation.X = g_D.m_cLocation.X;
		g_sChar.m_cLocation.Y = g_D.m_cLocation.Y-1;
	}
	 
	 
	 if (TeleportActive == true && mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == 'B'
		 || TeleportActive == true && mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == 'C'
		 || TeleportActive == true && mapSize[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y] == 'D')
	 {
		 g_sChar.m_cLocation.X = g_A.m_cLocation.X;
		 g_sChar.m_cLocation.Y = g_A.m_cLocation.Y+1;
	 }

}

void processUserInput()
{
	// quits the game if player hits the escape key
	if (g_abKeyPressed[K_ESCAPE])
	{
		g_bQuitGame = true;
		if (GameTime != 0)
		{
			HighScore(to_string(GameTime), to_string(Score));
		}
	}
}

void clearScreen()
{
	// Clears the buffer with this colour attribute
	g_Console.clearBuffer(0x00);
}