#define _USE_MATH_DEFINES
#include <iostream>
#include "Game.h"
#include "Monster.h"
#include <cmath>

int main(int argc, char** argv) {

	Object* object1 = new StaticObject{ 1, ObstacleType::SmallPlant };
	Object* object2 = new StaticObject{ 2, ObstacleType::BigPlant };
	object2->SetX(2);
	object2->SetY(2);
	Object* object3 = new MovingObject{ 3, M_PI };
	object3->SetX(1);
	object3->SetY(1);
	Object* object4 = new Monster{ 4, 2*M_PI };
	object4->SetX(10);
	object4->SetY(10);
	Game game{ 1 };
	game.InsertObject(object1);
	game.InsertObject(object2);
	game.InsertObject(object3);
	game.InsertObject(object4);

	int* ids = game.FindIdOfStaticObjects(0,2,0,3);
	int iterator = 0;
	std::cout << "id's of static objects ";
	while (ids[iterator] != -1)
	{
		std::cout << ids[iterator++] << ", ";
	}

	std::cout << "\n";
	iterator = 0;

	MovingObject** foundMovingObjectsPtrs = game.FindMovingObjectsInArea(0,0,100,0,2*M_PI);
	std::cout << "pointers of moving objects: ";
	while (foundMovingObjectsPtrs[iterator] != nullptr)
	{
		std::cout << foundMovingObjectsPtrs[iterator++] << ", ";
	}

	delete[] ids;
	delete[] foundMovingObjectsPtrs;
	return 0;
}
