#pragma once

#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "Object.h"
#include "ObstacleType.h"

class StaticObject : public Object {

private:
	ObstacleType m_obstacleType;
public:
	StaticObject(int id, ObstacleType obstacleType);
	ObstacleType GetObstacleType() const;
};
#endif // !STATICOBJECT_H

