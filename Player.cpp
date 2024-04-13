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
		else if (target.compare("inventory") == 0 || target.compare("Inventory") == 0)
		{
			list<Entity*> playerInventory = GetAllChildren();

			if (playerInventory.size() > 0)
			{
				for (Entity* entity : playerInventory)
				{
					entity->Describe();
				}
			}
			else
			{
				cout << "Your inventory is empty\n";
			}
			
		}
		else if (target.compare("all") == 0 || target.compare("All") == 0)
		{
			location->Describe();
			for (Entity* entity : location->GetAllChildren())
			{
				if (entity != this)
					entity->Describe();
			}
			Describe();
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

		location->RemoveChild(this);
		nextRoom->AddChild(this);
		location = nextRoom;
		
		Describe("room");
	}
	else
	{
		cout << "There is no exit in that direction \n";
	}
}

void Player::PickItem(string itemName, string source)
{
	Entity* oldParent;

	if (source == "")
	{
		// If no source is given, by default picks the item from the current room
		oldParent = location;
	}
	else
	{
		cout << "Item from source\n";
		// If source is given, picks the item fron another item the player already has
		if (!TryGetChildByName(source, oldParent))
		{
			cout << "The source ";
			cout << source;
			cout << " doesn't exist!\n";
			return;
		}
	}

	Item* item = 0;

	MoveItem(itemName, item, oldParent, this);
}

void Player::DropItem(string itemName, string destination)
{
	Entity* newParent;

	if (destination == "")
	{
		// If no source is given, by default picks the item from the current room
		newParent = location;
	}
	else
	{
		cout << "Item to source\n";
		// If source is given, drops the item to another item the player already has
		if (!TryGetChildByName(destination, newParent))
		{
			cout << "The destination ";
			cout << destination;
			cout << " doesn't exist!\n";
			return;
		}
	}

	Item* item = 0;

	MoveItem(itemName, item, this, newParent);
}