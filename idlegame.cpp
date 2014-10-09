#include "idlegame.h"

using namespace std;

//Enemies
string adj[] = {"spooky","scary","big","sick","large","small","tall","fat","skinny","hungry","dying","strong","black","white","orange","red","yellow","green","blue","purple","grey","smart","stupid","fire","water","ice","wind","cold","angry","sad","insane","depressed","bleeding","evil","unholy","holy","crying","weeping","obese","massive","elder","ancient","old","young","baby","floppy","attractive","ugly","smelly","happy","chunky","grotesque","squishy","filthy","crimson","undead","ghostly","phantom","creepy","metal","tired","energetic","fast","slow","powerful","strong","weak","mighty","magnificent","courageous","cowardly","mini","round","limbless","armless","legless","headless","glowing","shiny","dancing","crawling","flying","magical","forest","swamp","cave","sewer","smoldering","burning","lonely","poor","starving","intelligent","soggy","hairy","bald","naked","female","male","droopy","grand","greater","lesser","muscular","wild","crazed","lazy","bruised","toothless","enraged","carnivorous","vengeful","aqua","prime","master","pale","enflamed","frozen","air","rock","stone","crippled"};
string enemies[] = {"skeleton","goblin","cow","warrior","zombie","imp","kobold","dwarf","elf","gnome","ooze","gremlin","orc","fairy","ghoul","wight","vampire","wolf","werewolf","wraith","wizard","warlock","lizard","snake","spider","rat","tiger","cougar","squid","frog","minotaur","barbarian","bandit","thief","golem","elemental","wisp","treant","hobbit","lion","gorilla","crab","knight","ogre","troll","turtle","slime","succubus","demon","ghost","midget","dragon","bat","mutant","sorcerer","sorceress","witch","drunkard","cannibal","man-eating plant","worm","alligator","crocodile","scorpion","beetle","monk","salesman","naga","moth","shade","genie","giant","parasite","dolphin","angel","mage","archon","assassin","bugbear","centaur","chimera","cockatrice","devil","ghast","gnome","gnoll","griffon","gargoyle","boar","wolverine","bear","dryad","harpy","kraken","gorgon","hag","hydra","hobgoblin","hippogriff","halfling","homunculus","satyr","leopard","lich","wasp","mantis","manticore","medusa","mummy","merfolk","mimic","nightmare","nymph","titan","troglodyte","triton","tarrasque","worg","owlbear","sphinx","spectre","rhino","homeless child"};

//Items
string wepAdj[] = {"big","chaotic","large","small","short","strong","iron","black","white","orange","red","yellow","green","blue","purple","grey","steel","mithril","crystal","diamond","gold","silver","copper","stone","steel","floppy","sharp","brass","godly","demonic","legendary","little","ruby","emerald","sapphire","unbreakable","fragile","wood","wet","water","hot","burning","flame","thunder","lightning","cold","frozen","icy","wind","void","dark","broken","scratched","dirty","rusty","bent","dented","perfect","molten","pointy","dull","blunt","corrosive","ancient","old","rune","holy","unholy","golden","burnt","tasty","corrupted","glittering","shiny","fancy","expensive","mighty","powerful","The Magnificent","cheap","military","royal","bloody","deadly","brutal","adamantium","flawless","weak","angry","glowing","smelly","edible","phantom","slimy","sticky","jelly","moldy","poisonous","happy","sad","depressed","flat","stubby","stinky","light","heavy","invisible"};
string weapons[] = {"bucket","longsword","shortsword","dagger","hatchet","battleaxe","knife","spatula","rapier","spear","scimitar","lance","javelin","halberd","trident","whip","greatsword","cutlass","club","mace","morningstar","flail","hammer","war Pick","scythe","throwing axes","throwing knives","darts","sling","slingshot","voulge","staff","stick","knuckles","shortbow","crossbow","frying pan","mallet","blowgun","shiv","hook","shovel","rake","signpost","nunchucks","shuriken","katana","falchion","flamberge","sabre","bardiche","glaive","pike","gauntlets","fish","baguette","spoon","battle stool","gunblade","tiger claws","kris","stiletto","broadsword","bastard sword","master sword","mattock","pickaxe","broadaxe","tomahawk","wrench","rock","boomerang","pitchfork","spetum","partisan","harpoon","chakram","fishing pole","scepter","lamb chop","torch","garrote","machete","hoe","fence post","chair","lute","boot","shoe","longbow","composite bow","toothpick","gloves","goblet","midget","maul","platter","pot","horn","sheers"};

int main()
{
	//
	string title = "Idlegame";
	string version = "0.0.2";
	
	
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
	titleScreen(title, version);
	
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
