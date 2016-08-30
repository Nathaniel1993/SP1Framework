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
	bool returnToSpawn = false;
	extern bool encounter;
	extern int encounterCheck[9];

	for (int i = 0; i < 9; i++)
	{
		if (i != 2)
		{
			if ((Enemies[i].X > 0 && g_sChar.m_cLocation.X - Enemies[i].X > 0)	//Detect Right  //Lesser than 0 
				&& (g_sChar.m_cLocation.Y == Enemies[i].Y)										//Greater than -7
				&& (g_sChar.m_cLocation.X - Enemies[i].X <= 7))									// -7 < x < 0
			{
				Detect = true;
			}
			else if ((g_sChar.m_cLocation.X > 0 && g_sChar.m_cLocation.X - Enemies[i].X < 0) //Detect Left
				&& (g_sChar.m_cLocation.Y == Enemies[i].Y)
				&& (g_sChar.m_cLocation.X - Enemies[i].X >= -7))
			{
				Detect = true;
			}
			else if ((g_sChar.m_cLocation.Y > 0 && g_sChar.m_cLocation.Y - Enemies[i].Y > 0) // Detect Down
				&& (g_sChar.m_cLocation.X == Enemies[i].X)
				&& (g_sChar.m_cLocation.Y - Enemies[i].Y <= 7))
			{
				Detect = true;
			}
			else if ((g_sChar.m_cLocation.Y > 0 && g_sChar.m_cLocation.Y - Enemies[i].Y < 0) //Detect Up
				&& (g_sChar.m_cLocation.X == Enemies[i].X)
				&& (g_sChar.m_cLocation.Y - Enemies[i].Y >= -7))
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
				if (patrol == 1 && (mapSize[Enemies[i].X][Enemies[i].Y - 1] != '#')) // random patrol
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
		}
		else
		{
			for (unsigned loop = 1; loop != 5; loop++) // circular patrol
			{
				switch (loop)
				{
				case 1:
				{
					if ((mapSize[Enemies[2].X][Enemies[2].Y + 1] != '#') &&
						Enemies[2].Y != 22 && Enemies[2].X == 56)
					{
						Enemies[2].Y++;
					}
					break;
				}
				case 2:
				{
					if ((mapSize[Enemies[2].X + 1][Enemies[2].Y] != '#') &&
						Enemies[2].X != 63 && Enemies[2].Y == 21)
					{
						Enemies[2].X++;
					}
					break;
				}
				case 3:
				{
					if ((mapSize[Enemies[2].X][Enemies[2].Y - 1] != '#') &&
						Enemies[2].Y != 19 && Enemies[2].X == 62)
					{
						Enemies[2].Y--;
					}
					break;
				}
				case 4:
				{
					if ((mapSize[Enemies[i].X - 1][Enemies[i].Y] != '#') &&
						Enemies[2].X != 56 && Enemies[2].Y == 19)
					{
						Enemies[2].X--;
					}
					break;
				}

				if (loop == 4)
				{
					loop = 1;
				}

				}
			}
		}
	
		if ((Enemies[i].X == g_sChar.m_cLocation.X) && (Enemies[i].Y == g_sChar.m_cLocation.Y)
			&& encounterCheck[i] == 0)
			{
				encounter = true;
				encounterCheck[i] = 1;
			}
	}
	Bounce.aiBounceTime1 = g_dElapsedTime + 0.125;
}

void renderEnemies(COORD Enemy)
{
	for (int i = 0; i < 6; i++)
	{
		g_Console.writeToBuffer(Enemy, (char)65, 0x0C);
	
	}
}

void enemiesSpawn1()
{
	Enemies[0].X = 18; // enemy 1 spawn location
	Enemies[0].Y = 25;

	Enemies[1].X = 18; // enemy 2 spawn location
	Enemies[1].Y = 10;

	Enemies[2].X = 56; // enemy 3 spawn location
	Enemies[2].Y = 19; 

}
void enemiesSpawn2()
{
	Enemies[3].X = 15; // enemy 4 spawn location
	Enemies[3].Y = 27;

	Enemies[4].X = 46; // enemy 5 spawn location
	Enemies[4].Y = 18;

	Enemies[5].X = 33; // enemy 6 spawn location
	Enemies[5].Y = 18;

	Enemies[6].X = 20; // enemy 7 spawn location
	Enemies[6].Y = 20;

	Enemies[7].X = 57; // enemy 8 spawn location
	Enemies[7].Y = 15;

	Enemies[8].X = 57; // enemy 9 spawn location
	Enemies[8].Y = 27;

}