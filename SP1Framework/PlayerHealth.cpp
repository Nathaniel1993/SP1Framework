#include "Ai.h"

COORD HealthBar;
int maxHealth = 5;
int health = 5;
extern bool launchDefScreen;
extern EGAMESTATES g_eGameState;

void healthAi()
{
	if (Bounce.healthBounceTime > g_dElapsedTime)
	{
		return;
	}
	Bounce.healthBounceTime = 0.0;
	/*	-------------------------------------------hit player collision --------------------------------------------------- */
		if ((g_sBoss.m_cLocation.X == g_sChar.m_cLocation.X) && (g_sBoss.m_cLocation.Y == g_sChar.m_cLocation.Y))//If Boss collides with Player, health minus
		{

			health -= 1;

		}
		if ((health == 0) && ((g_sBoss.m_cLocation.X == g_sChar.m_cLocation.X) && (g_sBoss.m_cLocation.Y == g_sChar.m_cLocation.Y)))//If Health reaches 0, launch defeat screen
		{
			launchDefScreen = true; //character dies or defeat screen
			g_eGameState = S_DEFEAT;
		}
	for (int i = 0; i < 9; i++)
	{
		if ((trap[i].X == g_sChar.m_cLocation.X) && (trap[i].Y == g_sChar.m_cLocation.Y))//If Character's location == Trap's location, minus health
		{
			health -= 1;
		}
		if ((health == 0) && ((trap[i].X == g_sChar.m_cLocation.X) && (trap[i].Y == g_sChar.m_cLocation.Y)))//If Character's health reaches 0 from touching the traps, display defeat screen
		{
			launchDefScreen = true;
			g_eGameState = S_DEFEAT; //character dies or defeat screen
		}
	}
	Bounce.healthBounceTime = g_dElapsedTime + 0.125;//The speed of which the health decreases.
}
void renderHealth()
{
	
	HealthBar.X = 11;
	HealthBar.Y = 1;

	for (int i = 0; i <= health; i++)
	{
		g_Console.writeToBuffer(HealthBar, (char)(3), 0x0A);
		HealthBar.X++;
	}
}