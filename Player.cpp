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