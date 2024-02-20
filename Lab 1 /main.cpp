#include <iostream>
#include "computer.h"
//using namespace std;
int main()
{
    Computer Computer1;
    Computer1.cpiArith = 2;
    Computer1.cpiBranch = 4;
    Computer1.cpiLoad = 3;
    Computer1.cpiStore = 2;
    Computer1.clockRateGHz = 1;

    Program Program1;
    Program1.numArith = 2000;
    Program1.numBranch = 50;
    Program1.numLoad = 100;
    Program1.numStore = 100;

    printf("Computer1: %f\n",Computer1.calculateGlobalCPI(Program1));
    Computer1.printStats();



    return 0;
};
