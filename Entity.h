#pragma once

#ifndef ENTITY_H
#define ENTITY_H

using namespace std;

#include <string>
#include <list>
#include <iostream>

enum EntityType
{
	CREATURE,
	PLAYER,
	ROOM,
	EXIT,
	ITEM
};

class Entity
{
public:

	Entity(const string name, const string description);
	virtual void Tick();
	virtual void Describe();

	list<Entity*> GetChildrenByType(EntityType type);
	void AddChild(Entity* newChild);

public:
	EntityType type;
	string name;
	string description;
	list<Entity*> children;
};

#endif
