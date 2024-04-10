#pragma once
#ifndef CREATURE_H
#define CREATURE_H

#include "Entity.h";
#include <string>

using namespace std;

class Creature : Entity
{
public:
	
	Creature(const string name, const string description);

	virtual void Tick();


private:
	//Room* location;
};

#endif 
