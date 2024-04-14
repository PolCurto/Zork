#include "Room.h"
#include "Exit.h"

Room::Room(const string name, const string description) : Entity(name, description)
{

}

/*
* Prints the room's name and description
*/
void Room::Describe()
{
	cout << "You are in " + name + ". " + description + '\n';
}

/*
* Checks if an exit exists in the given direction. If it does, stores
* the room it connects to in a referenced variable
*/
bool Room::LookForExit(string direction, Entity* &nextRoom)
{
	list<Entity*> exits = GetChildrenByType(EXIT);
	list<Entity*>::iterator it;

	for (it = exits.begin(); it != exits.end(); it++)
	{
		Exit* exit = (Exit*)(*it);

		if (exit->IsValidDirection(direction, this))
		{
			nextRoom = exit->GetLinkedRoom(this);
			return true;
		}
	}

	return false;
}

/*
* Gets all the available exit directions from this room
*/
list<string> Room::GetExitDirections()
{
	list<string> directions;

	list<Entity*> exits = GetChildrenByType(EXIT);
	list<Entity*>::iterator it;
	for (it = exits.begin(); it != exits.end(); it++)
	{
		Exit* exit = (Exit*)(*it);

		if (exit->GetSource() == this)
		{
			switch (exit->GetForwardDirection())
			{
				case UP:
					directions.push_back("up");
					break;
				case RIGHT:
					directions.push_back("right");
					break;
				case DOWN:
					directions.push_back("down");
					break;
				case LEFT:
					directions.push_back("left");
					break;
			}
		}
		else
		{
			switch (exit->GetBackwardsDirection())
			{
				case UP:
					directions.push_back("up");
					break;
				case RIGHT:
					directions.push_back("right");
					break;
				case DOWN:
					directions.push_back("down");
					break;
				case LEFT:
					directions.push_back("left");
					break;
			}
		}
	}
	return directions;
}