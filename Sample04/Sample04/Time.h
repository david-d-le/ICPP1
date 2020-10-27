#pragma once
#ifndef TIME_H
#define TIME_H
#include "IComparable.h"

struct Time : public IComparable
{
private: 
	int m_hours;
	int m_minutes;
	int m_seconds;
public:
	int compareTo(IComparable* obj) const override;
	std::string toString() const override;
	Time(int hours, int minutes, int seconds);
};

#endif // !TIME_H

