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

list<Entity*> Entity::GetChildrenByType(EntityType type)
{
	list<Entity*> selectedChildren;
	list<Entity*>::iterator it;

	for (it = children.begin(); it != children.end(); it++)
	{
		if ((*it)->type == type)
		{
			selectedChildren.push_back((*it));
		}
	}
	return selectedChildren;
}

list<Entity*> Entity::GetAllChildren()
{
	return children;
}

bool Entity::TryGetChildByName(string name, Entity* &child)
{
	list<Entity*>::iterator it;

	cout << "Find children by name\n";

	for (it = children.begin(); it != children.end(); it++)
	{
		
		cout << (*it)->name;
		cout << '\n';

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
	children.push_back(newChild);
}

void Entity::RemoveChild(Entity* oldChild)
{
	children.remove(oldChild);
}

void Entity::ChangeParent(Entity* newParent)
{

}