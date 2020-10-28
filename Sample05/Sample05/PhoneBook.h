#pragma once
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Person.h"

namespace Model{
	class PhoneBook
	{
	private:
		class ListNode
		{
		public:
			ListNode* m_next;
			Entity::Person m_data;
			ListNode(Entity::Person person);
		};

	private:
		ListNode* m_beginning;
	public:
		PhoneBook();
		~PhoneBook();
		void AddPerson(Entity::Person o);
		std::string FindPhone(std::string name) const;
		std::string FindPhone(int id) const;
	};
}


#endif // !PHONEBOOK_H



