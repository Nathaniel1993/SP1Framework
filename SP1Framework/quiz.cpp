#include"quiz.h"
#include <fstream>
#include <sstream>
#include "loadfile.h"

extern bool encounter;
extern bool g_abKeyPressed[K_COUNT];
extern EGAMESTATES g_eGameState;
extern Console g_Console;

extern char easyQuiz[80][31];
extern char mediumQuiz[80][31];
extern char hardQuiz[80][31];

extern int Score;

int secondEasyRoll;
int secondMediumRoll;
int secondHardRoll;

int Lifecounter = 0;

bool questionConfirm = false;
bool quizTime = false;

void combatEasy()
{
	if (questionConfirm == true)
	{
		int EasyRoll;
		EasyRoll = rand() % 5 + 1;
		secondEasyRoll = EasyRoll;
		quizTime = true;
		questionConfirm = false;
	}

	if (quizTime == true)
	{
		loadquizEasy();

		if (Lifecounter == 0)
		{
			Score += 5;
		}
		else if (Lifecounter == 1)
		{
			Score += 3;
		}
		else if (Lifecounter == 2)
		{
			Score += 1;
		}
		else if (Lifecounter <= 3)
		{
			g_eGameState = S_DEFEAT;
			Lifecounter = 0;
		}

		quizTime = false;
	}
	switch (secondEasyRoll)
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
	encounter = false;
}

void combatMedium()
{
	if (questionConfirm == true)
	{
		int MediumRoll;
		MediumRoll = rand() % 5 + 1;
		secondMediumRoll = MediumRoll;
		quizTime = true;
		questionConfirm = false;
	}
	if (quizTime == true)
	{
		loadquizMedium();
		if (Lifecounter == 0)
		{
			Score += 10;
		}
		else if (Lifecounter == 1)
		{
			Score += 7;
		}
		else if (Lifecounter == 2)
		{
			Score += 5;
		}
		else if (Lifecounter <= 3)
		{
			g_eGameState = S_DEFEAT;
			Lifecounter = 0;
		}
		quizTime = false;
	}
	switch (secondMediumRoll)
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
	encounter = false;
}

void combatHard()
{
	if (questionConfirm == true)
	{
		int HardRoll;
		HardRoll = rand() % 5 + 1;
		secondHardRoll = HardRoll;
		quizTime = true;
		questionConfirm = false;
	}
	if (quizTime == true)
	{
		loadquizHard();
		if (Lifecounter == 0)
		{
			Score += 15;
		}
		else if (Lifecounter == 1)
		{
			Score += 12;
		}
		else if (Lifecounter == 2)
		{
			Score += 10;
		}
		else if (Lifecounter <= 3)
		{
			g_eGameState = S_DEFEAT;
			Lifecounter = 0;
		}
		quizTime = false;
	}
	switch (secondHardRoll)
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
	encounter = false;
}

void rendercombatEasy()
{
	COORD c;
	for (int y = 0; y < 31; y++)
	{
		c.Y = y;
		for (int x = 0; x < 80; x++)
		{
			if (easyQuiz[x][y] == 'i')
			{
				easyQuiz[x][y] = ' ';
			}
			c.X = x;
			g_Console.writeToBuffer(c, easyQuiz[x][y], 0x01);
			if (easyQuiz[x][y] == '-')
			{
				g_Console.writeToBuffer(c, easyQuiz[x][y], 0x0C);
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
			if (mediumQuiz[x][y] == 'i')
			{
				mediumQuiz[x][y] = ' ';
			}
			c.X = x;
			g_Console.writeToBuffer(c, mediumQuiz[x][y], 0x01);
			if (mediumQuiz[x][y] == '-')
			{
				g_Console.writeToBuffer(c, mediumQuiz[x][y], 0x0C);
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
			if (hardQuiz[x][y] == 'i')
			{
				hardQuiz[x][y] = ' ';
			}
			c.X = x;
			g_Console.writeToBuffer(c, hardQuiz[x][y], 0x01);
			if ((hardQuiz[x][y] == '-') || (hardQuiz[x][y] == '|'))
			{
				g_Console.writeToBuffer(c, hardQuiz[x][y], 0x0C);
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