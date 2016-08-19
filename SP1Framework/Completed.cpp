#include "Completed.h"
extern int g_MapNo;
extern WORD color;
void checkcomplete()
{
	if (g_MapNo == 1)
	{
		if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X == 0 && g_sChar.m_cLocation.Y == 2)
		{
			g_MapNo = 2;
			color = 0x0E;
			g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 1;
			g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 29;
		}
	}
	if (g_MapNo == 2)
	{
		if (g_abKeyPressed[K_RIGHT] && g_sChar.m_cLocation.X == 79 && g_sChar.m_cLocation.Y == 2)
		{
			g_MapNo = 1;
			color = 0x09;
			g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 80;
			g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 29;
		}
		if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X == 0 && g_sChar.m_cLocation.Y == 28)
		{
			g_MapNo = 3;
			color = 0x04;
			g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 1;
			g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 3;
		}
	}
	if (g_MapNo == 3)
	{
		if (g_abKeyPressed[K_RIGHT] && g_sChar.m_cLocation.X == 79 && g_sChar.m_cLocation.Y == 28)
		{
			g_MapNo = 2;
			color = 0x0E;
			g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 80;
			g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 3;
		}
		if (g_abKeyPressed[K_UP] && g_sChar.m_cLocation.X == 39 && g_sChar.m_cLocation.Y == 0)
		{
			g_MapNo = 4;
			color = 0x0B;
			g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 42;
			g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 1;
		}
	}
	if (g_MapNo == 4)
	{
		if (g_abKeyPressed[K_DOWN] && g_sChar.m_cLocation.X == 38 && g_sChar.m_cLocation.Y == 30)
		{
			g_MapNo = 3;
			color = 0x04;
			g_sChar.m_cLocation.X = g_Console.getConsoleSize().X - 41;
			g_sChar.m_cLocation.Y = g_Console.getConsoleSize().Y - 30;
		}
	}
}