#include "idlegame.h"
#include "character.h"
using namespace std;

int main()
{	
	//
	string title = "Idlegame";
	string version = "0.0.5";
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
	c.setSpecial();
	c.saveData(outputFile);
	do
	{
		if (loopCount >= 10)
		{
			c.saveData(outputFile);
			loopCount = 0;
		}
		c.displayStats();
		cout << c.getTask(seconds) << endl;
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
