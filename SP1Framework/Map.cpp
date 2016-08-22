#include "map.h"

int g_MapNo;
extern WORD color;
extern char MapSize[80][31];
extern Console g_Console;
extern SGameChar g_sChar;
extern bool g_abKeyPressed[K_COUNT];
extern EGAMESTATES g_eGameState;

void rendermap1()
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
		}
	}	
	renderCharacter();
	if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X == 0 && g_sChar.m_cLocation.Y == 2)
	{
		clearScreen();
		loadmap2();
		g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 1;
		g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 29;
	}
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

void rendermap2()
{
	gameplay();
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
			g_Console.writeToBuffer(c, MapSize[x][y], 0x0B);
		}
	}
	renderCharacter();
	/*if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X == 0 && g_sChar.m_cLocation.Y == 28)
	{
		clearScreen();
		loadmap3();
		g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 1;
		g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 3;
	}*/
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

void rendermap3()
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
			g_Console.writeToBuffer(c, MapSize[x][y], 0x0C);
		}
	}
	renderCharacter();
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

//void rendermap4()
//{
//	COORD c;
//	for (int y = 0;y < 31;y++)
//	{
//		c.Y = y;
//		for (int x = 0;x < 80;x++)
//		{
//			if (MapSize[x][y] == 'i')
//			{
//				MapSize[x][y] = ' ';
//			}
//			c.X = x;
//			g_Console.writeToBuffer(c, MapSize[x][y], 0x0B);
//		}
//	}
//	renderCharacter();
//	if (g_abKeyPressed[K_DOWN] && g_sChar.m_cLocation.X == 38 && g_sChar.m_cLocation.Y == 30)
//	{
//		g_eGameState = S_MAP3;
//		gameplay();
//		g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 41;
//		g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 30;
//	}
//}
//
//void loadmap4()
//{
//	g_MapNo = 4;
//	ifstream file("map4.txt");
//	int width = 0;
//	int height = 0;
//	color = 0x0B;
//	gameplay();
//	if (file.is_open())
//	{
//		while (height < 31)
//		{
//			while (width < 80)
//			{
//				file >> MapSize[width][height];
//				width++;
//			}
//			height++;
//			width = 0;
//		}
//		file.close();
//	}
//}