#include "Exit.h"

Exit::Exit(const string name, const string description, Room* soruce, Room* destination, const ExitDirection direction) : Entity(name, description)
{
	this->source = source;
	this->destination = destination;
	this->direction = direction;
}