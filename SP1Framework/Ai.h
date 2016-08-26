#include "Framework\timer.h"
#include "Framework\console.h"
#include "game.h"



extern Console g_Console;
extern SGameChar g_sChar;
extern EnemyStruct Enemy;
extern SGameBoss g_sBoss;
extern COORD c;
extern COORD trap[9];
extern COORD Enemies[9];
extern char mapSize[80][31];
extern AiBounceTime Bounce;
extern double g_dElapsedTime;

void renderTrap(COORD a);
void trapSpawn();
void damageBoss();

void renderHealth();
void healthAi();

void renderBoss();
void BossAi();
void bossHealthAi();
void renderBossHealth();

void EnemiesAi(COORD Enemy);
void renderEnemies(COORD Enemy);
void enemiesSpawn1();
void enemiesSpawn2();

void trapTrigger();
void renderTrapTrigger(COORD a);

//void AiEnemy();
//void AiEnemy2();
//void AiEnemy3();
//void AiEnemy4();
//void AiEnemy5();
//void AiEnemy6();
//
//void renderEnemy();
//void renderEnemy2();
//void renderEnemy3();
//void renderEnemy4();
//void renderEnemy5();
//void renderEnemy6();