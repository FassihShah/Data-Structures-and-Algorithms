#ifndef DATE_H
#define DATE_H
#include"String.h"
class Date
{
	int day;
	int month;
	int year;
	static const String monthsName[13];
public:
	Date();
	Date(int, int, int);
	void setDate(int, int, int);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void addDays(int = 1);
	void subtractDays(int = 1);
	void displayDate();
	~Date();
};
#endif