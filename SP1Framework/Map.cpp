#include "map.h"
#include "Completed.h"
int g_MapNo;
void rendermaps()
{
	ifstream file;
	if (g_MapNo == 1)
		file.open("map1.txt");
	if (g_MapNo == 2)
		file.open("map2.txt");
	if (g_MapNo == 3)
		file.open("map3.txt");
	if (g_MapNo == 4)
		file.open("map4.txt");
	if (g_MapNo == 5)
		file.open("map5.txt");
	if (g_MapNo == 6)
		file.open("map6.txt");
	if (g_MapNo == 7)
		file.open("map7.txt");
	if (g_MapNo == 8)
		file.open("map8.txt");
	if (g_MapNo == 9)
		file.open("map9.txt");
}
void rendermap1()
{
	ifstream file;
	int width = 0;
	int height = 0;
	COORD c;
	moveCharacter();
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
		for (int y = 0;y < 31;y++)
		{
			c.Y = y;
			for (int x = 0;x < 80;x++)
			{
				if (MapSize[x][y] == 'i')
				{
					MapSize[x][y] = ' ';
				}
				c.X = x;
				g_Console.writeToBuffer(c, MapSize[x][y], 0x09);
			}
		}
	}
	renderCharacter();
	checkcomplete();
}
void rendermap2()
{
	ifstream file("map2.txt");
	int width = 0;
	int height = 0;
	processUserInput();
	moveCharacter();
	COORD c;
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
		for (int y = 0;y < 31;y++)
		{
			c.Y = y;
			for (int x = 0;x < 80;x++)
			{
				if (MapSize[x][y] == 'i')
				{
					MapSize[x][y] = ' ';
				}
				c.X = x;
				g_Console.writeToBuffer(c, MapSize[x][y], 0x0B);
			}
		}
	}
	renderCharacter();
	checkcomplete();
}
void rendermap3()
{
	ifstream file("map3.txt");
	int width = 0;
	int height = 0;
	processUserInput();
	moveCharacter();
	COORD c;
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
		for (int y = 0;y < 31;y++)
		{
			c.Y = y;
			for (int x = 0;x < 80;x++)
			{
				if (MapSize[x][y] == 'i')
				{
					MapSize[x][y] = ' ';
				}
				c.X = x;
				g_Console.writeToBuffer(c, MapSize[x][y], 0x0C);
			}
		}
	}
	renderCharacter();
	checkcomplete();
}
void rendermap4()
{
	ifstream file("map4.txt");
	int width = 0;
	int height = 0;
	processUserInput();
	moveCharacter();
	COORD c;
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
		for (int y = 0;y < 31;y++)
		{
			c.Y = y;
			for (int x = 0;x < 80;x++)
			{
				if (MapSize[x][y] == 'i')
				{
					MapSize[x][y] = ' ';
				}
				c.X = x;
				g_Console.writeToBuffer(c, MapSize[x][y], 0x0B);
			}
		}
	}
	renderCharacter();
	checkcomplete();
}