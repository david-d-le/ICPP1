#include "Person.h"
#include "PhoneBook.h"
#include <iostream>

int main(int argc, char** argv) {
	Model::PhoneBook phoneBook1 = Model::PhoneBook::PhoneBook();
	Entity::Person person1 = Entity::Person("Peter","111111111",1);
	Entity::Person person2 = Entity::Person("John", "222222222", 2);
	Entity::Person person3 = Entity::Person("Jackson", "333333333", 3);
	phoneBook1.AddPerson(person1);
	phoneBook1.AddPerson(person3);
	phoneBook1.AddPerson(person2);
	std::cout << "found phone: " << phoneBook1.FindPhone("John");
}