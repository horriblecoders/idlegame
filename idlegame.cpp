#include "idlegame.h"
#include "character.h"
using namespace std;

int main()
{	
	//
	string title = "Idlegame";
	string version = "0.0.6";
	srand (time(NULL)); //Seed
	ifstream inputFile;
	ofstream outputFile;
	Character c;
	int seconds = 0;
	int loopCount = 0;
	titleScreen(title, version);
	
	//Attempt to load game
	c.getData(inputFile);
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
		if (c.getTotalxp() >= (pow(2,c.getLevel())*10)) //Main Level Up
		{
			c.levelUp();
			c.buyWep();
			c.saveData(outputFile);
			clear();
		}
		
		clear();
		loopCount++;
	}
	while(1);
	return 0;
}
