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

	Item(string name, string description, Entity* parent, int hp, int attackDamage, int defense, int agility, float attackSpeed, int equipmentSlots, ItemType itemType);
	void Describe() const;
	void ChangeParent(Entity* newParent);
	ItemType GetItemType() const;
	int GetHp() const;
	int GetAttackDamage() const;
	int GetDefense() const;
	int GetAgility() const;
	float GetAttackSpeed() const;
	int GetEquipmentSlots() const;


private:
	Entity* parent;

	int hp;
	int attackDamage;
	int defense;
	int agility;
	float attackSpeed;
	int equipmentSlots;

	ItemType itemType;

};

#endif 
