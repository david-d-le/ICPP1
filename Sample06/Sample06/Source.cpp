#include "ExpandingContainer.h"

int main(int argc, char** argv) {

	ExpandingContainer<std::string, 5> arr1{};
	std::string s1 = "string1";
	std::string s2 = "string2";
	std::string s3 = "string3";
	std::string s4 = "string4";
	std::string s5 = "string5";
	std::string s6 = "string6";
	arr1.Add(s1);
	arr1.AddToIndex(0,s2);
	arr1.AddToIndex(0, s3);
	arr1.AddToIndex(0, s4);
	arr1.AddToIndex(0, s5);
	arr1.AddToIndex(0, s6);
	for (unsigned i = 0; i < arr1.Size(); i++)
	{
		std::cout << arr1.operator[](i) << ", ";
	}
	std::cout << "\n";
	arr1.Remove(0);
	arr1.Remove(arr1.Size()-1);
	for (unsigned i = 0; i < arr1.Size(); i++)
	{
		std::cout << arr1.operator[](i) << ", ";
	}

	return 0;
}