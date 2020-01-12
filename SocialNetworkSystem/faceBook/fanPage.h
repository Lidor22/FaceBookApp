#define _CRT_SECURE_NO_WARNINGS

#pragma once

#ifndef __FANPAGE_H
#include "memberList.h"
#include "postList.h"
#include "Entity.h"

class FanPage: public Entity
{

public:
	FanPage() = default; // default constructor 
	FanPage(char* fanPageName);//  constructor of given input 
	FanPage(const FanPage & other);// copy ctor
};
#endif // ! __FANPAGE_H

