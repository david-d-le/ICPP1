#include "Person.h"

Person::Person(std::string firstName, std::string lastName, Address address, Date birthDate)
	: _firstName(firstName), _lastName(lastName), _address(address), _birthDate(birthDate) {
}

Person::~Person()
{
}

std::ostream& operator<<(std::ostream& os, const Person& person)
{
	os << person._firstName << " " << person._lastName << " " << person._address << " " << person._birthDate;
	return os;
}

std::istream& operator>>(std::istream& is, Person& person)
{
	is >> person._firstName >> person._lastName >> person._address >> person._birthDate;
	return is;
}