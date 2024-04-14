#include "Creature.h"

Creature::Creature(const string name, const string description, Room* location, int hp, int attackDamage, int defense, int agility, float attackSpeed, int equipmentSlots) : Entity(name, description)
{
	this->location = location;
	this->maxHp = hp;
	this->currentHp = hp;
	this->attackDamage = attackDamage;
	this->defense = defense;
	this->agility = agility;
	this->attackSpeed = attackSpeed;
	this->equipmentSlots = equipmentSlots;
	this->type = CREATURE;
}

void Creature::Tick()
{
	if (isDead) return;

	if (isInCombat)
	{
		if (clock() - lastAttack > (attackSpeed * 1000))
		{
			Attack();
		}
	}
}

void Creature::Describe()
{
	if (isDead)
	{
		cout << "You can see the corpse of: " + name + " rotting in the ground\n";
	}
	else
	{
		cout << "Creature with ne name: " + name + ". " + description + '\n';
	}
}

void Creature::Move(string direction, bool &valid)
{
	Entity* nextRoom = 0;

	//cout << "Player move\n";
	//cout << "Location adress: ";
	//cout << location;
	//cout << '\n';

	if (location->LookForExit(direction, nextRoom))
	{
		//cout << "Next room returned with adress:";
		//cout << nextRoom;
		//cout << '\n';

		ChangeParent(nextRoom);
		valid = true;

		cout << "Creature with name " + name + " move to " + nextRoom->name + '\n';
	}
	else
	{
		valid = false;
	}
}

void Creature::PickUp()
{

}

void Creature::DropItem()
{

}

void Creature::Talk()
{

}

void Creature::MoveItem(const string itemName, Entity* item, Entity* oldParent, Entity* newParent)
{
	/*
	cout << "Try to pick / drop item: ";
	cout << itemName;
	cout << " from / to ";
	cout << oldParent->name + '\n';
	*/

	if (oldParent->TryGetChildByName(itemName, item) && item->type == ITEM)
	{
		/*
		cout << "New parent: ";
		cout << newParent->name + '\n';
		cout << "New item: ";
		cout << item->name + '\n';
		*/

		if (newParent == item)
		{
			cout << "You can't place an item inside itself! That would bend the rules of the unverse\n";
			return;
		}

		item->ChangeParent(newParent);
	}
	else
	{
		cout << "There is no item called ";
		cout << itemName;
		cout << " in ";
		cout << oldParent->name + '\n';
	}
}

void Creature::SetTarget(Creature* target)
{
	if (isDead)
	{
		return;
	}

	lastAttack = clock();
	this->target = target;
	isInCombat = true;
}

void Creature::Attack()
{
	if (target->IsDead())
	{
		isInCombat = false;
		this->target = 0;
		cout << "The combat has finished\n\n";
		return;
	}

	target->ReceiveAttack(attackDamage);
	lastAttack = clock();
}

void Creature::ReceiveAttack(int damage)
{
	int accuracy = rand() % 100;

	if (accuracy <= agility)
	{
		cout << name + " dodged the attack!\n";
	}
	else
	{
		currentHp -= (damage - defense);
		if (currentHp < 0) currentHp = 0;

		cout << name + " received the attack! Damage dealt: ";
		cout << (damage - defense);
		cout << " current hp: ";
		cout << currentHp;
		cout << " / ";
		cout << maxHp;
		cout << '\n';

		if (currentHp <= 0)
		{
			Die();
		}
	}
}

void Creature::Die()
{
	isInCombat = false;
	isDead = true;
}

void Creature::ChangeParent(Entity* newParent)
{
	location->RemoveChild(this);
	location = (Room*)newParent;
	location->AddChild(this);
}

bool Creature::IsDead()
{
	return isDead;
}