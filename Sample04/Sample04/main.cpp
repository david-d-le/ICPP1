#include <iostream>
#include "Time.h"

void SeraditPole(IComparable** pole, int velikostPole) {
    for (int i = 0; i < velikostPole; i++) {
        for (int j = i + 1; j < velikostPole; j++)
        {
            if (pole[j]->compareTo(pole[j]) == -1) {
                IComparable* temp = pole[i];
                pole[i] = pole[j];
                pole[j] = temp;
            }
        }
    }
}

int main(int argc,char** argv) {
    IComparable** pole = new IComparable*[10];
    pole[0] = new Time(1,10,30);
    pole[1] = new Time(2, 10, 30);
    pole[2] = new Time(2, 30, 30);
    pole[3] = new Time(3, 30, 30);
    pole[4] = new Time(4, 30, 30);
    pole[5] = new Time(5, 30, 30);
    pole[6] = new Time(5, 50, 30);
    pole[7] = new Time(0, 30, 30);
    pole[8] = new Time(3, 20, 30);
    pole[9] = new Time(10, 30, 30);
    int pocet = 10;
    SeraditPole(pole, pocet);

    for (int i = 0; i < pocet; i++)
    {
        std::cout << pole[i]->toString() << "\n";
    }
    for (int i = 0; i < pocet; i++)
    {
        delete pole[i];
    }
    delete[] pole;

	return 0;
}
