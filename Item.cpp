#include "Item.h"

Item::Item(const string name, const string description, Entity* parent, int hp, int attackDamage, int defense, int agility, float attackSpeed, int equipmentSlots, ItemType itemType) : 
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
void Item::Describe()
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

ItemType Item::GetItemType()
{
	return this->itemType;
}

int Item::GetHp()
{
	return this->hp;
}

int Item::GetAttackDamage()
{
	return this->attackDamage;
}

int Item::GetDefense()
{
	return this->defense;
}

int Item::GetAgility()
{
	return this->agility;
}

float Item::GetAttackSpeed()
{
	return this->attackSpeed;
}

int Item::GetEquipmentSlots()
{
	return this->equipmentSlots;
}
