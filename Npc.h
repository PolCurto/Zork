#pragma once

#ifndef NPC_H
#define NPC_H

#include "Creature.h"

class Npc : public Creature
{
public:

	Npc(string name, string description, Room* location, int hp, int attackDamage, int defense, int agility, float attackSpeed, string phrases[]);

	void Tick();
	void Describe() const;
	void Move();
	void Talk();
	void Die();

private:
	int timeToMove;
	clock_t lastMoveTime;
	int timesTalked;
	string phrases[4];
};

#endif 

