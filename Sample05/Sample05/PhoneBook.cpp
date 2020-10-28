#include "PhoneBook.h"
#include <exception>

Model::PhoneBook::PhoneBook() {
	m_beginning = nullptr;
}

Model::PhoneBook::~PhoneBook(){
	Model::PhoneBook::ListNode* node = m_beginning;
	while (node != nullptr){
		Model::PhoneBook::ListNode* tmp = node->m_next;
		delete node;
		node = tmp;
	}
}

void Model::PhoneBook::AddPerson(Entity::Person person) {
	if (m_beginning == nullptr)
	{
		m_beginning = new Model::PhoneBook::ListNode(person);
	}
	else {
		Model::PhoneBook::ListNode* newNode = new Model::PhoneBook::ListNode(person);
		newNode->m_next = m_beginning;
		m_beginning = newNode;
	}
}

std::string Model::PhoneBook::FindPhone(std::string name) const {
	if (name.empty())
	{
		throw std::invalid_argument("Given name is empty");
	}
	Model::PhoneBook::ListNode* next = m_beginning;
	while (next != nullptr){
		if (next->m_data.GetName() == name){
			return next->m_data.GetPhone();
		}
		next = next->m_next;
	}
	throw "Phone not found with given name";
}
std::string Model::PhoneBook::FindPhone(int id) const {
	if (id < 0)
	{
		throw std::invalid_argument("id cannot be negative number");
	}
	Model::PhoneBook::ListNode* next = m_beginning;
	while (next != nullptr) {
		if (next->m_data.GetId() == id) {
			return next->m_data.GetPhone();
		}
		next = next->m_next;
	}
	throw "Phone not found with given id";
}

Model::PhoneBook::ListNode::ListNode(Entity::Person person) : m_data(person), m_next(nullptr) {}
