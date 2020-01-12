#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include "fanPageList.h"
#include "memberList.h"
#include "postList.h"
#include "post.h"
#include "Entity.h"

#ifndef __MEMBER_H

class Member: public Entity
{
private:

	char birthDay[9];

public:
	Member() = default;//  constructor default
	Member(char* userName, char* bDay);//  constructor of given input
	Member(const Member & m);// copy ctor
	PostList* getLatestPostOfMember(int numPosts);//get method - getting the member latest posts
	PostList* getLatestPostOfAllFriens(int numPosts);//get method - getting the latest posts of a given member's friends
	char* getBday();//get method - getting the member birthday
	void show();//show method - printing the member details
};
#endif // ! __MEMBER_H

