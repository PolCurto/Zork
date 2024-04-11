#include "Room.h"
#include "Exit.h"

Room::Room(const string name, const string description) : Entity(name, description)
{

}

void Room::Describe()
{
	cout << "You are in " + name + ". " + description + '\n';
}

bool Room::LookForExit(string direction, Room* &nextRoom)
{
	//cout << "This adress: ";
	//cout << this;
	//cout << '\n';

	list<Entity*> exits = GetChildrenByType(EXIT);

	list<Entity*>::iterator it;

	//cout << "Exits length: ";
	//cout << exits.size();
	//cout << '\n';

	for (it = exits.begin(); it != exits.end(); it++)
	{
		Exit* exit = (Exit*)(*it);

		if (exit->IsValidDirection(direction))
		{
			//cout << "Valid direction\n";
			nextRoom = exit->GetLinkedRoom(this);

			//cout << "Next room adress: ";
			//cout << nextRoom->name;
			//cout << '\n';

			return true;
		}
	}

	return false;
}