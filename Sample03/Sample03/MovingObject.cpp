#include "MovingObject.h"

MovingObject::MovingObject(int id, double rotationAngle) : Object(id){
	this->m_rotationAngle = rotationAngle;
}
MovingObject::~MovingObject() {

}

double MovingObject::GetRotationAngle() const {
	return m_rotationAngle;
}
void MovingObject::SetRotationAngle(double rotationAngle) {
	this->m_rotationAngle = rotationAngle;
}