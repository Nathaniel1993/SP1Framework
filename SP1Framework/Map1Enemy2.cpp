#include "Ai.h"

void AiEnemy2()
{
	if (Bounce.aiBounceTime2 > g_dElapsedTime)
	{
		return;
	}

	bool Detect = false;

	if ((Enemy.g_sEnemy2.m_cLocation.X > 0 && g_sChar.m_cLocation.X - Enemy.g_sEnemy2.m_cLocation.X > 0)	//Detect Right  //Lesser than 0 
		&& (g_sChar.m_cLocation.Y == Enemy.g_sEnemy2.m_cLocation.Y)												//Greater than -5
		&& (g_sChar.m_cLocation.X - Enemy.g_sEnemy2.m_cLocation.X <= 5))											// -5 < x < 0
	{
		Detect = true;
	}
	if ((g_sChar.m_cLocation.X > 0 && g_sChar.m_cLocation.X - Enemy.g_sEnemy2.m_cLocation.X < 0) //Detect Left
		&& (g_sChar.m_cLocation.Y == Enemy.g_sEnemy2.m_cLocation.Y)
		&& (g_sChar.m_cLocation.X - Enemy.g_sEnemy2.m_cLocation.X >= -5))
	{
		Detect = true;
	}
	if ((g_sChar.m_cLocation.Y > 0 && g_sChar.m_cLocation.Y - Enemy.g_sEnemy2.m_cLocation.Y > 0) // Detect Down
		&& (g_sChar.m_cLocation.X == Enemy.g_sEnemy2.m_cLocation.X)
		&& (g_sChar.m_cLocation.Y - Enemy.g_sEnemy2.m_cLocation.Y <= 5))
	{
		Detect = true;
	}
	if ((g_sChar.m_cLocation.Y > 0 && g_sChar.m_cLocation.Y - Enemy.g_sEnemy2.m_cLocation.Y < 0) //Detect Up
		&& (g_sChar.m_cLocation.X == Enemy.g_sEnemy2.m_cLocation.X)
		&& (g_sChar.m_cLocation.Y - Enemy.g_sEnemy2.m_cLocation.Y >= -5))
	{
		Detect = true;
	}

	if (Detect == true)
	{
		if (g_sChar.m_cLocation.Y < Enemy.g_sEnemy2.m_cLocation.Y && (MapSize[Enemy.g_sEnemy2.m_cLocation.X][Enemy.g_sEnemy2.m_cLocation.Y - 1] != '#'))
		{
			Enemy.g_sEnemy2.m_cLocation.Y--;
		}
		else if (g_sChar.m_cLocation.Y > Enemy.g_sEnemy2.m_cLocation.Y && (MapSize[Enemy.g_sEnemy2.m_cLocation.X][Enemy.g_sEnemy2.m_cLocation.Y + 1] != '#'))
		{
			Enemy.g_sEnemy2.m_cLocation.Y++;
		}

		if (g_sChar.m_cLocation.X < Enemy.g_sEnemy2.m_cLocation.X && (MapSize[Enemy.g_sEnemy2.m_cLocation.X - 1][Enemy.g_sEnemy2.m_cLocation.Y] != '#'))
		{
			Enemy.g_sEnemy2.m_cLocation.X--;
		}
		else if (g_sChar.m_cLocation.X > Enemy.g_sEnemy2.m_cLocation.X && (MapSize[Enemy.g_sEnemy2.m_cLocation.X + 1][Enemy.g_sEnemy2.m_cLocation.Y] != '#'))
		{
			Enemy.g_sEnemy2.m_cLocation.X++;
		}
	}


	Bounce.aiBounceTime2 = g_dElapsedTime + 0.2;
}

void renderEnemy2()
{
	
	//Draw location of Enemy
	WORD charColor = 0x0C;
	COORD c = g_Console.getConsoleSize();
	//Enemy.g_sEnemy2.m_cLocation.X = 18; // enemy spawn location
	//Enemy.g_sEnemy2.m_cLocation.Y = 10;

	c.X = 5;
	c.Y = 5;

	g_Console.writeToBuffer(Enemy.g_sEnemy2.m_cLocation, (char)97, charColor);

	if ((Enemy.g_sEnemy2.m_cLocation.X == g_sChar.m_cLocation.X) && (Enemy.g_sEnemy2.m_cLocation.Y == g_sChar.m_cLocation.Y))
	{
		g_Console.writeToBuffer(c, "Caught Lel ", 0x03);

	}
}

