#include "Entity.h"

Entity::Entity(const string name, const string description)
{
	this->name = name;
	this->description = description;
}

void Entity::Tick()
{

}

void Entity::Describe()
{
	
}

/*
* Stores in a list all the entities the parent entity contains that match the given type.
*/
list<Entity*> Entity::GetChildrenByType(EntityType type)
{
	list<Entity*> selectedChildren;
	list<Entity*>::iterator it;

	for (it = contains.begin(); it != contains.end(); it++)
	{
		if ((*it)->type == type)
		{
			selectedChildren.push_back((*it));
		}
	}
	return selectedChildren;
}

/*
* Stores in a list all the entities the parent entity contains
*/
list<Entity*> Entity::GetAllChildren()
{
	return contains;
}

/*
* Stores in a referenced entity the first entity the parent contains that match the given name.
* Returns whether there is a child with that name or not
*/
bool Entity::TryGetChildByName(string name, Entity* &child)
{
	list<Entity*>::iterator it;

	//cout << "Find children by name\n";

	for (it = contains.begin(); it != contains.end(); it++)
	{
		//cout << (*it)->name;
		//cout << '\n';

		if ((*it)->name.compare(name) == 0)
		{
			child = (*it);
			return true;
		}
	}
	return false;
}

void Entity::AddChild(Entity* newChild)
{
	contains.push_back(newChild);
}

void Entity::RemoveChild(Entity* oldChild)
{
	contains.remove(oldChild);
}

void Entity::ChangeParent(Entity* newParent)
{

}