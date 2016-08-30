#include "HighScore.h"
#include <vector>
extern Console g_Console;
extern EGAMESTATES g_eGameState;
extern bool g_abKeyPressed[K_COUNT];


void HighScore(string Time, string Points)
{
	//Write into File (HighScore.txt)
	fstream file;
	file.open("HighScore.txt", fstream::app);
	file << Time << endl << Points << endl;
}

void renderScore()
{
	COORD c = g_Console.getConsoleSize();//Coordinates to display High Scores
	c.Y = 19;
	c.X = g_Console.getConsoleSize().X / 2 - 30;
	
	string line;

	//Render High Score title
	RenderHighScore();

	double HighScoreTime[10] = { 0.0, };
	int HighScorePoints[10] = { 0, };

	int AllPoints[150] = { 0, };
	double AllTime[150] = { 0.0, };

	//High Score Based on points

	int i = 0;
	int x = 0;
	int a = 0;

	ifstream file("HighScore.txt");//Read File from HighScore.txt
	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (i % 2 == 1)//Check to see whether it's even or odd line. If even, score is time
			{
				int Points;
				Points = stoi(line);//Cnverts string to integers
				AllPoints[i - x] = Points;
			}
			if (i % 2 == 0)//If Odd, score is Points
			{
				double ScoreTime;
				ScoreTime = stod(line);//Convert String to double
				AllTime[a+x] = ScoreTime;
				x++;
			}
			i++;//Go to next line
		}
		file.close();//Close file
	}

	
	for (int HighScoreCount = 0; HighScoreCount < 10; HighScoreCount++)//Processes the latest 10 Scores
	{
		int mostpoints = 0;
		double ShortestTime = 0;

		for (int a = 0; a < i; a++)//Check to see which scores to display
		{
			if (mostpoints == 0)//check to see if it's the first set of scores in the text file
			{
				ShortestTime = AllTime[a];//If it is, it will be regarded as the shortest time and most points
				mostpoints = AllPoints[a];
			}
			if (mostpoints < AllPoints[a])//Placing it in order of most points to least points. Change < to > to do the opposite 
			{
				bool InArray = false;
					for (int c = 0; c < 10; c++)//Processes 10 Scores
					{
						if (HighScorePoints[c] == AllPoints[a]) // checking to see if there's anything in HighScore[] that has the same value as the selected value of (AllScores[])
						{
							InArray = true; // if there is, set it to true
						}
					}
					if (InArray == false)
					{
						mostpoints = AllPoints[a];//Top points
						ShortestTime = AllTime[a];//Top timing
					}
			}
		}
		HighScoreTime[HighScoreCount] = ShortestTime; // Shortest Time
		HighScorePoints[HighScoreCount] = mostpoints; // Most points
	}
	for (int b = 0; b < (i / 2) && b < 5; b++) // Displays only top 5 scores-Rows. i is a variable integer,
	{                                             // so editing i will change the amount of scores displayed in accordance to the number of scores in the txt file
		string strTime;
		string strPoints;
		char Digit[20];
		char Points[10];
		strPoints = to_string(HighScorePoints[b]);//To StringPoints
		strTime = to_string(HighScoreTime[b]);//To String Time

		strcpy(Digit, strTime.c_str());
		strcpy(Points, strPoints.c_str());

		//Coordinates for displaying Time on HighScore
		c.X = g_Console.getConsoleSize().X / 2 - 30;//X coord
		c.Y += 1;//Y coord
		g_Console.writeToBuffer(c, Digit);
		//Coordinates for displaying the word 'Seconds'
		COORD SecondsCoord;
		SecondsCoord.X = g_Console.getConsoleSize().X / 2 - 20;
		SecondsCoord.Y = c.Y;
		g_Console.writeToBuffer(SecondsCoord, " Seconds");

		//Coordinates for displaying Score on HighScore
		c.X = g_Console.getConsoleSize().X / 2;
		g_Console.writeToBuffer(c, Points);
		//Coordinates for displaying the word 'Points'
		SecondsCoord.X = g_Console.getConsoleSize().X / 2 + 5;
		SecondsCoord.Y = c.Y;
		g_Console.writeToBuffer(SecondsCoord, " Points");
	}
	if (g_eGameState == S_HIGHSCORE && g_abKeyPressed [K_BACK])
	{
		g_eGameState = S_SPLASHSCREEN;
	}
}