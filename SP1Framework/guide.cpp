#include "guide.h"

extern bool g_abKeyPressed[K_COUNT];
extern EGAMESTATES g_eGameState;
extern Console g_Console;

void guide()
{
	if (g_abKeyPressed[K_ESCAPE]) //going back to splashscreen upon 'esc' key
	{
		g_eGameState = S_SPLASHSCREEN;
	}
}

void renderguide()
{
	COORD l = g_Console.getConsoleSize();
	l.Y = 2;
	l.X = (g_Console.getConsoleSize().X / 2 - 13);
	g_Console.writeToBuffer(l, "Guide Manual for Beginners", 0x0B);
	l.Y = 3;
	l.X = (g_Console.getConsoleSize().X / 2 - 13);
	g_Console.writeToBuffer(l, "Press <Esc> to go back to Main Menu", 0x0B);
	l.Y = 5;
	l.X = 0;
	g_Console.writeToBuffer(l, "-----------------------------------Key Controls---------------------------------", 0x0A);
	l.Y = 7;
	l.X = 1;
	g_Console.writeToBuffer(l, "Left Arrow ------------------- Move Left", 0x0A);
	l.Y = 8;
	l.X = 1;
	g_Console.writeToBuffer(l, "Right Arrow ----------------- Move Right", 0x0A);
	l.Y = 9;
	l.X = 1;
	g_Console.writeToBuffer(l, "Up Arrow ----------------------- Move Up", 0x0A);
	l.Y = 10;
	l.X = 1;
	g_Console.writeToBuffer(l, "Down Arrow ------------------- Move Down", 0x0A);
	l.Y = 11;
	l.X = 1;
	g_Console.writeToBuffer(l, "Press <Space> to change Character Colour", 0x0A);
	l.Y = 13;
	l.X = 0;
	g_Console.writeToBuffer(l, "--------------------------------------------------------------------------------", 0x0A);

	l.Y = 15;
	l.X = 1;
	g_Console.writeToBuffer(l, "-----------------------------------How to Play---------------------------------", 0x0C);
	l.Y = 17;
	l.X = 1;
	g_Console.writeToBuffer(l, "Venture through the maze and find the 'X' endpoint", 0x0C);
	l.Y = 18;
	l.X = 1;
	g_Console.writeToBuffer(l, "Upon reaching 'X', you will be teleported to the boss room to fight the boss", 0x0C);
	l.Y = 19;
	l.X = 1;
	g_Console.writeToBuffer(l, "Lure the final boss into the hole of death to win the game!", 0x0C);
	l.Y = 20;
	l.X = 1;
	g_Console.writeToBuffer(l, "There will be enemy AI chasing the character when you are near one", 0x0C);
	l.Y = 21;
	l.X = 1;
	g_Console.writeToBuffer(l, "Upon contact or caught, roll the dice to determine difficulty of question", 0x0C);
	l.Y = 22;
	l.X = 1;
	g_Console.writeToBuffer(l, "For easy and medium difficulty questions, type the answer in the box provided", 0x0C);
	l.Y = 23;
	l.X = 1; 
	g_Console.writeToBuffer(l, "For hard questions, 5 choices is given, press the 1-5 keys to answer", 0x0C);
	l.Y = 24;
	l.X = 1;
	g_Console.writeToBuffer(l, "You have only 3 chances per question and 1 LIFE", 0x0C);
	l.Y = 25;
	l.X = 1;
	g_Console.writeToBuffer(l, "Failing to get the correct answer after 3 tries means GAME OVER!", 0x0C);
	l.Y = 27;
	l.X = 0;
	g_Console.writeToBuffer(l, "--------------------------------------------------------------------------------", 0x0C);
	l.Y = 28;
	l.X = (g_Console.getConsoleSize().X / 2 - 13);
	g_Console.writeToBuffer(l, "Good Luck and Have Fun", 0x0B);
}