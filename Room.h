#pragma once

#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"
#include "Item.h"

class Room : public Entity
{
public:
	
	Room(const string name, const string description);
	void Describe();
	bool LookForExit(string direction, Entity* &nextRoom);
	list<string> GetExitDirections();

private:

};


#endif