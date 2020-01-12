#define _CRT_SECURE_NO_WARNINGS
#pragma once



#ifndef __VIDEOPOST_H
#include "post.h"

class VideoPost : virtual public Post
{
private:
	Color videoColor;

public:
	VideoPost() = default;
	VideoPost(char* contentFromUser, Color videoColorFromUser);  //constructor
	VideoPost(const VideoPost & other); // copy ctor
	virtual void show();
	virtual bool operator==(VideoPost& other)const
	{
		return Post::operator==(other);
	}
	virtual bool operator!=(VideoPost& other)const
	{
		return !(*this == other);
	}
};
#endif
