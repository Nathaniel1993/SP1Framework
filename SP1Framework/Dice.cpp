#include "Dice.h"
#include <fstream>
#include <ctime>
#include <stdlib.h>
extern bool g_abKeyPressed[K_COUNT];
extern EGAMESTATES g_eGameState;
extern Console g_Console;
extern char MapSize[80][31];

SGDICE white;
SGDICE red;


void Dice()
{
	int roll = rand() % 31 + 1;
	srand(time(0));


	switch (roll)
	{
	}

	if (roll == 1 || roll == 2 || roll == 3 || roll == 4 || roll == 5)
	{
		Dice1();
		g_eGameState = S_SPLASHSCREEN;
	}

	else if (roll == 6 || roll == 7 || roll == 8 || roll == 9 || roll == 10)
	{
		Dice2();
		g_eGameState = S_SPLASHSCREEN;
	}

	else if (roll == 11 || roll == 12 || roll == 13 || roll == 14 || roll == 15)
	{
		Dice3();
		g_eGameState = S_SPLASHSCREEN;
	}

	else if (roll == 16 || roll == 17 || roll == 18 || roll == 19 || roll == 20)
	{
		Dice4();
		g_eGameState = S_SPLASHSCREEN;
	}

	else if (roll == 21 || roll == 22 || roll == 23 || roll == 24 || roll == 25)
	{
		Dice5();
		g_eGameState = S_SPLASHSCREEN;
	}

	else if (roll == 26 || roll == 27 || roll == 28 || roll == 29 || roll == 30)
	{
		Dice6();
		g_eGameState = S_SPLASHSCREEN;
	}
}


void Dice1()
{
	ifstream Dice1("dice1.txt");
	int width = 0;
	int height = 0;
	processUserInput();
	moveCharacter();
	COORD c;
	if (Dice1.is_open())
	{
		while (height < 31)
		{
			while (width < 80)
			{
				Dice1 >> MapSize[width][height];
				width++;
			}
			height++;
			width = 0;
		}

		Dice1.close();
		for (int y = 0; y < 31; y++)
		{
			c.Y = y;
			for (int x = 0; x < 80; x++)
			{
				if (MapSize[x][y] == 'i')
				{
					MapSize[x][y] = ' ';
				}
				if (MapSize[x][y] == 'x')
				{
					white.m_cLocation.X = x;
					white.m_cLocation.Y = y;
				}
				if (MapSize[x][y] == '*')
				{
					red.m_cLocation.X = x;
					red.m_cLocation.Y = y;
				}
				c.X = x;
				g_Console.writeToBuffer(c, MapSize[x][y],0x0F);
				g_Console.writeToBuffer(white.m_cLocation, MapSize[x][y], 0x0F);
				g_Console.writeToBuffer(red.m_cLocation, MapSize[x][y], 0xFF);
			}
		}
		COORD c;
		c.X = 20;
		c.Y = 3;
		g_Console.writeToBuffer(c, "You rolled a one!", 0x1F);
	}

}

void Dice2()
{
	ifstream Dice2("dice2.txt");
	int width = 0;
	int height = 0;
	processUserInput();
	moveCharacter();
	COORD c;
	if (Dice2.is_open())
	{
		while (height < 31)
		{
			while (width < 80)
			{
				Dice2 >> MapSize[width][height];
				width++;
			}
			height++;
			width = 0;
		}

		Dice2.close();
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
				g_Console.writeToBuffer(c, MapSize[x][y], 0x1A);
			}
		}
	}
}
void Dice3()
{
	ifstream Dice3("dice3.txt");
	int width = 0;
	int height = 0;
	processUserInput();
	moveCharacter();
	COORD c;
	if (Dice3.is_open())
	{
		while (height < 31)
		{
			while (width < 80)
			{
				Dice3 >> MapSize[width][height];
				width++;
			}
			height++;
			width = 0;
		}

		Dice3.close();
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
				g_Console.writeToBuffer(c, MapSize[x][y], 0x1A);
			}
		}
	}
}
void Dice4()
{
	ifstream Dice4("dice4.txt");
	int width = 0;
	int height = 0;
	processUserInput();
	moveCharacter();
	COORD c;
	if (Dice4.is_open())
	{
		while (height < 31)
		{
			while (width < 80)
			{
				Dice4 >> MapSize[width][height];
				width++;
			}
			height++;
			width = 0;
		}

		Dice4.close();
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
				g_Console.writeToBuffer(c, MapSize[x][y], 0x1A);
			}
		}
	}
}
void Dice5()
{
	ifstream Dice5("dice5.txt");
	int width = 0;
	int height = 0;
	processUserInput();
	moveCharacter();
	COORD c;
	if (Dice5.is_open())
	{
		while (height < 31)
		{
			while (width < 80)
			{
				Dice5 >> MapSize[width][height];
				width++;
			}
			height++;
			width = 0;
		}

		Dice5.close();
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
				g_Console.writeToBuffer(c, MapSize[x][y], 0x1A);
			}
		}
	}
}
void Dice6()
{
	ifstream Dice6("dice6.txt");
	int width = 0;
	int height = 0;
	processUserInput();
	moveCharacter();
	COORD c;
	if (Dice6.is_open())
	{
		while (height < 31)
		{
			while (width < 80)
			{
				Dice6 >> MapSize[width][height];
				width++;
			}
			height++;
			width = 0;
		}

		Dice6.close();
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
				g_Console.writeToBuffer(c, MapSize[x][y], 0x1A);
			}
		}
	}
}