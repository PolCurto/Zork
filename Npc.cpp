#include "Npc.h"

Npc::Npc(string name, string description, Room* location, int hp, int attackDamage, int defense, int agility, float attackSpeed, string phrases[]) :
	Creature(name, description, location, hp, attackDamage, defense, agility, attackSpeed, 1)
{
	this->timesTalked = 0;
	this->timeToMove = 0;
	this->lastMoveTime = 0;
	this->type = NPC;

	int size = sizeof(this->phrases) / sizeof(string);

	for (int i = 0; i < size; i++)
	{
		this->phrases[i] = phrases[i];
	}
	timeToMove = rand() % (60000 - 10000 + 1) + 10000;
}

/*
* Moves around every x seconds if it is not in combat
*/
void Npc::Tick()
{
	if (isDead) return;

	Creature::Tick();

	if (!isInCombat && clock() - lastMoveTime > timeToMove)
	{
		timeToMove = rand() % (60000 - 10000 + 1) + 10000;
		lastMoveTime = clock();
		Move();
	}
}

/*
* Prints the name and the description of the npc. If the npc is dead the
* message is modified
*/
void Npc::Describe() const
{
	if (isDead)
	{
		cout << "You can see the corpse of " + name + " rotting in the ground\n";
	}
	else
	{
		cout << "You can see someone. It is " + name + ". " + description + '\n';
	}
}

/*
* If not in combat, picks a random direction from the available ones and moves
* in that direction
*/
void Npc::Move()
{
	if (isInCombat) return;

	list<string> directions = location->GetExitDirections();
	list<string>::iterator it = directions.begin();

	int directionIndex = rand() % ((directions.size() - 1) + 1);
	advance(it, directionIndex);

	bool isValid;
	Creature::Move((*it), isValid);
}

/*
* Prints a dialogue phrase, depending on the amount of times the npc has already 
* talked. If dead or in combat, the phrase is modified
*/
void Npc::Talk()
{
	if (isDead)
	{
		cout << "Corpses do not talk";
		return;
	}

	if (isInCombat)
	{
		cout << name + ":\n    - ";
		cout << "mmph... gnygh... uurff...\n";
		return;
	}

	// Stay for longer if talked to
	lastMoveTime = clock();

	cout << name + ":\n    - ";
	cout << phrases[timesTalked];
	cout << '\n';

	timesTalked++;

	if (timesTalked > 3)
	{
		timesTalked = 1;
	}
}

/*
* Drops all the items to the current room and dies
*/
void Npc::Die()
{
	cout << "You have slain " + name + '\n';

	list<Entity*> items = GetAllChildren();
	list<Entity*>::iterator it;

	for (it = items.begin(); it != items.end(); it++)
	{
		if ((*it)->type == ITEM)
		{
			MoveItem((*it), location);
			cout << (*it)->name + " dropped from " + name + '\n';
		}
	}

	Creature::Die();
}