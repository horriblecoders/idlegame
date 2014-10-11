#ifndef CHARACTER_H
#define CHARACTER_H

#include "idlegame.h"


class Character
{
	public:
		int getData(ifstream & inputFile);
		void saveData(ofstream & outputFile);
		void lvlUp(string skill);
		//In the future this will all be private:
		string charName = "Default";
		string raceName = "Human";		
		string className = "Battle Warlock";
		string weapon = "Fists";
		string special = "default"; //will be used in the future
		int level = 1;
		long gold = 10;
		int str = 0;
		long strxp = 0;
		int intellect = 0;
		long intxp = 0;
		int cha = 0;
		long chaxp = 0;
		int dex = 0;
		long dexxp = 0;
		int mag = 0;
		long magxp = 0;
		long totalxp = 0;
};

int Character::getData(ifstream & inputFile)
{
	inputFile.open("idlegame.sav");
	if(!inputFile)
	{                   
		cout << "No save file found!" << endl;	
		sleep(2);
		clear();
		return 0;
	}
	
	getline(inputFile, charName);
	getline(inputFile, raceName);		
	getline(inputFile, className);
	getline(inputFile, weapon);
	getline(inputFile, special);
	inputFile >> level;
	inputFile >> gold;
	inputFile >> str;
	inputFile >> strxp;
	inputFile >> intellect;
	inputFile >> intxp;
	inputFile >> cha;
	inputFile >> chaxp;
	inputFile >> dex;
	inputFile >> dexxp;
	inputFile >> mag;
	inputFile >> magxp;
	inputFile >> totalxp;
	return 1;
}

void Character::lvlUp(string skill)
{
	if (skill == "str")
			str++;
	else if (skill == "int")
			intellect++;
	else if (skill == "cha")
			cha++;
	else if (skill == "dex")
			dex++;
}


void Character::saveData(ofstream & outputFile)
{
	outputFile.open("idlegame.sav");
	if(!outputFile)
	{
		cout << "Failed to create savegame!";
		sleep(5);
		clear();
	}
	outputFile << charName << endl;
	outputFile << raceName << endl;	
	outputFile << className << endl;
	outputFile << weapon << endl;
	outputFile << special << endl;
	outputFile << level << endl;
	outputFile << gold << endl;
	outputFile << str << endl;
	outputFile << strxp << endl;
	outputFile << intellect << endl;
	outputFile << intxp << endl;
	outputFile << cha << endl;
	outputFile << chaxp << endl;
	outputFile << dex << endl;
	outputFile << dexxp << endl;
	outputFile << mag << endl;
	outputFile << magxp << endl;
	outputFile << totalxp << endl;
	outputFile.close();
}




#endif //CHARACTER_H
