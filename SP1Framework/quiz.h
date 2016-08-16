#ifndef _QUIZ_H
#define _QUIZ_H

#include <string>
#include <iostream>

using namespace std;

struct QuizQuestion
{
	string question;
	string answer1;
	string answer2;
};

struct QuizQuestion stQuestion[30];
void Quiz(void);
#endif