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
		int m_id;
	public:
		Person(std::string name, std::string phone, int id);
	};
}

#endif // !PERSON_H


