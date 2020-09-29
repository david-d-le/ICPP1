#include <iostream>



typedef struct {
	int a, b, c;
}Triangle;

bool isConstructable(Triangle* t) {
	return (t->a + t->b) > t->c && (t->a + t->c) > t->b && (t->b + t->c) > t->a;
}

int main(int argc, char** argv) {
	Triangle* pointer = new Triangle();
	
	std::cout << "Insert number for side a:\n";
	std::cin >> pointer->a;
	std::cout << "Insert number for side b:\n";
	std::cin >> pointer->b;
	std::cout << "Insert number for side c:\n";
	std::cin >> pointer->c;

	if (isConstructable(pointer))
	{
		std::cout << "Perimeter of triangle is: " << (pointer->a + pointer->b + pointer->c);
	}
	else {
		std::cout << "Tringle with these sides is not valid";
	}
	delete pointer;
	return 0;
}


