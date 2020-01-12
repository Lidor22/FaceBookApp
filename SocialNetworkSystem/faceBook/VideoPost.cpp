#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


#include "VideoPost.h"

VideoPost::VideoPost(char* contentFromUser, Color videoColorFromUser):Post(contentFromUser)
{
	videoColor = videoColorFromUser;
}

VideoPost::VideoPost(const VideoPost & other):Post(other)
{
	videoColor = other.videoColor;
}

void VideoPost::show()
{
	cout << "This is " <<videoColor<<" Video !" << endl;
}