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

bool Caught = false;

void AiEnemy()
{
	if (aiBounceTime > aiTimeElapsed)
	{
		return;
	}

	bool Detect = false;
	unsigned int distance = 2;

	if ((g_sChar.m_cLocation.X > 0 && g_sChar.m_cLocation.X - g_sEnemy.m_cLocation.X > 0 )	//Detect Right  //Lesser than 0 
		&& (g_sChar.m_cLocation.Y == g_sEnemy.m_cLocation.Y )												//Greater than -5
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

	if ((g_sEnemy.m_cLocation.X == g_sChar.m_cLocation.X) && (g_sEnemy.m_cLocation.Y == g_sChar.m_cLocation.Y))
	{
		Caught = true;
	}
	aiBounceTime = aiTimeElapsed + 0.2;
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