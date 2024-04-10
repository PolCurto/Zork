#include "Player.h"

Player::Player(const string name, const string description) : Creature(name, description)
{

}

void Player::SayHello()
{
	cout << "Hello fellow master!\n";
}