#include "Person.h"
#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>

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
	Person person2 = Person("Peter", "adam", Address("street2", "city2", 22222), Date(2, 12, 2000));
	Person person3 = Person("Jane", "Austen", Address("street3", "city3", 33333), Date(3, 12, 2000));
	Person people[3] = { person1, person2, person3 };

	std::ofstream to{};
	to.open("file.bin", std::ios_base::binary);
	if (to.is_open())
	{
		for (int i = 0; i < 3; i++)
		{
			int size = 0;
			std::stringstream ss;
			ss << people[i];
			std::string s = ss.str();

			size = s.capacity();
			to.write((char*)&size, sizeof(int));
			to.write(s.c_str(), size);
		}
		to.close();
	}

}

void loadBinary() {
	// https://www.geeksforgeeks.org/processing-strings-using-stdistringstream/
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
			int size = 0;
			in.read((char*)&size, sizeof(int));
			in.seekg(size, std::ios_base::cur);
			count++;
		}
	}
	in.close();
	std::cout << std::endl << "number of persons in file: " << count;

	Person* people = new Person[count];
	in.open("file.bin", std::ios_base::binary);

	if (in.is_open())
	{
		for (int i = 0; i < count; i++)
		{
			int size = 0;
			char* s;

			in.read((char*)&size, sizeof(int));
			s = new char[size];
			in.read(s, size);
			std::istringstream ss(s);
			
			ss >> people[i];
			delete s;
			std::cout << std::endl << people[i];
		}
		
		in.close();
	}
	delete[] people;
}


int main(int argc, char** argv) {
	
	save();
	load();
	std::cout << std::endl;
	saveBinary();
	loadBinary();

	return 0;
}