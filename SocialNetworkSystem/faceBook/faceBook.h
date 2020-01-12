#define _CRT_SECURE_NO_WARNINGS

#pragma once

#ifndef __faceBook_h

#include "time.h"
#include "fanPage.h"
#include "member.h"
#include "post.h"

class FaceBook
{
private:
	EntityList allEntitys;

public:
	friend char* getStrFromUser(); //Getting input string from user
	friend char* get2StrFromUser(); //Getting input string from user
	void createNewMember(); //create new memeber to FaceBook
	void createNewFansPage(); //create new fanPage to FaceBook
	void createNewEntity();//create new entity to FaceBook
	void writePost(); //write post to member OR fanpage
	void showAllEntityPosts(); //function to show all friends of given memeber/fanPage
	void addNewFriend(); // adding new friend to memeber
	void likeFansPage(); //function for members in order to like fanpage
	void showAllTheEntitysOnFacebook(); //show all of the members and fanPage on Facebook
	void showAllFriendsOfMemberOrFanPage(); //show all friends of the members and fanPage on Facebook
	void showTenLastestPostsOfMembersFriends(); //show 10 latest posts of member's friends on FaceBook.
	friend void menu();//facebook menu
};

#endif // !__faceBook_h
