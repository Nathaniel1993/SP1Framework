#include "Ai.h"
#include <vector>

using std::vector;
COORD c;
vector<COORD> coordSave;

extern bool launchVicScreen;
extern bool launchDefScreen;
extern EGAMESTATES g_eGameState;

bool bossAlive = true;
int bossLife = 9;
void coordSaveLocation()					// head sets last position and passes the coordinates down the array
{											//for the body parts to follow
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
void damageBoss()					// Boss moving through trap damages it
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
	Bounce.trapTime = g_dElapsedTime + 0.5; // set how fast the trap kills the boss, higher the value slower it kills
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
		{																														// detect up, move up
			c.X = g_sBoss.m_cLocation.X;
			c.Y = g_sBoss.m_cLocation.Y;
			g_sBoss.m_cLocation.Y--;
			coordSave[0] = c;

		}
		else if (g_sChar.m_cLocation.Y > g_sBoss.m_cLocation.Y && (mapSize[g_sBoss.m_cLocation.X][g_sBoss.m_cLocation.Y + 1] != '#')) //detect down, move down
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
		else if (g_sChar.m_cLocation.X > g_sBoss.m_cLocation.X && (mapSize[g_sBoss.m_cLocation.X + 1][g_sBoss.m_cLocation.Y] != '#')) //detect right, move right
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
		}
		if ((bossLife == 0) && ((trap[i].X == g_sBoss.m_cLocation.X) && (trap[i].Y == g_sBoss.m_cLocation.Y)))
		{
			bossAlive = false;
			launchVicScreen = true;
			g_eGameState = S_VICTORY; 
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
		g_Console.writeToBuffer(bossHealthBar, (char)(3),0x0C);
		bossHealthBar.X++;
	}
}

void renderBoss()
{
	//Draw Boss
	WORD charColor = 0x0C;
	if (bossAlive == true)
	{
		for (unsigned int i = 0; i < coordSave.size(); i++)
		{
			g_Console.writeToBuffer(coordSave[i], (char)65, charColor);
		}
	}
}