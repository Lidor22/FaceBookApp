#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include "memberList.h"
#include "member.h"
#include <string.h>


MemberList::MemberList():EntityList()
{
}

MemberList::MemberList(const MemberList & other)
{
	theEntitys = other.theEntitys;
	logSize = other.logSize;
	phySize = other.phySize;
}
