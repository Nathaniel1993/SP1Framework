#pragma once
#ifndef _COMPLETED_H
#define _COMEPLETED_H
#include <iostream>
#include "game.h"
#include "Framework\console.h"
using namespace std;
extern Console g_Console;
extern SGameChar g_sChar;
extern bool g_abKeyPressed[K_COUNT];
extern EGAMESTATES g_eGameState;
void checkcomplete();
#endif