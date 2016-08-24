#include "Dice.h"
#include <ctime>
#include <stdlib.h>
#include "loadfile.h"

extern bool g_abKeyPressed[K_COUNT];
extern EGAMESTATES g_eGameState;
extern Console g_Console;
int rollednumber = 0;

//void dice()
//{
//	int roll;
//	roll = rand() % 6 + 1;
//	rollednumber = roll;
//
//	switch (roll)
//	{
//	case 1: loadDice1();
//		break;
//	case 2: loadDice2();
//		break;
//	case 3: loadDice3();
//		break;
//	case 4: loadDice4();
//		break;
//	case 5: loadDice5();
//		break;
//	case 6: loadDice6();
//		break;
//	}
//}
//
//void renderdice()
//{
//	switch (rollednumber)
//	{
//	case 1: renderDice1();
//		break;
//	case 2: renderDice2();
//		break;
//	case 3: renderDice3();
//		break;
//	case 4: renderDice4();
//		break;
//	case 5: renderDice5();
//		break;
//	case 6: renderDice6();
//		break;
//	}
//}

//void renderDice1()
//{
//	COORD c;
//	for (int y = 0; y < 31; y++)
//	{
//		c.Y = y;
//		for (int x = 0; x < 80; x++)
//		{
//			if (MapSize[x][y] == 'i')
//			{
//				MapSize[x][y] = ' ';
//			}
//			c.X = x;
//			g_Console.writeToBuffer(c, MapSize[x][y]);
//		}
//	}
//	COORD l;
//	l.Y = 26;
//	l.X = 20;
//	g_Console.writeToBuffer(l, "You have rolled a 1!", 0x0B);
//	l.Y = 27;
//	l.X = 20;
//	g_Console.writeToBuffer(l, "Question Difficulty: Easy", 0x0B);
//	l.Y = 28;
//	l.X = 20;
//	g_Console.writeToBuffer(l, "Press <Enter> key to continue", 0x0B);
//}
//
//void renderDice2()
//{
//	COORD c;
//	for (int y = 0; y < 31; y++)
//	{
//		c.Y = y;
//		for (int x = 0; x < 80; x++)
//		{
//			if (MapSize[x][y] == 'i')
//			{
//				MapSize[x][y] = ' ';
//			}
//			c.X = x;
//			g_Console.writeToBuffer(c, MapSize[x][y]);
//		}
//	}
//	COORD l;
//	l.Y = 26;
//	l.X = 20;
//	g_Console.writeToBuffer(l, "You have rolled a 2!", 0x0B);
//	l.Y = 27;
//	l.X = 20;
//	g_Console.writeToBuffer(l, "Question Difficulty: Easy", 0x0B);
//	l.Y = 28;
//	l.X = 20;
//	g_Console.writeToBuffer(l, "Press <Enter> key to continue", 0x0B);
//}
//
//void renderDice3()
//{
//	COORD c;
//	for (int y = 0; y < 31; y++)
//	{
//		c.Y = y;
//		for (int x = 0; x < 80; x++)
//		{
//			if (MapSize[x][y] == 'i')
//			{
//				MapSize[x][y] = ' ';
//			}
//			c.X = x;
//			g_Console.writeToBuffer(c, MapSize[x][y]);
//		}
//	}
//	COORD l;
//	l.Y = 26;
//	l.X = 20;
//	g_Console.writeToBuffer(l, "You have rolled a 3!", 0x0B);
//	l.Y = 27;
//	l.X = 20;
//	g_Console.writeToBuffer(l, "Question Difficulty: Medium", 0x0B);
//	l.Y = 28;
//	l.X = 20;
//	g_Console.writeToBuffer(l, "Press <Enter> key to continue", 0x0B);
//}
//
//void renderDice4()
//{
//	COORD c;
//	for (int y = 0; y < 31; y++)
//	{
//		c.Y = y;
//		for (int x = 0; x < 80; x++)
//		{
//			if (MapSize[x][y] == 'i')
//			{
//				MapSize[x][y] = ' ';
//			}
//			c.X = x;
//			g_Console.writeToBuffer(c, MapSize[x][y]);
//		}
//	}
//	COORD l;
//	l.Y = 26;
//	l.X = 20;
//	g_Console.writeToBuffer(l, "You have rolled a 4!", 0x0B);
//	l.Y = 27;
//	l.X = 20;
//	g_Console.writeToBuffer(l, "Question Difficulty: Medium", 0x0B);
//	l.Y = 28;
//	l.X = 20;
//	g_Console.writeToBuffer(l, "Press <Enter> key to continue", 0x0B);
//}
//
//void renderDice5()
//{
//	COORD c;
//	for (int y = 0; y < 31; y++)
//	{
//		c.Y = y;
//		for (int x = 0; x < 80; x++)
//		{
//			if (MapSize[x][y] == 'i')
//			{
//				MapSize[x][y] = ' ';
//			}
//			c.X = x;
//			g_Console.writeToBuffer(c, MapSize[x][y]);
//		}
//	}
//	COORD l;
//	l.Y = 26;
//	l.X = 20;
//	g_Console.writeToBuffer(l, "You have rolled a 5!", 0x0B);
//	l.Y = 27;
//	l.X = 20;
//	g_Console.writeToBuffer(l, "Question Difficulty: Hard", 0x0B);
//	l.Y = 28;
//	l.X = 20;
//	g_Console.writeToBuffer(l, "Press <Enter> key to continue", 0x0B);
//}
//
//void renderDice6()
//{
//	COORD c;
//	for (int y = 0; y < 31; y++)
//	{
//		c.Y = y;
//		for (int x = 0; x < 80; x++)
//		{
//			if (MapSize[x][y] == 'i')
//			{
//				MapSize[x][y] = ' ';
//			}
//			c.X = x;
//			g_Console.writeToBuffer(c, MapSize[x][y]);
//		}
//	}
//	COORD l;
//	l.Y = 26;
//	l.X = 20;
//	g_Console.writeToBuffer(l, "You have rolled a 6!", 0x0B);
//	l.Y = 27;
//	l.X = 20;
//	g_Console.writeToBuffer(l, "Question Difficulty: Hard", 0x0B);
//	l.Y = 28;
//	l.X = 20;
//	g_Console.writeToBuffer(l, "Press <Enter> key to continue", 0x0B);
//}