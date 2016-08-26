#include "HighScore.h"
#include <vector>
extern Console g_Console;

void HighScore(string Time, string Points)
{
	//Write into File (HighScore.txt)
	fstream file;
	file.open("HighScore.txt", fstream::app);
	file << Time << "\n" << Points << "\n";
}
void renderScore()
{
	COORD c = g_Console.getConsoleSize();
	c.Y = 19;
	c.X = g_Console.getConsoleSize().X / 2 - 30;
	
	string line;

	RenderHighScore();

	double HighScore[5] = { 0.0, };
	int HighScorePoints[5] = { 0, };

	int AllPoints[150] = { 0, };
	double AllTime[150] = { 0.0, };
	int i = 0;
	int x = 0;
	int a = 0;

	ifstream file("HighScore.txt");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (i % 2 == 1)
			{
				double ScoreTime;
				ScoreTime = stod(line);
				AllTime[a + x] = ScoreTime;
				a++;
			}
			if (i % 2 == 0)
			{
				int Points;
				Points = stoi(line);
				AllPoints[i - x] = Points;
			}
			i++;
		}
		file.close();
	}
	
	for (int HighScoreCount = 0; HighScoreCount < 5; HighScoreCount++)
	{
		double ShortestTime = 0;
		int mostpoints = 0;

		for (int a = 0; a < i; a++)
		{
			if (ShortestTime == 0)
			{
				ShortestTime = AllTime[a];
				mostpoints = AllPoints[a];
			}
			if (ShortestTime > AllTime[a])
			{
				bool inarray = false;
					for (int c = 0; c < 5; c++)
					{
						if (HighScore[c] == AllTime[a]) // checking to see if there's anything in HighScore[] that has the same value as the selected value of (AllScores[])
						{
							inarray = true; // if there is, set it to true
						}
					}
					if (inarray == false)
					{
						ShortestTime = AllTime[a];
						mostpoints = AllPoints[a];
					}
			}
		}
		HighScore[HighScoreCount] = ShortestTime; // Shortest Time
		HighScorePoints[HighScoreCount] = mostpoints; // Most points
	}
	for (int b = 0; b < 5; b++) // Displays only top 5 scores
	{
		std::string str;
		std::string strPoints;
		char Digit[10];
		char Points[10];
		str = to_string(HighScore[b]);//Time
		strPoints = to_string(HighScorePoints[b]);//Points

		std::strcpy(Digit, str.c_str());
		std::strcpy(Points, strPoints.c_str());

		//Coordinates for displaying points on HighScore
		c.X = g_Console.getConsoleSize().X / 2 - 30;
		c.Y += 1;
		g_Console.writeToBuffer(c, Digit);
		COORD SecondsCoord;
		SecondsCoord.X = g_Console.getConsoleSize().X / 2 - 20;
		SecondsCoord.Y = c.Y;
		g_Console.writeToBuffer(SecondsCoord, " Seconds");

		//Coordinates for displaying Time on HighScore
		c.X = g_Console.getConsoleSize().X / 2;

		g_Console.writeToBuffer(c, Points);
		SecondsCoord.X = g_Console.getConsoleSize().X / 2 + 5;
		SecondsCoord.Y = c.Y;
		
		g_Console.writeToBuffer(SecondsCoord, " Mikus");
	}
}