#include "Npc.h"

Npc::Npc(const string name, const string description, Room* location, int hp, int attackDamage, int defense, int agility, float attackSpeed, string phrases[]) :
	Creature(name, description, location, hp, attackDamage, defense, agility, attackSpeed, 1)
{
	this->type = NPC;

	int size = sizeof(this->phrases) / sizeof(string);

	for (int i = 0; i < size; i++)
	{
		this->phrases[i] = phrases[i];
	}
	timeToMove = rand() % (20000 - 10000 + 1) + 10000;
}

void Npc::Tick()
{
	if (isDead) return;

	Creature::Tick();

	if (!isInCombat && clock() - lastMoveTime > timeToMove)
	{
		timeToMove = rand() % (20000 - 10000 + 1) + 10000;
		lastMoveTime = clock();
		Move();
	}
}

void Npc::Describe()
{
	if (isDead)
	{
		cout << "You can see the corpse of: " + name + " rotting in the ground\n";
	}
	else
	{
		cout << "You can see someone. It is " + name + ". " + description + '\n';
	}
}

void Npc::Move()
{
	if (isInCombat) return;

	//Triar direcció
	list<string> directions = location->GetExitDirections();
	list<string>::iterator it = directions.begin();

	int directionIndex = rand() % ((directions.size()-1) + 1);
	advance(it, directionIndex);

	bool isValid;
	Creature::Move((*it), isValid);
}

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

void Npc::Die()
{
	cout << "You have slain " +  + '\n';
	Creature::Die();
}