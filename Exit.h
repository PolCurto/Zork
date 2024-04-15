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

	Exit(string name, string description, Room* source, Room* destination, ExitDirection forwardDirection, ExitDirection backwardsDirection);
	bool IsValidDirection(string direction, const Room* soruce) const;
	Entity* GetLinkedRoom(const Entity* currentRoom) const;
	void Describe() const;
	Room* GetSource() const;
	Room* GetDestination() const;
	ExitDirection GetForwardDirection() const;
	ExitDirection GetBackwardsDirection() const;

private:
	ExitDirection forwardDirection;
	ExitDirection backwardsDirection;
	Room* source;
	Room* destination;
};

#endif 
