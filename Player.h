#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"
#include <string>

using namespace std;

class Player : Creature
{
public:

	Player(const string name, const string description);

	void SayHello();

private:

};


#endif