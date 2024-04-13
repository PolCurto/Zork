#include "World.h"
#include "Exit.h"
#include "Item.h"
#include "Npc.h"


World::World()
{
	// Rooms and exits
	Room* startingRoom = new Room("Entrance", "A monumental iron door. Gives you the chills");
	Room* forest = new Room("Dark forest", "You have never seen such an amount of trees together");
	entities.push_back(startingRoom);
	entities.push_back(forest);

	Exit* startToForest = new Exit("Green cave", "A rapid-changing mossy cave", startingRoom, forest, UP, DOWN);
	startingRoom->AddChild(startToForest);
	forest->AddChild(startToForest);
	entities.push_back(startToForest);

	Room* dungeon = new Room("Dungeon Main Hall", "Darkness and algo everywhere the eye can reach");
	Exit* startToDungeon = new Exit("Tight Corridors", "Better not be claustrophobic", startingRoom, dungeon, RIGHT, LEFT);
	startingRoom->AddChild(startToDungeon);
	dungeon->AddChild(startToDungeon);
	entities.push_back(dungeon);
	entities.push_back(startToDungeon);

	Room* chamber = new Room("King's Chamber", "The kingdom's mightiest treasures gathered in a single room");
	Exit* dungeonToChamber = new Exit("Royal corridors", "You can smell the wealth of the place", dungeon, chamber, UP, DOWN);
	Exit* chamberToForest = new Exit("Secret passage", "Can't build a castle without it's secret exit", chamber, forest, LEFT, RIGHT);
	dungeon->AddChild(dungeonToChamber);
	forest->AddChild(chamberToForest);
	chamber->AddChild(dungeonToChamber);
	chamber->AddChild(chamberToForest);
	entities.push_back(chamber);
	entities.push_back(dungeonToChamber);
	entities.push_back(chamberToForest);

	// Items
	Item* sword = new Item("Greatsword", "Better be strong to handle this blade", startingRoom, 0, 20, 0, 0);
	startingRoom->AddChild(sword);
	entities.push_back(sword);

	Item* pearl = new Item("Zenimyte", "Its magic powers everything in contact with its surface", forest, 0, 10, 10, 0);
	forest->AddChild(pearl);
	entities.push_back(pearl);

	Item* shield = new Item("Shield", "Can be used to take some hits, but won't last for long", dungeon, 0, 0, 20, 0);
	dungeon->AddChild(shield);
	entities.push_back(sword);

	Item* potion = new Item("Potion", "The king's last resource. Gives you a boost you have nefer experienced", chamber, 20, 20, 20, 20);
	chamber->AddChild(potion);
	entities.push_back(potion);

	// Creatures
	player = new Player("Godfrey", "The first Elden Lord", startingRoom, 10, 2, 2, 2);
	startingRoom->AddChild(player);
	entities.push_back(player);

	
	string phrases[4] = {
		"Greetings " + player->name,
		"How do I know you name? I know many things... heheheh...",
		"I also know you are " + player->description,
		"Be careful " + player->name + ", may we find each other again... or not..."
	};

	Npc* oldMan = new Npc("Gideon", "His knowledge of the world is beyond human comprehension", forest, 4, 8, 1, 2, phrases);
	forest->AddChild(oldMan);
	entities.push_back(oldMan);

	phrases->clear();
	phrases[0] = "You must be brave to talk to me, stranger";
	phrases[1] = "This place is not even a glimpse of what it was in the golden days";
	phrases[2] = "Take all the equipment you find, you will most likely need it";
	phrases[3] = "See you again, fellow traveler";

	Npc* warrior = new Npc("Malenia", "She has never known defeat", dungeon, 15, 4, 4, 4, phrases);
	dungeon->AddChild(warrior);
	entities.push_back(warrior);
	
}

void World::TickGame()
{
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
			player->Inventory();
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