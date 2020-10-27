#include "Person.h"

Entity::Person::Person(std::string name, std::string phone, int id) {
	this->m_id = id;
	this->m_name = name;
	this->m_phone = phone;
}