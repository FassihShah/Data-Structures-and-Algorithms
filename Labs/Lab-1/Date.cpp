#include<iostream>
#include"Date.h"
#include"String.h"
using namespace std;
const String Date::monthsName[13] = { "","January","February","March","April","May","June","July","August","September","October","November","December" };
Date::Date()
{
	this->~Date();
}
Date::Date(int d, int m, int y) :Date()
{
	setMonth(m);
	setDay(d);
	setYear(y);
}
void Date::setDate(int d, int m, int y)
{
	setMonth(m);
	setDay(d);
	setYear(y);
}
void Date::setDay(int d)
{
	if (d > 0 && d <= 30)
	{
		day = d;
	}
}
void Date::setMonth(int m)
{
	if (m > 0 && m <= 12 && day <= 30)
	{
		month = m;
	}
}
void Date::setYear(int y)
{
	if (y >= 1000 && y <= 3000)
	{
		year = y;
	}
}
int Date::getDay() const
{
	return day;
}
int Date::getMonth() const
{
	return month;
}
int Date::getYear() const
{
	return year;
}
void Date::addDays(int d)
{
	if (d <= 0)
		return;
	day = day + d;
	month = month + (day / 30);
	day = day % 30;
	year = year + (month / 12);
	month = month % 12;
}
void Date::subtractDays(int d)
{
	if (d <= 0)
		return;
	day = day - d;
	while (day <= 0)
	{
		day += 30;
		month--;
		if (month <= 0)
		{
			month += 12;
			year--;
		}
	}
}
void Date::displayDate()
{
	cout << monthsName[month] << " " << day << ", " << year;
}
Date::~Date()
{
	day = 1;
	month = 1;
	year = 2000;
}