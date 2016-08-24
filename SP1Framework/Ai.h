#include "Framework\timer.h"
#include "Framework\console.h"
#include "game.h"



extern Console g_Console;
extern SGameChar g_sChar;
//extern SGameEnemy g_sEnemy;
//extern SGameEnemy g_sEnemy2;
extern EnemyStruct Enemy;
extern AiBounceTime Bounce;
extern SGameBoss g_sBoss;
extern double g_dElapsedTime;
extern COORD c;
extern char mapSize[80][31];

void renderHealth();
void healthAi();

void renderBoss();
void BossAi();

void AiEnemy();
void AiEnemy2();
void AiEnemy3();
void AiEnemy4();
void AiEnemy5();
void AiEnemy6();

void renderEnemy();
void renderEnemy2();
void renderEnemy3();
void renderEnemy4();
void renderEnemy5();
void renderEnemy6();