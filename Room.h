#pragma once

#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"
#include "Item.h"

class Room : public Entity
{
public:
	
	Room(string name, string description);
	void Describe() const;
	bool LookForExit(string direction, Entity* &nextRoom);
	list<string> GetExitDirections();

private:

};


#endif