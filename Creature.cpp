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

void Creature::MoveItem(const string itemName, Item* item, Entity* oldParent, Entity* newParent)
{
	cout << "Try to pick / drop item: ";
	cout << itemName;
	cout << " from / to ";
	cout << oldParent->name + '\n';

	Entity* newItem;

	if (oldParent->TryGetChildByName(itemName, newItem) && newItem->type == ITEM)
	{
		cout << "New parent: ";
		cout << newParent->name + '\n';
		cout << "New item: ";
		cout << newItem->name + '\n';

		if (newParent == newItem)
		{
			cout << "You can't place an item inside itself! That would bend the rules of the unverse\n";
			return;
		}
		item = (Item*)newItem;
		item->ChangeParent(newParent);
	}
	else
	{
		cout << "There is no item called ";
		cout << itemName;
		cout << " in ";
		cout << oldParent->name + '\n';
	}
}