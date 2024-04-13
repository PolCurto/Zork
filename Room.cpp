#include "Room.h"
#include "Exit.h"

Room::Room(const string name, const string description) : Entity(name, description)
{

}

void Room::Describe()
{
	cout << "You are in " + name + ". " + description + '\n';
}

bool Room::LookForExit(string direction, Entity* &nextRoom)
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

		if (exit->IsValidDirection(direction, this))
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