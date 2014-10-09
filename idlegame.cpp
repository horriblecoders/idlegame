#include "idlegame.h"
#include "character.h"
using namespace std;

int main()
{	
	//
	string title = "Idlegame";
	string version = "0.0.3";
	srand (time(NULL)); //Seed
	ifstream inputFile;
	ofstream outputFile;
	Character c;
	int seconds = 0;
	int loopCount = 0;
	titleScreen(title, version);
	
	//Attempt to load game
	if(!c.getData(inputFile))
	{
		cout << "Enter your hero's name: ";
		getline(cin,c.charName);
		cout << "Enter your hero's race: ";
		getline(cin,c.raceName);
		cout << "Enter your hero's class: ";
		getline(cin, c.className);
		clear();
	}

	do
	{
		if (loopCount >= 10)
		{
			c.saveData(outputFile);
			loopCount = 0;
		}
		cout << "Name: " << c.charName << endl;
		cout << "Race: " << c.raceName << endl;
		cout << "Class: " << c.className << endl;
		cout << "Level: " << c.level << endl;
		cout << "Total XP: " << c.totalxp << endl;
		cout << "Weapon: " << c.weapon << endl;
		cout << "Gold: " << c.gold << endl;
		cout << "Str: " << c.str << endl;
		cout << "Dex: " << c.dex << endl;
		cout << "Int: " << c.intellect << endl;
		cout << "Cha: " << c.cha << endl;
		cout << "Magic: " << c.mag << endl;
		cout << loopCount << endl; //DELETE
		cout << getTask(c.str,c.dex,c.intellect,c.cha,c.mag,c.strxp,c.dexxp,c.intxp,c.chaxp,c.magxp,c.gold, c.totalxp, seconds) << endl;
		sleep(seconds);
		if (c.totalxp >= (pow(2,c.level)*10)) //Main Level Up
		{
			levelUp(c.level, c.weapon, c.gold);
			buyWep(c.weapon, c.gold);
			c.saveData(outputFile);
			clear();
		}
		
		clear();
		loopCount++;
	}
	while(1);
	return 0;
}
