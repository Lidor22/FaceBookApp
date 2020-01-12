#define _CRT_SECURE_NO_WARNINGS

#pragma once

#ifndef __MEMBERLIST_H
#define SIZE 2
#include "EntityList.h"
class Member;

class MemberList:public EntityList
{

public:
	MemberList();//  constructor
	MemberList(const MemberList & other);// copy ctor
};
#endif // ! __MEMBERLIST_H
