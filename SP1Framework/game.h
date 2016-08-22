#ifndef _GAME_H
#define _GAME_H

#include "Framework\timer.h"

extern CStopWatch g_swTimer;
extern bool g_bQuitGame;

// Enumeration to store the control keys that your game will have
enum EKEYS
{
    K_UP,
    K_DOWN,
    K_LEFT,
    K_RIGHT,
    K_ESCAPE,
    K_SPACE,
	K_LEFTCONTROL,
	K_ENTER,
    K_COUNT,

};

// Enumeration for the different screen states
enum EGAMESTATES
{
    S_SPLASHSCREEN,
	S_MENU,
    S_GAME,
	S_MAP1, S_MAP2, S_MAP3, S_MAP4, S_MAP5, S_MAP6, S_MAP7, S_MAP8, S_MAP9,
    S_COUNT,
	S_GUIDE,
	S_DICE, S_DICE1, S_DICE2, S_DICE3, S_DICE4, S_DICE5, S_DICE6,
};

// struct for the game character
struct SGameChar
{
    COORD m_cLocation;
    bool  m_bActive;
};

struct SGameEnemy
{
	COORD m_cLocation;
};
struct SGDICE
{
	COORD m_cLocation;
};
struct SGameBoss
{
	COORD m_cLocation;
};

void init        ( void );      // initialize your variables, allocate memory, etc
void getInput    ( void );      // get input from player
void update      ( double dt ); // update the game and the state of the game
void render      ( void );      // renders the current state of the game to the console
void shutdown    ( void );      // do clean up, free memory

void splashScreenWait();    // waits for time to pass in splash screen
void gameplay();            // gameplay logic
void moveCharacter();       // moves the character, collision detection, physics, etc
void processUserInput();    // checks if you should change states or do something else with the game, e.g. pause, exit
void clearScreen();         // clears the current screen and draw from scratch 
void renderSplashScreen();  // renders the splash screen
void renderGame();          // renders the game stuff
void renderMap();           // renders the map to the buffer first
void renderCharacter();     // renders the character into the buffer
void renderFramerate();     // renders debug information, frame rate, elapsed time, etc
void renderToScreen();      // dump the contents of the buffer to the screen, one frame worth of game
void guide();				// guide menu logic
void loadsplashscreen();

void rendermap1();
void rendermap2();
void rendermap3();
void rendermap4();
void rendermap5();
void rendermap6();
void rendermap7();
void rendermap8();
void rendermap9();

void loadsplashscreen();

void map1();
void map2();
void map3();
void map4();
void map5();
void map6();
void map7();
void map8();
void map9();

#endif // _GAME_H