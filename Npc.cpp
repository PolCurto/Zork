#include "Npc.h"

Npc::Npc(const string name, const string description, Room* location, int hp, int attackDamage, int defense, int agility, string phrases[]) : 
	Creature(name, description, location, hp, attackDamage, defense, agility, 1)
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
	if (clock() - lastMoveTime > timeToMove)
	{
		timeToMove = rand() % (20000 - 10000 + 1) + 10000;
		lastMoveTime = clock();
		Move();
	}
}

void Npc::Describe()
{
	cout << "You can see someone. It is " + name + ". " + description + '\n';
}

void Npc::Move()
{
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