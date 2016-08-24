#include"quiz.h"
#include <fstream>

extern bool g_abKeyPressed[K_COUNT];
extern EGAMESTATES g_eGameState;
extern Console g_Console;
extern char MapSize[80][31];
extern int Lifecounter;
extern bool mapLoader;

void MediumQuestion1()
{
	if (g_abKeyPressed[K_THREE])
	{
		g_eGameState = S_GAME;
		mapLoader = true;
	}
	else if (g_abKeyPressed[K_ONE] || g_abKeyPressed[K_FOUR] || g_abKeyPressed[K_FIVE] || g_abKeyPressed[K_TWO])
	{
		Lifecounter++;
	}
}

void MediumQuestion2()
{
	if (g_abKeyPressed[K_FOUR])
	{
		g_eGameState = S_GAME;
		mapLoader = true;
	}
	else if (g_abKeyPressed[K_ONE] || g_abKeyPressed[K_TWO] || g_abKeyPressed[K_FIVE] || g_abKeyPressed[K_THREE])
	{
		Lifecounter++;
	}
}

void MediumQuestion3()
{
	if (g_abKeyPressed[K_FOUR])
	{
		g_eGameState = S_GAME;
		mapLoader = true;
	}
	else if (g_abKeyPressed[K_ONE] || g_abKeyPressed[K_TWO] || g_abKeyPressed[K_FIVE] || g_abKeyPressed[K_THREE])
	{
		Lifecounter++;
	}
}

void MediumQuestion4()
{
	if (g_abKeyPressed[K_FOUR])
	{
		g_eGameState = S_GAME;
		mapLoader = true;
	}
	else if (g_abKeyPressed[K_ONE] || g_abKeyPressed[K_TWO] || g_abKeyPressed[K_FIVE] || g_abKeyPressed[K_THREE])
	{
		Lifecounter++;
	}
}

void MediumQuestion5()
{
	if (g_abKeyPressed[K_ONE])
	{
		g_eGameState = S_GAME;
		mapLoader = true;
	}
	else if (g_abKeyPressed[K_FOUR] || g_abKeyPressed[K_TWO] || g_abKeyPressed[K_FIVE] || g_abKeyPressed[K_THREE])
	{
		Lifecounter++;
	}
}

void renderMediumQuestion1()
{
	COORD l;
	l.X = 2;
	l.Y = 24;
	g_Console.writeToBuffer(l, "Johnny's mother had three children. The first child was named April.", 0x0A);
	l.X = 2;
	l.Y = 25;
	g_Console.writeToBuffer(l, "The second child was named May. What was the third child's name?", 0x0A);
	l.X = 2;
	l.Y = 26;
	g_Console.writeToBuffer(l, "1: June", 0x0B);
	l.X = 50;
	l.Y = 26;
	g_Console.writeToBuffer(l, "2: Jan", 0x0B);
	l.X = 2;
	l.Y = 27;
	g_Console.writeToBuffer(l, "3: Johnny", 0x0B);
	l.X = 50;
	l.Y = 27;
	g_Console.writeToBuffer(l, "4: Jake", 0x0B);
	l.X = 2;
	l.Y = 28;
	g_Console.writeToBuffer(l, "5: Janny", 0x0B);
}

void renderMediumQuestion2()
{
	COORD l;
	l.X = 2;
	l.Y = 24;
	g_Console.writeToBuffer(l, "Before Mt. Everest was discovered, what was the highest mountain in the world?", 0x0A);
	l.X = 2;
	l.Y = 26;
	g_Console.writeToBuffer(l, "1: Mt. Moon", 0x0B);
	l.X = 50;
	l.Y = 26;
	g_Console.writeToBuffer(l, "2: Mt Fuji", 0x0B);
	l.X = 2;
	l.Y = 27;
	g_Console.writeToBuffer(l, "3: Mt. Kilimanjaro", 0x0B);
	l.X = 50;
	l.Y = 27;
	g_Console.writeToBuffer(l, "4: Mt. Everest", 0x0B);
	l.X = 2;
	l.Y = 28;
	g_Console.writeToBuffer(l, "5: The Black Mountain", 0x0B);
}

void renderMediumQuestion3()
{
	COORD l;
	l.X = 2;
	l.Y = 24;
	g_Console.writeToBuffer(l, "If there are 6 apples and you take away 4, how many do you have?", 0x0A);
	l.X = 2;
	l.Y = 26;
	g_Console.writeToBuffer(l, "1: 1 apples", 0x0B);
	l.X = 50;
	l.Y = 26;
	g_Console.writeToBuffer(l, "2: 2 apples", 0x0B);
	l.X = 2;
	l.Y = 27;
	g_Console.writeToBuffer(l, "3: 3 apples", 0x0B);
	l.X = 50;
	l.Y = 27;
	g_Console.writeToBuffer(l, "4: 4 apples", 0x0B);
	l.X = 2;
	l.Y = 28;
	g_Console.writeToBuffer(l, "5: None", 0x0B);
}

void renderMediumQuestion4()
{
	COORD l;
	l.X = 2;
	l.Y = 24;
	g_Console.writeToBuffer(l, "If you had only one match, and entered a dark room containing an oil lamp,", 0x0A);
	l.X = 2;
	l.Y = 25;
	g_Console.writeToBuffer(l, "some newspaper, and some kindling wood, which would you light first? ", 0x0A);
	l.X = 2;
	l.Y = 27;
	g_Console.writeToBuffer(l, "1: Oil lamp", 0x0B);
	l.X = 50;
	l.Y = 28;
	g_Console.writeToBuffer(l, "2: The Newspaper", 0x0B);
	l.X = 2;
	l.Y = 28;
	g_Console.writeToBuffer(l, "3: The Wood", 0x0B);
	l.X = 50;
	l.Y = 29;
	g_Console.writeToBuffer(l, "4: The Match", 0x0B);
	l.X = 2;
	l.Y = 29;
	g_Console.writeToBuffer(l, "5: The dark room", 0x0B);
}

void renderMediumQuestion5()
{
	COORD l;
	l.X = 2;
	l.Y = 24;
	g_Console.writeToBuffer(l, "A little girl kicks a soccer ball. It goes 7 metres and comes back to her. How is this possible?", 0x0A);
	l.X = 2;
	l.Y = 26;
	g_Console.writeToBuffer(l, "1: Gravity", 0x0B);
	l.X = 50;
	l.Y = 26;
	g_Console.writeToBuffer(l, "2: Witch craft", 0x0B);
	l.X = 2;
	l.Y = 27;
	g_Console.writeToBuffer(l, "3: Ball is a boomarang", 0x0B);
	l.X = 50;
	l.Y = 27;
	g_Console.writeToBuffer(l, "4: Impossible", 0x0B);
	l.X = 2;
	l.Y = 28;
	g_Console.writeToBuffer(l, "5: All but 4", 0x0B);
}