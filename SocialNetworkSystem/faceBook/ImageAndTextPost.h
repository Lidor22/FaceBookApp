#define _CRT_SECURE_NO_WARNINGS
#pragma once



#ifndef __IMAGEANDTEXTPOST_H
#include "ImagePost.h"
#include "TextPost.h"


class ImageAndTextPost : public ImagePost, public TextPost
{
public:
	ImageAndTextPost(const ImagePost &ip, const TextPost& tp) :Post("ImageAndTextPost"), ImagePost(ip), TextPost(tp)
	{}  //constructor
	virtual void show()
	{
		ImagePost::show();
		TextPost::show();
	}
	virtual bool operator==(ImageAndTextPost& other)const
	{
		if (!TextPost::operator==(other))
			return false;
		else
			return true;
	}
	virtual bool operator!=(ImageAndTextPost& other)const
	{
		return !(*this == other);
	}
};
#endif
