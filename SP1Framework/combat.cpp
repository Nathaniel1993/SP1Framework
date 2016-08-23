#include"combat.h"
#include <fstream>
#include <sstream>

extern bool g_abKeyPressed[K_COUNT];
extern EGAMESTATES g_eGameState;
extern Console g_Console;
extern char MapSize[80][31];

int secondEasyRoll;
int secondMediumRoll;
int secondHardRoll;

int Lifecounter = 0;

void combatEasy()
{
	int EasyRoll;
	EasyRoll = rand() % 5 + 1;
	secondEasyRoll = EasyRoll;

	ifstream file("combateasy.txt");
	int width = 0;
	int height = 0;
	if (file.is_open())
	{
		while (height < 31)
		{
			while (width < 80)
			{
				file >> MapSize[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}

	switch (EasyRoll)
	{
	case 1: EasyQuestion1();
		break;
	case 2: EasyQuestion2();
		break;
	case 3: EasyQuestion3();
		break;
	case 4: EasyQuestion4();
		break;
	case 5: EasyQuestion5();
		break;
	}

	if (Lifecounter == 3)
	{
		g_eGameState = S_DEFEAT;
		Lifecounter = 0;
	}
}

void combatMedium()
{
	int MediumRoll;
	MediumRoll = rand() % 5 + 1;
	secondMediumRoll = MediumRoll;

	ifstream file("combatmedium.txt");
	int width = 0;
	int height = 0;
	if (file.is_open())
	{
		while (height < 31)
		{
			while (width < 80)
			{
				file >> MapSize[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}

	switch (MediumRoll)
	{
	case 1: MediumQuestion1();
		break;
	case 2: MediumQuestion2();
		break;
	case 3: MediumQuestion3();
		break;
	case 4: MediumQuestion4();
		break;
	case 5: MediumQuestion5();
		break;
	}

	if (Lifecounter == 3)
	{
		g_eGameState = S_DEFEAT;
		Lifecounter = 0;
	}
}

void combatHard()
{
	int HardRoll;
	HardRoll = rand() % 5 + 1;
	secondHardRoll = HardRoll;

	ifstream file("combathard.txt");
	int width = 0;
	int height = 0;
	if (file.is_open())
	{
		while (height < 31)
		{
			while (width < 80)
			{
				file >> MapSize[width][height];
				width++;
			}
			height++;
			width = 0;
		}
		file.close();
	}

	switch (HardRoll)
	{
	case 1: HardQuestion1();
		break;
	case 2: HardQuestion2();
		break;
	case 3: HardQuestion3();
		break;
	case 4: HardQuestion4();
		break;
	case 5: HardQuestion5();
		break;
	}

	if (Lifecounter == 3)
	{
		g_eGameState = S_DEFEAT;
		Lifecounter = 0;
	}
}

void rendercombatEasy()
{
	COORD c;
	for (int y = 0; y < 31; y++)
	{
		c.Y = y;
		for (int x = 0; x < 80; x++)
		{
			if (MapSize[x][y] == 'i')
			{
				MapSize[x][y] = ' ';
			}
			c.X = x;
			g_Console.writeToBuffer(c, MapSize[x][y]);
			if (MapSize[x][y] == '-')
			{
				g_Console.writeToBuffer(c, MapSize[x][y], 0x0C);
			}
		}
	}
	std::ostringstream ss;
	ss.str("");
	ss << (3 - Lifecounter) << "tries left";
	c.X = 46;
	c.Y = 1;
	g_Console.writeToBuffer(c, ss.str());

	switch (secondEasyRoll)
	{
	case 1: renderEasyQuestion1();
		break;
	case 2: renderEasyQuestion2();
		break;
	case 3: renderEasyQuestion3();
		break;
	case 4: renderEasyQuestion4();
		break;
	case 5: renderEasyQuestion5();
		break;
	}
}

void rendercombatMedium()
{
	COORD c;
	for (int y = 0; y < 31; y++)
	{
		c.Y = y;
		for (int x = 0; x < 80; x++)
		{
			if (MapSize[x][y] == 'i')
			{
				MapSize[x][y] = ' ';
			}
			c.X = x;
			g_Console.writeToBuffer(c, MapSize[x][y]);
			if (MapSize[x][y] == '-')
			{
				g_Console.writeToBuffer(c, MapSize[x][y], 0x0C);
			}
		}
	}

	std::ostringstream ss;
	ss.str("");
	ss << (3 - Lifecounter) << "tries left";
	c.X = 42;
	c.Y = 4;
	g_Console.writeToBuffer(c, ss.str());

	switch (secondMediumRoll)
	{
	case 1: renderMediumQuestion1();
		break;
	case 2: renderMediumQuestion2();
		break;
	case 3: renderMediumQuestion3();
		break;
	case 4: renderMediumQuestion4();
		break;
	case 5: renderMediumQuestion5();
		break;
	}
}

void rendercombatHard()
{
	COORD c;
	for (int y = 0; y < 31; y++)
	{
		c.Y = y;
		for (int x = 0; x < 80; x++)
		{
			if (MapSize[x][y] == 'i')
			{
				MapSize[x][y] = ' ';
			}
			c.X = x;
			g_Console.writeToBuffer(c, MapSize[x][y]);
			if ((MapSize[x][y] == '-') || (MapSize[x][y] == '|'))
			{
				g_Console.writeToBuffer(c, MapSize[x][y], 0x0C);
			}
		}
	}

	std::ostringstream ss;
	ss.str("");
	ss << (3 - Lifecounter) << "tries left";
	c.X = 50;
	c.Y = 3;
	g_Console.writeToBuffer(c, ss.str());

	switch (secondHardRoll)
	{
	case 1: renderHardQuestion1();
		break;
	case 2: renderHardQuestion2();
		break;
	case 3: renderHardQuestion3();
		break;
	case 4: renderHardQuestion4();
		break;
	case 5: renderHardQuestion5();
		break;
	}
}