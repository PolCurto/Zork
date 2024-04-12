#pragma once

#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"

class Item : public Entity
{
public:

	Item(const string name, const string description, Entity* parent);
	void Describe();
	void ChangeParent(Entity* newParent);


private:
	Entity* parent;

};

#endif 
