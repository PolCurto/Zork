#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"

class Player : public Creature
{
public:

	Player(const string name, const string description, Room* location);

	void SayHello();
	void Describe(string target);
	void Move(string direction);
	void PickItem(string item, string source = "");
	void DropItem(Entity* source, string item);

private:

};

#endif