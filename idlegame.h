#ifndef IDLEGAME_H
#define IDLEGAME_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <array>
#include <fstream>
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
void saveData(ofstream & outputFile, string & charName, string & className, int & xp, int & gold, int & level, int & nextLevel, string & weapon);
int getData(ifstream & inputFile, string & charName, string & className, int & xp, int & gold, int & level, int & nextLevel, string & weapon);


//Functions
int getData(ifstream & inputFile, string & charName, string & className, int & xp, int & gold, int & level, int & nextLevel, string & weapon)
{
	inputFile.open("idlegame.sav");
	if(!inputFile)
	{                   
		cout << "No save file found!" << endl;	
		sleep(2);
		clear();
		return 0;
	}
	
	string adjective = "default";
	inputFile >> charName;
	inputFile >> className;
	inputFile >> level;
	inputFile >> nextLevel;
	inputFile >> xp;
	inputFile >> gold;
	inputFile >> adjective;
	inputFile >> weapon;
	weapon = adjective + " " + weapon;
	return 1;
}


void saveData(ofstream & outputFile, string & charName, string & className, int & xp, int & gold, int & level, int & nextLevel, string & weapon)
{	
	outputFile.open("idlegame.sav");
	if(!outputFile)
	{
		cout << "Failed to create savegame!";
		sleep(5);
		clear();
	}
	outputFile << charName << " " <<className << " " << level << " " << nextLevel << " " << xp << " " << gold << " " << weapon << endl;
	outputFile.close();
	
}

void titleScreen(string title, string version)
{
	cout << title << endl;
	cout << "Version: " << version << endl;
	sleep(2);
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
