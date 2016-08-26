#include "Ai.h"

COORD trap[9];
extern bool hitTarget[9];

void renderTrap(COORD a) 
{
	WORD charColor = 0x0E;


	for (int i = 0; i < 9; i++)
	{
		g_Console.writeToBuffer(a, (char)64, charColor);
	}
}

void trapSpawn()
{

	for (int i = 0; i < 9; i++)
	{
		trap[i].X = rand() % 60 + 1;
		trap[i].Y = rand() % 27 + 3;
	}

}
void renderTrapTrigger(COORD a)
{
	for (int i = 0; i < 9; i++)
	{
		if (trap[i].X == a.X&&trap[i].Y == a.Y)
		{
			if (hitTarget[i] == true)
			{
				g_Console.writeToBuffer(a, (char)64, 0x0A);
				renderToScreen();
				hitTarget[i] = false;
			}
		}
		else
		{
			g_Console.writeToBuffer(a, (char)64, 0x0E);
		}

	}
}

