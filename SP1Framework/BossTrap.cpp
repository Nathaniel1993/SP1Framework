#include "Ai.h"
//
//void damageBoss()
//{
//	int bossLife = 9;
//	bool bossAlive = true;
//	for (int i = 0; i < 6; i++)
//	{
//		if ((BossTrap[i].m_cLocation.X == g_sBoss.m_cLocation.X) && (BossTrap[i].m_cLocation.Y == g_sBoss.m_cLocation.Y))
//		{
//			bossLife -= 1;
//		}
//	}
//	if (bossLife == 0)
//	{
//		bossAlive = false;
//	}
//}
//	
//
//void renderTrap() 
//{
//	WORD charColor = 0x0E;
//
//
//	for (int i = 0; i < 6; i++)
//	{
//		g_Console.writeToBuffer(BossTrap[i].m_cLocation, (char)64, charColor);
//	}
//}
//void trapSpawn()
//{
//	COORD trap;
//
//	trap.X = (rand() % 59) + 1;
//	trap.Y = (rand() % 70) + 1;
//
//	for (int i = 0; i < 6; i++)
//	{
//		g_Console.writeToBuffer(trap, (char)64, 0x0E);
//	}
//	
//}