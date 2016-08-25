#include "RenderHighScore.h"

extern Console g_Console;

void RenderHighScore()
{
	COORD c = g_Console.getConsoleSize();
	c.Y = 0;
	c.X = 0;

	string line;
	ifstream file("HighScoreTitle.txt");

	if (file.is_open())
	{
		while (getline(file, line))
		{
			c.Y += 1;
			g_Console.writeToBuffer(c, line);
		}
		file.close();
	}
}