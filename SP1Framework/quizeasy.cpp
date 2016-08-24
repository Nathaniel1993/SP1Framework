#include"quiz.h"
#include <fstream>

extern int Score;
extern bool mapLoader;
extern bool g_abKeyPressed[K_COUNT];
extern EGAMESTATES g_eGameState;
extern Console g_Console;
extern char MapSize[80][31];
extern int Lifecounter;

void EasyQuestion1()
{
	if (g_abKeyPressed[K_THREE])
	{
		g_eGameState = S_GAME;
		mapLoader = true;
	}
	else if (g_abKeyPressed[K_ONE] || g_abKeyPressed[K_TWO] || g_abKeyPressed[K_FOUR] || g_abKeyPressed[K_FIVE])
	{
		Lifecounter++;
	}
}

void EasyQuestion2()
{
	if (g_abKeyPressed[K_ONE])
	{
		g_eGameState = S_GAME;
		mapLoader = true;
	}
	else if (g_abKeyPressed[K_TWO] || g_abKeyPressed[K_FOUR] || g_abKeyPressed[K_FIVE] || g_abKeyPressed[K_THREE])
	{
		Lifecounter++;
	}
}

void EasyQuestion3()
{
	if (g_abKeyPressed[K_TWO])
	{
		g_eGameState = S_GAME;
		mapLoader = true;
	}
	else if (g_abKeyPressed[K_ONE] || g_abKeyPressed[K_FOUR] || g_abKeyPressed[K_FIVE] || g_abKeyPressed[K_THREE])
	{
		Lifecounter++;
	}
}

void EasyQuestion4()
{
	if (g_abKeyPressed[K_FIVE])
	{
		g_eGameState = S_GAME;
		mapLoader = true;
	}
	else if (g_abKeyPressed[K_ONE] || g_abKeyPressed[K_FOUR] || g_abKeyPressed[K_TWO] || g_abKeyPressed[K_THREE])
	{
		Lifecounter++;
	}
}

void EasyQuestion5()
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

void renderEasyQuestion1()
{
	COORD l;
	l.X = 46;
	l.Y = 3;
	g_Console.writeToBuffer(l, "Who is the richest man in the", 0x0A);
	l.X = 46;
	l.Y = 4;
	g_Console.writeToBuffer(l, "world?", 0x0A);
	l.Y = 6;
	g_Console.writeToBuffer(l, "1: Tim Cook", 0x0B);
	l.Y = 8;
	g_Console.writeToBuffer(l, "2: Warren Buffet", 0x0B);
	l.Y = 10;
	g_Console.writeToBuffer(l, "3: Bill Gates", 0x0B);
	l.Y = 12;
	g_Console.writeToBuffer(l, "4: Mark Zuckerberg", 0x0B);
	l.Y = 14;
	g_Console.writeToBuffer(l, "5: Lee Byung Chul", 0x0B);
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
	g_Console.writeToBuffer(l, "Which is the most subscribed", 0x0A);
	l.X = 46;
	l.Y = 4;
	g_Console.writeToBuffer(l, "channel in YouTube?", 0x0A);
	l.Y = 6;
	g_Console.writeToBuffer(l, "1: Smosh", 0x0B);
	l.Y = 8;
	g_Console.writeToBuffer(l, "2: Pewdiepie", 0x0B);
	l.Y = 10;
	g_Console.writeToBuffer(l, "3: YOGSCAST Lewis & Simon", 0x0B);
	l.Y = 12;
	g_Console.writeToBuffer(l, "4: LoL Esports", 0x0B);
	l.Y = 14;
	g_Console.writeToBuffer(l, "5: Sky Does Minecraft", 0x0B);
}

void renderEasyQuestion4()
{
	COORD l;
	l.X = 46;
	l.Y = 3;
	g_Console.writeToBuffer(l, "Who is the first football legend?", 0x0A);
	l.Y = 6;
	g_Console.writeToBuffer(l, "1: Cristiano Ronaldo", 0x0B);
	l.Y = 8;
	g_Console.writeToBuffer(l, "2: Lionel Messi", 0x0B);
	l.Y = 10;
	g_Console.writeToBuffer(l, "3: Diego Maradona", 0x0B);
	l.Y = 12;
	g_Console.writeToBuffer(l, "4: Peter Schmeichel", 0x0B);
	l.Y = 14;
	g_Console.writeToBuffer(l, "5: Pele", 0x0B);
}

void renderEasyQuestion5()
{
	COORD l;
	l.X = 46;
	l.Y = 3;
	g_Console.writeToBuffer(l, "Where is the first youth olympics", 0x0A);
	l.X = 46;
	l.Y = 4;
	g_Console.writeToBuffer(l, "held?", 0x0A);
	l.Y = 6;
	g_Console.writeToBuffer(l, "1: Brazil", 0x0B);
	l.Y = 8;
	g_Console.writeToBuffer(l, "2: U.S.A", 0x0B);
	l.Y = 10;
	g_Console.writeToBuffer(l, "3: China", 0x0B);
	l.Y = 12;
	g_Console.writeToBuffer(l, "4: Singapore", 0x0B);
	l.Y = 14;
	g_Console.writeToBuffer(l, "5: Australia", 0x0B);
}