#include "Ai.h"

void AiEnemy()
{
	if (aiBounceTime > aiTimeElapsed)
	{
		return;
	}

	bool Detect = false;

	if ((g_sEnemy.m_cLocation.X > 0 && g_sChar.m_cLocation.X - g_sEnemy.m_cLocation.X > 0)	//Detect Right  //Lesser than 0 
		&& (g_sChar.m_cLocation.Y == g_sEnemy.m_cLocation.Y)												//Greater than -5
		&& (g_sChar.m_cLocation.X - g_sEnemy.m_cLocation.X <= 5))											// -5 < x < 0
	{
		Detect = true;
	}
	if ((g_sChar.m_cLocation.X > 0 && g_sChar.m_cLocation.X - g_sEnemy.m_cLocation.X < 0) //Detect Left
		&& (g_sChar.m_cLocation.Y == g_sEnemy.m_cLocation.Y)
		&& (g_sChar.m_cLocation.X - g_sEnemy.m_cLocation.X >= -5))
	{
		Detect = true;
	}
	if ((g_sChar.m_cLocation.Y > 0 && g_sChar.m_cLocation.Y - g_sEnemy.m_cLocation.Y > 0) // Detect Down
		&& (g_sChar.m_cLocation.X == g_sEnemy.m_cLocation.X)
		&& (g_sChar.m_cLocation.Y - g_sEnemy.m_cLocation.Y <= 5))
	{
		Detect = true;
	}
	if ((g_sChar.m_cLocation.Y > 0 && g_sChar.m_cLocation.Y - g_sEnemy.m_cLocation.Y < 0) //Detect Up
		&& (g_sChar.m_cLocation.X == g_sEnemy.m_cLocation.X)
		&& (g_sChar.m_cLocation.Y - g_sEnemy.m_cLocation.Y >= -5))
	{
		Detect = true;
	}

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


	aiBounceTime = aiTimeElapsed + 0.2;
}

void renderEnemy()
{
	
	//Draw location of Enemy
	WORD charColor = 0x0C;
	COORD c = g_Console.getConsoleSize();
	g_sEnemy.m_cLocation.X = 18; // enemy spawn location
	g_sEnemy.m_cLocation.Y = 25;

	c.X = 5;
	c.Y = 5;
	
	g_Console.writeToBuffer(g_sEnemy.m_cLocation, (char)97, charColor);

	if ((g_sEnemy.m_cLocation.X == g_sChar.m_cLocation.X) && (g_sEnemy.m_cLocation.Y == g_sChar.m_cLocation.Y))
	{
		g_Console.writeToBuffer(c, "Caught Lel ", 0x03);

	}
}