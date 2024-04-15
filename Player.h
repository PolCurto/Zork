#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"

class Player : public Creature
{
public:

	Player(string name, string description, Room* location, int hp, int attackDamage, int defense, int agility, float attackSpeed, int equipmentSlots);

	void SayHello() const;
	void Describe(string target = "") const;
	void CheckInventory() const;
	void Move(string direction);
	void PickItem(string item, string source = "");
	void DropItem(string item, string destination = "");
	void Talk(string target) const;
	void Equip(string itemName);
	void AddEquipment(Item* item);
	void UnEquip(string itemName);
	void Use(string item);
	void CheckEquipment() const;
	void ModifyStats(const Item* item, bool add);
	void SetTarget(string targetName);
	void Die();
	bool IsLord() const;

private:
	bool isLord;
};

#endif