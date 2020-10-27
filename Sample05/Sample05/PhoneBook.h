#pragma once
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Person.h"

namespace Model{
	class PhoneBook
	{
		class ListNode
		{
		public:
			ListNode* m_next;
			Object data;
		};

	private:
		void AddPerson(Entity::Person o);
		std::string FindPhone(std::string name) const;
		std::string FindPhone(int id) const;
	};
}

#endif // !PHONEBOOK_H



