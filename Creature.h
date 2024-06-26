#pragma once

#ifndef CREATURE_H
#define CREATURE_H

#include "Entity.h"
#include "Room.h"

class Creature : public Entity
{
public:
	
	Creature(string name, string description, Room* location, int hp, int attackDamage, int defense, int agility, float attackSpeed, int equipmentSlots);

	virtual void Tick();
	virtual void Describe() const;
	virtual void Move(string direction, bool &valid);
	virtual void PickUp();
	virtual void DropItem();
	virtual void Talk();
	virtual void SetTarget(Creature* target);
	void Attack();
	void ReceiveAttack(int damage);
	virtual void Die();
	bool MoveItem(Entity* item, Entity* newParent);
	void ChangeParent(Entity* newParent);
	bool IsDead() const;


protected:
	Room* location;
	int maxHp;
	int currentHp;
	int attackDamage;
	int defense;
	int agility;
	float attackSpeed;
	int equipmentSlots;
	vector<Item*> equipment;

	Creature* target;
	bool isInCombat;
	clock_t lastAttack;
	bool isDead;
	
};

#endif 
