#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include "member.h"
#include <typeinfo.h>




Member::Member(char* userName, char* bDay):Entity(userName)
{
	strcpy(birthDay, bDay);
}

Member::Member(const Member & other):Entity(other)
{
	strcpy(birthDay, other.birthDay);
}

PostList* Member::getLatestPostOfMember(int numPosts)
{
	return this->entityPostList.getLatestPosts(numPosts);
}

PostList* Member::getLatestPostOfAllFriens(int numPosts)
{
	PostList* result = new PostList;
	PostList* prevResult = NULL;
	PostList* friendResult = NULL;
	int i, count = 0;
	int prevResultIndex, friendResultIndex, resultIndex;
	Entity* temp;

	for (i = 0; i < this->allEntitys.getSize(); i++)
	{
		temp = this->allEntitys.getEntityByIndex(i);
		if (typeid(temp) == typeid(Member*))
		{
			friendResult = (this->allEntitys.getEntityByIndex(i))->getLatestPostOfEntity(numPosts);
			
			while (friendResult->getThePosts() == NULL)
			{
				i++;
				temp = this->allEntitys.getEntityByIndex(i);
				while (typeid(temp) != typeid(Member*))
				{
					i++;
					temp = this->allEntitys.getEntityByIndex(i);
				}

					friendResult = (this->allEntitys.getEntityByIndex(i))->getLatestPostOfEntity(numPosts);
				
			}

			prevResult = result;
			result = new PostList(numPosts);

			prevResultIndex = friendResultIndex = resultIndex = 0;
			while ((prevResultIndex < prevResult->getSize() || friendResultIndex < friendResult->getSize())
				&& resultIndex < numPosts)
			{
				Post* p1 = friendResult->getThePosts()[friendResultIndex];

				if (count != 0)
				{
					Post* p2 = prevResult->getThePosts()[prevResultIndex];
					if (friendResultIndex < friendResult->getSize())
						result->getThePosts()[resultIndex] = compTime(p1, p2);
					else
						result->getThePosts()[resultIndex] = p2;

					if (result->getThePosts()[resultIndex] == p1)
						friendResultIndex++;
					else
						prevResultIndex++;
				}
				else
				{
					result->getThePosts()[resultIndex] = p1;
					friendResultIndex++;
				}
				resultIndex++;
			}
			count++;

			delete friendResult;
			delete prevResult;
			result->setLogSize(resultIndex);
		}
	}

	result->setLogSize(resultIndex);
	return result;
}

char* Member::getBday()
{
	return this->birthDay;
}

void Member::show()
{
	cout << this->name << " " << this->birthDay << endl;
}


