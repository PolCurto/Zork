#include "Exit.h"

Exit::Exit(const string name, const string description, Room* source, Room* destination, const ExitDirection forwardDirection, const ExitDirection backwardsDirection) : Entity(name, description)
{
	this->type = EXIT;
	this->source = source;
	this->destination = destination;
	this->forwardDirection = forwardDirection;
	this->backwardsDirection = backwardsDirection;
}

bool Exit::IsValidDirection(string direction, Room* source)
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

Room* Exit::GetSource()
{
	return source;
}

Room* Exit::GetDestination()
{
	return destination;
}

ExitDirection Exit::GetForwardDirection()
{
	return forwardDirection;
}

ExitDirection Exit::GetBackwardsDirection()
{
	return backwardsDirection;
}