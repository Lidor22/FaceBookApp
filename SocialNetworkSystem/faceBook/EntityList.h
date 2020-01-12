#define _CRT_SECURE_NO_WARNINGS
#pragma once

#ifndef __ENTITYLIST_H

class Entity;

class EntityList
{
protected:
	Entity ** theEntitys;
	int logSize;
	int phySize;
public:
	EntityList();//  constructor
	EntityList(const EntityList & other);// copy ctor
	~EntityList();// d'tor 
	void addEntityToFaceBook(Entity* e); // adding fan page to facebook
	void addEntityToEntityList(Entity* e, EntityList* entityFriends);// adding entity to entity list
	Entity* getEntityByName(char* EntityName); //get method - getting the fanpage by name
	int getSize(); //get method - getting the size of a given Entitys list
	Entity* getEntityByIndex(int index);//getting entity by index
	void show(); //show method
	Entity ** getTheEntitys();//getting all entitys
	int getEntityIndexByName(char* name);//getting an entity index by name
	Entity* getEntityByNameAfterIndex(char* name, int index);//gettin entity by name after index
};
#endif
