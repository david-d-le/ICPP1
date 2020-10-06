#include "Receipt.h"
#include "CashRegister.h"
#include <iostream>
int main(int argc, char** argv) {

	CashRegister* cr1 = new CashRegister();
	
	Receipt rec1 = cr1->CreateReceipt(100, 21);
	Receipt rec2 = cr1->CreateReceipt(200, 21);
	Receipt rec3 = cr1->CreateReceipt(300, 21);

	std::cout << "receipt with ID: " << rec1.GetId() << " Price: " << rec1.GetPrice() << " DPH: " << rec1.GetDph() << "%\n";
	std::cout << "receipt with ID: " << rec2.GetId() << " Price: " << rec2.GetPrice() << " DPH: " << rec2.GetDph() << "%\n";
	std::cout << "receipt with ID: " << rec3.GetId() << " Price: " << rec3.GetPrice() << " DPH: " << rec3.GetDph() << "%\n";

	Receipt foundReceipt = cr1->FindReceipt(1003);
	std::cout	<< "Found receipt with ID: " << foundReceipt.GetId() << " Price: " 
				<< foundReceipt.GetPrice() << " DPH: " << foundReceipt.GetDph() << "%\n";

	return 0;
}