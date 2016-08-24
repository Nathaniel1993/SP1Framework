#include "Ai.h"
#include <vector>

using std::vector;
COORD c;
vector<COORD> coordSave;

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

void BossAi()
{
	if (Bounce.bossBounceTime > g_dElapsedTime)
	{
		return;
	}
	
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
	Bounce.bossBounceTime = g_dElapsedTime + 0.2;
}

void renderBoss()
{

	//Draw location of Boss
	WORD charColor = 0x0C;
	//COORD c = g_Console.getConsoleSize();
	//g_sBoss.m_cLocation.X = 18; // Boss spawn location
	//g_sBoss.m_cLocation.Y = 25;

	//c.X = 5;
	//c.Y = 5;
	for (int i = 0; i < coordSave.size(); i++)
	{
		g_Console.writeToBuffer(coordSave[i], (char)65, charColor);
	}

	//if ((g_sBoss.m_cLocation.X == g_sChar.m_cLocation.X) && (g_sBoss.m_cLocation.Y == g_sChar.m_cLocation.Y))
	//{
	//	g_Console.writeToBuffer(c, "Ayy Lmao ", 0x03);

	//}
}