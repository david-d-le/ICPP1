#include "Person.h"

Entity::Person::Person(std::string name, std::string phone, int id) : m_id(id){
	m_name = name;
	m_phone = phone;
}

int Entity::Person::GetId() const {
	return m_id;
}

std::string Entity::Person::GetName() const {
	return m_name;
}

std::string Entity::Person::GetPhone() const {
	return m_phone;
}

