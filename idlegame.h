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
void buyWep(string & weapon, long & gold);
void levelUp(int & level, int & nextLevel, string weapon, int gold);

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

void buyWep(string & weapon, long & gold)
{
	//Items
	const string wepAdj[] = {"big","chaotic","large","small","short","strong","iron","black","white","orange","red","yellow","green","blue","purple","grey","steel","mithril","crystal","diamond","gold","silver","copper","stone","steel","floppy","sharp","brass","godly","demonic","legendary","little","ruby","emerald","sapphire","unbreakable","fragile","wood","wet","water","hot","burning","flame","thunder","lightning","cold","frozen","icy","wind","void","dark","broken","scratched","dirty","rusty","bent","dented","perfect","molten","pointy","dull","blunt","corrosive","ancient","old","rune","holy","unholy","golden","burnt","tasty","corrupted","glittering","shiny","fancy","expensive","mighty","powerful","The Magnificent","cheap","military","royal","bloody","deadly","brutal","adamantium","flawless","weak","angry","glowing","smelly","edible","phantom","slimy","sticky","jelly","moldy","poisonous","happy","sad","depressed","flat","stubby","stinky","light","heavy","invisible"};
	const string weapons[] = {"bucket","longsword","shortsword","dagger","hatchet","battleaxe","knife","spatula","rapier","spear","scimitar","lance","javelin","halberd","trident","whip","greatsword","cutlass","club","mace","morningstar","flail","hammer","war Pick","scythe","throwing axes","throwing knives","darts","sling","slingshot","voulge","staff","stick","knuckles","shortbow","crossbow","frying pan","mallet","blowgun","shiv","hook","shovel","rake","signpost","nunchucks","shuriken","katana","falchion","flamberge","sabre","bardiche","glaive","pike","gauntlets","fish","baguette","spoon","battle stool","gunblade","tiger claws","kris","stiletto","broadsword","bastard sword","master sword","mattock","pickaxe","broadaxe","tomahawk","wrench","rock","boomerang","pitchfork","spetum","partisan","harpoon","chakram","fishing pole","scepter","lamb chop","torch","garrote","machete","hoe","fence post","chair","lute","boot","shoe","longbow","composite bow","toothpick","gloves","goblet","midget","maul","platter","pot","horn","sheers"};

	weapon = wepAdj[rand()%(sizeof(wepAdj)/sizeof(string))] + " " + weapons[rand()%(sizeof(weapons)/sizeof(string))];
	int spent = (gold * (rand()%9 * 0.1) + 1);
	gold = gold - spent;
	clear();
	cout << "Bought a " << weapon << " for " << spent << " gold!" << endl;
	sleep(2);
}

void levelUp(int & level, string weapon, int gold)
{
	clear();
	level = level + 1;
	cout << "Leveled Up!" << endl;
	cout << "Weapon: " << weapon << endl;
	cout << "Gold: " << gold << endl;
	cout << "Task: Heading to the shops" << endl;
	sleep(2);
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
