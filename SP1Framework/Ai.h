#include "Framework\timer.h"
#include "Framework\console.h"
#include "game.h"
#include "map.h"


extern Console g_Console;
extern SGameChar g_sChar;
extern SGameEnemy g_sEnemy;
extern SGameEnemy g_sEnemy2;
extern SGameBoss g_sBoss;
extern double g_dElapsedTime;
extern COORD c;
extern char MapSize[80][31];

extern double aiBounceTime1;
extern double aiBounceTime2;
extern double bossBounceTime;


void renderBoss();
void BossAi();

void AiEnemy();
void renderEnemy();
void renderGame();
//void EnemyDetect();
//void init(void);