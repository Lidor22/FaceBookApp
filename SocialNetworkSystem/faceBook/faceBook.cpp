#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "faceBook.h"
#define MAX 300
#define MAX_POST 2000
using namespace std;
#pragma warning(disable:4996)

char* getStrFromUser()
{
	char str[MAX], *finalStr;
	cin.ignore();
	cin.getline(str, MAX);
	finalStr = new char[strlen(str) + 1];
	strcpy(finalStr, str);
	return finalStr;
}

char* get2StrFromUser()
{
	char str[MAX], *secFinalStr;
	
	cin.getline(str, MAX);
	secFinalStr = new char[strlen(str) + 1];
	strcpy(secFinalStr, str);
	return secFinalStr;
}

void FaceBook::createNewMember()
{
	char* name;
	char birthDay[9];
	
	cout << "enter your name\n";
	name = getStrFromUser();

	Entity* temp = this->allEntitys.getEntityByName(name);

	if (!allEntitys.getEntityByName(name) || typeid(temp) == typeid(FanPage*))
	{
		cout << "enter your birth day in this format: dd.mm.yy\n";
		cin >> birthDay;

		Member* newMember = new Member(name, birthDay);
		Member* member = dynamic_cast<Member*>(newMember);
		if (member)
			this->allEntitys.addEntityToFaceBook(newMember);
	}

	else
		cout << "The name already exists in FaceBook" << endl;
}

void FaceBook::createNewFansPage()
{
	char *pageName;

	cout << "enter the fans page name\n";
	pageName = getStrFromUser();

	Entity* temp = this->allEntitys.getEntityByName(pageName);

	if (!allEntitys.getEntityByName(pageName) || typeid(temp) == typeid(Member*))
	{
		FanPage* newPage = new FanPage(pageName);
		FanPage* page = dynamic_cast<FanPage*>(newPage);
		if(page)
			this->allEntitys.addEntityToFaceBook(newPage);
	}
	
	else
		cout << "The name already exists in FaceBook" << endl;
}

void FaceBook::createNewEntity()
{
	char ch;
	cout << "Hey ! please enter F to create Fan page OR M to create Member";
	cin >> ch;

	if (ch == 'F' || ch == 'f')
		createNewFansPage();

	if (ch == 'M' || ch == 'm')
		createNewMember();
}

void FaceBook::writePost()
{
	char* name;
	char* post;
	int type, postColor;
	char ch;
	char* content=NULL;

	post = NULL;
	cout << "Hey ! please enter F for adding post to Fan page OR M for adding status to yourself :\n ";
	cin >> ch;

	cout << "What's your name?\n";
	name = getStrFromUser();
	cout << "Which kind of post?\n text - 0,image - 1, Video - 2, text and image-3, text and video-4";
	cin >> type;
	switch (type)
	{
	case 0:
	{
		cout << "Write the Post\n";
		post = getStrFromUser();
		content = "text";
	}break;
	case 1:
	{
		content = "image";
		cout << "choose a color\nred - 0, yellow - 1, blue - 2, pink - 3, orange - 4, white - 5, green - 6\n";
		cin >> postColor;
	}break;
	case 2:
	{
		content = "video";
		cout << "choose a color\nred - 0, yellow - 1, blue - 2, pink - 3, orange - 4, white - 5, green - 6\n";
		cin >> postColor;
	}break;
	case 3:
	{
		content = "text and image";
		cout << "choose a color\nred - 0, yellow - 1, blue - 2, pink - 3, orange - 4, white - 5, green - 6\n";
		cin >> postColor;
		cout << "Write the Post\n";
		post = getStrFromUser();
		
	}break;
	case 4:
	{
		content = "text and video";
		cout << "choose a color\nred - 0, yellow - 1, blue - 2, pink - 3, orange - 4, white - 5, green - 6\n";
		cin >> postColor;
		cout << "Write the Post\n";
		post = getStrFromUser();
		
	}break;
		default:
		break;
	}

	Entity *m = this->allEntitys.getEntityByName(name);
	m->addPostToEntity(content, post, postColor);
}

void FaceBook::showAllEntityPosts()
{
	char ch;
	char *name;
	int index;

	cout << "Do you want to show posts of member or fan? M for member, F for fans page\n";
	cin >> ch;
	cout << "what's the entity's name?\n";
	name = getStrFromUser();

	Entity *m = this->allEntitys.getEntityByName(name);

	if ((ch == 'm') || (ch == 'M') && (typeid(m) == typeid(Member*)) || ((ch == 'f') || (ch == 'F') && (typeid(m) == typeid(FanPage*))))
		(this->allEntitys.getEntityByName(name)->getEntityPostList())->show();

	else
	{
		index = this->allEntitys.getEntityIndexByName(name);
		m = this->allEntitys.getEntityByNameAfterIndex(name, index);
		(this->allEntitys.getEntityByName(name)->getEntityPostList())->show();
	}	
}

void FaceBook::addNewFriend()
{
	char *name1, *name2;
	Entity *m1, *m2;
	int index;

	cout << "What's your name?\n";
	name1 = getStrFromUser();
	Entity *temp1 = this->allEntitys.getEntityByName(name1);

	if (temp1 == NULL)
	{
		cout << "Entity doesn't found\n";
		return;
	}

	if (typeid(temp1) != typeid(Member*))
		m1 = temp1;

	else
	{
		index = this->allEntitys.getEntityIndexByName(name1);
		m1 = this->allEntitys.getEntityByNameAfterIndex(name1, index);
	}

	cout << "Who do you want to add?\n";
	name2 = get2StrFromUser();


	Entity* temp2 = this->allEntitys.getEntityByName(name2);
	if (temp2 == NULL)
	{
		cout << "Entity doesn't found\n";
		return;
	}

	if (typeid(temp2) != typeid(Member*))
		m2 = temp2;

	else
	{
		index = this->allEntitys.getEntityIndexByName(name2);
		m2 = this->allEntitys.getEntityByNameAfterIndex(name2, index);
	}

	if (m2 == m1)
		cout << "you can't add yourself" << endl;

	else if (typeid(m2) == typeid(Member*) && m1->getAllEntitys()->getEntityByName(name2))
		cout << "you'r already friends" << endl;

	else
	{
		m1->addEntity(m2, m1->getAllEntitys());
		m2->addEntity(m1, m2->getAllEntitys());
	}
}

void FaceBook::likeFansPage()
{
	char name1[MAX], name2[MAX];
	Entity *temp, *m, *p;
	int index;

	cout << "What's your name?\n";
	strcpy(name1, getStrFromUser());

	cout << "Which page do you want to like?\n";
	strcpy(name2, getStrFromUser());

	temp = this->allEntitys.getEntityByName(name1);

	if (typeid(temp) == typeid(Member*))
		m = temp;

	else
	{
		index = this->allEntitys.getEntityIndexByName(name1);
		m = this->allEntitys.getEntityByNameAfterIndex(name1, index);
	}

	temp = this->allEntitys.getEntityByName(name2);

	if (typeid(temp) == typeid(FanPage*))
		p = temp;

	else
	{
		index = this->allEntitys.getEntityIndexByName(name2);
		p = this->allEntitys.getEntityByNameAfterIndex(name2, index);
	}

	if (typeid(p) == typeid(FanPage*) && m->getAllEntitys()->getEntityByName(name2))
		cout << "you'r already like this page" << endl;
	else
	{
		m->addEntity(p, m->getAllEntitys());
		p->addEntity(m, p->getAllEntitys());
	}
}

void FaceBook::showAllTheEntitysOnFacebook()
{
	this->allEntitys.show();
}

void FaceBook::showAllFriendsOfMemberOrFanPage()
{
	char ch;
	char name[MAX];
	int index;

	cout << "Do you want to show friends of member or friend? M for member, F for fans page\n";
	cin >> ch;

	cout << "what's the entity's name?\n";
	strcpy(name, getStrFromUser());
	Entity *m = this->allEntitys.getEntityByName(name);

	if ((ch == 'm') || (ch == 'M') && (typeid(m) == typeid(Member*)) || ((ch == 'f') || (ch == 'F') && (typeid(m) == typeid(FanPage*))))
		m->getAllEntitys()->show();

	else
	{
		index = this->allEntitys.getEntityIndexByName(name);
		m = this->allEntitys.getEntityByNameAfterIndex(name, index);
		m->getAllEntitys()->show();
	}
}

void FaceBook::showTenLastestPostsOfMembersFriends()
{
	char name[MAX];
	int index;

	cout << "what's your name?" << endl;
	strcpy(name, getStrFromUser());
	
	if (this->allEntitys.getEntityByName(name)->getAllEntitys()->getSize() == 0)
		cout << "Memeber has no friends !" << endl;

	Entity *temp = this->allEntitys.getEntityByName(name);

	if (typeid(temp) == typeid(Member*))
		this->allEntitys.getEntityByName(name)->getLatestPostOfEntity(10)->show();
	
	else
	{
		index = this->allEntitys.getEntityIndexByName(name);
		temp = this->allEntitys.getEntityByNameAfterIndex(name, index);
		cout << "the last 10 post of" << name << "are:" << endl;
		this->allEntitys.getEntityByName(name)->getLatestPostOfEntity(10)->show();
	}		
}

void menu()
{
	cout << "Welcome to Facebook:\nTo create new Entity - 1\n" <<
		"To write a post - 2\nTo show all fried's or fans page's posts - 3\n" <<
		"To add new friend - 4\nTo like fans page - 5\nTo show all the entities on facebook - 6\n" <<
		"To show all the friends of member or fans page - 7\nTo show the 10 lastest posts of member's friends - 8\n" <<
		"TO exit - 9" << endl;
}





