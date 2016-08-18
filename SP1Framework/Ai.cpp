#include "Framework\timer.h"
#include "Framework\console.h"
#include "Ai.h"
#include "game.h"
#include "map.h"

extern Console g_Console;
extern SGameChar g_sChar;
extern SGameEnemy g_sEnemy;
extern char MapSize[80][30];

extern double aiTimeElapsed;
extern double aiBounceTime;
extern double aiDeltaTime;
//extern double g_dElapsedTime;
//extern double g_dBounceTime;
bool Caught = false;
//char Size[80][30];
void AiEnemy()
{
	//enemyRight = g_sEnemy.m_cLocation.X++;
	//enemyLeft = g_sEnemy.m_cLocation.X--;
	//enemyUp = g_sEnemy.m_cLocation.Y--;
	//enemyDown = g_sEnemy.m_cLocation.Y++;
	if (aiBounceTime > aiTimeElapsed)
	{
		return;
	}


	bool Collision = false;
	bool Detect = false;
	bool idle = true;
	unsigned int distance = 2;
	
	//if (idle == true)
	//{
	//	if (g_sEnemy.m_cLocation.X < (MapSizeSize[g_sEnemy.m_cLocation.X][g_sEnemy.m_cLocation.Y] == '#'))
	//	{
	//		g_sEnemy.m_cLocation.X++;

	//	}
	//	else
	//	{
	//		g_sEnemy.m_cLocation.X--;
	//	}
	//}
	if (MapSize[g_sEnemy.m_cLocation.X][g_sEnemy.m_cLocation.Y] == '#')
	{
		Collision = true;
	}
	if (Collision != true)
	{
		if (
			(((g_sChar.m_cLocation.X - g_sEnemy.m_cLocation.X) < 5) && ((g_sChar.m_cLocation.X - g_sEnemy.m_cLocation.X) > 0)) ||
			(((g_sChar.m_cLocation.Y - g_sEnemy.m_cLocation.Y) < 5) && ((g_sChar.m_cLocation.Y - g_sEnemy.m_cLocation.Y) > 0)) ||
			(((g_sChar.m_cLocation.X - g_sEnemy.m_cLocation.X) > -5) && ((g_sChar.m_cLocation.X - g_sEnemy.m_cLocation.X) < 0)) ||
			(((g_sChar.m_cLocation.Y - g_sEnemy.m_cLocation.Y) > -5) && ((g_sChar.m_cLocation.Y - g_sEnemy.m_cLocation.Y) < 0))
			)
			//Lesser than 0
			//Greater than -3
			// -3 < x < 0
		{


			Detect = true;
		}
	}

	/*if ((g_sChar.m_cLocation.X - g_sEnemy.m_cLocation.X) < 5)
	{
		Detect = true;
	}
	else if ((g_sChar.m_cLocation.X - g_sEnemy.m_cLocation.X) < 5)
	{
		Detect = true;
	}*/


	if (Detect == true)
	{
		if (g_sChar.m_cLocation.Y < g_sEnemy.m_cLocation.Y && (MapSize[g_sEnemy.m_cLocation.X][g_sEnemy.m_cLocation.Y - 1] != '#'))
		{
			g_sEnemy.m_cLocation.Y--;
		}
		else if (g_sChar.m_cLocation.Y > g_sEnemy.m_cLocation.Y && (MapSize[g_sEnemy.m_cLocation.X][g_sEnemy.m_cLocation.Y + 1] != '#'))
		{
			g_sEnemy.m_cLocation.Y++;
		}

		if (g_sChar.m_cLocation.X < g_sEnemy.m_cLocation.X && (MapSize[g_sEnemy.m_cLocation.X - 1][g_sEnemy.m_cLocation.Y] != '#'))
		{
			g_sEnemy.m_cLocation.X--;
		}
		else if (g_sChar.m_cLocation.X > g_sEnemy.m_cLocation.X && (MapSize[g_sEnemy.m_cLocation.X + 1][g_sEnemy.m_cLocation.Y] != '#'))
		{
			g_sEnemy.m_cLocation.X++;
		}
	}

	if ((g_sEnemy.m_cLocation.X == g_sChar.m_cLocation.X) && (g_sEnemy.m_cLocation.Y == g_sChar.m_cLocation.Y))
	{
		Caught = true;
	}
	aiBounceTime = aiTimeElapsed + 0.4;
	//g_dBounceTime = g_dElapsedTime + 0.6;
}

void renderEnemy()
{
	//Draw location of Enemy
	WORD charColor = 0x0C;
	COORD c = g_Console.getConsoleSize();
	c.X = 5;
	c.Y = 5;

	g_Console.writeToBuffer(g_sEnemy.m_cLocation, (char)97, charColor);
	if (Caught == true)
	{
		g_Console.writeToBuffer(c, "Caught Lel ", 0x03);
	}

}