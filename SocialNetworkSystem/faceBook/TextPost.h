#define _CRT_SECURE_NO_WARNINGS


#pragma once

#ifndef __TEXTPOST_H
#include "post.h"

class TextPost:virtual public Post
{
private:
	char* textPost;
	Color textColor = WHITE;

public:
	TextPost() = default;
	TextPost(char* contentFromUser, char* theUserPost);  //constructor
	TextPost(const TextPost & other); // copy ctor
	~TextPost();  //d'tor
	char* getPost();
	virtual void show();
	virtual bool operator==(TextPost& other)const
	{
		if (!Post::operator==(other))
			return false;

		TextPost* temp = dynamic_cast<TextPost*>(&other);
		return (strcmp(textPost, other.getPost()) == 0);
	}
	virtual bool operator!=(TextPost& other)const
	{
		return !(*this == other);
	}
};
#endif

