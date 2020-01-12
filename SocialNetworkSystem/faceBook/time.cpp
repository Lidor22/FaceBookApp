#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;


#include "time.h"
#include <time.h>
#include <math.h>
#include <string.h>

int Time::charToDig(char ch)
{
	return (ch - '0');
}

Time::Time()
{
	int counter = 0;
	time_t curtime;
	time(&curtime);
	char str[26];
	strcpy(str, ctime(&curtime));

	char* token = strtok(str, " ");
	while (token != NULL)
	{
		if (counter == 1)
			month = monthToNum(token);
		else if (counter == 2)
			day = atoi(token);
		else if (counter == 3)
		{
			hours = charToDig(token[0]) * 10;
			hours += charToDig((token[1]));
			minutes = charToDig(token[3]) * 10;
			minutes += charToDig((token[4]));
			seconds = charToDig(token[6]) * 10;
			seconds += charToDig((token[7]));

		}
		else if (counter == 4)
			year = atoi(token);

		counter++;
		token = strtok(NULL, " ");
	}

}

int Time::monthToNum(char* str)
{
	if (strcmp(str, "Jan") == 0)
		return 1;
	else if (strcmp(str, "Feb") == 0)
		return 2;
	else if (strcmp(str, "Mar") == 0)
		return 3;
	else if (strcmp(str, "Apr") == 0)
		return 4;
	else if (strcmp(str, "May") == 0)
		return 5;
	else if (strcmp(str, "Jun") == 0)
		return 6;
	else if (strcmp(str, "Jul") == 0)
		return 7;
	else if (strcmp(str, "Aug") == 0)
		return 8;
	else if (strcmp(str, "Sep") == 0)
		return 9;
	else if (strcmp(str, "Oct") == 0)
		return 10;
	else if (strcmp(str, "Nov") == 0)
		return 11;
	else
		return 12;
}

int Time::getDay()
{
	return this->day;
}

int Time::getMonth()
{
	return this->month;
}

int Time::getYear()
{
	return this->year;
}

int Time::getHours()
{
	return this->hours;
}

int Time::getMinutes()
{
	return this->minutes;
}

int Time::getSeconds()
{
	return this->seconds;
}

void Time::show()
{
	cout << "The date is " << day << "." << month << "." << year << endl;
	cout << "The time is " << hours << ":" << minutes << ":" << seconds << endl;

}