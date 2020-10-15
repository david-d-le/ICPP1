#pragma once
#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include "Object.h"

class MovingObject : public Object {
private: 
	double m_rotationAngle;
public:
    MovingObject(int id, double rootationAngle);
    ~MovingObject();
    double GetRotationAngle() const;
    void SetRotationAngle(double rotationAngle); // 0 – 2*pi, 0 – north, pi - south

};

#endif // !MOVINGOBJECT_H
