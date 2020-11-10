#include "Date.h"

Date::Date(int day, int month, int year) : _day(day), _month(month), _year(year) {

}

Date::~Date(){

}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
	os << date._day << " " << date._month << " " << date._year;
	return os;
}

std::istream& operator>>(std::istream& is, Date& date)
{
	is >> date._day >> date._month >> date._year;
	return is;
	// TODO: insert return statement here
}
