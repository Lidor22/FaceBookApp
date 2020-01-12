#define _CRT_SECURE_NO_WARNINGS

#pragma once

#ifndef __POST_H
#include "time.h"
enum Color { RED, YELLOW, BLUE, PINK, ORANGE, WHITE, GREEN };

class Post
{
protected:
	Time timeOfPost;
	char* content;

public:
	Post() = default; //constructor default
	Post(char* contentFromUser);  //constructor
	Post(const Post & s); // copy ctor
	~Post();  //d'tor
	char* getContent();
	friend Post* compTime(Post* p1, Post* p2); // comparing the time creation of two given posts
	Time getTime(); //get method - getting the time creation of a post
	virtual void show(){}
	virtual bool operator==(Post& other)const
	{
		return (strcmp(content, other.getContent())==0);
	}
	virtual bool operator!=(Post& other)const
	{
		return !(*this == other);
	}

};
#endif // ! __POST_H