#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include "Entity.h"

Entity::Entity(char* userName)
{
	name = new char[strlen(userName) + 1];
	strcpy(name, userName);
}

Entity::Entity(const Entity& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	allEntitys = other.allEntitys;
	entityPostList = other.entityPostList;
}

Entity::~Entity()
{
	delete[]name;
}

char* Entity::getName()
{
	return this->name;
}

EntityList* Entity::getAllEntitys()
{
	return &this->allEntitys;
}

PostList* Entity::getEntityPostList()
{
	return &this->entityPostList;
}

void Entity::addPostToEntity(char* content, char* post, int color)
{
	this->entityPostList.addPost(content, color, post);
}

void Entity::addEntity(Entity* newEntity, EntityList* allEntitysFriends)
{
	this->allEntitys.addEntityToEntityList(newEntity, allEntitysFriends);
}

PostList* Entity::getLatestPostOfEntity(int numPosts)
{
	return this->entityPostList.getLatestPosts(numPosts);

}

bool Entity::operator>(Entity & other)
{
	int i, thisSize = 0, othetSize = 0;

	for (i = 0; i < this->allEntitys.getSize(); i++)
		thisSize++;
	
	for (i = 0; i < other.allEntitys.getSize(); i++)
		othetSize++;
	
	return thisSize > othetSize;
}

Entity* Entity:: operator+=(Entity& other)
{
	addEntity(&other,&this->allEntitys);
	return this;
}
