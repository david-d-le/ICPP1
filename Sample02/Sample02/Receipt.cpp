#include "Receipt.h"

void Receipt::SetId(unsigned int id) {
	this->id = id;
}
int Receipt::GetId() const {
	return this->id;
}

void Receipt::SetPrice(double price) {
	this->price = price;
}
double Receipt::GetPrice() const {
	return this->price;
}

void Receipt::SetDph(double dph) {
	this->dph = dph;
}
double Receipt::GetDph() const {
	return this->dph;
}