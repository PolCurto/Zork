#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"

class Player : public Creature
{
public:

	Player(const string name, const string description, Room* location, int hp, int attackDamage, int defense, int agility, float attackSpeed, int equipmentSlots);

	void SayHello();
	void Describe(string target = "");
	void CheckInventory();
	void Move(string direction);
	void PickItem(string item, string source = "");
	void DropItem(string item, string destination = "");
	void Talk(string target);
	void Equip(string itemName);
	void AddEquipment(Item* item);
	void UnEquip(string itemName);
	void Use(string item);
	void CheckEquipment();
	void ModifyStats(Item* item, bool add);
	void SetTarget(string targetName);
	void Die();
	bool IsLord();

private:
	bool isLord;
};

#endif