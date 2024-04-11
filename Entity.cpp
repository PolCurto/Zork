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

void Entity::AddChild(Entity* newChild)
{
	children.push_back(newChild);
}