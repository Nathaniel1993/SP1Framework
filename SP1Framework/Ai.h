#include "Framework\timer.h"
#include "Framework\console.h"
#include "game.h"



extern Console g_Console;
extern SGameChar g_sChar;
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