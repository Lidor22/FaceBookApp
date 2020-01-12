#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include "post.h"


Post::Post(char* contentFromUser)
{
	content = new char[strlen(contentFromUser) + 1];
	strcpy(content, contentFromUser);
}

Post::Post(const Post & other)
{
	content = new char[strlen(other.content) + 1];
	strcpy(content, other.content);
	timeOfPost = other.timeOfPost;
}

Post:: ~Post()
{
	delete[]content;
}

char* Post::getContent()
{
	return content;
}

Time Post::getTime()
{
	return timeOfPost;
}

Post* compTime(Post* p1, Post* p2)
{
	if (p1->getTime().getYear() > p2->getTime().getYear())
		return p1;
	else if (p1->getTime().getYear() < p2->getTime().getYear())
		return p2;
	else
	{
		if (p1->getTime().getMonth() > p2->getTime().getMonth())
			return p1;
		else if (p1->getTime().getMonth() < p2->getTime().getMonth())
			return p2;
		else
		{
			if (p1->getTime().getDay() > p2->getTime().getDay())
				return p1;
			else if (p1->getTime().getDay() < p2->getTime().getDay())
				return p2;
			else
			{
				if (p1->getTime().getHours() > p2->getTime().getHours())
					return p1;
				else if ((p1->getTime().getHours() < p2->getTime().getHours()) || p1->getTime().getHours() == 00)
					return p2;
				else
				{
					if (p1->getTime().getMinutes() > p2->getTime().getMinutes())
						return p1;
					else if (p1->getTime().getMinutes() < p2->getTime().getMinutes())
						return p2;
					else
					{
						if (p1->getTime().getSeconds() > p2->getTime().getSeconds())
							return p1;
						return p2;
					}
				}
			}
		}
	}
}