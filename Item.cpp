#include "Item.h"

Item::Item(const string name, const string description, Entity* parent) : Entity(name, description)
{
	this->type = ITEM;
	this->parent = parent;
}

void Item::Describe()
{
	cout << name + ". " + description + '\n';
}