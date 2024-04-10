#include "World.h"

World::World()
{
	Room* startingRoom = new Room("Entrance", "A monumental iron door. Gives you the chills");
	entities.push_back(startingRoom);

	player = new Player("Lisan Al-Gaib", "Duque of Arrakis", startingRoom);
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

		if (argument[0].compare("describe") == 0)
		{
			player->Describe("");
			exists = true;
		}
	}
	else if (argument.size() > 1)
	{
		if (argument[0].compare("describe") == 0)
		{
			player->Describe(argument[1]);
			exists = true;
		}
	}

	return exists;
}