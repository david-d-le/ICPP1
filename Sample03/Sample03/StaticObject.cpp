#include "StaticObject.h"
#include "ObstacleType.h"

StaticObject::StaticObject(int id, ObstacleType obstacleType) : Object(id) {
	this->m_obstacleType = obstacleType;
}
ObstacleType StaticObject::GetObstacleType() const {
	return m_obstacleType;
}