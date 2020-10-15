#include "Object.h"

Object::Object(int id) {
	this->m_id = id;
	this->m_x = 0;	//???
	this->m_y = 0;	//???
}

Object::~Object() { 

}

int Object::GetId() const {
	return m_id;
}
double Object::GetX() const {
	return m_x;
}
void Object::SetX(double x) {
	this->m_x = x;
}
double Object::GetY() const {
	return m_y;
}
void Object::SetY(double y) {
	this->m_y = y;
}