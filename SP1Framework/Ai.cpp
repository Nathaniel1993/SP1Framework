#include "Framework\timer.h"
#include "Framework\console.h"
#include "Ai.h"
#include "game.h"
#include "map.h"

extern Console g_Console;
extern SGameChar g_sChar;
extern SGameEnemy g_sEnemy;
bool Caught = false;
char Size[80][30];
void AiEnemy()
{
	//enemyRight = g_sEnemy.m_cLocation.X++;
	//enemyLeft = g_sEnemy.m_cLocation.X--;
	//enemyUp = g_sEnemy.m_cLocation.Y--;
	//enemyDown = g_sEnemy.m_cLocation.Y++;

	bool Collision = false;
	bool Detect = false;
	bool idle = true;
	
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
	if (Size[g_sEnemy.m_cLocation.X][g_sEnemy.m_cLocation.Y] == '#')
	{
		Collision = true;
	}

	if (((g_sChar.m_cLocation.X - g_sEnemy.m_cLocation.X) <= 5) && (g_sChar.m_cLocation.Y - g_sEnemy.m_cLocation.Y) <= 4)
	{
		Detect = true;
	}
	if (Detect == true)
	{
		if (g_sChar.m_cLocation.Y < g_sEnemy.m_cLocation.Y && (Size[g_sEnemy.m_cLocation.X][g_sEnemy.m_cLocation.Y - 1] != '#'))
		{
			g_sEnemy.m_cLocation.Y--;
		}
		else if (g_sChar.m_cLocation.Y > g_sEnemy.m_cLocation.Y && (Size[g_sEnemy.m_cLocation.X][g_sEnemy.m_cLocation.Y + 1] != '#'))
		{
			g_sEnemy.m_cLocation.Y++;
		}

		if (g_sChar.m_cLocation.X < g_sEnemy.m_cLocation.X && (Size[g_sEnemy.m_cLocation.X - 1][g_sEnemy.m_cLocation.Y] != '#'))
		{
			g_sEnemy.m_cLocation.X--;
		}
		else if (g_sChar.m_cLocation.X > g_sEnemy.m_cLocation.X && (Size[g_sEnemy.m_cLocation.X + 1][g_sEnemy.m_cLocation.Y] != '#'))
		{
			g_sEnemy.m_cLocation.X++;
		}
	}

	if ((g_sEnemy.m_cLocation.X == g_sChar.m_cLocation.X) && (g_sEnemy.m_cLocation.Y == g_sChar.m_cLocation.Y))
	{
		Caught = true;
	}
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