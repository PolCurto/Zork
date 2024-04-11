#include "World.h"
#include "Exit.h"

World::World()
{
	Room* startingRoom = new Room("Entrance", "A monumental iron door. Gives you the chills");
	Room* forest = new Room("Dark forest", "You have never seen such an amount of trees together");
	entities.push_back(startingRoom);
	entities.push_back(forest);

	Exit* startToForest = new Exit("Green cave", "A rapid-changing mossy cave", startingRoom, forest, UP);
	Exit* forestToStart = new Exit("Purple hills", "Breathtaking heights, it's better to not look down", forest, startingRoom, DOWN);
	startingRoom->AddChild(startToForest);
	forest->AddChild(forestToStart);
	entities.push_back(startToForest);

	player = new Player("Lisan Al-Gaib", "Duque of Arrakis", startingRoom);
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
			player->Describe("");
			exists = true;
		}
		else if (argument[0].compare("move") == 0 || argument[0].compare("Move") == 0)
		{
			cout << "Where to?\n";
			exists = true;
		}
	}
	else if (argument.size() > 1)
	{
		if (argument[0].compare("describe") == 0 || argument[0].compare("Describe") == 0)
		{
			player->Describe(argument[1]);
			exists = true;
		}
		else if (argument[0].compare("move") == 0 || argument[0].compare("Move") == 0)
		{
			player->Move(argument[1]);
			; exists = true;
		}
	}

	return exists;
}