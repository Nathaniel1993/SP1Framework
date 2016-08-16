#include "Framework\timer.h"



struct SGameEnemy
{
	COORD m_cLocation;
	bool  m_bActive;
};

struct position 
{
	int x, y;
};
struct position move_towards(COORD enemy, COORD player);
bool in_range(struct position enemy, COORD player);
void renderEnemy();
void renderGame();