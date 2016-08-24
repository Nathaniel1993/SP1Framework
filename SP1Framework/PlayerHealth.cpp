#include "Ai.h"
#include <vector>
using std::vector;

COORD HealthBar;
int maxHealth = 5;
int health = 5;
void healthAi()
{
	if (Bounce.healthBounceTime > g_dElapsedTime)
	{
		return;
	}
	/*	----------------------------- Boss hit player collision --------------------------------------------------- */
	if ((g_sBoss.m_cLocation.X == g_sChar.m_cLocation.X) && (g_sBoss.m_cLocation.Y == g_sChar.m_cLocation.Y))
	{
	
		health -= 1;

	}
	if ((health == 0) && ((g_sBoss.m_cLocation.X == g_sChar.m_cLocation.X) && (g_sBoss.m_cLocation.Y == g_sChar.m_cLocation.Y)))
	{
		//character dies or defeat screen
	}
	Bounce.healthBounceTime = g_dElapsedTime + 0.125;
}
void renderHealth()
{
	
	HealthBar.X = 20;
	HealthBar.Y = 0;

	for (int i = 0; i <= health; i++)
	{
		g_Console.writeToBuffer(HealthBar, (char)(3));
		HealthBar.X++;
	}
	
	/*g_Console.writeToBuffer(c,(char)3,0x03);*/

	
}