#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include "fanPageList.h"
#include "fanPage.h"
#include <string.h>

FanPageList::FanPageList():EntityList()
{
}

FanPageList::FanPageList(const FanPageList & other)
{
	theEntitys = other.theEntitys;
	logSize = other.logSize;
	phySize = other.phySize;
}

