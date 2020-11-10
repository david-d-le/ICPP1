#pragma once
#ifndef DATE_H
#define DATE_H

#include <iostream>

struct Date
{
	int _day;
	int _month;
	int _year;
	Date() {};
	Date(int day, int month, int year);
	~Date();
};
std::ostream& operator<<(std::ostream& os, const Date& person);
std::istream& operator>>(std::istream& is, Date& obj);


#endif // !DATE_H

