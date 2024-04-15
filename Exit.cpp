#include "Exit.h"

Exit::Exit(string name, string description, Room* source, Room* destination, const ExitDirection forwardDirection, const ExitDirection backwardsDirection) : 
	Entity(name, description)
{
	this->source = source;
	this->destination = destination;
	this->forwardDirection = forwardDirection;
	this->backwardsDirection = backwardsDirection;

	this->type = EXIT;
}

/*
* Checks whether the given direction is valid or not, taking into account
* the source room as it swaps the exit directions
*/
bool Exit::IsValidDirection(string direction, const Room* source) const
{
	if (direction.compare("up") == 0 || direction.compare("Up") == 0)
	{
		if (source == this->source)
		{
			if (this->forwardDirection == UP) return true;
			else return false;
		}
		else
		{
			if (this->backwardsDirection == UP) return true;
			else return false;
		}
	}
	else if (direction.compare("right") == 0 || direction.compare("Right") == 0)
	{
		if (source == this->source)
		{
			if (this->forwardDirection == RIGHT) return true;
			else return false;
		}
		else
		{
			if (this->backwardsDirection == RIGHT) return true;
			else return false;
		}
	}
	else if (direction.compare("down") == 0 || direction.compare("Down") == 0)
	{
		if (source == this->source)
		{
			if (this->forwardDirection == DOWN) return true;
			else return false;
		}
		else
		{
			if (this->backwardsDirection == DOWN) return true;
			else return false;
		}
	}
	else if (direction.compare("left") == 0 || direction.compare("Left") == 0)
	{
		if (source == this->source)
		{
			if (this->forwardDirection == LEFT) return true;
			else return false;
		}
		else
		{
			if (this->backwardsDirection == LEFT) return true;
			else return false;
		}
	}

	return false;
}

/*
* Returns the room linked to the ongiven by value
*/
Entity* Exit::GetLinkedRoom(const Entity* currentRoom) const
{
	if (currentRoom == source)
	{
		return destination;
	}
	else
	{
		return source;
	}
}

/*
* Prints the exit name, description and the rooms it connects
*/
void Exit::Describe() const
{
	cout << name;
	cout << ". ";
	cout << description;
	cout << ". Connects ";
	cout << source->name;
	cout << " with ";
	cout << destination->name + '\n';
}
 
Room* Exit::GetSource() const
{
	return source;
}

Room* Exit::GetDestination() const
{
	return destination;
}

ExitDirection Exit::GetForwardDirection() const
{
	return forwardDirection;
}

ExitDirection Exit::GetBackwardsDirection() const
{
	return backwardsDirection;
}