#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <iostream>

namespace Entity {
	class Person
	{
	private:
		std::string m_name;
		std::string m_phone;
		const int m_id;
	public:
		Person(std::string name, std::string phone, int id);
		int GetId() const;
		std::string GetName() const;
		std::string GetPhone() const;
	};
}

#endif // !PERSON_H


