#ifndef CHARACTER_H
#define CHARACTER_H

#include "idlegame.h"


class Character
{
	public:
		int getData(ifstream & inputFile);
		void saveData(ofstream & outputFile);
		void lvlUp(string skill);
		string getTask(int & seconds);
		void setSpecial();
		void displayStats();
		void bonusxp(string stat, int taskLevel);
		
		//This will be private in the future!
		string charName = "Default";
		string raceName = "Human";		
		string className = "Battle Warlock";
		string weapon = "Fists";
		string special = "default";
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

void Character::bonusxp(string stat, int taskLevel)
{
	int bonus = 50; //50% Bonus Xp
	bonus = int((bonus*.01)*taskLevel);
	if (stat == "str" && special == "str")
	{
		strxp = strxp + bonus;
	}
	else if (stat == "dex" && special == "dex")
	{
		dexxp = dexxp + bonus;
	}
	else if (stat == "int" && special == "int")
	{
		intxp = intxp + bonus;
	}
	else if (stat == "cha" && special == "cha")
	{
		chaxp = chaxp + bonus;
	}
	else if (stat == "mag" && special == "mag")
	{
		magxp = magxp + bonus;
	}
	
}

void Character::setSpecial()
{
	if (special == "default")
	{
		cout << "Which skill would you like to specialize in:" << endl;
		cout << "1) Strength" << endl;
		cout << "2) Magic" << endl;
		cout << "3) Dexterity" << endl;
		cout << "4) Intellect" << endl;
		cout << "5) Charisma" << endl;
		
		int input;
		cin >> input;
		
		switch(input)
		{
			case 1:
			special = "str";
			break;
			
			case 2:
			special = "mag";
			break;
			
			case 3:
			special = "dex";
			break;
			
			case 4:
			special = "int";
			break;
			
			case 5:
			special = "cha";
			break;
			
			default:
			clear();
			cout << "Please type the number and press enter" << endl;
			setSpecial();
		}
	}
	clear();
}

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
	else if (skill == "mag")
			mag++;
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

void Character::displayStats()
{
	cout << "Name: " << charName << endl;
	cout << "Race: " << raceName << endl;
	cout << "Class: " << className << endl;
	cout << "Level: " << level << endl;
	cout << "Total XP: " << fixed << setprecision(0) << totalxp << endl;
	cout << "XP to Level: " << fixed << setprecision(0) << ((pow(2,level)*10)-totalxp) << endl;
	cout << "Weapon: " << weapon << endl;
	cout << "Gold: " << fixed << setprecision(0) << gold << endl;
	cout << "Strength: " << str << endl;
	cout << "Magic: " << mag << endl;
	cout << "Dexterity: " << dex << endl;
	cout << "Intellect: " << intellect << endl;
	cout << "Charisma: " << cha << endl;
}

string Character::getTask(int & seconds)
{
	//Arrays
	const string adj[] = {"Spooky","Scary","Big","Sick","Large","Small","Tall","Fat","Skinny","Hungry","Dying","Strong","Black","White","Orange","Red","Yellow","Green","Blue","Purple","Grey","Smart","Stupid","Fire","Water","Ice","Wind","Cold","Angry","Sad","Insane","Depressed","Bleeding","Evil","Unholy","Holy","Crying","Weeping","Obese","Massive","Elder","Ancient","Old","Young","Baby","Floppy","Attractive","Ugly","Smelly","Happy","Chunky","Grotesque","Squishy","Filthy","Crimson","Undead","Ghostly","Phantom","Creepy","Metal","Tired","Energetic","Fast","Slow","Powerful","Strong","Weak","Mighty","Magnificent","Courageous","Cowardly","Mini","Round","Limbless","Armless","Legless","Headless","Glowing","Shiny","Dancing","Crawling","Flying","Magical","Forest","Swamp","Cave","Sewer","Smoldering","Burning","Lonely","Poor","Starving","Intelligent","Soggy","Hairy","Bald","Naked","Female","Male","Droopy","Grand","Greater","Lesser","Muscular","Wild","Crazed","Lazy","Bruised","Toothless","Enraged","Carnivorous","Vengeful","Aqua","Prime","Master","Pale","Enflamed","Frozen","Air","Rock","Stone","Crippled","Homeless"};
	const string enemies[] = {"Skeleton","Goblin","Cow","Warrior","Zombie","Imp","Kobold","Dwarf","Elf","Gnome","Ooze","Gremlin","Orc","Fairy","Ghoul","Wight","Vampire","Wolf","Werewolf","Wraith","Wizard","Warlock","Lizard","Snake","Spider","Rat","Tiger","Cougar","Squid","Frog","Minotaur","Barbarian","Bandit","Thief","Golem","Elemental","Wisp","Treant","Hobbit","Lion","Gorilla","Crab","Knight","Ogre","Troll","Turtle","Slime","Succubus","Demon","Ghost","Midget","Dragon","Bat","Mutant","Sorcerer","Sorceress","Witch","Drunkard","Cannibal","Man-eating Plant","Worm","Alligator","Crocodile","Scorpion","Beetle","Monk","Salesman","Naga","Moth","Shade","Genie","Giant","Parasite","Dolphin","Angel","Mage","Archon","Assassin","Bugbear","Centaur","Chimera","Cockatrice","Devil","Ghast","Gnome","Gnoll","Griffon","Gargoyle","Boar","Wolverine","Bear","Dryad","Harpy","Kraken","Gorgon","Hag","Hydra","Hobgoblin","Hippogriff","Halfling","Homunculus","Satyr","Leopard","Lich","Wasp","Mantis","Manticore","Medusa","Mummy","Merfolk","Mimic","Nightmare","Nymph","Titan","Troglodyte","Triton","Tarrasque","Worg","Owlbear","Sphinx","Spectre","Rhino","Child"};

	
	srand (time(NULL)); //Seed
	string taskString;
	string stats[] = {"str","dex","int","cha","mag"};
	string stat = stats[rand() % 5];
	int level;
	int subTask;
	
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
	string sTaskLevel = static_cast<ostringstream*>( &(ostringstream() << taskLevel) )->str();
	
	if (stat == "str")
	{
		const string building[] = {"A House","Walls","A Fort","A Castle","A Mailbox","An Outhouse","A Cottage","Boxes","Cabins","A Keep","Palisades","A Watchtower","Tower","An Asylum","A Brothel","A Bathhouse","Huts","Catapults","Ballistae","A Trebuchet","Battering Rams","A Well","Chairs","A Bottomless Pit","A Monument","A Seige Tower","Carts","Bridges","An Outpost","A Moat","An Orphanage","A Blood Altar","A Temple"};
		const string forging[] = {"Swords","Shields","A Mighty Artifact","Hammers","Hoes","Spears","Buckets","Axes","Greaves","Gauntlets","Helmets","Chainmail","Plate Armor","Spatulas","Shovels","Sharp Things","Widgets","Cutlery","Daggers","Knives","Chastity Belts","Bedpans","Torture Devices","Scale Mail","Steel Bars","Iron Bars","Golden Bars","Mithril Bars","Adamantium Bars","Cell Door","Chains","Shackels"};
		
		subTask = rand()%3;
		switch (subTask)
		{
			case 0:
			taskString = "Task: Building " + building[rand()%(sizeof(building)/sizeof(string))];
			break;
			
			case 1:
			taskString = "Task: Forging " + forging[rand()%(sizeof(forging)/sizeof(string))];
			break;
			
			default:
			taskString = "Task: Killing level " + sTaskLevel + " " + adj[rand()%(sizeof(adj)/sizeof(string))] + " " + enemies[rand()%(sizeof(enemies)/sizeof(string))];		
			break;
		}
		
		strxp = strxp + taskLevel;
		levelCheck(strxp, str);
	}
	else if (stat == "dex")
	{
		const string stealing[] = {"Purses","Wallets","Money Bags","Jewellery","Candy","Babies","Cattle","Candles","Handbags","Satchels","Veggies","Fruits","Bread","Furniture","Weapons","Clothes","Shoes","Kidneys","Sheep","Kittens","Puppies","Cutlery","Horses","Women","Wives","Husbands","Princesses","Treasure","Wagons","Boats","Names","Gems","Pants","Stolen Goods","Free Stuff","Chicken","Plants"};
		const string dancing[] = {"Nobles","Women","Men","Fairies","Gnomes","Goblins","A King","A Prince","A Princess","A Queen","A Jester","Midgets","No Pants","Passion","Villagers","Citizens","Merchants","A Hoe","Drunkards","A Duchess","A Duke","Homeless People","Farmers","Orcs","A Mayor","The Neighbors","Your Weapon","Nobody","A Dog","A Travelling Assassin","Your Best Friend","Your Nemesis","Your Family"};
		
		subTask = rand()%3;
		switch (subTask)
		{
			case 0:
			taskString = "Task: Attempting to steal " + stealing[rand()%(sizeof(stealing)/sizeof(string))];
			break;
			
			case 1:
			taskString = "Task: Dancing with " + dancing[rand()%(sizeof(dancing)/sizeof(string))];
			break;
			
			default:
			taskString = "Task: Hunting level " + sTaskLevel + " " + adj[rand()%(sizeof(adj)/sizeof(string))] + " " + enemies[rand()%(sizeof(enemies)/sizeof(string))];
			break;
		}
			
		dexxp = dexxp + taskLevel;
		levelCheck(dexxp, dex);

	}
	else if (stat == "int")
	{
		const string pondering[] = {"Life","Eggshells","Rain","Happiness","Poop","Midgets","Hoes","Pastries","Economics","The Future","The Past","Breakfast","Supper","Lunch","Fashion","Beliefs","Ideologies","Purpose","Hope","Gravity","Violence","Peace","Unity","Friendship","Hatred","Philosophy","Time","Death","Desire","Investments","Origins","Creation","Perspective","Chickens","Magnets","The Stars","The Sun","The Moon"};
		const string studying[] = {"Books","Tomes","Scrolls","Tablets","Novels","Languages"};
		const string learning[] = {"Languages","Midgets","Industry","Weaponry","Medicine","First Aid","History","Cooking","Trapping","Metallurgy","Baking","Cooking","Gardening","Smelting","Candle Making","Swimming","Addition","Subtraction","Integers","Significant Digits","Division","Multiplication","Spelling","Grammar","Plants","Brewing","Archery","Decapitation","Art","Music","Yodelling","Modelling","Pottery"};
		
		subTask = rand()%3;
		switch (subTask)
		{
			case 0:
			taskString = "Task: Pondering " + pondering[rand()%(sizeof(pondering)/sizeof(string))];
			break;
			
			case 1:
			taskString = "Task: Studying " + studying[rand()%(sizeof(studying)/sizeof(string))];
			break;
			
			default:
			taskString = "Task: Learning about " + learning[rand()%(sizeof(learning)/sizeof(string))];
			break;
		}
		intxp = intxp + taskLevel;
		levelCheck(intxp, intellect);
	}
	else if (stat == "cha")
	{
		const string negotiating[] = {"Peace","Better Prices","Contracts","Agreements","Treaties","Borders","Trades","Alliances","Trade pacts","Settlements","Tributes","Judgements","Services","Investments","Deposits","Payments","Fee","Taxes","Spending","Savings","Expenses","Losses","Gains","Defensive Pacts","Disarmaments","Sales","Profits","Employment","Salary","Marriages","Mergers","Unionization"};
		const string leading[] = {"Seige","Battle","Navy","Fleet","Battalion","Charge","Caravan","Trade Mission","Diplomatic Mission","Covert Mission","Research Effort","City Patrol","Party","Search","Cult","Blind Man","Village","City","Town","Country","Nation","Friend","Group","Expedition","Cave Exploration","New Settlement","Scouting Mission","Infiltration","Military Coupe","Rebellion","Heist","Massacre"};
		const string charming[] = {"Prince","King","Princess","Queen","Duke","Duchess","Lady","Man","Group of women","Group of men","Child","Friend","Mother","Daughter","Gremlin","Goblin","Orc","Ogre","Troll","Fat man","Mayor","Noble","Hoe","Midget","Rattlesnake","Homeless man","Brick wall","Mirror","Tree","Naga","Ostrich","Lion","Tiger","Ooze","Slime","Kobold","Merchant","Sailor","Captain","Knight","Admiral","Genie","Ghost"};
	
		subTask = rand()%3;
		switch (subTask)
		{
			case 0:
			taskString = "Task: Negotiating " + negotiating[rand()%(sizeof(negotiating)/sizeof(string))];
			break;
			
			case 1:
			taskString = "Task: Leading a " + leading[rand()%(sizeof(leading)/sizeof(string))];
			break;
			
			default:
			taskString = "Task: Charming a " + charming[rand()%(sizeof(charming)/sizeof(string))];
			break;
		}
		chaxp = chaxp + taskLevel;
		levelCheck(chaxp, cha);
	}
	else if (stat == "mag")
	{
		const string spell[] {"Fireball","Ice Bolt","Lightning Bolt","Chain Lightning","Ice Lance","Fire Blast","Magic Missle","Wind Bolt","Acid Arrow","Ray Of Frost","Acid Splash","Magical Barrier","Burning Hands","Shocking Grasp","Gust Of Wind","Scorching Ray","Shattering Blast","Invisibility","Magic Shield","Dancing Lights","Glitterdust","Mirror Image","Wind Wall","Sleet Storm","Ray Of Exhaustion","Flame Arrow","Vampiric Touch","Rage","Arcane Sight","Haste","Shrink Item","Fire Trap","Confusion","Wall Of Fire","Wall Of Ice","Teleport","Blight","Telekinesis","Acid Fog","Circle Of Death","Phase Door","Banish"};
		const string spellAdj[] =  {"Deadly","Magnificent","Godly","Weak","Mini","Minor","Major","Incredible","Useless","Sad","Happy","Crappy","Sexy","Hot","Cold","Chilly","Warm","Smelly","Tasty","Friendly","Unfriendly","Angry","Inverted","Wet","Droopy","Powerful","Midget's","Potent"};

		const string potion[] = {"Health Potion","Strength Potion","Magic Potion","Love Potion","Barkskin Potion","Health Elixir","Cough Potion","Vitamin Potion","Heartburn Potion","Poison","Speed Potion","Elixir of Immortality","Life Elixir","Death Elixir","Shrinking Potion","Growing Potion","Potion Of Blindness","Potion Of Sight","Potion Of Might","Potion Of Light","Potion Of Dark","Levitation Potion","Potion Of Flight"};
		const string potionAdj[] = {"Weak","Potent","Disgusting","Tasty","Yellow","Green","Pink","Purple","Blue","Black","White","Evil","Holy","Deadly","Enriched","Glowing","Hot","Warm","Sticky","Gooey","Thick","Evaporating","Cold","Chilly","Frozen","Lame","Bland","Transparent","Chunky"};

		subTask = rand()%3;
		switch (subTask)
		{
			case 0:
			taskString = "Task: Casting level " + sTaskLevel + " " + spellAdj[rand()%(sizeof(spellAdj)/sizeof(string))] + " " + spell[rand()%(sizeof(spell)/sizeof(string))];
			break;
			
			case 1:
			taskString = "Task: Brewing " + potionAdj[rand()%(sizeof(potionAdj)/sizeof(string))] + " " + potion[rand()%(sizeof(potion)/sizeof(string))];
			break;
			
			default:
			taskString = "Task: Summoning " + sTaskLevel + " " + adj[rand()%(sizeof(adj)/sizeof(string))] + " " + enemies[rand()%(sizeof(enemies)/sizeof(string))];
			break;
		}
		magxp = magxp + taskLevel;
		levelCheck(magxp, mag);
	}
	
	totalxp = totalxp + taskLevel;
	bonusxp(stat, taskLevel);
	seconds = taskLevel - level;
	if (seconds < 1)
	{
		seconds = 1;
	}
	gold = gold + (rand()%taskLevel);
	return taskString;

}


#endif //CHARACTER_H
