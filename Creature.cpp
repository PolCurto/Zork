#include "Creature.h"

Creature::Creature(const string name, const string description, Room* location) : Entity(name, description)
{
	this->location = location;
	this->type = CREATURE;
}

void Creature::Tick()
{

}

void Creature::Describe()
{
	cout << "Creature with name: " + name + ". " + description;
}

void Creature::Move()
{

}

void Creature::PickUp()
{

}

void Creature::DropItem()
{

}