#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include"fanPage.h"
#include "member.h"

FanPage::FanPage(char* fanPageName):Entity(fanPageName)
{
}

FanPage::FanPage(const FanPage & other): Entity(other)
{
}

