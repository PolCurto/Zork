#include "Item.h"

Item::Item(const string name, const string description, Entity* parent) : Entity(name, description)
{
	this->type = ITEM;
	this->parent = parent;
}

void Item::Describe()
{
	cout << name + ". " + description + '\n';
}

void Item::ChangeParent(Entity* newParent)
{
	Entity* oldPArent;

	cout << "Old parent children size: ";
	cout << parent->GetAllChildren().size();
	cout << ". New parent children size: ";
	cout << newParent->GetAllChildren().size();
	cout << '\n';

	cout << name;
	cout << " old parent: ";
	cout << parent->name;

	parent->RemoveChild(this);
	oldPArent = parent;
	parent = newParent;
	newParent->AddChild(this);

	cout << ". New parent: ";
	cout << parent->name;
	cout << '\n';

	cout << "Old parent children size: ";
	cout << oldPArent->GetAllChildren().size();
	cout << ". New parent children size: ";
	cout << newParent->GetAllChildren().size();
	cout << '\n';
}