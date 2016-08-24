#include"combat.h"
#include <fstream>

extern bool g_abKeyPressed[K_COUNT];
extern EGAMESTATES g_eGameState;
extern Console g_Console;
extern char MapSize[80][31];
extern int Lifecounter;

void HardQuestion1()
{
	if (g_abKeyPressed[K_ONE])
	{
		g_eGameState = S_GAME;
	}
	else
	{
		Lifecounter++;
	}
}

void HardQuestion2()
{
	if (g_abKeyPressed[K_TWO])
	{
		g_eGameState = S_GAME;
	}
	else
	{
		Lifecounter++;
	}
}

void HardQuestion3()
{
	if (g_abKeyPressed[K_THREE])
	{
		g_eGameState = S_GAME;
	}
	else
	{
		Lifecounter++;
	}
}

void HardQuestion4()
{
	if (g_abKeyPressed[K_FOUR])
	{
		g_eGameState = S_GAME;
	}
	else
	{
		Lifecounter++;
	}
}

void HardQuestion5()
{
	if (g_abKeyPressed[K_FIVE])
	{
		g_eGameState = S_GAME;
	}
	else
	{
		Lifecounter++;
	}
}

void renderHardQuestion1()
{
	COORD l;
	l.X = 50;
	l.Y = 7;
	g_Console.writeToBuffer(l, "Who wrote the 'Sword Art Online Series'?", 0x0A);
	l.Y = 28;
	l.X = 3;
	g_Console.writeToBuffer(l, "1: Reki Kawahara", 0x0B);
	l.Y = 28;
	l.X = 50;
	g_Console.writeToBuffer(l, "2: Sui Ishida", 0x0B);
	l.Y = 29;
	l.X = 3;
	g_Console.writeToBuffer(l, "3: Yuto Tsukuda", 0x0B);
	l.Y = 29;
	l.X = 50;
	g_Console.writeToBuffer(l, "4: Eiichiro Oda", 0x0B);
	l.Y = 30;
	l.X = 3;
	g_Console.writeToBuffer(l, "5: Tite Kubo", 0x0B);
}

void renderHardQuestion2()
{
	COORD l;
	l.X = 50;
	l.Y = 7;
	g_Console.writeToBuffer(l, "In Shakesphere's novel, which country is Hamlet the prince of?", 0x0A);
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
	g_Console.writeToBuffer(l, "What is the game that inspired making of MOBA games?", 0x0A);
	l.Y = 28;
	l.X = 3;
	g_Console.writeToBuffer(l, "1: League of Legends", 0x0B);
	l.Y = 28;
	l.X = 50;
	g_Console.writeToBuffer(l, "2: Dota 2", 0x0B);
	l.Y = 29;
	l.X = 3;
	g_Console.writeToBuffer(l, "3: Warcraft 3", 0x0B);
	l.Y = 29;
	l.X = 50;
	g_Console.writeToBuffer(l, "4: Starcraft", 0x0B);
	l.Y = 30;
	l.X = 3;
	g_Console.writeToBuffer(l, "5: Dota", 0x0B);
}

void renderHardQuestion4()
{
	COORD l;
	l.X = 50;
	l.Y = 7;
	g_Console.writeToBuffer(l, "How are Pokemon game versions named after?", 0x0A);
	l.Y = 28;
	l.X = 3;
	g_Console.writeToBuffer(l, "1: Main antagonist of the game", 0x0B);
	l.Y = 28;
	l.X = 50;
	g_Console.writeToBuffer(l, "2: Randomly think of a name", 0x0B);
	l.Y = 29;
	l.X = 3;
	g_Console.writeToBuffer(l, "3: The name of the region", 0x0B);
	l.Y = 29;
	l.X = 50;
	g_Console.writeToBuffer(l, "4: Main protagonist of the region in the manga", 0x0B);
	l.Y = 30;
	l.X = 3;
	g_Console.writeToBuffer(l, "5: The anime title of the region", 0x0B);
}

void renderHardQuestion5()
{
	COORD l;
	l.X = 50;
	l.Y = 7;
	g_Console.writeToBuffer(l, "Who came out with the formula 'e = mc^2'?", 0x0A);
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