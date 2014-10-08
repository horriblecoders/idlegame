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
void saveData(ofstream & outputFile, string & charName, string & className, int & xp, int & gold, int & level, int & nextLevel, string & weapon);
int getData(ifstream & inputFile, string & charName, string & className, int & xp, int & gold, int & level, int & nextLevel, string & weapon);


//Enemies
string adj[] = {"spooky","scary","big","sick","large","small","tall","fat","skinny","hungry","dying","strong","black","white","orange","red","yellow","green","blue","purple","grey","smart"};
string enemies[] = {"monster","skeleton","goblin","cow","warrior","zombie","imp"};

//Items
string wepAdj[] = {"big","chaotic","large","small","short","strong","iron","black","white","orange","red","yellow","green","blue","purple","grey","steel","mithril","crystal","diamond","gold","silver","copper","stone"};
string weapons[] = {"bucket","longsword","shortsword","dagger","hatchet","battleaxe","knife","spatula","rapier","spear","scimitar","lance","javelin","halberd","trident","whip","greatsword","cutlass","club","mace","morningstar","flail","hammer","war Pick","scythe","throwing axes","throwing knives","darts","sling","slingshot","voulge","staff","stick","knuckles","shortbow","crossbow","frying pan","mallet","blowgun","shiv","hook","shovel","rake","signpost","nunchucks","shuriken","katana","falchion","flamberge","sabre""bardiche","glaive","pike","gauntlets","fish","baguette","spoon","battle stool","gunblade","tiger claws","kris","stiletto","broadsword","bastard sword","master sword","mattock","pickaxe","broadaxe","tomahawk","wrench","rock","boomerang","pitchfork","spetum","partisan","harpoon","chakram","fishing pole","scepter","lamb chop","torch","garrote","machete","hoe","fence post","chair","lute","boot","shoe","longbow","composite bow","toothpick","gloves","goblet","midget","maul","platter","pot","horn","sheers"};

int main()
{
	//Start
	srand (time(NULL)); //Seed
	ifstream inputFile;
	ofstream outputFile;
	int level = 1;
	int xp = 0;
	int nextLevel = 10;
	int gold = 10;
	string className = "Human";
	string charName = "Default";
	string weapon = "Fists";
	int enemyLevel = rand() % (level+9) + 1;
	
	//Attempt to load game
	if (!getData(inputFile, charName, className, xp, gold, level, nextLevel, weapon))
	{
		cout << "Enter your hero's name: ";
		cin >> charName;
		cout << "Enter your hero's race: ";
		cin >> className;
	}

	do
	{
		string enemy = adj[rand()%(sizeof(adj)/sizeof(string))] + " " + enemies[rand()%(sizeof(enemies)/sizeof(string))];
		cout << "Name: " << charName << endl;
		cout << "Class: " << className << endl;
		cout << "Level: " << level << endl;
		cout << "Xp to next level: " << nextLevel - xp << "\n";
		cout << "Weapon: " << weapon << "\n";
		cout << "Gold: " << gold << "\n";
		cout << "Task: Killing level " << enemyLevel << " " << enemy << "\n";
		int seconds = enemyLevel - level;
		if (seconds < 1)
		{
			seconds = 1;
		}
		sleep(seconds);
		xp = xp + enemyLevel;
		if (xp >= nextLevel){
			//Level Up!
			level = level + 1;
			nextLevel = nextLevel * 2;
			
			//Head to shops
			clear();
			cout << "Leveled Up!" << endl;
			cout << "Weapon: " << weapon << endl;
			cout << "Gold: " << gold << endl;
			cout << "Task: Heading to the shops" << endl;
			sleep(2);
			
			//Buy Weapon
			weapon = wepAdj[rand()%(sizeof(wepAdj)/sizeof(string))] + " " + weapons[rand()%(sizeof(weapons)/sizeof(string))];
			int spent = (gold * (rand()%9 * 0.1) + 1);
			gold = gold - spent;
			clear();
			cout << "Bought a " << weapon << " for " << spent << " gold!" << endl;
			sleep(2);
			
			//Save Game
			saveData(outputFile, charName, className, xp, gold, level, nextLevel, weapon);
			
		}
		clear();
		enemyLevel = (rand()%(level+9) + 1);
		gold = gold + (rand()%enemyLevel);
	}
	while(1);
	return 0;
}

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

void sleep(int seconds)
{
	#if defined(_WIN32)
		Sleep(seconds * 1000);
	#else
		std::this_thread::sleep_for(std::chrono::milliseconds(seconds * 1000));
	#endif
}
