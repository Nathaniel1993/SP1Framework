#include "postgame.h"
#include <fstream>
#include "game.h"
#include "Framework\console.h"
#include "loadfile.h"

extern bool    g_abKeyPressed[K_COUNT];
extern bool splashScreenload;

extern char defeat[80][31];
extern char victory[80][31];
extern Console g_Console;
extern EGAMESTATES g_eGameState;

extern bool launchVicScreen;
extern bool launchDefScreen;

void defeatScreen()
{
	if (launchDefScreen == true)
	{
		loadDefeatScreen();
		launchDefScreen = false;
	}
	if (g_abKeyPressed[K_ENTER])
	{
		splashScreenload = true;
		g_eGameState = S_SPLASHSCREEN;
	}
	if (g_abKeyPressed[K_ESCAPE])
	{
		g_bQuitGame = true;
	}

}

void renderDefeatScreen()
{
	COORD c;
	for (int y = 0; y < 31; y++)
	{
		c.Y = y;
		for (int x = 0; x < 80; x++)
		{
			if (defeat[x][y] == 'i')
			{
				defeat[x][y] = ' ';
			}
			c.X = x;
			g_Console.writeToBuffer(c, defeat[x][y]);
			if (defeat[x][y] != ' ')
			{
				g_Console.writeToBuffer(c, defeat[x][y], 0x0C);
			}
		}
	}
	COORD l;
	l.Y = 26;
	l.X = 30;
	g_Console.writeToBuffer(l, "", 0x0B); //highscore
	l.Y = 27;
	l.X = 30;
	g_Console.writeToBuffer(l, "", 0x0B); // time
	l.Y = 28;
	l.X = 30;
	g_Console.writeToBuffer(l, "Press <Enter> key to return to main menu", 0x0B); 
	l.Y = 29;
	l.X = 30;
	g_Console.writeToBuffer(l, "Press <Esc> key to quit", 0x0B);
}

void victoryScreen()
{
	if (launchVicScreen == true)
	{
		loadVictoryScreen();
		launchVicScreen = false;
	}

	if (g_abKeyPressed[K_ENTER])
	{
		splashScreenload = true;
		g_eGameState = S_SPLASHSCREEN;
	}
	if (g_abKeyPressed[K_ESCAPE])
	{
		g_bQuitGame = true;
	}
}

void renderVictoryScreen()
{
	COORD c;
	for (int y = 0; y < 31; y++)
	{
		c.Y = y;
		for (int x = 0; x < 80; x++)
		{
			if (victory[x][y] == 'i')
			{
				victory[x][y] = ' ';
			}
			c.X = x;
			g_Console.writeToBuffer(c, victory[x][y]);
			if (victory[x][y] != ' ')
			{
				g_Console.writeToBuffer(c, victory[x][y], 0x0A);
			}
		}
	}
	COORD l;
	l.Y = 26;
	l.X = 30;
	g_Console.writeToBuffer(l, "", 0x0B); //highscore
	l.Y = 27;
	l.X = 30;
	g_Console.writeToBuffer(l, "", 0x0B); // time
	l.Y = 28;
	l.X = 30;
	g_Console.writeToBuffer(l, "Press <Enter> key to return to main menu", 0x0B);
	l.Y = 29;
	l.X = 30;
	g_Console.writeToBuffer(l, "Press <Esc> key to quit", 0x0B);
}