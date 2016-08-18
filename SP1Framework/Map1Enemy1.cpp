#include "Ai.h"


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

