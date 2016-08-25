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
int g_MapNo = 0;

/*-------Variable for Interactive Objects and Score*/
extern int Score; 
extern int keys;
extern int numkey;
extern SGameKeys g_sKeys[4];
extern SGameKeys g_sDoor;
/*------------------------------------------------*/

extern double  g_dElapsedTime;
extern double  g_dDeltaTime;

extern bool g_abKeyPressed[K_COUNT];

extern int encounterCheck1;
extern int encounterCheck2;
extern int encounterCheck3;
extern int encounterCheck4;
extern int encounterCheck5;
extern int encounterCheck6;

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
}

void renderGame()
{
	renderMap(); 
	renderCharacter();  // renders the character into the buffer
	//openDoor();
	moveCharacter();
	if (g_MapNo == 1)
	{
		if (encounterCheck1 == 0)
		{
			renderEnemy();
		}
		if (encounterCheck2 == 0)
		{
			renderEnemy2();
		}
		if (encounterCheck3 == 0)
		{
			renderEnemy3();
		}
	}
	else if (g_MapNo == 2)
	{
		if (encounterCheck4 == 0)
		{
			renderEnemy4();
		}
		if (encounterCheck5 == 0)
		{
			renderEnemy5();
		}
		if (encounterCheck6 == 0)
		{
			renderEnemy6();
		}
	}
	else if (g_MapNo == 3)
	{
		renderBoss();
		//renderHealth();
		//renderTrap;
	}
	//renderKeys();
	renderSight();
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
			c.X = x;
			g_Console.writeToBuffer(c, mapSize[x][y], 0x00);
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
	ss << g_dElapsedTime << "secs";
	c.X = 0;
	c.Y = 0;
	g_Console.writeToBuffer(c, ss.str());

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

void renderSight()
{
	COORD c;
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
				if (mapSize[VisionX][VisionY] == '.')
				{
					g_Console.writeToBuffer(c, mapSize[VisionX][VisionY], 0x0A);
				}
				if (mapSize[VisionX][VisionY] == '#')
				{
					g_Console.writeToBuffer(c, mapSize[VisionX][VisionY], 0x09);
				}
				if (mapSize[VisionX][VisionY] == 'A')
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
			}
		}
	}
}
