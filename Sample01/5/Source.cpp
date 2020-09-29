#include <iostream>



typedef struct {
	int a, b, c;
}Triangle;

bool isConstructable(Triangle* t) {
	return (t->a + t->b) > t->c && (t->a + t->c) > t->b && (t->b + t->c) > t->a;
}

int main(int argc, char** argv) {
	int numberOfTriangles;
	std::cout << "Insert number of triangles\n";
	std::cin >> numberOfTriangles;
	
	Triangle* arrayTriang = new Triangle[numberOfTriangles];

	for (int i = 0; i < numberOfTriangles; i++)
	{
		std::cout << "Insert number for side a of " << i+1 << ". triangle:\n";
		std::cin >> arrayTriang[i].a;
		std::cout << "Insert number for side b of " << i+1 << ". triangle:\n";
		std::cin >> arrayTriang[i].b;
		std::cout << "Insert number for side c of " << i+1 << ". triangle:\n";
		std::cin >> arrayTriang[i].c;
	}
	for (int i = 0; i < numberOfTriangles; i++)
	{
		if (isConstructable(&arrayTriang[i]))
		{
			std::cout << "Perimeter of "<< i+1 <<". triangle is: " << (arrayTriang[i].a + arrayTriang[i].b + arrayTriang[i].c) << "\n";
		}
		else {
			std::cout << i << ". tringle with these sides is not Constructable\n";
		}
	}
	delete[] arrayTriang;
	return 0;
}


