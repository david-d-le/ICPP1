#pragma once
#ifndef GAME_H
#define GAME_H

#include "Object.h"
#include "MovingObject.h"
#include "StaticObject.h"

class Game {
private:
	Object** m_objects;
	int m_counter;
	int m_size;
public:
	Game(int size);
	~Game();
	void InsertObject(Object* o);
	int* FindIdOfStaticObjects(double xmin, double xmax, double ymin, double ymax);
	MovingObject** FindMovingObjectsInArea(double x, double y, double r);
	MovingObject** FindMovingObjectsInArea(double x, double y, double r, double umin, double umax);
};

#endif // !GAME_H
