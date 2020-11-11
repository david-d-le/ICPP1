#include "Address.h"

Address::Address(std::string street, std::string city, int postalCode)
	: _street(street), _city(city), _postalCode(postalCode){
}

Address::~Address(){
}


std::ostream& operator<<(std::ostream& os, const Address& address)
{
	os << address._street << " " << address._city << " " << address._postalCode;
	return os;
}

std::istream& operator>>(std::istream& is, Address& address)
{
	is >> address._street >> address._city >> address._postalCode;
	return is;
}