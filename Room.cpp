#include "Room.h"

Room::Room(const string name, const string description) : Entity(name, description)
{

}

void Room::Describe()
{
	cout << "Room: " + name + ". " + description + '\n';
}