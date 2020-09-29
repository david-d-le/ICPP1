#include <iostream>



struct Triangle {
	int a, b, c;
};

bool isConstructable(Triangle t) {
	return (t.a + t.b) > t.c && (t.a + t.c) > t.b && (t.b + t.c) > t.a;
}

int main(int argc, char** argv) {
	Triangle t;
	
	std::cout << "Insert number for side a:\n";
	std::cin >> t.a;
	std::cout << "Insert number for side b:\n";
	std::cin >> t.b;
	std::cout << "Insert number for side c:\n";
	std::cin >> t.c;

	if (isConstructable(t))
	{
		std::cout << "Perimeter of triangle is: " << (t.a + t.b + t.c);
	}
	else {
		std::cout << "Tringle with these sides is not valid";
	}
	return 0;
}


