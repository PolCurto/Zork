#pragma once

#ifndef CREATURE_H
#define CREATURE_H

#include "Entity.h";
#include "Room.h";
#include "Item.h";

class Creature : public Entity
{
public:
	
	Creature(const string name, const string description, Room* location);

	virtual void Tick();
	virtual void Describe();
	virtual void Move();
	virtual void PickUp();
	virtual void DropItem();


protected:
	Room* location;
};

#endif 
