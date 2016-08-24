#include "combat.h"
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Ai.h"
#include "guide.h"
#include "Dice.h"
#include <fstream>
#include <mmsystem.h>
#include "loadfile.h"

char splashScreen[80][31];
char mapSize[80][31];
char dice1[80][31];
char dice2[80][31];
char dice3[80][31];
char dice4[80][31];
char dice5[80][31];
char dice6[80][31];

void loadSplashscreen()
{
	ifstream file("mainmenu.txt");
	int width = 0;
	int height = 0;
	if (file.is_open())
	{
		while (height < 31)
		{
			while (width < 80)
			{
				file >> splashScreen[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}
}

void loadMap1()
{
	ifstream file("map1.txt");
	int width = 0;
	int height = 0;
	if (file.is_open())
	{
		while (height < 31)
		{
			while (width < 80)
			{
				file >> mapSize[width][height];
				width++;
			}
			height++;
			width = 0;
		}

		file.close();
	}
}

void loadMap2()
{
	ifstream file("map2.txt");
	int width = 0;
	int height = 0;
	if (file.is_open())
	{
		while (height < 31)
		{
			while (width < 80)
			{
				file >> mapSize[width][height];
				width++;
			}
			height++;
			width = 0;
		}

		file.close();
	}
}

void loadMap3()
{

	ifstream file("map3.txt");
	int width = 0;
	int height = 0;
	if (file.is_open())
	{
		while (height < 31)
		{
			while (width < 80)
			{
				file >> mapSize[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}	
}

void loadDice1()
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
				file >> dice1[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}
}

void loadDice2()
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
				file >> dice2[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}
}

void loadDice3()
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
				file >> dice3[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}
}

void loadDice4()
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
				file >> dice4[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}
}

void loadDice5()
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
				file >> dice5[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}
}

void loadDice6()
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
				file >> dice6[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}
}