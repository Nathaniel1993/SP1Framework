#include "Framework\timer.h"
#include "Framework\console.h"
#include "game.h"
#include "map.h"


extern Console g_Console;
extern SGameChar g_sChar;
//extern SGameEnemy g_sEnemy;
//extern SGameEnemy g_sEnemy2;
extern EnemyStruct Enemy;
extern AiBounceTime Bounce;
extern SGameBoss g_sBoss;
extern double g_dElapsedTime;
extern COORD c;
extern char MapSize[80][31];



void renderBoss();
void BossAi();

void Enemy1();
void Enemy2();
void Enemy3();
void Enemy4();
void Enemy5();
void Enemy6();

//void AiEnemy();
//void renderEnemy();
//void renderGame();
//void EnemyDetect();
//void init(void);