#include "map.h"

int g_MapNo;
extern WORD color;
extern char MapSize[80][31];
extern Console g_Console;
extern SGameChar g_sChar;
extern bool g_abKeyPressed[K_COUNT];
extern EGAMESTATES g_eGameState;
bool LoadMap = true;

void rendermap1()
{
	if (LoadMap = true)
	{
		COORD c;
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
				if (MapSize[x][y] == '.')
				{
					g_Console.writeToBuffer(c, MapSize[x][y], 0x0A);
				}
				if (MapSize[x][y] == 'X')
				{
					g_Console.writeToBuffer(c, MapSize[x][y], 0x0C);
				}
				if (MapSize[x][y] == 'l')
				{
					g_Console.writeToBuffer(c, MapSize[x][y], 0x0F);
				}
			}
		}
		renderCharacter();
	}
	LoadMap = false;
}

void loadmap1()
{
	g_MapNo = 1;
	gameplay();
	ifstream file("map1.txt");
	int width = 0;
	int height = 0;
	color = 0x09;
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
}

void loadmap2()
{
	g_MapNo = 2;
	ifstream file("map2.txt");
	int width = 0;
	int height = 0;
	gameplay();
	color = 0x0E;
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
}

void loadmap3()
{
	g_MapNo = 3;
	ifstream file("map3.txt");
	int width = 0;
	int height = 0;
	color = 0x04;
	gameplay();
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
}