#include "World.h"
#include "Exit.h"
#include "Item.h"
#include "Npc.h"


World::World()
{
	/***Rooms and exits***/
	Room* entrance = new Room("Entrance", "A monumental iron door. Gives you the chills");
	Room* woods = new Room("Dark woods", "You have never seen such an amount of trees together");
	Exit* entranceToWoods = new Exit("Green cave", "A rapid-changing mossy cave", entrance, woods, UP, DOWN);
	entrance->AddChild(entranceToWoods);
	woods->AddChild(entranceToWoods);
	entities.push_back(entrance);
	entities.push_back(woods);
	entities.push_back(entranceToWoods);

	Room* hall = new Room("Castle main room", "Darkness and creep everywhere the eye can reach");
	Exit* entranceToHall = new Exit("Tight Corridors", "Better not be claustrophobic", entrance, hall, RIGHT, LEFT);
	entrance->AddChild(entranceToHall);
	hall->AddChild(entranceToHall);
	entities.push_back(hall);
	entities.push_back(entranceToHall);

	Room* chamber = new Room("King's chamber", "The kingdom's mightiest treasures gathered in a single room");
	Exit* hallToChamber = new Exit("Royal corridors", "You can smell the wealth of the place", hall, chamber, UP, DOWN);
	Exit* chamberToWoods = new Exit("Secret passage", "Can't build a castle without it's secret exit", chamber, woods, LEFT, RIGHT);
	hall->AddChild(hallToChamber);
	woods->AddChild(chamberToWoods);
	chamber->AddChild(hallToChamber);
	chamber->AddChild(chamberToWoods);
	entities.push_back(chamber);
	entities.push_back(hallToChamber);
	entities.push_back(chamberToWoods);

	Room* guest = new Room("Guest's room", "A place to rest for the lucky invited to the castle");
	Exit* entranceToGuest = new Exit("Broken hallways", "A modest series of hallways, now infected by the rot", entrance, guest, DOWN, UP);
	entrance->AddChild(entranceToGuest);
	guest->AddChild(entranceToGuest);
	entities.push_back(guest);
	entities.push_back(entranceToGuest);

	Room* lake = new Room("Poison lake", "This lake's precious water is long gone. Only filthy poison remains");
	Exit* woodsToLake = new Exit("Ogre's Swamp", "The legends says a green ogre lives in these lands", woods, lake, LEFT, RIGHT);
	woods->AddChild(woodsToLake);
	lake->AddChild(woodsToLake);
	entities.push_back(lake);
	entities.push_back(woodsToLake);

	Room* catacombs = new Room("Castle's catacombs", "Long ago it was a scary place. Now you wish it was only that");
	Exit* hallToCatacombs = new Exit("Deep staircase", "What a thrill", hall, catacombs, RIGHT, LEFT);
	hall->AddChild(hallToCatacombs);
	catacombs->AddChild(hallToCatacombs);
	entities.push_back(hall);
	entities.push_back(catacombs);


	/***Creatures***/
	// Player
	player = new Player("Godfrey", "The first Elden Lord", entrance, 10, 1, 1, 4, 1.5, 1);
	entrance->AddChild(player);
	entities.push_back(player);

	// Gideon
	string phrases[4] = {
		"Greetings " + player->name,
		"How do I know you name? I know many things... heheheh...",
		"I also know you are " + player->description,
		"Be careful " + player->name + ", may we find each other again... or not..."
	};

	Npc* gideon = new Npc("Gideon", "His knowledge of the world is beyond human comprehension", woods, 15, 8, 1, 3, 3, phrases);
	woods->AddChild(gideon);
	entities.push_back(gideon);

	// Malenia
	phrases->clear();
	phrases[0] = "You must be brave to talk to me, stranger";
	phrases[1] = "This place is not even a glimpse of what it was in the golden days";
	phrases[2] = "Take all the equipment you find, you will most likely need it";
	phrases[3] = "See you again, fellow traveler";

	Npc* malenia = new Npc("Malenia", "She has never known defeat", hall, 20, 5, 5, 20, 0.8f, phrases);
	hall->AddChild(malenia);
	entities.push_back(malenia);

	// Jesse
	phrases->clear();
	phrases[0] = "You shouldn't be here";
	phrases[1] = "Hell, I shouldn't be here either";
	phrases[2] = "Fight me if you want, but don't regret later";
	phrases[3] = "Go away";

	Npc* jesse = new Npc("Jesse", "Has spent a lifetime in the catacombs. He has probably lost it by now. He also used to cook", catacombs, 30, 15, 8, 10, 1, phrases);
	catacombs->AddChild(jesse);
	entities.push_back(jesse);

	/***Items***/
	Item* sword = new Item("Greatsword", "Better be strong to handle this blade", entrance, 0, 7, 0, -1, 1.5, 0, EQUIPMENT);
	entrance->AddChild(sword);
	entities.push_back(sword);

	Item* pearl = new Item("Zenimyte", "Its magic powers everything in contact with its surface", woods, 5, 2, 3, 0, 0, 0, EQUIPMENT);
	woods->AddChild(pearl);
	entities.push_back(pearl);

	Item* shield = new Item("Shield", "Can be used to take some hits, but won't last for long", hall, 0, 0, 6, -1, 0.5, 0, EQUIPMENT);
	hall->AddChild(shield);
	entities.push_back(sword);

	Item* potion = new Item("Potion", "The king's last resource. Gives you a boost you have never experienced", chamber, 10, 2, 2, 2, -0.2f, 0, CONSUMABLE);
	chamber->AddChild(potion);
	entities.push_back(potion);

	Item* bag = new Item("Bag", "A bag big enough to equip one more item", guest, 0, 0, 0, 0, 0, 1, CONSUMABLE);
	guest->AddChild(bag);
	entities.push_back(bag);

	Item* arkanioxys = new Item("Arkanioxys", "An ancient drink that lets you equip more items because an ancient reason. Also makes you feel better overall", gideon, 5, 2, 2, 2, 0, 1, CONSUMABLE);
	gideon->AddChild(arkanioxys);
	entities.push_back(arkanioxys);

	Item* dagger = new Item("Dagger", "A fast weapon built from prosthetic parts of a body. Malenia's favourite weapon", malenia, 0, 5, 0, 5, -0.5, 0, EQUIPMENT);
	malenia->AddChild(dagger);
	entities.push_back(dagger);

	Item* boots = new Item("Boots", "Wind-enhanced boots to do everything faster", lake, 0, 0, 0, 5, -0.3f, 0, EQUIPMENT);
	lake->AddChild(boots);
	entities.push_back(boots);

	Item* star = new Item("Star", "A real star fallen from the sky. Consume it and become lord of a new era", jesse, 0, 0, 0, 0, 0, 0, CONSUMABLE);
	jesse->AddChild(star);
	entities.push_back(star);
}


void World::TickGame()
{
	// Ticks all existing entities
	for (int i = 0; i < entities.size(); i++)
	{
		entities[i]->Tick();
	}
}

bool World::TranslateArgument(vector<string> argument)
{
	bool exists = false;

	if (argument.size() == 1)
	{
		if (argument[0].compare("hello") == 0 || argument[0].compare("Hello") == 0)
		{
			player->SayHello();
			exists = true;
		}
		else if (argument[0].compare("describe") == 0)
		{
			player->Describe();
			exists = true;
		}
		else if (argument[0].compare("move") == 0 || argument[0].compare("Move") == 0)
		{
			cout << "Where to?\n";
			exists = true;
		}
		else if (argument[0].compare("inventory") == 0 || argument[0].compare("Inventory") == 0)
		{
			player->CheckInventory();
			exists = true;
		}
		else if (argument[0].compare("equipment") == 0 || argument[0].compare("Equipment") == 0)
		{
			player->CheckEquipment();
			exists = true;
		}
	}
	else if (argument.size() == 2)
	{
		if (argument[0].compare("describe") == 0 || argument[0].compare("Describe") == 0)
		{
			player->Describe(argument[1]);
			exists = true;
		}
		else if (argument[0].compare("move") == 0 || argument[0].compare("Move") == 0)
		{
			player->Move(argument[1]);
			exists = true;
		}
		else if (argument[0].compare("pick") == 0 || argument[0].compare("Pick") == 0)
		{
			player->PickItem(argument[1]);
			exists = true;
		}
		else if (argument[0].compare("drop") == 0 || argument[0].compare("Drop") == 0)
		{
			player->DropItem(argument[1]);
			exists = true;
		}
		else if (argument[0].compare("equip") == 0 || argument[0].compare("Equip") == 0)
		{
			player->Equip(argument[1]);
			exists = true;
		}
		else if (argument[0].compare("unequip") == 0 || argument[0].compare("UnEquip") == 0)
		{
			player->UnEquip(argument[1]);
			exists = true;
		}
		else if (argument[0].compare("use") == 0 || argument[0].compare("Use") == 0)
		{
			player->Use(argument[1]);
			exists = true;
		}
		else if (argument[0].compare("attack") == 0 || argument[0].compare("Attack") == 0)
		{
			player->SetTarget(argument[1]);
			exists = true;
		}
	}
	else if (argument.size() == 3)
	{
		if ((argument[0].compare("talk") == 0 || argument[0].compare("Talk") == 0) && (argument[1].compare("to") == 0 || argument[1].compare("To") == 0))
		{
			player->Talk(argument[2]);
			exists = true;
		}
	}
	else if (argument.size() == 4)
	{
		if ((argument[0].compare("pick") == 0 || argument[0].compare("Pick") == 0) && (argument[2].compare("from") == 0 || argument[2].compare("From") == 0))
		{
			player->PickItem(argument[1], argument[3]);
			exists = true;
		}
		if ((argument[0].compare("drop") == 0 || argument[0].compare("Drop") == 0) && (argument[2].compare("to") == 0 || argument[2].compare("To") == 0))
		{
			player->DropItem(argument[1], argument[3]);
			exists = true;
		}
	}

	return exists;
}

bool World::PlayerIsDead() const
{
	return player->IsDead();
}

bool World::PlayerIsLord() const
{
	return player->IsLord();
}