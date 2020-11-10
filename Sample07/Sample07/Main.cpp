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
	to.open("file.bin", std::ios_base::binary);
	if (to.is_open())
	{
		for (int i = 0; i < 3; i++)
		{

			to.write((char*)&people[i], sizeof(people[i]));
			
		}
		to.close();
	}

}

void loadBinary() {
	/* https://www.tutorialspoint.com/reading-and-writing-binary-file-in-c-cplusplus */
	std::ifstream in{};
	int count = 0;
	in.open("file.bin", std::ios_base::binary);
	if (in.is_open())
	{
		in.seekg(0, std::ios_base::end);
		int end = in.tellg();
		in.seekg(0, std::ios_base::beg);
		while (in.tellg() != end)
		{
			in.seekg(sizeof(Person), std::ios_base::cur);
			count++;
		}
	}
	in.close();

	Person* people = new Person[count];
	in.open("file.bin", std::ios_base::binary);
	
	if (in.is_open())
	{
		//TODO
		for (int i = 0; i < count; i++)
		{
			in.read((char*)&people[i], sizeof(Person));
			std::cout << std::endl << people[i];
		}
		std::cout << std::endl << "number of persons in file: " << count;
		in.close();
	}
}

int main(int argc, char** argv) {
	
	save();
	load();
	std::cout << std::endl;
	saveBinary();
	loadBinary();

	return 0;
}