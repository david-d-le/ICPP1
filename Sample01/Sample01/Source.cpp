#include <iostream>

int main(int argc, char** argv) {
	int a, b, c;
	std::cout << "Insert number for side a:\n";
	std::cin >> a;
	std::cout << "Insert number for side b:\n";
	std::cin >> b;
	std::cout << "Insert number for side c:\n";
	std::cin >> c;

	if ((a + b) > c && (a + c) > b && (b + c) > a)
	{
		std::cout << "Perimeter of triangle is: " << (a+b+c);
	}
	else {
		std::cout << "Tringle with these sides is not valid";
	}
	return 0;
}