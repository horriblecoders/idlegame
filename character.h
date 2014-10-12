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
	const string adj[] = {"spooky","scary","big","sick","large","small","tall","fat","skinny","hungry","dying","strong","black","white","orange","red","yellow","green","blue","purple","grey","smart","stupid","fire","water","ice","wind","cold","angry","sad","insane","depressed","bleeding","evil","unholy","holy","crying","weeping","obese","massive","elder","ancient","old","young","baby","floppy","attractive","ugly","smelly","happy","chunky","grotesque","squishy","filthy","crimson","undead","ghostly","phantom","creepy","metal","tired","energetic","fast","slow","powerful","strong","weak","mighty","magnificent","courageous","cowardly","mini","round","limbless","armless","legless","headless","glowing","shiny","dancing","crawling","flying","magical","forest","swamp","cave","sewer","smoldering","burning","lonely","poor","starving","intelligent","soggy","hairy","bald","naked","female","male","droopy","grand","greater","lesser","muscular","wild","crazed","lazy","bruised","toothless","enraged","carnivorous","vengeful","aqua","prime","master","pale","enflamed","frozen","air","rock","stone","crippled","homeless"};
	const string enemies[] = {"skeleton","goblin","cow","warrior","zombie","imp","kobold","dwarf","elf","gnome","ooze","gremlin","orc","fairy","ghoul","wight","vampire","wolf","werewolf","wraith","wizard","warlock","lizard","snake","spider","rat","tiger","cougar","squid","frog","minotaur","barbarian","bandit","thief","golem","elemental","wisp","treant","hobbit","lion","gorilla","crab","knight","ogre","troll","turtle","slime","succubus","demon","ghost","midget","dragon","bat","mutant","sorcerer","sorceress","witch","drunkard","cannibal","man-eating plant","worm","alligator","crocodile","scorpion","beetle","monk","salesman","naga","moth","shade","genie","giant","parasite","dolphin","angel","mage","archon","assassin","bugbear","centaur","chimera","cockatrice","devil","ghast","gnome","gnoll","griffon","gargoyle","boar","wolverine","bear","dryad","harpy","kraken","gorgon","hag","hydra","hobgoblin","hippogriff","halfling","homunculus","satyr","leopard","lich","wasp","mantis","manticore","medusa","mummy","merfolk","mimic","nightmare","nymph","titan","troglodyte","triton","tarrasque","worg","owlbear","sphinx","spectre","rhino","child"};

	
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
		const string building[] = {"a house","walls","a fort","a castle","a mailbox","an outhouse","a cottage","boxes","cabins","a keep","palisades","a watchtower","tower","an asylum","a brothel","a bathhouse","huts","catapults","ballistae","a trebuchet","battering rams","a well","chairs","a bottomless pit","a monument","a seige tower","carts","bridges","an outpost","a moat","an orphanage","a blood altar","a temple"};
		const string forging[] = {"swords","shields","a mighty artifact","hammers","hoes","spears","buckets","axes","greaves","gauntlets","helmets","chainmail","plate armor","spatulas","shovels","sharp things","widgets","cutlery","daggers","knives","chastity belts","bedpans","torture devices","scale mail","steel bars","iron bars","golden bars","mithril bars","adamantium bars","cell door","chains","shackels"};
		
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
		const string stealing[] = {"purses","wallets","money bags","jewellery","candy","babies","cattle","candles","handbags","satchels","veggies","fruits","bread","furniture","weapons","clothes","shoes","kidneys","sheep","kittens","puppies","cutlery","horses","women","wives","husbands","princesses","treasure","wagons","boats","names","gems","pants","stolen goods","free stuff","chicken","plants"};
		const string dancing[] = {"nobles","women","men","fairies","gnomes","goblins","a king","a prince","a princess","a queen","a jester","midgets","no pants","passion","villagers","citizens","merchants","a hoe","drunkards","a duchess","a duke","homeless people","farmers","orcs","a mayor","the neighbours","your weapon","nobody","a dog","a travelling assassin","your best friend","your nemesis","your family"};
		
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
		const string pondering[] = {"life","eggshells","rain","happiness","poop","midgets","hoes","pastries","economics","the future","the past","breakfast","supper","lunch","fashion","beliefs","ideologies","purpose","hope","gravity","violence","peace","unity","friendship","hatred","philosophy","time","death","desire","investments","origins","creation","perspective","chickens","magnets","the stars","the sun","the moon"};
		const string studying[] = {"books","tomes","scrolls","tablets","novels","languages"};
		const string learning[] = {"languages","midgets","industry","weaponry","medicine","first aid","history","cooking","trapping","metallurgy","baking","cooking","gardening","smelting","candle making","swimming","addition","subtraction","integers","significant digits","division","multiplication","spelling","grammar","plants","brewing","archery","decapitation","art","music","yodelling","modelling","pottery"};
		
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
		const string negotiating[] = {"peace","better prices","contracts","agreements","treaties","borders","trades","alliances","trade pacts","settlements","tributes","judgements","services","investments","deposits","payments","fee","taxes","spending","savings","expenses","losses","gains","defensive pacts","disarmaments","sales","profits","employment","salary","marriages","mergers","unionization"};
		const string leading[] = {"seige","battle","navy","fleet","battalion","charge","caravan","trade mission","diplomatic mission","covert mission","research effort","city patrol","party","search","cult","blind man","village","city","town","country","nation","friend","group","expedition","cave exploration","new settlement","scouting mission","infiltration","military coupe","rebellion","heist","massacre"};
		const string charming[] = {"prince","king","princess","queen","duke","duchess","lady","man","group of women","group of men","child","friend","mother","daughter","gremlin","goblin","orc","ogre","troll","fat man","mayor","noble","hoe","midget","rattlesnake","homeless man","brick wall","mirror","tree","naga","ostrich","lion","tiger","ooze","slime","kobold","merchant","sailor","captain","knight","admiral","genie","ghost"};
	
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
		const string spell[] {"fireball","ice bolt","lightning bolt","chain lightning","ice lance","fire blast","magic missle","wind bolt","acid arrow","ray of frost","acid splash","magical barrier","burning hands","shocking grasp","gust of wind","scorching ray","shattering blast","invisibility","magic shield","dancing lights","glitterdust","mirror image","wind wall","sleet storm","ray of exhaustion","flame arrow","vampiric touch","rage","arcane sight","haste","shrink item","fire trap","confusion","wall of fire","wall of ice","teleport","blight","telekinesis","acid fog","circle of death","phase door","banish"};
		const string spellAdj[] =  {"deadly","magnificent","godly","weak","mini","minor","major","incredible","useless","sad","happy","crappy","sexy","hot","cold","chilly","warm","smelly","tastY","friendly","unfriendly","angry","inverted","wet","droopy","powerful","midget's","potent"};

		const string potion[] = {"health potion","strength potion","magic potion","love potion","barkskin potion","health elixir","cough potion","vitamin potion","heartburn potion","poison","speed potion","elixir of immortality","life elixir","death elixir","shrinking potion","growing potion","potion of blindness","potion of sight","potion of might","potion of light","potion of dark","levitation potion","potion of flight"};
		const string potionAdj[] = {"weak","potent","disgusting","tasty","yellow","green","pink","purple","blue","black","white","evil","holy","deadly","enriched","glowing","hot","warm","sticky","gooey","thick","evaporating","cold","chilly","frozen","lame","bland","transparent","chunky"};

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
