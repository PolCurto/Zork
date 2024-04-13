#include "Player.h"

Player::Player(const string name, const string description, Room* location, int hp, int attackDamage, int defense, int agility) :
	Creature(name, description, location, hp, attackDamage, defense, agility)
{
	this->type = PLAYER;
}

void Player::SayHello()
{
	cout << "Hello master!\n";
}

void Player::Describe(string target)
{
	if (target.length() > 0)
	{
		//cout << "Target: " + target + '\n';
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

void Player::Inventory()
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

// Moves to the given direction
void Player::Move(string direction)
{
	bool isValid;
	Creature::Move(direction, isValid);

	if (isValid)
	{
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

	Entity* item = 0;

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

	Entity* item = 0;

	MoveItem(itemName, item, this, newParent);
}

void Player::Talk(string target)
{
	Entity* entity;

	if (location->TryGetChildByName(target, entity) && entity->type == NPC)
	{
		Creature* npc = (Creature*)entity;
		npc->Talk();
	}
	else
	{
		cout << target + " is not in this room\n";
	}
}