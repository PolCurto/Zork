#pragma once

#ifndef ROOM_H
#define ROOM_H

#include "Entity.h";

class Room : public Entity
{
public:
	
	Room(const string name, const string description);
	void Describe();
	bool LookForExit(string direction, Room* &nextRoom);

private:

};


#endif