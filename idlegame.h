#ifndef IDLEGAME_H
#define IDLEGAME_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <array>
#include <fstream>
#include <iomanip>
#include <math.h>

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
string getTask(int & str,int & dex,int & intellect,int & cha,int & strxp,int & dexxp,int & intxp,int & chaxp,int & gold,int & totalxp, int & seconds);
void buyWep(string & weapon, int & gold);
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

string getTask(int & str,int & dex,int & intellect,int & cha,int & mag,int & strxp,int & dexxp,int & intxp,int & chaxp,int & magxp,int & gold, int & totalxp, int & seconds)
{
	string task;
	string stats[] = {"str","dex","int","cha","mag"};
	string stat = stats[rand() % 5];

	//Enemies
	const string adj[] = {"spooky","scary","big","sick","large","small","tall","fat","skinny","hungry","dying","strong","black","white","orange","red","yellow","green","blue","purple","grey","smart","stupid","fire","water","ice","wind","cold","angry","sad","insane","depressed","bleeding","evil","unholy","holy","crying","weeping","obese","massive","elder","ancient","old","young","baby","floppy","attractive","ugly","smelly","happy","chunky","grotesque","squishy","filthy","crimson","undead","ghostly","phantom","creepy","metal","tired","energetic","fast","slow","powerful","strong","weak","mighty","magnificent","courageous","cowardly","mini","round","limbless","armless","legless","headless","glowing","shiny","dancing","crawling","flying","magical","forest","swamp","cave","sewer","smoldering","burning","lonely","poor","starving","intelligent","soggy","hairy","bald","naked","female","male","droopy","grand","greater","lesser","muscular","wild","crazed","lazy","bruised","toothless","enraged","carnivorous","vengeful","aqua","prime","master","pale","enflamed","frozen","air","rock","stone","crippled","homeless"};
	const string enemies[] = {"skeleton","goblin","cow","warrior","zombie","imp","kobold","dwarf","elf","gnome","ooze","gremlin","orc","fairy","ghoul","wight","vampire","wolf","werewolf","wraith","wizard","warlock","lizard","snake","spider","rat","tiger","cougar","squid","frog","minotaur","barbarian","bandit","thief","golem","elemental","wisp","treant","hobbit","lion","gorilla","crab","knight","ogre","troll","turtle","slime","succubus","demon","ghost","midget","dragon","bat","mutant","sorcerer","sorceress","witch","drunkard","cannibal","man-eating plant","worm","alligator","crocodile","scorpion","beetle","monk","salesman","naga","moth","shade","genie","giant","parasite","dolphin","angel","mage","archon","assassin","bugbear","centaur","chimera","cockatrice","devil","ghast","gnome","gnoll","griffon","gargoyle","boar","wolverine","bear","dryad","harpy","kraken","gorgon","hag","hydra","hobgoblin","hippogriff","halfling","homunculus","satyr","leopard","lich","wasp","mantis","manticore","medusa","mummy","merfolk","mimic","nightmare","nymph","titan","troglodyte","triton","tarrasque","worg","owlbear","sphinx","spectre","rhino","child"};
	int level;
	if (stat == "str")
	{
		level = str;
	}
	else if (stat == "dex")
	{
		level = dex;
	}
	else if (stat == "int")
	{
		level = intellect;
	}
	else if (stat == "cha")
	{
		level = cha;
	}
	else if (stat == "mag")
	{
		level = mag;
	}

	int taskLevel = rand() % (level+9) + 1;
	string sTaskLevel = to_string(taskLevel);

	if (stat == "str")
	{
		strxp = strxp + taskLevel;
		levelCheck(strxp, str);
		string enemy = adj[rand()%(sizeof(adj)/sizeof(string))] + " " + enemies[rand()%(sizeof(enemies)/sizeof(string))];
		task = "Task: Killing level " + sTaskLevel + " " + string(enemy);
	}
	else if (stat == "dex")
	{
		dexxp = dexxp + taskLevel;
		levelCheck(dexxp, dex);
		task = "Task: Jogging " + sTaskLevel + " miles";
	}
	else if (stat == "int")
	{
		intxp = intxp + taskLevel;
		levelCheck(intxp, intellect);
		task = "Task: Mixing " + sTaskLevel + " potions";
	}
	else if (stat == "cha")
	{
		chaxp = chaxp + taskLevel;
		levelCheck(chaxp, cha);
		task = "Task: Talking to " + sTaskLevel + " people";
	}
	else if (stat == "mag")
	{
		magxp = magxp + taskLevel;
		levelCheck(magxp, mag);
		task = "Task: Summoning " + sTaskLevel + " creatures";
	}
	
	totalxp = totalxp + taskLevel;
	seconds = taskLevel - level;
	if (seconds < 1)
	{
		seconds = 1;
	}
	gold = gold + (rand()%taskLevel);
	return task;

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

void buyWep(string & weapon, int & gold)
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
