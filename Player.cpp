#include "Player.h"

Player::Player(const string name, const string description, Room* location) : Creature(name, description, location)
{
	this->type = PLAYER;
}

void Player::SayHello()
{
	cout << "Hello fellow master!\n";
}

void Player::Describe(string target)
{
	if (target.length() > 0)
	{
		cout << "Target: " + target + '\n';
		if (target.compare("room") == 0 || target.compare("Room") == 0)
		{
			location->Describe();
			return;
		}
		else if (target.compare("all") == 0 || target.compare("All") == 0)
		{
			location->Describe();
			for (Entity* entity : location->GetAllChildren())
			{
				if (entity != this)
					entity->Describe();
			}
			Describe("");
		}
		else
		{
			cout << "That target does not exist\n";
		}
	}
	else
	{
		cout << "I am " + name + ", " + description + '\n';
	}
}

// Moves to the given direction
void Player::Move(string direction)
{
	Room* nextRoom = 0;
	
	//cout << "Player move\n";
	//cout << "Location adress: ";
	//cout << location;
	//cout << '\n';

	if (location->LookForExit(direction, nextRoom))
	{
		//cout << "Next room returned with adress:";
		//cout << nextRoom;
		//cout << '\n';

		location = nextRoom;
		Describe("room");
	}
	else
	{
		cout << "There is no exit in that direction \n";
	}
}

void Player::PickUp(string item)
{

}

void Player::Drop(string item) {

}