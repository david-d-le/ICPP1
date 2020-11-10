#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "Address.h"
#include "Date.h"


struct Person
{
	std::string _firstName;
	std::string _lastName;
	Address _address;
	Date _birthDate;
	Person() {};
	Person(std::string firstName, std::string lastName, Address address, Date birthDate);
	~Person();
};
std::ostream& operator<<(std::ostream& os, const Person& person);
std::istream& operator>>(std::istream& is, Person& obj);

#endif // !PERSON_H



