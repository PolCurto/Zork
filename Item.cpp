#include "Item.h"

Item::Item(const string name, const string description, Entity* parent, int hp, int attackDamage, int defense, int agility, int equipmentSlots, ItemType itemType) : Entity(name, description)
{
	this->type = ITEM;
	this->parent = parent;
	this->hp = hp;
	this->attackDamage = attackDamage;
	this->defense = defense;
	this->agility = agility;
	this->equipmentSlots = equipmentSlots;
	this->itemType = itemType;
}

void Item::Describe()
{
	cout << name + ". " + description + '\n';
}

void Item::ChangeParent(Entity* newParent)
{
	Entity* oldParent;

	/*
	cout << "Old parent children size: ";
	cout << parent->GetAllChildren().size();
	cout << ". New parent children size: ";
	cout << newParent->GetAllChildren().size();
	cout << '\n';

	cout << name;
	cout << " old parent: ";
	cout << parent->name;
	*/

	parent->RemoveChild(this);
	oldParent = parent;
	parent = newParent;
	newParent->AddChild(this);

	/*
	cout << ". New parent: ";
	cout << parent->name;
	cout << '\n';

	cout << "Old parent children size: ";
	cout << oldParent->GetAllChildren().size();
	cout << ". New parent children size: ";
	cout << newParent->GetAllChildren().size();
	cout << '\n';
	*/
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

int Item::GetEquipmentSlots()
{
	return this->equipmentSlots;
}
