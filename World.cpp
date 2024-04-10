#include "World.h"

World::World()
{
	player = new Player("Lisan Al-Gaib", "Duque of Arrakis");
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

	if (argument[0].compare("hello") == 0 || argument[0].compare("Hello") == 0)
	{
		player->SayHello();
		exists = true;
	}

	return exists;
}