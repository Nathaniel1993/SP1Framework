#include"quiz.h"
#include <fstream>

extern int Score;
extern bool mapLoader;
extern bool g_abKeyPressed[K_COUNT];
extern EGAMESTATES g_eGameState;
extern Console g_Console;
extern char MapSize[80][31];
extern int Lifecounter;
extern bool giveScore;

void EasyQuestion1()
{
	if (Bounce.easyQuizBounceTime > g_dElapsedTime)
	{
		return;
	}
	Bounce.easyQuizBounceTime = 0.0;
	if (g_abKeyPressed[K_FIVE])
	{
		giveScore = true;
		g_eGameState = S_GAME;
	}
	else if (g_abKeyPressed[K_ONE] || g_abKeyPressed[K_TWO] || g_abKeyPressed[K_FOUR] || g_abKeyPressed[K_FIVE])
	{
		if (Lifecounter == 3)
		{
			giveScore = true;
		}
		else
		{
			Lifecounter++;
		}
	}
	Bounce.easyQuizBounceTime = g_dElapsedTime + 0.125;
}

void EasyQuestion2()
{
	if (Bounce.easyQuizBounceTime > g_dElapsedTime)
	{
		return;
	}
	Bounce.easyQuizBounceTime = 0.0;
	if (g_abKeyPressed[K_ONE])
	{
		giveScore = true;
		g_eGameState = S_GAME;
	}
	else if (g_abKeyPressed[K_TWO] || g_abKeyPressed[K_FOUR] || g_abKeyPressed[K_FIVE] || g_abKeyPressed[K_THREE])
	{
		if (Lifecounter == 3)
		{
			giveScore = true;
		}
		else
		{
			Lifecounter++;
		}
	}
	Bounce.easyQuizBounceTime = g_dElapsedTime + 0.125;
}

void EasyQuestion3()
{
	if (Bounce.easyQuizBounceTime > g_dElapsedTime)
	{
		return;
	}
	Bounce.easyQuizBounceTime = 0.0;
	if (g_abKeyPressed[K_TWO])
	{
		giveScore = true;
		g_eGameState = S_GAME;
	}
	else if (g_abKeyPressed[K_ONE] || g_abKeyPressed[K_FOUR] || g_abKeyPressed[K_FIVE] || g_abKeyPressed[K_THREE])
	{
		if (Lifecounter == 3)
		{
			giveScore = true;
		}
		else
		{
			Lifecounter++;
		}
	}
	Bounce.easyQuizBounceTime = g_dElapsedTime + 0.125;
}

void EasyQuestion4()
{
	if (Bounce.easyQuizBounceTime > g_dElapsedTime)
	{
		return;
	}
	Bounce.easyQuizBounceTime = 0.0;
	if (g_abKeyPressed[K_FIVE])
	{
		giveScore = true;
		g_eGameState = S_GAME;
	}
	else if (g_abKeyPressed[K_ONE] || g_abKeyPressed[K_FOUR] || g_abKeyPressed[K_TWO] || g_abKeyPressed[K_THREE])
	{
		if (Lifecounter == 3)
		{
			giveScore = true;
		}
		else
		{
			Lifecounter++;
		}
	}
	Bounce.easyQuizBounceTime = g_dElapsedTime + 0.125;
}

void EasyQuestion5()
{
	if (Bounce.easyQuizBounceTime > g_dElapsedTime)
	{
		return;
	}
	Bounce.easyQuizBounceTime = 0.0;
	if (g_abKeyPressed[K_FOUR])
	{
		giveScore = true;
		g_eGameState = S_GAME;
	}
	else if (g_abKeyPressed[K_ONE] || g_abKeyPressed[K_TWO] || g_abKeyPressed[K_FIVE] || g_abKeyPressed[K_THREE])
	{
		if (Lifecounter == 3)
		{
			giveScore = true;
		}
		else
		{
			Lifecounter++;
		}
	}
	Bounce.easyQuizBounceTime = g_dElapsedTime + 0.125;
}

void renderEasyQuestion1()
{
	COORD l;
	l.X = 46;
	l.Y = 3;
	g_Console.writeToBuffer(l, "Which is the heaviest? ", 0x0A);
	l.X = 46;
	l.Y = 4;
	g_Console.writeToBuffer(l, "100g bricks, 100g stones ", 0x0A);
	l.X = 46;
	l.Y = 5;
	g_Console.writeToBuffer(l, "100g feathers?", 0x0A);
	l.Y = 7;
	g_Console.writeToBuffer(l, "1: Stones", 0x0B);
	l.Y = 9;
	g_Console.writeToBuffer(l, "2: Bricks", 0x0B);
	l.Y = 11;
	g_Console.writeToBuffer(l, "3: Feathers", 0x0B);
	l.Y = 13;
	g_Console.writeToBuffer(l, "4: All of the above" ,0x0B);
	l.Y = 15;
	g_Console.writeToBuffer(l, "5: None of the above", 0x0B);
}

void renderEasyQuestion2()
{
	COORD l;
	l.X = 46;
	l.Y = 3;
	g_Console.writeToBuffer(l, "What is the position of Earth from", 0x0A);
	l.X = 46;
	l.Y = 4;
	g_Console.writeToBuffer(l, "the sun?", 0x0A);
	l.Y = 6;
	g_Console.writeToBuffer(l, "1: Third", 0x0B);
	l.Y = 8;
	g_Console.writeToBuffer(l, "2: First", 0x0B);
	l.Y = 10;
	g_Console.writeToBuffer(l, "3: Sixth", 0x0B);
	l.Y = 12;
	g_Console.writeToBuffer(l, "4: Fourth", 0x0B);
	l.Y = 14;
	g_Console.writeToBuffer(l, "5: Second", 0x0B);
}

void renderEasyQuestion3()
{
	COORD l;
	l.X = 46;
	l.Y = 3;
	g_Console.writeToBuffer(l, "Which is a predator?", 0x0A);
	l.Y = 6;
	g_Console.writeToBuffer(l, "1: Earthworm", 0x0B);
	l.Y = 8;
	g_Console.writeToBuffer(l, "2: Snake", 0x0B);
	l.Y = 10;
	g_Console.writeToBuffer(l, "3: Caterpillar", 0x0B);
	l.Y = 12;
	g_Console.writeToBuffer(l, "4: Giraffe", 0x0B);
	l.Y = 14;
	g_Console.writeToBuffer(l, "5: None of the above", 0x0B);
}

void renderEasyQuestion4()
{
	COORD l;
	l.X = 46;
	l.Y = 3;
	g_Console.writeToBuffer(l, "Red + Blue what colour do you get?", 0x0A);
	l.Y = 6;
	g_Console.writeToBuffer(l, "1: Green", 0x0B);
	l.Y = 8;
	g_Console.writeToBuffer(l, "2: Yellow", 0x0B);
	l.Y = 10;
	g_Console.writeToBuffer(l, "3: Pink", 0x0B);
	l.Y = 12;
	g_Console.writeToBuffer(l, "4: Orange", 0x0B);
	l.Y = 14;
	g_Console.writeToBuffer(l, "5: Purple", 0x0B);
}

void renderEasyQuestion5()
{
	COORD l;
	l.X = 46;
	l.Y = 3;
	g_Console.writeToBuffer(l, "What is a chicken classified ", 0x0A);
	l.X = 46;
	l.Y = 4;
	g_Console.writeToBuffer(l, "under?", 0x0A);
	l.Y = 6;
	g_Console.writeToBuffer(l, "1: Insects", 0x0B);
	l.Y = 8;
	g_Console.writeToBuffer(l, "2: Mammals", 0x0B);
	l.Y = 10;
	g_Console.writeToBuffer(l, "3: Amphibians", 0x0B);
	l.Y = 12;
	g_Console.writeToBuffer(l, "4: Birds", 0x0B);
	l.Y = 14;
	g_Console.writeToBuffer(l, "5: Fishes", 0x0B);
}