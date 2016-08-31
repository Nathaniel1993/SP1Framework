#include "Dice.h"
#include <ctime>
#include <stdlib.h>
#include "loadfile.h"
#include <time.h>

extern char dice1[100][31];
extern char dice2[100][31];
extern char dice3[100][31];
extern char dice4[100][31];
extern char dice5[100][31];
extern char dice6[100][31];

extern bool g_abKeyPressed[K_COUNT];
bool launchDice = false;
extern bool quizTime;
extern bool questionConfirm;

extern EGAMESTATES g_eGameState;
extern Console g_Console;
int rollednumber = 0;

extern double g_dElapsedTime;

void dice()
{
	if (launchDice == true)
	{
		int roll;

		roll = rand() % 6 + 1;
		rollednumber = roll;
		
		switch (roll)
		{
		case 1: loadDice1();
			break;
		case 2: loadDice2();
			break;
		case 3: loadDice3();
			break;
		case 4: loadDice4();
			break;
		case 5: loadDice5();
			break;
		case 6: loadDice6();
			break;
		}
		launchDice = false;
	}

	if (g_abKeyPressed[K_ENTER])
	{
		if ((rollednumber == 1) || (rollednumber == 2))
		{
			questionConfirm = true;
			g_eGameState = S_QUIZEASY;
			
		}
		else if ((rollednumber == 3) || (rollednumber == 4))
		{
			questionConfirm = true;
			g_eGameState = S_QUIZMEDIUM;
		}
		else if ((rollednumber == 5) || (rollednumber == 6))
		{
			questionConfirm = true;
			g_eGameState = S_QUIZHARD;
		}
	}
	
}

void renderdice()
{
	switch (rollednumber)
	{
	case 1: renderDice1();
		break;
	case 2: renderDice2();
		break;
	case 3: renderDice3();
		break;
	case 4: renderDice4();
		break;
	case 5: renderDice5();
		break;
	case 6: renderDice6();
		break;
	}
}

void renderDice1()
{
	COORD c;
	for (int y = 0; y < 31; y++)
	{
		c.Y = y;
		for (int x = 0; x < 80; x++)
		{
			if (dice1[x][y] == 'i')
			{
				dice1[x][y] = ' ';
			}
			c.X = x;
			g_Console.writeToBuffer(c, dice1[x][y]);
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

void renderDice2()
{
	COORD c;
	for (int y = 0; y < 31; y++)
	{
		c.Y = y;
		for (int x = 0; x < 80; x++)
		{
			if (dice2[x][y] == 'i')
			{
				dice2[x][y] = ' ';
			}
			c.X = x;
			g_Console.writeToBuffer(c, dice2[x][y]);
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

void renderDice3()
{
	COORD c;
	for (int y = 0; y < 31; y++)
	{
		c.Y = y;
		for (int x = 0; x < 80; x++)
		{
			if (dice3[x][y] == 'i')
			{
				dice3[x][y] = ' ';
			}
			c.X = x;
			g_Console.writeToBuffer(c, dice3[x][y]);
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

void renderDice4()
{
	COORD c;
	for (int y = 0; y < 31; y++)
	{
		c.Y = y;
		for (int x = 0; x < 80; x++)
		{
			if (dice4[x][y] == 'i')
			{
				dice4[x][y] = ' ';
			}
			c.X = x;
			g_Console.writeToBuffer(c, dice4[x][y]);
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

void renderDice5()
{
	COORD c;
	for (int y = 0; y < 31; y++)
	{
		c.Y = y;
		for (int x = 0; x < 80; x++)
		{
			if (dice5[x][y] == 'i')
			{
				dice5[x][y] = ' ';
			}
			c.X = x;
			g_Console.writeToBuffer(c, dice5[x][y]);
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

void renderDice6()
{
	COORD c;
	for (int y = 0; y < 31; y++)
	{
		c.Y = y;
		for (int x = 0; x < 80; x++)
		{
			if (dice6[x][y] == 'i')
			{
				dice6[x][y] = ' ';
			}
			c.X = x;
			g_Console.writeToBuffer(c, dice6[x][y]);
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