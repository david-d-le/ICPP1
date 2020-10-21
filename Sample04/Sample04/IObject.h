#pragma once
#ifndef IOBJECT_H
#define IOBJECT_H

#include <iostream>

class IObject
{
private:

public:
	virtual ~IObject();
	virtual std::string toString() const = 0;
};

#endif // !IOBJECT_H



