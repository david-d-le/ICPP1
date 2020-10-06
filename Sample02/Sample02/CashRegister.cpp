#include "CashRegister.h"
#include <exception>
#include <iostream>

#define ID_COUNTER_INIT_VALUE 1000;
const int MAX_NUMBER_OF_RECEIPTS = 10;
int CashRegister::idCounter = ID_COUNTER_INIT_VALUE;

CashRegister::CashRegister() {
	receiptsCount = 0;
	receipts = new Receipt[MAX_NUMBER_OF_RECEIPTS];
}

CashRegister::~CashRegister() {
	delete[] receipts;
}

Receipt& CashRegister::CreateReceipt(double cost, double dph) {
	if (receiptsCount >= MAX_NUMBER_OF_RECEIPTS)
	{
		throw new std::exception("CashRegister is full.");
	}
	receipts[receiptsCount].SetId(++idCounter);
	receipts[receiptsCount].SetPrice(cost);
	receipts[receiptsCount].SetDph(dph);
	return receipts[receiptsCount++];
}

Receipt& CashRegister::FindReceipt(int id) {
	if (receiptsCount <= 0)
	{
		throw new std::exception("There is no receipt.");
	}
	else {
		for (int i = 0; i < receiptsCount; i++){
			if (receipts[i].GetId() == id)
			{
				return receipts[i];
			}
		}
		
	}
	
	return receipts[0];
}

double CashRegister::GetSum() const {
	double sum = 0;
	if (receiptsCount <= 0)
	{
		return 0;
	}
	for (int i = 0; i < receiptsCount; i++)
	{
		sum += receipts[i].GetPrice();
	}
	return sum;
}

double CashRegister::GetSumTaxed() const {
	double sum = 0;
	if (receiptsCount <= 0)
	{
		return 0;
	}
	for (int i = 0; i < receiptsCount; i++)
	{
		sum += (receipts[i].GetPrice()*(1+ receipts[i].GetDph()/100));
	}
	return sum;
}