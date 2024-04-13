#include "Exit.h"

Exit::Exit(const string name, const string description, Room* source, Room* destination, const ExitDirection direction) : Entity(name, description)
{
	this->type = EXIT;
	this->source = source;
	this->destination = destination;
	this->direction = direction;
	//new Exit(name, description, chamber, dungeon, DOWN);
}

bool Exit::IsValidDirection(string direction)
{
	if (direction.compare("up") == 0 || direction.compare("Up") == 0)
	{
		if (this->direction == UP) return true;
		else return false;
	}
	else if (direction.compare("right") == 0 || direction.compare("Right") == 0)
	{
		if (this->direction == RIGHT) return true;
		else return false;
	}
	else if (direction.compare("down") == 0 || direction.compare("Down") == 0)
	{
		if (this->direction == DOWN) return true;
		else return false;
	}
	else if (direction.compare("left") == 0 || direction.compare("Left") == 0)
	{
		if (this->direction == LEFT) return true;
		else return false;
	}

	return false;
}

// Returns the room linked to the one given
Entity* Exit::GetLinkedRoom(Entity* currentRoom)
{
	if (currentRoom == source)
	{
		//cout << "It is source\n";
		return destination;
	}
	else
	{
		//cout << "It is destination\n";
		return source;
	}

	//cout << "It is nothing\n";
}

void Exit::Describe()
{
	cout << name;
	cout << ". ";
	cout << description;
	cout << ". Connects ";
	cout << source->name;
	cout << " with ";
	cout << destination->name + '\n';
}