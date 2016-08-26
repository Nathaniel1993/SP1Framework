#include "Ai.h"

COORD Enemies[9];

void EnemiesAi(COORD Enemy)
{
	if (Bounce.aiBounceTime1 > g_dElapsedTime)
	{
		return;
	}
	Bounce.aiBounceTime1 = 0.0;
	int patrol = rand() % 4 + 1;
	bool Detect = false;
	extern bool encounter;
	extern int encounterCheck1;

	for (int i = 0; i < 9; i++)
	{
		if ((Enemies[i].X > 0 && g_sChar.m_cLocation.X - Enemies[i].X > 0)	//Detect Right  //Lesser than 0 
			&& (g_sChar.m_cLocation.Y == Enemies[i].Y)												//Greater than -5
			&& (g_sChar.m_cLocation.X - Enemies[i].X <= 5))											// -5 < x < 0
		{
			Detect = true;
		}
		if ((g_sChar.m_cLocation.X > 0 && g_sChar.m_cLocation.X - Enemies[i].X < 0) //Detect Left
			&& (g_sChar.m_cLocation.Y == Enemies[i].Y)
			&& (g_sChar.m_cLocation.X - Enemies[i].X >= -5))
		{
			Detect = true;
		}
		if ((g_sChar.m_cLocation.Y > 0 && g_sChar.m_cLocation.Y - Enemies[i].Y > 0) // Detect Down
			&& (g_sChar.m_cLocation.X == Enemies[i].X)
			&& (g_sChar.m_cLocation.Y - Enemies[i].Y <= 5))
		{
			Detect = true;
		}
		if ((g_sChar.m_cLocation.Y > 0 && g_sChar.m_cLocation.Y - Enemies[i].Y < 0) //Detect Up
			&& (g_sChar.m_cLocation.X == Enemies[i].X)
			&& (g_sChar.m_cLocation.Y - Enemies[i].Y >= -5))
		{
			Detect = true;
		}

		if (Detect == true)
		{
			if (g_sChar.m_cLocation.Y < Enemies[i].Y && (mapSize[Enemies[i].X][Enemies[i].Y - 1] != '#'))
			{
				Enemies[i].Y--;
			}
			else if (g_sChar.m_cLocation.Y > Enemies[i].Y && (mapSize[Enemies[i].X][Enemies[i].Y + 1] != '#'))
			{
				Enemies[i].Y++;
			}

			if (g_sChar.m_cLocation.X < Enemies[i].X && (mapSize[Enemies[i].X - 1][Enemies[i].Y] != '#'))
			{
				Enemies[i].X--;
			}
			else if (g_sChar.m_cLocation.X > Enemies[i].X && (mapSize[Enemies[i].X + 1][Enemies[i].Y] != '#'))
			{
				Enemies[i].X++;
			}
		}
		else
		{

			if (patrol == 1 && (mapSize[Enemies[i].X][Enemies[i].Y - 1] != '#'))
			{
				Enemies[i].Y--;
			}
			else if (patrol == 2 && (mapSize[Enemies[i].X][Enemies[i].Y + 1] != '#'))
			{
				Enemies[i].Y++;
			}

			if (patrol == 3 && (mapSize[Enemies[i].X - 1][Enemies[i].Y] != '#'))
			{
				Enemies[i].X--;
			}
			else if (patrol == 4 && (mapSize[Enemies[i].X + 1][Enemies[i].Y] != '#'))
			{
				Enemies[i].X++;
			}
		}
		/*	if ((Enemies[i].X == g_sChar.m_cLocation.X) && (Enemies[i].Y == g_sChar.m_cLocation.Y)
				&& encounterCheck1 == 0)
				{
				encounter = true;
				encounterCheck1 = 1;

				}
				}*/
	}
	Bounce.aiBounceTime1 = g_dElapsedTime + 0.2;
}

void renderEnemies(COORD Enemy)
{
	for (int i = 0; i < 9; i++)
	{
		g_Console.writeToBuffer(Enemy, (char)65, 0x0C);
		if ((Enemies[i].X == g_sChar.m_cLocation.X) && (Enemies[i].Y == g_sChar.m_cLocation.Y))
			//&& encounterCheck1 == 0)
		{
			/*encounter = true;
			encounterCheck1 = 1;*/
			COORD c;
			c.X = 5;
			c.Y = 5;
			g_Console.writeToBuffer(c, "Ayy Lmao", 0x0C);
		}

	}
}

void enemiesSpawn1()
{
	//Enemies[0].X = 0;
	//Enemies[0].Y = 0;

	Enemies[0].X = 18; // enemy 1 spawn location
	Enemies[0].Y = 25;

	Enemies[1].X = 18; // enemy 2 spawn location
	Enemies[1].Y = 10;

	Enemies[2].X = 59; // enemy 3 spawn location
	Enemies[2].Y = 15;

}
void enemiesSpawn2()
{
	Enemies[3].X = 15; // enemy 4 spawn location
	Enemies[3].Y = 27;

	Enemies[4].X = 46; // enemy 5 spawn location
	Enemies[4].Y = 18;

	Enemies[5].X = 33; // enemy 6 spawn location
	Enemies[5].Y = 18;
}