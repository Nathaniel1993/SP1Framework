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
	K_ONE, K_TWO, K_THREE, K_FOUR, K_FIVE,
	K_H, 
    K_COUNT,

};

// Enumeration for the different screen states
enum EGAMESTATES
{
    S_SPLASHSCREEN,
	S_MENU,
    S_GAME,
	S_GUIDE,
	S_DICE,
	S_QUIZEASY, S_QUIZMEDIUM, S_QUIZHARD,
	S_DEFEAT, S_VICTORY,
	S_HIGHSCORE,
	S_COUNT,
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
struct SGameTrap
{
	COORD m_cLocation;
};
struct AiBounceTime
{
	double aiBounceTime1;
	double bossBounceTime;
	double healthBounceTime;
	double bossHealthBounceTime;
	double trapTime;
	double easyQuizBounceTime;
	double medQuizBounceTime;
	double hardQuizBounceTime;
};

struct SGameKeys
{
	COORD m_cLocation;
	bool  m_bActive = true;
};
struct Teleporters
{
	COORD m_cLocation;
};
struct BoulderEndLocal
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

void renderSplashscreen();  // renders the splash screen
void renderGame();          // renders the game stuff
void renderMap();           // renders the map to the buffer first
void renderCharacter();     // renders the character into the buffer
void renderFramerate();     // renders debug information, frame rate, elapsed time, etc
void renderToScreen();      // dump the contents of the buffer to the screen, one frame worth of game

void renderKeys();
void renderPlayerTime();
void openDoor();
void BoulderIn();
void renderScore();
void renderSight();

#endif // _GAME_H