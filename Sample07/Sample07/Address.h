#pragma once
#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>

struct Address
{
	std::string _street;
	std::string _city;
	int _postalCode;
	Address() {};
	Address(std::string street, std::string city, int postalCode);
	~Address();
};
std::ostream& operator<<(std::ostream& os, const Address& person);
std::istream& operator>>(std::istream& is, Address& obj);

#endif // !ADDRESS_H



