#define _CRT_SECURE_NO_WARNINGS


#pragma once
#ifndef __TIME_H
#define __TIME_H

class Time
{
private:
	int day;
	int month;
	int year;

	int hours;
	int minutes;
	int seconds;

public:
	Time();
	int charToDig(char ch); //char to int
	int monthToNum(char* str); //getting the month our of a given string
	int getDay(); // get method - getting the Day
	int getMonth();// get method - getting the month
	int getYear();// get method - getting the year
	int getHours();// get method - getting the hours
	int getMinutes();// get method - getting the minutes
	int getSeconds();// get method - getting the seconds
    void show();//show method - printing to screen
};

#endif // __DATE_H


