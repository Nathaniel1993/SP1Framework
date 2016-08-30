#ifndef _HighScore_h
#define _HighScore_h

#include <iostream>
#include "Framework\console.h"
#include <fstream>
#include <string>
#include "RenderHighScore.h"
#include "game.h"

using namespace std;

void HighScore(string Time, string Points);

extern int Score;
#endif