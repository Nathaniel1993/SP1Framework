#include "HighScore.h"
#include <vector>
extern Console g_Console;

void HighScore(string Time, string Points)
{
	fstream file;
	file.open("HighScore.txt", fstream::app);
	file << Points << "\n" << Time << "\n";
}
void renderScore()
{
	COORD c = g_Console.getConsoleSize();
	c.Y = 19;
	c.X = g_Console.getConsoleSize().X / 2 - 30;

	string line;

	RenderHighScore();

	double HighScore[5] = { 0.0, };
	int HighScoreTime[5] = { 0, };

	int AllPoints[150] = { 0, };
	double AllTime[150] = { 0.0, };
	int i = 0;
	int a = 0;
	int b = 0;

	ifstream file("HighScore.txt");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (i % 2 == 1)
			{
				int Points;
				Points = stoi(line);
				AllPoints[i - a] = Points;
			}
			if (i % 2 == 0)
			{
				double ScoreTime;
				ScoreTime = stod(line);
				AllTime[b + a] = ScoreTime;
				a++;
			}
			i++;
		}
		file.close();
	}
	
	for (int HighScoreCount = 0; HighScoreCount < 5; HighScoreCount++)
	{
		double LongestTime = 0;
		int mostpoints = 0;

		for (int b = 0; b < i; a++)
		{
			if (LongestTime == 0)
			{
				LongestTime = AllTime[b];
				mostpoints = AllPoints[b];
			}
			if (LongestTime > AllTime[b])
			{
				bool inarray = false;
					for (int x = 0; x < 5; x++)
					{
						if (HighScore[x] == AllTime[a])
						{
							inarray = true;
						}
					}
					if (inarray == false)
					{
						LongestTime = AllTime[a];
						mostpoints = AllPoints[a];
					}
			}
		}
		HighScore[HighScoreCount] = mostpoints;
		HighScoreTime[HighScoreCount] = LongestTime;
	}
	for (int a = 0; a < 5; a++)
	{
		string str;
		string strPoints;
		char Digit[10];
		char Points[10];
		str = to_string(HighScore[b]);

		strcpy(Digit, str.c_str());
		strcpy(Points, strPoints.c_str());

		c.X = g_Console.getConsoleSize().X / 2 - 30;
		c.Y += 1;
		g_Console.writeToBuffer(c, Digit);
		COORD SecondsCoord;
		SecondsCoord.X = g_Console.getConsoleSize().X / 2 - 20;
		SecondsCoord.Y = c.Y;
		g_Console.writeToBuffer(SecondsCoord, " secs");

		c.X = g_Console.getConsoleSize().X / 2;

		g_Console.writeToBuffer(c, Points);
		SecondsCoord.X = g_Console.getConsoleSize().X / 2 + 5;
		SecondsCoord.Y = c.Y;
		g_Console.writeToBuffer(SecondsCoord, " Points");
	}
}