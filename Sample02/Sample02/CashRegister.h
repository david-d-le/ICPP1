#pragma once
#ifndef CASH_REGISTER_H
#define CASH_REGISTER_H

#include "Receipt.h"

class CashRegister {
	static int idCounter;
	Receipt* receipts;
	int receiptsCount;
public:
	CashRegister();
	~CashRegister();
	Receipt& CreateReceipt(double cost, double dph);
	Receipt& FindReceipt(int id);
	double GetSum() const;
	double GetSumTaxed() const;
};

#endif // CASH_REGISTER_H
