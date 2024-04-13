#pragma once

#ifndef EXIT_H
#define EXIT_H

#include "Entity.h";
#include "Room.h"

enum ExitDirection
{
	UP,
	RIGHT,
	DOWN,
	LEFT
};

class Exit : public Entity
{
public:

	Exit(const string name, const string description, Room* source, Room* destination, const ExitDirection direction);
	bool IsValidDirection(string direction);
	Entity* GetLinkedRoom(Entity* currentRoom);
	void Describe();

private:
	ExitDirection direction;
	Room* source;
	Room* destination;
};

#endif 
