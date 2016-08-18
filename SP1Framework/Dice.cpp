#include "Dice.h"


string Dice()
{
	string result;
	int roll = rand() % 7 + 1;


	switch (roll)
	{
	case 1: result = "You rolled a one!";
		break;
	case 2: result = "You rolled a two!";
		break;
	case 3:result = "You rolled a three!";
		break;
	case 4:result = "You rolled a four!";
		break;
	case 5:result = "You rolled a five!";
		break;
	case 6: result = "You rolled a six!";
	}
	return result;
}