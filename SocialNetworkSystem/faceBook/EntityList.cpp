#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define SIZE 2
#include "EntityList.h"
#include "Entity.h"
#include <string.h>

EntityList::EntityList()
{
	theEntitys = new Entity*[SIZE];
	logSize = 0;
	phySize = SIZE;
}

EntityList::EntityList(const EntityList & other)
{
	theEntitys = other.theEntitys;
	logSize = other.logSize;
	phySize = other.phySize;
}

EntityList::~EntityList()
{
	delete[]theEntitys;
}

void EntityList::addEntityToFaceBook(Entity* e)
{
	Entity** newtheEntitys;
	int i;

	if (logSize == phySize)
	{
		phySize *= SIZE;
		newtheEntitys = new Entity*[phySize];

		for (i = 0; i < logSize; i++)
		{
			newtheEntitys[i] = theEntitys[i];
		}
		delete[]theEntitys;
		theEntitys = newtheEntitys;
	}

	this->theEntitys[logSize] = e;
	logSize++;
}

void EntityList::addEntityToEntityList(Entity* e, EntityList* entityFriends)
{
	Entity** newEntityList;
	int i;

	if (logSize == phySize)
	{
		phySize *= SIZE;
		newEntityList = new Entity*[phySize];

		for (i = 0; i < logSize; i++)
		{
			newEntityList[i] = theEntitys[i];
		}
		delete[]theEntitys;
		theEntitys = newEntityList;
	}

	theEntitys[logSize] = e;
	logSize++;
}

Entity ** EntityList::getTheEntitys()
{
	return this->theEntitys;
}

Entity* EntityList::getEntityByName(char* EntityName)
{
	int numOfEntitys, i;

	numOfEntitys = this->getSize();

	for (i = 0; i < numOfEntitys; i++)
	{
		
		if (strcmp(this->theEntitys[i]->getName(), EntityName) == 0)
		{
			return this->theEntitys[i];
		}
	}

	return NULL;
}

int EntityList::getEntityIndexByName(char* name)
{
	int numOfEntitys, i;

	numOfEntitys = this->getSize();

	for (i = 0; i < numOfEntitys; i++)
	{

		if (strcmp(this->theEntitys[i]->getName(), name) == 0)
		{
			return i;
		}
	}
	return NULL;
}

Entity* EntityList::getEntityByNameAfterIndex(char* name, int index)
{

	int numOfEntitys, i;

	numOfEntitys = this->getSize();

	for (i = index + 1; i < numOfEntitys; i++)
	{

		if (strcmp(this->theEntitys[i]->getName(), name) == 0)
		{
			return this->theEntitys[i];
		}
	}

	return NULL;
}

int EntityList::getSize()
{
	return this->logSize;
}

Entity* EntityList::getEntityByIndex(int index)
{
	int numOfEntitys, i;

	numOfEntitys = this->getSize();

	for (i = 0; i < numOfEntitys; i++)
	{
		if (i == index)
		{
			return this->theEntitys[i];
		}
	}

	return NULL;
}

void EntityList::show()
{
	int i;

	cout << "The Entitys are: \n";
	for (i = 0; i < logSize; i++)
	{
		cout << "The name: " << theEntitys[i]->getName() << endl;
	}
}


