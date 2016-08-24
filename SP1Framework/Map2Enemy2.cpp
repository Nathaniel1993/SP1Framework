#include "Ai.h"

void AiEnemy5()
{
	if (Bounce.aiBounceTime5 > g_dElapsedTime)
	{
		return;
	}

	int patrol = rand() % 4 + 1;
	bool Detect = false;
	extern int encounterCheck5;
	extern bool encounter;


	if ((Enemy.g_sEnemy5.m_cLocation.X > 0 && g_sChar.m_cLocation.X - Enemy.g_sEnemy5.m_cLocation.X > 0)	//Detect Right  //Lesser than 0 
		&& (g_sChar.m_cLocation.Y == Enemy.g_sEnemy5.m_cLocation.Y)												//Greater than -5
		&& (g_sChar.m_cLocation.X - Enemy.g_sEnemy5.m_cLocation.X <= 5))											// -5 < x < 0
	{
		Detect = true;
	}
	if ((g_sChar.m_cLocation.X > 0 && g_sChar.m_cLocation.X - Enemy.g_sEnemy5.m_cLocation.X < 0) //Detect Left
		&& (g_sChar.m_cLocation.Y == Enemy.g_sEnemy5.m_cLocation.Y)
		&& (g_sChar.m_cLocation.X - Enemy.g_sEnemy5.m_cLocation.X >= -5))
	{
		Detect = true;
	}
	if ((g_sChar.m_cLocation.Y > 0 && g_sChar.m_cLocation.Y - Enemy.g_sEnemy5.m_cLocation.Y > 0) // Detect Down
		&& (g_sChar.m_cLocation.X == Enemy.g_sEnemy5.m_cLocation.X)
		&& (g_sChar.m_cLocation.Y - Enemy.g_sEnemy5.m_cLocation.Y <= 5))
	{
		Detect = true;
	}
	if ((g_sChar.m_cLocation.Y > 0 && g_sChar.m_cLocation.Y - Enemy.g_sEnemy5.m_cLocation.Y < 0) //Detect Up
		&& (g_sChar.m_cLocation.X == Enemy.g_sEnemy5.m_cLocation.X)
		&& (g_sChar.m_cLocation.Y - Enemy.g_sEnemy5.m_cLocation.Y >= -5))
	{
		Detect = true;
	}

	if (Detect == true)
	{
		if (g_sChar.m_cLocation.Y < Enemy.g_sEnemy5.m_cLocation.Y && (mapSize[Enemy.g_sEnemy5.m_cLocation.X][Enemy.g_sEnemy5.m_cLocation.Y - 1] != '#'))
		{
			Enemy.g_sEnemy5.m_cLocation.Y--;
		}
		else if (g_sChar.m_cLocation.Y > Enemy.g_sEnemy5.m_cLocation.Y && (mapSize[Enemy.g_sEnemy5.m_cLocation.X][Enemy.g_sEnemy5.m_cLocation.Y + 1] != '#'))
		{
			Enemy.g_sEnemy5.m_cLocation.Y++;
		}

		if (g_sChar.m_cLocation.X < Enemy.g_sEnemy5.m_cLocation.X && (mapSize[Enemy.g_sEnemy5.m_cLocation.X - 1][Enemy.g_sEnemy5.m_cLocation.Y] != '#'))
		{
			Enemy.g_sEnemy5.m_cLocation.X--;
		}
		else if (g_sChar.m_cLocation.X > Enemy.g_sEnemy5.m_cLocation.X && (mapSize[Enemy.g_sEnemy5.m_cLocation.X + 1][Enemy.g_sEnemy5.m_cLocation.Y] != '#'))
		{
			Enemy.g_sEnemy5.m_cLocation.X++;
		}
	}
	else
	{
		if (patrol == 1 && (mapSize[Enemy.g_sEnemy5.m_cLocation.X][Enemy.g_sEnemy5.m_cLocation.Y - 1] != '#'))
		{
			Enemy.g_sEnemy5.m_cLocation.Y--;
		}
		else if (patrol == 2 && (mapSize[Enemy.g_sEnemy5.m_cLocation.X][Enemy.g_sEnemy5.m_cLocation.Y + 1] != '#'))
		{
			Enemy.g_sEnemy5.m_cLocation.Y++;
		}

		if (patrol == 3 && (mapSize[Enemy.g_sEnemy5.m_cLocation.X - 1][Enemy.g_sEnemy5.m_cLocation.Y] != '#'))
		{
			Enemy.g_sEnemy5.m_cLocation.X--;
		}
		else if (patrol == 4 && (mapSize[Enemy.g_sEnemy5.m_cLocation.X + 1][Enemy.g_sEnemy5.m_cLocation.Y] != '#'))
		{
			Enemy.g_sEnemy5.m_cLocation.X++;
		}
	}

	if ((Enemy.g_sEnemy5.m_cLocation.X == g_sChar.m_cLocation.X) && (Enemy.g_sEnemy5.m_cLocation.Y == g_sChar.m_cLocation.Y)
		&& encounterCheck5 == 0)
	{
		encounter = true;
		encounterCheck5 = 1;
	}

	Bounce.aiBounceTime5 = g_dElapsedTime + 0.2;
}

void renderEnemy5()
{

	//Draw location of Enemy
	WORD charColor = 0x0C;
	COORD c = g_Console.getConsoleSize();
	//Enemy.g_sEnemy5.m_cLocation.X = 18; // enemy spawn location
	//Enemy.g_sEnemy5.m_cLocation.Y = 25;

	c.X = 5;
	c.Y = 5;

	g_Console.writeToBuffer(Enemy.g_sEnemy5.m_cLocation, (char)97, charColor);
}
