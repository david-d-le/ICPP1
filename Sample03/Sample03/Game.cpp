#include "Game.h"
#define DEF_SIZE 10;
Game::Game(int size) {
	this->m_counter = 0;
	if (size == 0){
		this->m_size = DEF_SIZE;
	}
	else {
		this->m_size = size;
	}
	this->m_objects = new Object * [m_size];
}
Game::~Game() {
	for (int i = 0; i < m_counter; i++)
	{
		delete m_objects[i];
	}
	delete[] m_objects;
}



void Game::InsertObject(Object* o) {
	if (m_counter >= m_size)
	{
		m_size *= 2;
		Object** objects = new Object * [m_size];
		for (int i = 0; i < m_counter; i++)
		{
			objects[i] = m_objects[i];
		}

		Object** temp = m_objects;
		m_objects = objects;
		delete[] temp;	//removes old smaller array of pointers
	}

	m_objects[m_counter] = o;
	m_counter++;
}

int* Game::FindIdOfStaticObjects(double xmin, double xmax, double ymin, double ymax) {
	int* ids = new int[m_counter+1];
	int numOfFoundStaticObj = 0;
	for (int i = 0; i < m_counter; i++)
	{
		if (dynamic_cast<StaticObject*>(m_objects[i]) != nullptr && 
			m_objects[i]->GetX() >= xmin && m_objects[i]->GetX() <= xmax &&
			m_objects[i]->GetY() >= ymin && m_objects[i]->GetY() <= ymax)
		{
			ids[numOfFoundStaticObj++] = m_objects[i]->GetId();
		}
	}
	ids[numOfFoundStaticObj] = -1;	//end of array value 
	return ids;
}

MovingObject** Game::FindMovingObjectsInArea(double x, double y, double r) {
	MovingObject** movObjs = new MovingObject * [m_counter + 1];
	int numOfFoundMovingObj = 0;
	for (int i = 0; i < m_counter; i++)
	{
		if (dynamic_cast<MovingObject*>(m_objects[i]) != nullptr &&
			((m_objects[i]->GetX()-x)*(m_objects[i]->GetX() - x) + 
				(m_objects[i]->GetY()-y)*(m_objects[i]->GetY() - y)) <= 2*r)
		{
			movObjs[numOfFoundMovingObj++] = dynamic_cast<MovingObject*>(m_objects[i]); //TODO
		}
	}
	movObjs[numOfFoundMovingObj] = nullptr;	//end of array value 
	return movObjs;
}

MovingObject** Game::FindMovingObjectsInArea(double x, double y, double r, double umin, double umax) {
	MovingObject** movObjs = new MovingObject * [m_counter + 1];
	int numOfFoundMovingObj = 0;
	for (int i = 0; i < m_counter; i++)
	{
		if (dynamic_cast<MovingObject*>(m_objects[i]) != nullptr &&
			((m_objects[i]->GetX() - x) * (m_objects[i]->GetX() - x) +
				(m_objects[i]->GetY() - y) * (m_objects[i]->GetY() - y)) <= 2 * r &&
			dynamic_cast<MovingObject*>(m_objects[i])->GetRotationAngle() >= umin &&
			dynamic_cast<MovingObject*>(m_objects[i])->GetRotationAngle() <= umax)	//TODO refactor
		{
			movObjs[numOfFoundMovingObj++] = dynamic_cast<MovingObject*>(m_objects[i]); //TODO
		}
	}
	movObjs[numOfFoundMovingObj] = nullptr;	//end of array value 
	return movObjs;
}