#pragma once

#ifndef EXIT_H
#define EXIT_H

#include "Entity.h"
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

	Exit(const string name, const string description, Room* source, Room* destination, const ExitDirection forwardDirection, const ExitDirection backwardsDirection);
	bool IsValidDirection(string direction, Room* soruce);
	Entity* GetLinkedRoom(Entity* currentRoom);
	void Describe();
	Room* GetSource();
	Room* GetDestination();
	ExitDirection GetForwardDirection();
	ExitDirection GetBackwardsDirection();

private:
	ExitDirection forwardDirection;
	ExitDirection backwardsDirection;
	Room* source;
	Room* destination;
};

#endif 
