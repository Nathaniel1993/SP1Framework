#include "postgame.h"
#include <fstream>
#include "game.h"
#include "Framework\console.h"
#include "loadfile.h"
#include <sstream>

extern bool    g_abKeyPressed[K_COUNT];
extern bool splashScreenload;

extern char defeat[80][31];
extern char victory[80][31];
extern Console g_Console;
extern EGAMESTATES g_eGameState;

extern bool launchVicScreen;
extern bool launchDefScreen;

extern int Score;
extern double  g_dElapsedTime;

int tempScore = 0;
double tempTime = 0.0;

void defeatScreen()
{
	if (launchDefScreen == true)
	{
		tempScore = Score;
		tempTime = g_dElapsedTime;
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
	std::ostringstream ss;			//displays the game score post game
	ss.str("");
	ss << "Score: " << tempScore << "points";
	l.X = 30;
	l.Y = 26;
	g_Console.writeToBuffer(l, ss.str(), 0x0B);
	
	ss.str("");						//displays the time spend post game
	ss << "Time Spend: " << tempTime << "secs";
	l.X = 30;
	l.Y = 27;
	g_Console.writeToBuffer(l, ss.str(), 0x0B);

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
		tempTime = g_dElapsedTime;
		tempScore = Score;
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
	std::ostringstream ss;			//displays the game score post game
	ss.str("");
	ss << "Score: " << tempScore << "points";
	l.X = 30;
	l.Y = 26;
	g_Console.writeToBuffer(l, ss.str(), 0x0B);

	ss.str("");						//displays the time spend post game
	ss << "Time Spend: " << tempTime << "secs";
	l.X = 30;
	l.Y = 27;
	g_Console.writeToBuffer(l, ss.str(), 0x0B);
	l.Y = 28;
	l.X = 30;
	g_Console.writeToBuffer(l, "Press <Enter> key to return to main menu", 0x0B);
	l.Y = 29;
	l.X = 30;
	g_Console.writeToBuffer(l, "Press <Esc> key to quit", 0x0B);
}