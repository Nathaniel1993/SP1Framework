#include <iostream>
#include "Framework\timer.h"
#include "game.h"
#include "Framework\console.h"
#include <fstream>

using namespace std;
extern char MapSize[80][31];
extern Console g_Console;
extern SGameChar g_sChar;
extern bool g_abKeyPressed[K_COUNT];
extern EGAMESTATES g_eGameState;