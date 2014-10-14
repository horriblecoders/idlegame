#ifndef IDLEGAME_H
#define IDLEGAME_H

#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <array>
#include <fstream>
#include <math.h>
#include <iomanip>

//Horrible cross platform clear screen
#if defined(_WIN32)
	#define COMMAND "cls" //Clears a windows console screen
	#include <windows.h>
#else
	#define COMMAND "clear" //Clears a linux console screen
	#include <chrono>
	#include <thread>
#endif
#define clear() system( COMMAND )

using namespace std;

//Prototypes
void sleep(int seconds);
void titleScreen(string title, string version);
bool levelCheck(int statxp, int & statLevel);

//Functions

bool levelCheck(int statxp, int & statLevel)
{
	int nextLevel = (pow(2,statLevel)*10);
	if (statxp >= nextLevel)
	{
		statLevel++;
		return true;
	}
	else
	{
		return false;
	}
	
}

void titleScreen(string title, string version)
{
	cout << title << endl;
	cout << "Version: " << version << endl;
	cout << "Press enter to continue" << endl;
	string input;
	getline(cin, input);
	clear();
	
}

void sleep(int seconds)
{
	#if defined(_WIN32)
		Sleep(seconds * 1000);
	#else
		std::this_thread::sleep_for(std::chrono::milliseconds(seconds * 1000));
	#endif
}

#endif //IDLEGAME_H
