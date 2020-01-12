#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include "ImagePost.h"

ImagePost::ImagePost(char* contentFromUser, Color imageColorFromUser):Post(contentFromUser)
{
	imageColor = imageColorFromUser;
}

ImagePost::ImagePost(const ImagePost & other):Post(other)
{
	imageColor = other.imageColor;
}

void ImagePost::show()
{
	cout << "This is " << imageColor << " Image !" << endl;
}