#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "faceBook.h"

using namespace std;

/*Chen Gohari and Lidor Hadar social network project.
05.01.19 
The project is called FaceBook and basically works like a social media program - based on the given instructions 
from the staff.
Please be aware that we assume that the input is VALID.*/

void main()
{
	FaceBook myFaceBook;
	char choice;
	
	menu();

	cin >> choice;

	while (choice != 9)
	{
		switch (choice)
		{
		case '1':
		{
			myFaceBook.createNewEntity();
			break;
		}
		case '2':
		{
			myFaceBook.writePost();
			break;
		}
		case '3':
		{
			myFaceBook.showAllEntityPosts();
			break;
		}
		case '4':
		{
			myFaceBook.addNewFriend();
			break;
		}
		case '5':
		{
			myFaceBook.likeFansPage();
			break;
		}
		case '6':
		{
			myFaceBook.showAllTheEntitysOnFacebook();
			break;
		}
		case '7':
		{
			myFaceBook.showAllFriendsOfMemberOrFanPage();
			break;
		}
		case '8':
		{
			myFaceBook.showTenLastestPostsOfMembersFriends();
			break;
		}
		case '9':
		{
			exit(1);
			break;
		}
		
		default:
			break;
		}

		menu();
		cin >> choice;
	}
}