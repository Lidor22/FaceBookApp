#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include "postList.h"
#include "EntityList.h"
#ifndef __ENTITY_H

class Entity
{
protected:
	char * name;
	EntityList allEntitys;
	PostList  entityPostList;
public:
	Entity(char* userName);
	Entity()=default;
	Entity(const Entity& other);
	~Entity();
	char* getName();
	EntityList*  getAllEntitys();
	PostList*  getEntityPostList();
	PostList* getLatestPostOfEntity(int numPosts);//get method - getting the member latest posts
	void addPostToEntity(char* contentFromUser,char* postFromUser, int postColor);
	void addEntity(Entity* newEntity, EntityList* allEntitysFriends);
	bool operator>(Entity & other);
	Entity* operator+=(Entity& other);
};
#endif
