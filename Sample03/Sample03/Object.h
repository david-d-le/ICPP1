#pragma once
#ifndef OBJECT_H
#define OBJECT_H

class Object {
private:
    int m_id;
    double m_x;
    double m_y;

public:
    Object(int id);
    virtual ~Object();

    int GetId() const;
    double GetX() const;
    void SetX(double x);
    double GetY() const;
    void SetY(double y);

};

#endif // !OBJECT_H
