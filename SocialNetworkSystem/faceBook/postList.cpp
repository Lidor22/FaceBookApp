
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include "postList.h"
#include "post.h"
#include <typeinfo.h>


PostList::PostList()
{
	thePosts = new Post*[SIZE];
	logSize = 0;
	phySize = SIZE;
}

PostList::PostList(int size)
{
	thePosts = new Post*[size];
	logSize = 0;
	phySize = size;
}

PostList::PostList(const PostList & other)
{
	thePosts = other.thePosts;
	logSize = other.logSize;
	phySize = other.phySize;
}

PostList::~PostList()
{
	delete[]thePosts;
}

void PostList::addPost(Post*newPost)
{
	Post** newPostList;
	int i;

	if (logSize == phySize)
	{
		phySize *= SIZE;
		newPostList = new Post*[phySize];

		for (i = 0; i < logSize; i++)
		{
			newPostList[i] = thePosts[i];
		}
		delete[]thePosts;
		thePosts = newPostList;

	}
	thePosts[logSize] = newPost;
	logSize++;
}

void PostList::addPost(char* contentFromUser, int postColor, char* postFromUser)
{
	Color color;
	color = (Color)postColor;
	if (strcmp(contentFromUser, "text")==0)
	{
		TextPost* p = new TextPost(contentFromUser, postFromUser);
		TextPost* newPost = dynamic_cast<TextPost*>(p);
		if (newPost)
			this->addPost(p);
	}
	else if (strcmp(contentFromUser, "video")==0)
	{
		VideoPost* p = new VideoPost(contentFromUser, color);
		VideoPost* newPost = dynamic_cast<VideoPost*>(p);
		if (newPost)
			this->addPost(p);
	}
	else if (strcmp(contentFromUser, "image")==0)
	{
		ImagePost* p = new ImagePost(contentFromUser, color);
		ImagePost* newPost = dynamic_cast<ImagePost*>(p);
		if (newPost)
			this->addPost(p);
	}
	else if (strcmp(contentFromUser, "text and image")==0)
	{
		ImageAndTextPost* p = new ImageAndTextPost(ImagePost("image", color), TextPost("text", postFromUser));
		ImageAndTextPost* newPost = dynamic_cast<ImageAndTextPost*>(p);
		if (newPost)
			this->addPost(p);
	}
	else if (strcmp(contentFromUser, "text and video")==0)
	{
		VideoAndTextPost* p = new VideoAndTextPost(VideoPost("video", color), TextPost("text", postFromUser));
		VideoAndTextPost* newPost = dynamic_cast<VideoAndTextPost*>(p);
		if(newPost)
			this->addPost(p);
	}
}

int PostList::getSize()
{
	return logSize ;
}

Post* PostList::getPostByIndex(int index)
{
	int numOfPosts, i;

	numOfPosts = this->getSize();

	for (i = 0; i < numOfPosts; i++)
	{
		if (i == index)
		{
			return this->thePosts[i];
		}
	}
	return NULL;
}

Post** PostList::getThePosts()
{
	return this->thePosts;
}

PostList* PostList::getLatestPosts (int numPosts)
{
	PostList* result2=new PostList;
	int i;

	for (i = 0; i < numPosts && i < this->logSize; i++)
	{
		result2->addPost(this->getPostByIndex(this->logSize - 1 - i));
	}

	return result2;
}

void PostList::setLogSize(int size)
{
	this->logSize = size;
}

void PostList::show()
{
	int i;

	cout << "The posts are: \n";
	if (this->logSize != NULL )
	{
		for (i = 0; i < this->logSize; i++)
			thePosts[i]->show();
	}
	else
		cout << "No post to show ! " << endl;
}

