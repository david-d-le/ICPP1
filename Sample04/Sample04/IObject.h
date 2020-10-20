#pragma once
#ifndef IOBJECT_H
#define IOBJECT_H

#include <iostream>
using namespace std;

class IObject
{
private:

public:
	virtual ~IObject();
	virtual string toString() const = 0;
};

#endif // !IOBJECT_H



