#include"quiz.h"
#include <fstream>

extern bool g_abKeyPressed[K_COUNT];
extern EGAMESTATES g_eGameState;
extern Console g_Console;
extern char MapSize[80][31];
extern int Lifecounter;
extern bool mapLoader;
extern bool giveScore;

void HardQuestion1()
{
	if (Bounce.hardQuizBounceTime > g_dElapsedTime)
	{
		return;
	}
	Bounce.hardQuizBounceTime = 0.0;
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
	Bounce.hardQuizBounceTime = g_dElapsedTime + 0.125;
}

void HardQuestion2()
{
	if (Bounce.hardQuizBounceTime > g_dElapsedTime)
	{
		return;
	}
	Bounce.hardQuizBounceTime = 0.0;
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
	Bounce.hardQuizBounceTime = g_dElapsedTime + 0.125;
}

void HardQuestion3()
{
	if (Bounce.hardQuizBounceTime > g_dElapsedTime)
	{
		return;
	}
	Bounce.hardQuizBounceTime = 0.0;
	if (g_abKeyPressed[K_THREE])
	{
		giveScore = true;
		g_eGameState = S_GAME;
	}
	else if (g_abKeyPressed[K_ONE] || g_abKeyPressed[K_FOUR] || g_abKeyPressed[K_FIVE] || g_abKeyPressed[K_TWO])
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
	Bounce.hardQuizBounceTime = g_dElapsedTime + 0.125;
}

void HardQuestion4()
{
	if (Bounce.hardQuizBounceTime > g_dElapsedTime)
	{
		return;
	}
	Bounce.hardQuizBounceTime = 0.0;
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
	Bounce.hardQuizBounceTime = g_dElapsedTime + 0.125;
}

void HardQuestion5()
{
	if (Bounce.hardQuizBounceTime > g_dElapsedTime)
	{
		return;
	}
	Bounce.hardQuizBounceTime = 0.0;
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
	Bounce.hardQuizBounceTime = g_dElapsedTime + 0.125;
}

void renderHardQuestion1()
{
	COORD l;
	l.X = 45;
	l.Y = 7;
	g_Console.writeToBuffer(l, "How many stars are in ", 0x0A);
	l.X = 45;
	l.Y = 8;
	g_Console.writeToBuffer(l, "the American flag?", 0x0A);
	l.Y = 28;
	l.X = 3;
	g_Console.writeToBuffer(l, "1: 50", 0x0B);
	l.Y = 28;
	l.X = 50;
	g_Console.writeToBuffer(l, "2: 49", 0x0B);
	l.Y = 29;
	l.X = 3;
	g_Console.writeToBuffer(l, "3: 48", 0x0B);
	l.Y = 29;
	l.X = 50;
	g_Console.writeToBuffer(l, "4: 40", 0x0B);
	l.Y = 30;
	l.X = 3;
	g_Console.writeToBuffer(l, "5: 51", 0x0B);
}

void renderHardQuestion2()
{
	COORD l;
	l.X = 45;
	l.Y = 7;
	g_Console.writeToBuffer(l, "In Shakesphere's novel, which", 0x0A);
	l.X = 45;
	l.Y = 8;
	g_Console.writeToBuffer(l, "country is Hamlet the prince of?", 0x0A);
	l.Y = 28;
	l.X = 3;
	g_Console.writeToBuffer(l, "1: Spain", 0x0B);
	l.Y = 28;
	l.X = 50;
	g_Console.writeToBuffer(l, "2: Denmark", 0x0B);
	l.Y = 29;
	l.X = 3;
	g_Console.writeToBuffer(l, "3: France", 0x0B);
	l.Y = 29;
	l.X = 50;
	g_Console.writeToBuffer(l, "4: England", 0x0B);
	l.Y = 30;
	l.X = 3;
	g_Console.writeToBuffer(l, "5: Germany", 0x0B);
}

void renderHardQuestion3()
{
	COORD l;
	l.X = 50;
	l.Y = 7;
	g_Console.writeToBuffer(l, "What is Newton's 1st law?", 0x0A);
	l.Y = 28;
	l.X = 3;
	g_Console.writeToBuffer(l, "1: Force = mass x acceleration", 0x0B);
	l.Y = 28;
	l.X = 50;
	g_Console.writeToBuffer(l, "2: Action = reaction", 0x0B);
	l.Y = 29;
	l.X = 3;
	g_Console.writeToBuffer(l, "3: What is in motion stays in motion", 0x0B);
	l.Y = 29;
	l.X = 50;
	g_Console.writeToBuffer(l, "4: Gravity", 0x0B);
	l.Y = 30;
	l.X = 3;
	g_Console.writeToBuffer(l, "5: None of the above", 0x0B);
}

void renderHardQuestion4()
{
	COORD l;
	l.X = 50;
	l.Y = 7;
	g_Console.writeToBuffer(l, "What did Peter piper picked?", 0x0A);
	l.Y = 28;
	l.X = 3;
	g_Console.writeToBuffer(l, "1: Corn", 0x0B);
	l.Y = 28;
	l.X = 40;
	g_Console.writeToBuffer(l, "2: Apples", 0x0B);
	l.Y = 29;
	l.X = 3;
	g_Console.writeToBuffer(l, "3: Oranges", 0x0B);
	l.Y = 29;
	l.X = 40;
	g_Console.writeToBuffer(l, "4: Pickled peppers", 0x0B);
	l.Y = 30;
	l.X = 3;
	g_Console.writeToBuffer(l, "5: Flowers", 0x0B);
}

void renderHardQuestion5()
{
	COORD l;
	l.X = 50;
	l.Y = 7;
	g_Console.writeToBuffer(l, "Who came out with the formula", 0x0A);
	l.X = 50;
	l.Y = 8;
	g_Console.writeToBuffer(l, "'e = mc^2'?", 0x0A);
	l.Y = 28;
	l.X = 3;
	g_Console.writeToBuffer(l, "1: Amelia Earhart", 0x0B);
	l.Y = 28;
	l.X = 50;
	g_Console.writeToBuffer(l, "2: Euclid", 0x0B);
	l.Y = 29;
	l.X = 3;
	g_Console.writeToBuffer(l, "3: Thomas Edison", 0x0B);
	l.Y = 29;
	l.X = 50;
	g_Console.writeToBuffer(l, "4: Isaac Newton", 0x0B);
	l.Y = 30;
	l.X = 3;
	g_Console.writeToBuffer(l, "5: Albert Einstein", 0x0B);
}