#define _CRT_SECURE_NO_WARNINGS
#pragma once



#ifndef __VIDEOANDTEXTPOST_H
#include "VideoPost.h"
#include "TextPost.h"


class VideoAndTextPost : public VideoPost,public TextPost
{
public:
	VideoAndTextPost(const VideoPost &vp, const TextPost& tp) :Post("VideoAndTextPost"), VideoPost(vp), TextPost(tp) {}  //constructor
	virtual void show()
	{
		VideoPost::show();
		TextPost::show();
	}
	virtual bool operator==(VideoAndTextPost& other)const
	{
		if (!TextPost::operator==(other))
			return false;
		else
			return true;
	}
	virtual bool operator!=(VideoAndTextPost& other)const
	{
		return !(*this == other);
	}
};
#endif

