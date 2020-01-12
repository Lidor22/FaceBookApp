#define _CRT_SECURE_NO_WARNINGS

#pragma once

#ifndef __FANPAGELIST_H
#define SIZE 2
#include "EntityList.h"

class FanPageList:public EntityList
{
	
public:
	FanPageList(); //  constructor of given input
	FanPageList(const FanPageList & other);// copy ctor
};
#endif // ! __FANPAGELIST_H