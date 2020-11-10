#include "Person.h"
#include <iostream>
#include <iostream>
#include <fstream>

void save() {
	Person person1 = Person("James", "Bond", Address("street1", "city1", 11111), Date(1,12,2000));
	Person person2 = Person("Peter", "Novak", Address("street2", "city2", 22222), Date(2, 12, 2000));
	Person person3 = Person("Jane", "Austen", Address("street3", "city3", 33333), Date(3, 12, 2000));
	Person people[3] = { person1, person2, person3};

	std::ofstream to {};
	to.open("file.txt");
	if (to.is_open())
	{
		for (int i = 0; i < 3; i++)
		{
			to << people[i];
		}
		to.close();
	}
}

void load() {
	std::ifstream in{};
	in.open("file.txt");
	int counter = 0;
	Person p;
	while (!in.eof()) {
		in >> p;
		counter++;
	}
	in.close();


	Person* people = new Person[counter];
	in.open("file.txt");
	if (in.is_open())
	{
		for (int i = 0; i < counter; i++)
		{
			in >> people[i];
			std::cout << people[i] << "\n";
		}
		std::cout << "number of persons in file: " << counter;
		in.close();
	}
	delete[] people;
}

void saveBinary() {
	Person person1 = Person("James", "Bond", Address("street1", "city1", 11111), Date(1, 12, 2000));
	Person person2 = Person("Peter", "Novak", Address("street2", "city2", 22222), Date(2, 12, 2000));
	Person person3 = Person("Jane", "Austen", Address("street3", "city3", 33333), Date(3, 12, 2000));
	Person people[3] = { person1, person2, person3 };

	std::ofstream to{};
	to.open("file.bin", std::ofstream::binary);
	if (to.is_open())
	{
		for (int i = 0; i < 3; i++)
		{
			to << people[i];
		}
		to.close();
	}
}

void loadBinary() {
	std::ifstream in{};
	in.open("file.bin", std::ofstream::binary);
	int counter = 0;
	Person p;
	while (!in.eof()) {
		in >> p;
		counter++;
	}
	in.close();


	Person* people = new Person[counter];
	in.open("file.bin", std::ofstream::binary);
	if (in.is_open())
	{
		for (int i = 0; i < counter; i++)
		{
			in >> people[i];
			std::cout << people[i] << "\n";
		}
		std::cout << "number of persons in file: " << counter;
		in.close();
	}
	delete[] people;
}

int main(int argc, char** argv) {
	
	save();
	load();
	std::cout << "\n\n";
	saveBinary();
	loadBinary();

	return 0;
}