#define _CRT_SECURE_NO_WARNINGS


#pragma once

#ifndef __IMAGEPOST_H
#include "post.h"
class ImagePost :virtual public Post
{

private:
	Color imageColor;

public:
	ImagePost() = default;
	ImagePost(char* contentFromUser, Color imageColorFromUser);  //constructor
	ImagePost(const ImagePost & other); // copy ctor
	virtual void show();
	virtual bool operator==(ImagePost& other)const
	{
		return Post::operator==(other);
	}
	virtual bool operator!=(ImagePost& other)const
	{
		return !(*this == other);
	}
};
#endif