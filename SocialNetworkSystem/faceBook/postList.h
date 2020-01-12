#define _CRT_SECURE_NO_WARNINGS

#pragma once

#ifndef __POSTLIST_H
#define SIZE 2
#include "TextPost.h"
#include "VideoPost.h"
#include "ImagePost.h"
#include "VideoAndTextPost.h"
#include "ImageAndTextPost.h"

class Post;

class PostList
{
private:
	Post** thePosts;
	int logSize;
	int phySize;

public:
	PostList(); //constructor default
	PostList(int size);//constructor 
	PostList(const PostList & other);// copy ctor
	~PostList();// d'tor
	virtual void addPost(char* contentFromUser, int postColor, char* postFromUser = NULL);
	virtual void addPost(Post* newPost);
	int getSize(); //get method - getting the size of a given postList
	Post* getPostByIndex(int index); //get method - getting the post using the index
	Post** getThePosts();//get method - getting the entire post list
	PostList* getLatestPosts(int numPosts);//get method - getting latest posts .
	void setLogSize(int size); // setting the logsize of a given postList
    void show(); //show method - printing to screen	
};
#endif // ! __POSTLIST_H
