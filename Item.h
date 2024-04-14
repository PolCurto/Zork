#pragma once

#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"

enum ItemType
{
	EQUIPMENT,
	CONSUMABLE
};

class Item : public Entity
{
public:

	Item(const string name, const string description, Entity* parent, int hp, int attackDamage, int defense, int agility, int equipmentSlots, ItemType itemType);
	void Describe();
	void ChangeParent(Entity* newParent);
	ItemType GetItemType();
	int GetHp();
	int GetAttackDamage();
	int GetDefense();
	int GetAgility();
	int GetEquipmentSlots();


private:
	Entity* parent;

	int hp;
	int attackDamage;
	int defense;
	int agility;
	int equipmentSlots;

	ItemType itemType;

};

#endif 
