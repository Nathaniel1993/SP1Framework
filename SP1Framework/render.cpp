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

/*--------Array to load file and render with---------------*/
extern char splashScreen[80][31];
extern char mapSize[80][31];
extern char dice1[80][31];
extern char dice2[80][31];
extern char dice3[80][31];
extern char dice4[80][31];
extern char dice5[80][31];
extern char dice6[80][31];
/*---------------------------------------------------------*/
extern bool mapLoader;
extern bool torchPossession;
int g_MapNo = 0;

/*-------Variable for Interactive Objects and Score*/
extern int Score; 
extern int keys;
extern int numkey;
extern SGameKeys g_sKeys[4];
extern SGameKeys g_sDoor;
extern Teleporters g_A, g_B, g_C,g_D;
extern BoulderEndLocal g_Alocal, g_Blocal, g_Clocal;
/*------------------------------------------------*/

extern double  g_dElapsedTime;
extern double  g_dDeltaTime;
extern double GameTime;
extern EGAMESTATES g_eGameState;

extern bool g_abKeyPressed[K_COUNT];
extern int encounterCheck[6];

void renderSplashscreen()  // renders the splash screen
{
	COORD c;
	for (int y = 0; y < 31; y++)
	{
		c.Y = y;
		for (int x = 0; x < 80; x++)
		{
			if (splashScreen[x][y] == 'i')
			{
				splashScreen[x][y] = ' ';
			}
			c.X = x;
			g_Console.writeToBuffer(c, splashScreen[x][y]);
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
	l.Y = 29;
	l.X = 20;
	g_Console.writeToBuffer(l, "Press <H> key in game to view High Scores", 0x0B);
}

void renderGame()
{
	renderMap(); 
	renderCharacter();  // renders the character into the buffer
	//openDoor();
	moveCharacter();
	//renderKeys();
	if(g_MapNo == 1)
	{
		renderSight();
		for (int a = 0; a < 3; a++)
		{
			if (encounterCheck[a] == 0)
			{
				renderEnemies(Enemies[a]);
			}
		}
	}
	else if (g_MapNo == 2)
	{
		renderSight();
		for (int a = 3; a < 6; a++)
		{
			if (encounterCheck[a] == 0)
			{
				renderEnemies(Enemies[a]);
			}
		}
	}
	else if (g_MapNo == 3)
	{
		renderBoss();
		renderHealth();
		renderBossHealth();
		for (int i = 0; i < 9; i++)
		{
			renderTrap(trap[i]);
		}
	}
	openDoor();
}

void renderMap()
{
	COORD c;
	for (int y = 0; y < 31; y++)
	{
		c.Y = y;
		for (int x = 0; x < 80; x++)
		{
			if (mapSize[x][y] == 'i')
			{
				mapSize[x][y] = ' ';
			}
			if (mapSize[x][y] == 'B')
			{
				g_B.m_cLocation.X = x;
				g_B.m_cLocation.Y = y;
			}
			if (mapSize[x][y] == 'C')
			{
				g_C.m_cLocation.X = x;
				g_C.m_cLocation.Y = y;
			}
			if (mapSize[x][y] == 'D')
			{
				g_D.m_cLocation.X = x;
				g_D.m_cLocation.Y = y;
			}
			if (mapSize[x][y] == 'G')
			{
				g_Alocal.m_cLocation.X = x;
				g_Alocal.m_cLocation.Y = y;
				g_Console.writeToBuffer(g_Alocal.m_cLocation, ' ', 0x00);
			}
			if (mapSize[x][y] == 'H')
			{
				g_Blocal.m_cLocation.X = x;
				g_Blocal.m_cLocation.Y = y;
				g_Console.writeToBuffer(g_Blocal.m_cLocation, ' ', 0x00);
			}
			if (mapSize[x][y] == 'J')
			{
				g_Clocal.m_cLocation.X = x;
				g_Clocal.m_cLocation.Y = y;
				g_Console.writeToBuffer(g_Clocal.m_cLocation, ' ', 0x00);
			}
			c.X = x;
			if ((g_MapNo == 1) || (g_MapNo == 2))
			{
				g_Console.writeToBuffer(c, mapSize[x][y], 0x00);
			}
			else if (g_MapNo == 3)
			{
				g_Console.writeToBuffer(c, mapSize[x][y], 0x09);
			}
		}
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
		ss << GameTime << "secs";
		c.X = 0;
		c.Y = 0;
		g_Console.writeToBuffer(c, ss.str(),0x00);
		if (g_eGameState == S_GAME)
		{
			g_Console.writeToBuffer(c, ss.str(), 0x0A);
		}
	//displays the score
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
			g_Console.writeToBuffer(g_sKeys[i].m_cLocation, ' ', 0x0f);
		}
	}
}

void openDoor()
{
	if (keys == 0)
	{
		mapSize[g_sDoor.m_cLocation.X][g_sDoor.m_cLocation.Y] = ' ';
	}
}

void BoulderIn()
{
	;
}

void renderPlayerTime()
{
	COORD c;

	ostringstream ss;
	ss << fixed << setprecision(3);
	
	ss.str("");
	ss << "Game Time: " << GameTime;
	c.X = 1;
	c.Y = 1;
	g_Console.writeToBuffer(c, ss.str());
}

void renderSight()
{
	COORD c;
	if (torchPossession == false)
	{
		for (int VisionX = g_sChar.m_cLocation.X - 6; VisionX < g_sChar.m_cLocation.X + 6; VisionX++)
		{
			c.X = VisionX;
			for (int VisionY = g_sChar.m_cLocation.Y - 3; VisionY < g_sChar.m_cLocation.Y + 3; VisionY++)
			{
				c.Y = VisionY;
				if (VisionX == g_sChar.m_cLocation.X && VisionY == g_sChar.m_cLocation.Y)
				{

				}
				else
				{
					if (mapSize[VisionX][VisionY] == 'T')
					{
						g_Console.writeToBuffer(c, mapSize[VisionX][VisionY], 0x0E);
					}
					if (mapSize[VisionX][VisionY] == '.')
					{
						g_Console.writeToBuffer(c, mapSize[VisionX][VisionY], 0x0A);
					}
					if (mapSize[VisionX][VisionY] == '#')
					{
						g_Console.writeToBuffer(c, mapSize[VisionX][VisionY], 0x09);
					}
					if (mapSize[VisionX][VisionY] == 'E')
					{
						g_Console.writeToBuffer(c, mapSize[VisionX][VisionY], 0x0F);
						g_sDoor.m_cLocation.X = VisionX;
						g_sDoor.m_cLocation.Y = VisionY;
					}
					if (mapSize[VisionX][VisionY] == 'K')
					{
						g_Console.writeToBuffer(c, mapSize[VisionX][VisionY], 0x0D);
					}
					if (mapSize[VisionX][VisionY] == '*')
					{
						g_Console.writeToBuffer(c, mapSize[VisionX][VisionY], 0x0B);
					}
					if (mapSize[VisionX][VisionY] == 'F')
					{
						g_Console.writeToBuffer(c, mapSize[VisionX][VisionY], 0x0E);
					}
					if (mapSize[VisionX][VisionY] == 'O')
					{
						g_Console.writeToBuffer(c, mapSize[VisionX][VisionY], 0x0D);
					}
					if (mapSize[VisionX][VisionY] == 'A')
					{
						g_A.m_cLocation.X = VisionX;
						g_A.m_cLocation.Y = VisionY;
						g_Console.writeToBuffer(c, mapSize[VisionX][VisionY], 0x0E);
					}
					if (mapSize[VisionX][VisionY] == 'B')
					{
						g_Console.writeToBuffer(c, mapSize[VisionX][VisionY], 0x0E);;
					}
					if (mapSize[VisionX][VisionY] == 'C')
					{
						g_Console.writeToBuffer(c, mapSize[VisionX][VisionY], 0x0E);
					}
					if (mapSize[VisionX][VisionY] == 'D')
					{
						g_Console.writeToBuffer(c, mapSize[VisionX][VisionY], 0x0E);
					}
					if (mapSize[VisionX][VisionY] == '|')
					{
						g_Console.writeToBuffer(c, mapSize[VisionX][VisionY], 0x0E);
					}
				}
			}
		}
	}
	else
	{
		for (int VisionX = g_sChar.m_cLocation.X - 10; VisionX < g_sChar.m_cLocation.X + 10; VisionX++)
		{
			c.X = VisionX;
			for (int VisionY = g_sChar.m_cLocation.Y - 5; VisionY < g_sChar.m_cLocation.Y + 5; VisionY++)
			{
				c.Y = VisionY;
				if (VisionX == g_sChar.m_cLocation.X && VisionY == g_sChar.m_cLocation.Y)
				{

				}
				else
				{
					if (mapSize[VisionX][VisionY] == '.')
					{
						g_Console.writeToBuffer(c, mapSize[VisionX][VisionY], 0x0A);
					}
					if (mapSize[VisionX][VisionY] == '#')
					{
						g_Console.writeToBuffer(c, mapSize[VisionX][VisionY], 0x09);
					}
					if (mapSize[VisionX][VisionY] == 'E')
					{
						g_Console.writeToBuffer(c, mapSize[VisionX][VisionY], 0x0F);
						g_sDoor.m_cLocation.X = VisionX;
						g_sDoor.m_cLocation.Y = VisionY;
					}
					if (mapSize[VisionX][VisionY] == 'K')
					{
						g_Console.writeToBuffer(c, mapSize[VisionX][VisionY], 0x0D);
					}
					if (mapSize[VisionX][VisionY] == '*')
					{
						g_Console.writeToBuffer(c, mapSize[VisionX][VisionY], 0x0B);
					}
					if (mapSize[VisionX][VisionY] == 'F')
					{
						g_Console.writeToBuffer(c, mapSize[VisionX][VisionY], 0x0E);
					}
					if (mapSize[VisionX][VisionY] == 'O')
					{
						g_Console.writeToBuffer(c, mapSize[VisionX][VisionY], 0x0D);
					}
					if (mapSize[VisionX][VisionY] == 'A')
					{
						g_A.m_cLocation.X = VisionX;
						g_A.m_cLocation.Y = VisionY;
						g_Console.writeToBuffer(c, mapSize[VisionX][VisionY], 0x0E);
					}
					if (mapSize[VisionX][VisionY] == 'B')
					{
						g_Console.writeToBuffer(c, mapSize[VisionX][VisionY], 0x0E);;
					}
					if (mapSize[VisionX][VisionY] == 'C')
					{
						g_Console.writeToBuffer(c, mapSize[VisionX][VisionY], 0x0E);
					}
					if (mapSize[VisionX][VisionY] == 'D')
					{
						g_Console.writeToBuffer(c, mapSize[VisionX][VisionY], 0x0E);
					}
					if (mapSize[VisionX][VisionY] == '|')
					{
						g_Console.writeToBuffer(c, mapSize[VisionX][VisionY], 0x0E);
					}
				}
			}
		}
	}
}
