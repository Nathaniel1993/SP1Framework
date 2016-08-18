#include "Framework\timer.h"
#include "Framework\console.h"
#include "game.h"
#include "map.h"


extern Console g_Console;
extern SGameChar g_sChar;
extern SGameEnemy g_sEnemy;
extern COORD c;
extern char MapSize[80][31];
extern double aiTimeElapsed;
extern double aiBounceTime;
extern double aiDeltaTime;

void AiEnemy(struct SGameEnemy enemy);
void renderEnemy();
void renderEnemy2();
void renderGame();
void EnemyDetect();
//void init(void);