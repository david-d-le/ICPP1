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
/*
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
			size = people[i]._firstName.capacity();
			to.write((char*)&size, sizeof(int));
			to.write(people[i]._firstName.c_str(), people[i]._firstName.capacity());
			size = people[i]._lastName.capacity();
			to.write((char*)&size, sizeof(int));
			to.write(people[i]._lastName.c_str(), people[i]._lastName.capacity());
			
			size = people[i]._address._street.capacity();
			to.write((char*)&size, sizeof(int));
			to.write(people[i]._address._street.c_str(), people[i]._address._street.capacity());

			size = people[i]._address._city.capacity();
			to.write((char*)&size, sizeof(int));
			to.write(people[i]._address._city.c_str(), people[i]._address._city.capacity());


			to.write((char*)&people[i]._address._postalCode, sizeof(int));
			to.write((char*)&people[i]._birthDate, sizeof(Date));
		}
		to.close();
	}

}
*/
/*
void loadBinary() {
	// https://www.tutorialspoint.com/reading-and-writing-binary-file-in-c-cplusplus 
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
			for (int i = 0; i < 4; i++)
			{
				in.read((char*)&size, sizeof(int));
				in.seekg(size, std::ios_base::cur);
			}
			in.seekg(sizeof(int), std::ios_base::cur);
			in.seekg(sizeof(Date), std::ios_base::cur);
			count++;
		}
	}
	in.close();


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
			people[i]._firstName = s;
			delete[] s;

			in.read((char*)&size, sizeof(int));
			s = new char[size];
			in.read(s, size);
			people[i]._lastName = s;
			delete[] s;

			in.read((char*)&size, sizeof(int));
			s = new char[size];
			in.read(s, size);
			people[i]._address._street = s;
			delete[] s;

			in.read((char*)&size, sizeof(int));
			s = new char[size];
			in.read(s, size);
			people[i]._address._city = s;
			delete[] s;


			in.read((char*)&people[i]._address._postalCode, sizeof(int));
			in.read((char*)&people[i]._birthDate, sizeof(Date));

			std::cout << std::endl << people[i];
		}
		std::cout << std::endl << "number of persons in file: " << count;
		in.close();
	}
}
*/


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

			std::cout << std::endl << people[i];
		}
		
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