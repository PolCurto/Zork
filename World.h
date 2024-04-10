#pragma once

#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <string>
#include <iostream>
#include "Entity.h"
#include "Player.h"

using namespace std;

class World
{
public:

	World();

	void TickGame();
	bool TranslateArgument(vector<string> argument);

private:
	vector<Entity*> entities;

	// Direct reference to the player so every time there is an input it is not needed to look for him in the entities vector
	Player* player;
};

#endif
