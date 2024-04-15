#pragma once

#ifndef ENTITY_H
#define ENTITY_H

using namespace std;

#include <string>
#include <list>
#include <iostream>
#include <vector>

enum EntityType
{
	CREATURE,
	PLAYER,
	NPC,
	ROOM,
	EXIT,
	ITEM
};

class Entity
{
public:

	Entity(string name, string description);
	virtual void Tick();
	virtual void Describe() const;
	list<Entity*> GetChildrenByType(EntityType type);
	list<Entity*> GetAllChildren() const;
	bool TryGetChildByName(string name, Entity*& child);
	void AddChild(Entity* newChild);
	void RemoveChild(Entity* oldChild);
	virtual void ChangeParent(Entity* newParent);

public:
	EntityType type;
	string name;
	string description;
	list<Entity*> contains;
};

#endif
