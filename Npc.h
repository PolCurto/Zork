#pragma once

#ifndef NPC_H
#define NPC_H

#include "Creature.h"

class Npc : public Creature
{
public:

	Npc(const string name, const string description, Room* location, int hp, int attackDamage, int defense, int agility, float attackSpeed, string phrases[]);

	void Tick();
	void Describe();
	void Move();
	void Talk();
	void Die();

private:
	float timeToMove;
	float lastMoveTime;
	int timesTalked;
	string phrases[4];

};

#endif 

