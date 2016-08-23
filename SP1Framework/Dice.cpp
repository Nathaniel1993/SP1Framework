#include "Dice.h"
#include <ctime>
#include <stdlib.h>

extern bool g_abKeyPressed[K_COUNT];
extern EGAMESTATES g_eGameState;
extern Console g_Console;
extern char MapSize[80][31];
int rollednumber = 0;

void dice()
{
	int roll;
	roll = rand() % 6 + 1;
	rollednumber = roll;

	switch (roll)
	{
	case 1: loaddice1();
		break;
	case 2: loaddice2();
		break;
	case 3: loaddice3();
		break;
	case 4: loaddice4();
		break;
	case 5: loaddice5();
		break;
	case 6: loaddice6();
		break;
	}
}

void renderdice()
{
	switch (rollednumber)
	{
	case 1: renderdice1();
		break;
	case 2: renderdice2();
		break;
	case 3: renderdice3();
		break;
	case 4: renderdice4();
		break;
	case 5: renderdice5();
		break;
	case 6: renderdice6();
		break;
	}
}
void loaddice1()
{
	ifstream file("dice1.txt");
	int width = 0;
	int height = 0;
	if (file.is_open())
	{
		while (height < 31)
		{
			while (width < 80)
			{
				file >> MapSize[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}
	if (g_abKeyPressed[K_ENTER])
	{
		g_eGameState = S_COMBATEASY;
	}
}

void loaddice2()
{
	ifstream file("dice2.txt");
	int width = 0;
	int height = 0;
	if (file.is_open())
	{
		while (height < 31)
		{
			while (width < 80)
			{
				file >> MapSize[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}
	if (g_abKeyPressed[K_ENTER])
	{
		g_eGameState = S_COMBATEASY;
	}
}

void loaddice3()
{
	ifstream file("dice3.txt");
	int width = 0;
	int height = 0;
	if (file.is_open())
	{
		while (height < 31)
		{
			while (width < 80)
			{
				file >> MapSize[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}
	if (g_abKeyPressed[K_ENTER])
	{
		g_eGameState = S_COMBATMEDIUM;
	}
}

void loaddice4()
{
	ifstream file("dice4.txt");
	int width = 0;
	int height = 0;
	if (file.is_open())
	{
		while (height < 31)
		{
			while (width < 80)
			{
				file >> MapSize[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}
	if (g_abKeyPressed[K_ENTER])
	{
		g_eGameState = S_COMBATMEDIUM;
	}
}

void loaddice5()
{
	ifstream file("dice5.txt");
	int width = 0;
	int height = 0;
	if (file.is_open())
	{
		while (height < 31)
		{
			while (width < 80)
			{
				file >> MapSize[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}
	if (g_abKeyPressed[K_ENTER])
	{
		g_eGameState = S_COMBATHARD;
	}
}

void loaddice6()
{
	ifstream file("dice6.txt");
	int width = 0;
	int height = 0;
	if (file.is_open())
	{
		while (height < 31)
		{
			while (width < 80)
			{
				file >> MapSize[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}
	if (g_abKeyPressed[K_ENTER])
	{
		g_eGameState = S_COMBATHARD;
	}
}

void renderdice1()
{
	COORD c;
	for (int y = 0; y < 31; y++)
	{
		c.Y = y;
		for (int x = 0; x < 80; x++)
		{
			if (MapSize[x][y] == 'i')
			{
				MapSize[x][y] = ' ';
			}
			c.X = x;
			g_Console.writeToBuffer(c, MapSize[x][y]);
		}
	}
	COORD l;
	l.Y = 26;
	l.X = 20;
	g_Console.writeToBuffer(l, "You have rolled a 1!", 0x0B);
	l.Y = 27;
	l.X = 20;
	g_Console.writeToBuffer(l, "Question Difficulty: Easy", 0x0B);
	l.Y = 28;
	l.X = 20;
	g_Console.writeToBuffer(l, "Press <Enter> key to continue", 0x0B);
}

void renderdice2()
{
	COORD c;
	for (int y = 0; y < 31; y++)
	{
		c.Y = y;
		for (int x = 0; x < 80; x++)
		{
			if (MapSize[x][y] == 'i')
			{
				MapSize[x][y] = ' ';
			}
			c.X = x;
			g_Console.writeToBuffer(c, MapSize[x][y]);
		}
	}
	COORD l;
	l.Y = 26;
	l.X = 20;
	g_Console.writeToBuffer(l, "You have rolled a 2!", 0x0B);
	l.Y = 27;
	l.X = 20;
	g_Console.writeToBuffer(l, "Question Difficulty: Easy", 0x0B);
	l.Y = 28;
	l.X = 20;
	g_Console.writeToBuffer(l, "Press <Enter> key to continue", 0x0B);
}

void renderdice3()
{
	COORD c;
	for (int y = 0; y < 31; y++)
	{
		c.Y = y;
		for (int x = 0; x < 80; x++)
		{
			if (MapSize[x][y] == 'i')
			{
				MapSize[x][y] = ' ';
			}
			c.X = x;
			g_Console.writeToBuffer(c, MapSize[x][y]);
		}
	}
	COORD l;
	l.Y = 26;
	l.X = 20;
	g_Console.writeToBuffer(l, "You have rolled a 3!", 0x0B);
	l.Y = 27;
	l.X = 20;
	g_Console.writeToBuffer(l, "Question Difficulty: Medium", 0x0B);
	l.Y = 28;
	l.X = 20;
	g_Console.writeToBuffer(l, "Press <Enter> key to continue", 0x0B);
}

void renderdice4()
{
	COORD c;
	for (int y = 0; y < 31; y++)
	{
		c.Y = y;
		for (int x = 0; x < 80; x++)
		{
			if (MapSize[x][y] == 'i')
			{
				MapSize[x][y] = ' ';
			}
			c.X = x;
			g_Console.writeToBuffer(c, MapSize[x][y]);
		}
	}
	COORD l;
	l.Y = 26;
	l.X = 20;
	g_Console.writeToBuffer(l, "You have rolled a 4!", 0x0B);
	l.Y = 27;
	l.X = 20;
	g_Console.writeToBuffer(l, "Question Difficulty: Medium", 0x0B);
	l.Y = 28;
	l.X = 20;
	g_Console.writeToBuffer(l, "Press <Enter> key to continue", 0x0B);
}

void renderdice5()
{
	COORD c;
	for (int y = 0; y < 31; y++)
	{
		c.Y = y;
		for (int x = 0; x < 80; x++)
		{
			if (MapSize[x][y] == 'i')
			{
				MapSize[x][y] = ' ';
			}
			c.X = x;
			g_Console.writeToBuffer(c, MapSize[x][y]);
		}
	}
	COORD l;
	l.Y = 26;
	l.X = 20;
	g_Console.writeToBuffer(l, "You have rolled a 5!", 0x0B);
	l.Y = 27;
	l.X = 20;
	g_Console.writeToBuffer(l, "Question Difficulty: Hard", 0x0B);
	l.Y = 28;
	l.X = 20;
	g_Console.writeToBuffer(l, "Press <Enter> key to continue", 0x0B);
}

void renderdice6()
{
	COORD c;
	for (int y = 0; y < 31; y++)
	{
		c.Y = y;
		for (int x = 0; x < 80; x++)
		{
			if (MapSize[x][y] == 'i')
			{
				MapSize[x][y] = ' ';
			}
			c.X = x;
			g_Console.writeToBuffer(c, MapSize[x][y]);
		}
	}
	COORD l;
	l.Y = 26;
	l.X = 20;
	g_Console.writeToBuffer(l, "You have rolled a 6!", 0x0B);
	l.Y = 27;
	l.X = 20;
	g_Console.writeToBuffer(l, "Question Difficulty: Hard", 0x0B);
	l.Y = 28;
	l.X = 20;
	g_Console.writeToBuffer(l, "Press <Enter> key to continue", 0x0B);
}