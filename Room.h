#pragma once

#ifndef ROOM_H
#define ROOM_H

#include "Entity.h";
#include "Item.h";

class Room : public Entity
{
public:
	
	Room(const string name, const string description);
	void Describe();
	bool LookForExit(string direction, Room* &nextRoom);
	bool FindItem(string item, Item* newItem);

private:

};


#endif