#include "Ai.h"
#include <vector>

using std::vector;
COORD c;
vector<COORD> coordSave;

extern bool launchDefScreen;
extern EGAMESTATES g_eGameState;

bool bossAlive = true;
int bossLife = 9;
void coordSaveLocation()
{
	if (coordSave.size() <= 0)
	{
		c.X = 20;
		c.Y = 25;
		for (int i = 0; i < 8; i++)
			coordSave.push_back(c);
	}
	else
	{
		coordSave[7] = coordSave[6];
		coordSave[6] = coordSave[5];
		coordSave[5] = coordSave[4];
		coordSave[4] = coordSave[3];
		coordSave[3] = coordSave[2];
		coordSave[2] = coordSave[1];
		coordSave[1] =  c;
	}

}
void damageBoss()
{
	if (Bounce.trapTime > g_dElapsedTime)
	{
		return;
	}
	Bounce.trapTime = 0.0;
	for (int i = 0; i < 9; i++)
	{
		if ((trap[i].X == g_sBoss.m_cLocation.X) && (trap[i].Y == g_sBoss.m_cLocation.Y))
		{
			bossLife -= 1;
		}
	}
	if (bossLife == 0)
	{
		bossAlive = false;
	}
	Bounce.trapTime = g_dElapsedTime + 0.2;
}

void BossAi()
{
	if (bossAlive == true)
	{
		if (Bounce.bossBounceTime > g_dElapsedTime)
		{
			return;
		}
		Bounce.bossBounceTime = 0.0;
		coordSaveLocation();

		if (g_sChar.m_cLocation.Y < g_sBoss.m_cLocation.Y && (mapSize[g_sBoss.m_cLocation.X][g_sBoss.m_cLocation.Y - 1] != '#')) //finding character, detect walls to prevent walking through
		{																														// detect 
			c.X = g_sBoss.m_cLocation.X;
			c.Y = g_sBoss.m_cLocation.Y;
			g_sBoss.m_cLocation.Y--;
			coordSave[0] = c;

		}
		else if (g_sChar.m_cLocation.Y > g_sBoss.m_cLocation.Y && (mapSize[g_sBoss.m_cLocation.X][g_sBoss.m_cLocation.Y + 1] != '#')) //detect up
		{
			c.X = g_sBoss.m_cLocation.X;
			c.Y = g_sBoss.m_cLocation.Y;

			g_sBoss.m_cLocation.Y++;
			coordSave[0] = c;
		}

		if (g_sChar.m_cLocation.X < g_sBoss.m_cLocation.X && (mapSize[g_sBoss.m_cLocation.X - 1][g_sBoss.m_cLocation.Y] != '#')) //detect left, move left
		{
			c.X = g_sBoss.m_cLocation.X;
			c.Y = g_sBoss.m_cLocation.Y;

			g_sBoss.m_cLocation.X--;
			coordSave[0] = c;
		}
		else if (g_sChar.m_cLocation.X > g_sBoss.m_cLocation.X && (mapSize[g_sBoss.m_cLocation.X + 1][g_sBoss.m_cLocation.Y] != '#')) //detect 
		{
			c.X = g_sBoss.m_cLocation.X;
			c.Y = g_sBoss.m_cLocation.Y;

			g_sBoss.m_cLocation.X++;
			coordSave[0] = c;
		}
	}
	Bounce.bossBounceTime = g_dElapsedTime + 0.2;
}
void bossHealthAi()
{
	if (Bounce.bossHealthBounceTime > g_dElapsedTime)
	{
		return;
	}
	/*	-------------------------------------------hit collision --------------------------------------------------- */
	Bounce.bossHealthBounceTime = 0.0;
	for (int i = 0; i < 9; i++)
	{
		if ((trap[i].X == g_sBoss.m_cLocation.X) && (trap[i].Y == g_sBoss.m_cLocation.Y))
		{
			bossLife -= 1;
			//hitTarget[i] = true;

		}
		if ((bossLife == 0) && ((trap[i].X == g_sBoss.m_cLocation.X) && (trap[i].Y == g_sBoss.m_cLocation.Y)))
		{
			bossAlive = false;
			//launchDefScreen = true;
			//g_eGameState = S_DEFEAT; //character dies or defeat screen
			//victory page
		}
	}


	Bounce.bossHealthBounceTime = g_dElapsedTime + 0.125;
}
void renderBossHealth()
{
	COORD bossHealthBar;
	bossHealthBar.X = 30;
	bossHealthBar.Y = 0;

	for (int i = 0; i <= bossLife; i++)
	{
		g_Console.writeToBuffer(bossHealthBar, (char)(3),0x0A);
		bossHealthBar.X++;
	}

	/*for (int i = 0; i < 9; i++)
	{
		if (hitTarget[i] == true)
		{
			renderTrapTrigger(trap[i]);
		}

	}*/
	/*g_Console.writeToBuffer(c,(char)3,0x03);*/
}



void renderBoss()
{
	
	//Draw location of Boss
	WORD charColor = 0x0C;
	if (bossAlive == true)
	{
		for (unsigned int i = 0; i < coordSave.size(); i++)
		{
			g_Console.writeToBuffer(coordSave[i], (char)65, charColor);
		}
	}

	
}