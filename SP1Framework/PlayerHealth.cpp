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
	/*	-------------------------------------------hit player collision --------------------------------------------------- */
	for (int i = 0; i < 6; i++)
	{
		if /*(*/((g_sBoss.m_cLocation.X == g_sChar.m_cLocation.X) && (g_sBoss.m_cLocation.Y == g_sChar.m_cLocation.Y))
			/*|| ((BossTrap[i].m_cLocation.X == g_sChar.m_cLocation.X) && (BossTrap[i].m_cLocation.Y == g_sChar.m_cLocation.Y)))*/
		{

			health -= 1;

		}
		if ((health == 0) && ((g_sBoss.m_cLocation.X == g_sChar.m_cLocation.X) && (g_sBoss.m_cLocation.Y == g_sChar.m_cLocation.Y)))
			/*|| ((BossTrap[i].m_cLocation.X == g_sChar.m_cLocation.X) && (BossTrap[i].m_cLocation.Y == g_sChar.m_cLocation.Y)))*/
		{
			launchDefScreen = true; //character dies or defeat screen
			g_eGameState = S_DEFEAT;
		}
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