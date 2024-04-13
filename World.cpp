#include "World.h"
#include "Exit.h"
#include "Item.h"


World::World()
{
	// Rooms and exits
	Room* startingRoom = new Room("Entrance", "A monumental iron door. Gives you the chills");
	Room* forest = new Room("Dark forest", "You have never seen such an amount of trees together");
	entities.push_back(startingRoom);
	entities.push_back(forest);

	Exit* startToForest = new Exit("Green cave", "A rapid-changing mossy cave", startingRoom, forest, UP);
	Exit* forestToStart = new Exit("Purple hills", "Breathtaking heights, it's better to not look down", forest, startingRoom, DOWN);
	startingRoom->AddChild(startToForest);
	forest->AddChild(forestToStart);
	entities.push_back(startToForest);

	Room* dungeon = new Room("Dungeon Main Hall", "Darkness and algo everywhere the eye can reach");
	Exit* startToDungeon = new Exit("Tight Corridors", "Better not be claustrophobic", startingRoom, dungeon, RIGHT);
	Exit* dungeonToStart = new Exit("Wide Corridors", "Enough space for a deadly ambush", dungeon, startingRoom, LEFT);
	startingRoom->AddChild(startToDungeon);
	dungeon->AddChild(dungeonToStart);
	entities.push_back(dungeon);
	entities.push_back(startToDungeon);
	entities.push_back(dungeonToStart);

	Room* chamber = new Room("King's Chamber", "The kingdom's mightiest treasures gathered in a single room");
	Exit* dungeonToChamber = new Exit("Royal corridors", "You can smell the wealth of the place", dungeon, chamber, UP);
	Exit* chamberToDungeon = new Exit("Royal corridors", "You can smell the wealth of the place", chamber, dungeon, DOWN);
	Exit* forestToChamber = new Exit("Steep hill", "Drop yourself and pray to fall in a safe spot", forest, chamber, RIGHT);
	Exit* chamberToForest = new Exit("Secret passage", "Can't build a castle without it's secret exit", dungeon, forest, LEFT);
	dungeon->AddChild(dungeonToChamber);
	forest->AddChild(forestToChamber);
	chamber->AddChild(chamberToDungeon);
	chamber->AddChild(chamberToForest);
	entities.push_back(chamber);
	entities.push_back(dungeonToChamber);
	entities.push_back(chamberToDungeon);
	entities.push_back(forestToChamber);
	entities.push_back(chamberToForest);

	// Items
	Item* sword = new Item("Greatsword", "Better be strong to handle this blade", startingRoom);
	startingRoom->AddChild(sword);
	entities.push_back(sword);

	Item* pearl = new Item("Zenimyte", "Its magic powers everything in contact with its surface", forest);
	forest->AddChild(pearl);
	entities.push_back(pearl);

	Item* shield = new Item("Shield", "Can be used to take some hits, but won't last for long", dungeon);
	dungeon->AddChild(shield);
	entities.push_back(sword);

	Item* potion = new Item("Potion", "The king's last resource. Gives you a boost you have nefer experienced", chamber);
	chamber->AddChild(potion);
	entities.push_back(potion);


	// Player
	player = new Player("Godfrey", "The first Elden Lord", startingRoom);
	startingRoom->AddChild(player);
	entities.push_back(player);
}

void World::TickGame()
{
	//cout << "Tick\n";
	for (Entity* entity : entities)
	{
		entity->Tick();
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