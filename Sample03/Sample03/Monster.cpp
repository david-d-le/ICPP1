#include "Monster.h"
#define DEF_MAX_HEALTH 100

Monster::Monster(int id, double rotationAngle) : MovingObject(id, rotationAngle) {
	this->m_hp = DEF_MAX_HEALTH;
	this->m_maxhp = DEF_MAX_HEALTH;
}
Monster::~Monster() {
	
}

int Monster::GetHp() const {
	return m_hp;
}
void Monster::SetHp(int hp) {
	this->m_hp = hp;
}
int Monster::GetMaxhp() const {
	return m_maxhp;
}
void Monster::SetMaxhp(int maxhp) {
	this->m_maxhp = maxhp;
}