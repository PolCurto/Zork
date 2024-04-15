#include "Player.h"

Player::Player(const string name, const string description, Room* location, int hp, int attackDamage, int defense, int agility, float attackSpeed, int equipmentSlots) :
	Creature(name, description, location, hp, attackDamage, defense, agility, attackSpeed, equipmentSlots)
{
	this->equipmentSlots = 1;

	this->isLord = false;
	this->type = PLAYER;
}

void Player::SayHello()
{
	cout << "Hello master!\n";
}

/*
* Prints the player's name and its stats. If given any more parameter, prints the
* information of the room or the information of all the entities within it
*/
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
		cout << "Stats:\n";
		cout << "    HP: ";
		cout << currentHp;
		cout << " / ";
		cout << maxHp;
		cout << '\n';
		cout << "    Attack damage: ";
		cout << attackDamage;
		cout << '\n';
		cout << "    Defense: ";
		cout << defense;
		cout << '\n';
		cout << "    Agility: ";
		cout << agility;
		cout << '\n';
		cout << "    Attack speed: ";
		cout << attackSpeed;
		cout << '\n';
		cout << "    Equipment slots: ";
		cout << equipmentSlots;
		cout << '\n';
	}
}

/*
* Prints all the items the player has in its inventory
*/
void Player::CheckInventory()
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

/*
* If not in combat, moves to the given direction and prints information about the new room
*/
void Player::Move(string direction)
{
	if (isInCombat)
	{
		cout << "You can't move while in combat!\n";
		return;
	}

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

/*
* Checks if an item and a source with the given names exist. If they do,
* tries to pick the item from the source and stores it in the player's inventory.
* By default the source is the current room
*/
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

	if (oldParent->TryGetChildByName(itemName, item) && item->type == ITEM)
	{
		if (MoveItem(item, oldParent, this)) 
			cout << "You picked " + item->name + " from " + oldParent->name + '\n';
	}
	else
	{
		cout << "There is no item called ";
		cout << itemName;
		cout << " in ";
		cout << oldParent->name + '\n';
	}
}

/*
* Checks if an item and a destination with the given names exist. If they do,
* tries to drop the item to the destination and removes it from the player's inventory.
* By default the destination is the current room
*/
void Player::DropItem(string itemName, string destination)
{
	Entity* newParent;

	if (destination == "")
	{
		// If no destination is given, by default drops the item to the current room
		newParent = location;
	}
	else
	{
		// If destination is given, drops the item to another item the player already has
		if (!TryGetChildByName(destination, newParent))
		{
			cout << "The destination ";
			cout << destination;
			cout << " doesn't exist!\n";
			return;
		}
	}

	// UnEquips the item to avoid duplications
	UnEquip(itemName);

	Entity* item = 0;

	if (this->TryGetChildByName(itemName, item) && item->type == ITEM)
	{
		if (MoveItem(item, this, newParent)) 
			cout << "You dropped " + item->name + " into " + newParent->name + '\n';
	}
	else
	{
		cout << "There is no item called ";
		cout << itemName;
		cout << " in ";
		cout << this->name + '\n';
	}
}

/*
* Checks if the target npc exists and talks to it
*/
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

/*
* Checks if the given item is within the player's inventory. If it is, tries
* to equip it
*/
void Player::Equip(string itemName)
{
	Entity* entity;

	if (TryGetChildByName(itemName, entity) && entity->type == ITEM)
	{
		Item* item = (Item*)entity;
		if (item->GetItemType() == EQUIPMENT)	// Only equips it if the item is of type equipment
		{
			AddEquipment(item);
		}
		else
		{
			cout << "The item " + itemName + " can't be equipped!\n";
		}
	}
	else
	{
		cout << "You don't have any item called " + itemName + '\n';
	}
}

/*
* Adds the given item to the player equipped items, as long as it has free slots
* and the item is not already equipped
*/
void Player::AddEquipment(Item* item)
{
	if (equipment.size() < equipmentSlots)    // Checks for the slots
	{
		if (find(equipment.begin(), equipment.end(), item) != equipment.end())    // Checks if the item is already equipped
		{
			cout << "You have already equipped " + item->name + '\n';
			return;
		}
		else
		{
			equipment.push_back(item);
		}

		ModifyStats(item, true);
		cout << "You equipped " + item->name + '\n';
	}
	else
	{
		cout << "Your equipment slots are full\n";
	}
}

/*
* Checks if the player has the given item equipped. If it does,
* removes it from the equipment slots
*/
void Player::UnEquip(string itemName)
{
	for (int i = 0; i < equipment.size(); i++)
	{
		if (equipment[i]->name.compare(itemName) == 0)
		{
			ModifyStats(equipment[i], false);
			equipment.erase(next(equipment.begin(), i));
			cout << "You unequipped " + itemName + '\n';
			return;
		}
	}

	cout << "You don't have any " + itemName + " equipped\n";

}

/*
* Checks if the given item is within the player's inventory. If it is, uses it,
* removes it from the player's inventory and makes it point to null to prevent 
* accessing to the item again
*/
void Player::Use(string itemName)
{
	Entity* entity;

	if (TryGetChildByName(itemName, entity) && entity->type == ITEM)
	{
		Item* item = (Item*)entity;
		if (item->GetItemType() == CONSUMABLE)
		{
			if (item->name.compare("Star") == 0)    // If the item is the star, modifies a unique stat so the game ends
			{
				isLord = true;
				return;
			}
			ModifyStats(item, true);
			RemoveChild(item);
			item = NULL;

			cout << "You used " + itemName + '\n';
		}
		else
		{
			cout << "The item " + itemName + " can't be used!\n";
		}
	}
	else
	{
		cout << "You don't have any item called " + itemName + '\n';
	}
}

/*
* Prints all the items the player has currently equipped
*/
void Player::CheckEquipment()
{
	if (equipment.size() < 1)
	{
		cout << "You have no items equipped\n";
	}
	else
	{
		for (int i = 0; i < equipment.size(); i++)
		{
			cout << equipment[i]->name + '\n';
		}
	}
}

/*
* Modifies the player's stats with the given item's stats. Also a bool
* indicates whether the item is being equipped or unequipped to add or 
* substract the stats
*/
void Player::ModifyStats(Item* item, bool add)
{
	if (add)
	{
		maxHp += item->GetHp();
		currentHp += item->GetHp();
		attackDamage += item->GetAttackDamage();
		defense += item->GetDefense();
		agility += item->GetAgility();
		attackSpeed += item->GetAttackSpeed();
		equipmentSlots += item->GetEquipmentSlots();
	}
	else
	{
		maxHp -= item->GetHp();
		currentHp -= item->GetHp();
		attackDamage -= item->GetAttackDamage();
		defense -= item->GetDefense();
		agility -= item->GetAgility();
		attackSpeed -= item->GetAttackSpeed();
		equipmentSlots -= item->GetEquipmentSlots();
	}
}

/*
* Checks if a npc with the given name exists in the current room. If it does,
* sets it as the player's target and sets the player as the creature's target
* to begin the combat.
* If it is dead or already in combat with another creature returns
*/
void Player::SetTarget(string targetName)
{
	if (isDead) return;
	
	if (isInCombat)
	{
		cout << "You are already fighting against " + target->name;
		return;
	}

	Entity* entity;

	if (location->TryGetChildByName(targetName, entity) && entity->type == NPC)
	{
		Creature* creature = (Creature*)entity;

		if (creature->IsDead())
		{
			cout << "Not my hobby to attack the dead";
		}
		else
		{
			lastAttack = clock();
			this->target = creature;
			cout << "Target set\n";
			isInCombat = true;

			this->target->SetTarget(this);
		}
	}
	else
	{
		cout << "There is no one called " + targetName + " in this room\n";
	}
}

/*
* Prints the creature you died against and dies, ending the game in consequence
*/
void Player::Die()
{
	cout << "You have died fighting against " + target->name + '\n';
	Creature::Die();
}

bool Player::IsLord()
{
	return isLord;
}