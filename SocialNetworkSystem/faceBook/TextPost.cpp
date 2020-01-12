#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include "TextPost.h"

TextPost::TextPost(char* contentFromUser, char* theUserPost) :Post(contentFromUser) //constructor
{
	textPost = new char[strlen(theUserPost) + 1];
	strcpy(textPost, theUserPost);
}

TextPost::TextPost(const TextPost & other) :Post(other)// copy ctor
{
	textPost = new char[strlen(other.textPost) + 1];
	strcpy(textPost, other.textPost);
}

TextPost::~TextPost()  //d'tor
{
	delete[]textPost;
}

char* TextPost::getPost()
{
	return this->textPost;
}

void TextPost::show()
{
	cout << textPost << endl;
}