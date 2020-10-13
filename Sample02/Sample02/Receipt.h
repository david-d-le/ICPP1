#pragma once
#ifndef RECEIPT_H
#define RECEIPT_H

class Receipt 
{
	unsigned int id;// id of receipt
	double price;	// raw price without tax
	double dph;		// tax in percentage

public:
	void SetId(unsigned int id);
	int GetId() const;
	void SetPrice(double price);
	double GetPrice() const;
	void SetDph(double dph);
	double GetDph() const;
};

#endif // !RECEIPT_H


