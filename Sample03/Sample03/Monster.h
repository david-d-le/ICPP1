#pragma once
#ifndef MONSTER_H
#define MONSTER_H

#include "MovingObject.h"

class Monster : public MovingObject
{
private:
	int m_hp;
	int m_maxhp;
public:
	Monster(int id, double rotationAngle);
	~Monster();
	int GetHp() const;
	void SetHp(int hp);
	int GetMaxhp() const;
	void SetMaxhp(int maxhp);
};

#endif // !MONSTER_H
