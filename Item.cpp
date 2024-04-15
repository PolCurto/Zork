#include "Item.h"

Item::Item(string name, string description, Entity* parent, int hp, int attackDamage, int defense, int agility, float attackSpeed, int equipmentSlots, ItemType itemType) : 
	Entity(name, description)
{
	this->parent = parent;
	this->hp = hp;
	this->attackDamage = attackDamage;
	this->defense = defense;
	this->agility = agility;
	this->attackSpeed = attackSpeed;
	this->equipmentSlots = equipmentSlots;
	this->itemType = itemType;

	this->type = ITEM;
}

/*
* Prints the item's name and description
*/
void Item::Describe() const
{
	cout << "Item named " + name + ". " + description + '\n';
}

/*
* Changes the item's parent to the given one, deleting itself from the old parent
*/
void Item::ChangeParent(Entity* newParent)
{
	parent->RemoveChild(this);
	parent = newParent;
	newParent->AddChild(this);
}

ItemType Item::GetItemType() const
{
	return this->itemType;
}

int Item::GetHp() const
{
	return this->hp;
}

int Item::GetAttackDamage() const
{
	return this->attackDamage;
}

int Item::GetDefense() const
{
	return this->defense;
}

int Item::GetAgility() const
{
	return this->agility;
}

float Item::GetAttackSpeed() const
{
	return this->attackSpeed;
}

int Item::GetEquipmentSlots() const
{
	return this->equipmentSlots;
}
