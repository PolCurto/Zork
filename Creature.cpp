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

void Creature::Talk()
{

}

void Creature::MoveItem(const string itemName, Entity* item, Entity* oldParent, Entity* newParent)
{
	cout << "Try to pick / drop item: ";
	cout << itemName;
	cout << " from / to ";
	cout << oldParent->name + '\n';

	if (oldParent->TryGetChildByName(itemName, item) && item->type == ITEM)
	{
		cout << "New parent: ";
		cout << newParent->name + '\n';
		cout << "New item: ";
		cout << item->name + '\n';

		if (newParent == item)
		{
			cout << "You can't place an item inside itself! That would bend the rules of the unverse\n";
			return;
		}
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