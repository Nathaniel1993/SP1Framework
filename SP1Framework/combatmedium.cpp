#include"combat.h"
#include <fstream>

extern bool g_abKeyPressed[K_COUNT];
extern EGAMESTATES g_eGameState;
extern Console g_Console;
extern char MapSize[80][31];
extern int Lifecounter;

void MediumQuestion1()
{
	if (g_abKeyPressed[])
	{

	}
	else
	{
		Lifecounter++;
	}
}

void MediumQuestion2()
{
	if (g_abKeyPressed[])
	{

	}
	else
	{
		Lifecounter++;
	}
}

void MediumQuestion3()
{
	if (g_abKeyPressed[])
	{

	}
	else
	{
		Lifecounter++;
	}
}

void MediumQuestion4()
{
	if (g_abKeyPressed[])
	{

	}
	else
	{
		Lifecounter++;
	}
}

void MediumQuestion5()
{
	if (g_abKeyPressed[])
	{

	}
	else
	{
		Lifecounter++;
	}
}

void renderMediumQuestion1()
{
	COORD l;
	l.X = 2;
	l.Y = 24;
	g_Console.writeToBuffer(l, "Which year did pokemon originated in?", 0x0A);
	l.X = 2;
	l.Y = 26;
	g_Console.writeToBuffer(l, "input option 1", 0x0B);
	l.X = 50;
	l.Y = 26;
	g_Console.writeToBuffer(l, "input option 2", 0x0B);
	l.X = 2;
	l.Y = 27;
	g_Console.writeToBuffer(l, "input option 3", 0x0B);
	l.X = 50;
	l.Y = 27;
	g_Console.writeToBuffer(l, "input option 4", 0x0B);
	l.X = 2;
	l.Y = 28;
	g_Console.writeToBuffer(l, "input option 5", 0x0B);
}

void renderMediumQuestion2()
{
	COORD l;
	l.X = 2;
	l.Y = 24;
	g_Console.writeToBuffer(l, "input question", 0x0A);
	l.X = 2;
	l.Y = 26;
	g_Console.writeToBuffer(l, "input option 1", 0x0B);
	l.X = 50;
	l.Y = 26;
	g_Console.writeToBuffer(l, "input option 2", 0x0B);
	l.X = 2;
	l.Y = 27;
	g_Console.writeToBuffer(l, "input option 3", 0x0B);
	l.X = 50;
	l.Y = 27;
	g_Console.writeToBuffer(l, "input option 4", 0x0B);
	l.X = 2;
	l.Y = 28;
	g_Console.writeToBuffer(l, "input option 5", 0x0B);
}

void renderMediumQuestion3()
{
	COORD l;
	l.X = 2;
	l.Y = 24;
	g_Console.writeToBuffer(l, "input question", 0x0A);
	l.X = 2;
	l.Y = 26;
	g_Console.writeToBuffer(l, "input option 1", 0x0B);
	l.X = 50;
	l.Y = 26;
	g_Console.writeToBuffer(l, "input option 2", 0x0B);
	l.X = 2;
	l.Y = 27;
	g_Console.writeToBuffer(l, "input option 3", 0x0B);
	l.X = 50;
	l.Y = 27;
	g_Console.writeToBuffer(l, "input option 4", 0x0B);
	l.X = 2;
	l.Y = 28;
	g_Console.writeToBuffer(l, "input option 5", 0x0B);
}

void renderMediumQuestion4()
{
	COORD l;
	l.X = 2;
	l.Y = 24;
	g_Console.writeToBuffer(l, "input question", 0x0A);
	l.X = 2;
	l.Y = 26;
	g_Console.writeToBuffer(l, "input option 1", 0x0B);
	l.X = 50;
	l.Y = 26;
	g_Console.writeToBuffer(l, "input option 2", 0x0B);
	l.X = 2;
	l.Y = 27;
	g_Console.writeToBuffer(l, "input option 3", 0x0B);
	l.X = 50;
	l.Y = 27;
	g_Console.writeToBuffer(l, "input option 4", 0x0B);
	l.X = 2;
	l.Y = 28;
	g_Console.writeToBuffer(l, "input option 5", 0x0B);
}

void renderMediumQuestion5()
{
	COORD l;
	l.X = 2;
	l.Y = 24;
	g_Console.writeToBuffer(l, "input question", 0x0A);
	l.X = 2;
	l.Y = 26;
	g_Console.writeToBuffer(l, "input option 1", 0x0B);
	l.X = 50;
	l.Y = 26;
	g_Console.writeToBuffer(l, "input option 2", 0x0B);
	l.X = 2;
	l.Y = 27;
	g_Console.writeToBuffer(l, "input option 3", 0x0B);
	l.X = 50;
	l.Y = 27;
	g_Console.writeToBuffer(l, "input option 4", 0x0B);
	l.X = 2;
	l.Y = 28;
	g_Console.writeToBuffer(l, "input option 5", 0x0B);
}