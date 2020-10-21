#include <iostream>
#include "Time.h"
#include <time.h>

#define DEFAULT_ARRAY_SIZE 10

void SeraditPole(IComparable** pole, int velikostPole) {
    for (int i = 0; i < velikostPole; i++) {
        for (int j = i + 1; j < velikostPole; j++)
        {
            if (pole[j]->compareTo(pole[i]) == -1) {
                
                IComparable* temp = pole[i];
                pole[i] = pole[j];
                pole[j] = temp;
            }
        }
    }
}

Time* randomTime() {
    return new Time(rand()%23, rand() % 59, rand() % 59);
}

int main(int argc,char** argv) {
    IComparable** pole = new IComparable*[10];

    for (int i = 0; i < DEFAULT_ARRAY_SIZE; i++)
    {
        pole[i] = randomTime();
    }

    SeraditPole(pole, DEFAULT_ARRAY_SIZE);

    for (int i = 0; i < DEFAULT_ARRAY_SIZE; i++)
    {
        std::cout << pole[i]->toString() << "\n";
    }
    for (int i = 0; i < DEFAULT_ARRAY_SIZE; i++)
    {
        delete pole[i];
    }
    delete[] pole;

	return 0;
}
