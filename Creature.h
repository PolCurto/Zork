#pragma once

#ifndef CREATURE_H
#define CREATURE_H

#include "Entity.h";
#include "Room.h";

class Creature : public Entity
{
public:
	
	Creature(const string name, const string description, Room* location, int hp, int attackDamage, int defense, int agility);

	virtual void Tick();
	virtual void Describe();
	virtual void Move(string direction, bool &valid);
	virtual void PickUp();
	virtual void DropItem();
	virtual void Talk();
	void MoveItem(const string itemName, Entity* item, Entity* oldParent, Entity* newParen);
	void ChangeParent(Entity* newParent);


protected:
	Room* location;
	int hp;
	int attackDamage;
	int defense;
	int agility;
};

#endif 
