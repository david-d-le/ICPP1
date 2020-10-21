#include "Time.h"
#include <string>

using namespace std;

Time::Time(int hours, int minutes, int seconds) {
	this->m_hours = hours%24;
	this->m_minutes = minutes%60;
	this->m_seconds = seconds%60;
}

int Time::compareTo(IComparable* obj) const {
	Time* right = dynamic_cast<Time*>(obj);
	if (m_hours > right->m_hours){
		return 1;
	}else if (m_hours < right->m_hours) {
		return -1;
	}

	if (m_minutes > right->m_minutes){
		return 1;
	}else if (m_minutes < right->m_minutes) {
		return -1;
	}

	if (m_seconds > right->m_seconds){
		return 1;
	}else if (m_seconds < right->m_seconds) {
		return -1;
	}
	return 0;
}

string Time::toString() const {
	return "Time: hours: " + to_string(m_hours) + " minutes: " + to_string(m_minutes) + " seconds: " + to_string(m_seconds) + "\n";
}