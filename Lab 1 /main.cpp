#include <iostream>
#include "computer.h"
#include "program.h"
using namespace std;

int main()
{
    Program ProgramA(2000, 100, 100, 50), ProgramB(2000, 0.1, 0.4, 0.25), ProgramC(500, 100, 2000, 200);
    ProgramA.printStats();
    ProgramB.printStats();
    ProgramC.printStats();
    Computer ComputerA(1, 2, 2, 3, 4), ComputerB(1.2, 2, 3, 4, 3), ComputerC(2, 2, 2, 4, 6);
    ComputerA.printStats();
    ComputerA.printStats();
    ComputerB.printStats();
    ComputerC.printStats();

    printf("%lf\n", ComputerA.calculateGlobalCPI(ProgramA));
    printf("%lf\n", ComputerA.calculateGlobalCPI(ProgramB));
    printf("%lf\n", ComputerA.calculateGlobalCPI(ProgramC));

    printf("%lf\n", ComputerA.calculateExecutionTime(ProgramA));
    printf("%lf\n", ComputerA.calculateExecutionTime(ProgramB));
    printf("%lf\n", ComputerA.calculateExecutionTime(ProgramC));

    printf("%lf\n", ComputerA.calculateMIPS(ProgramA));
    printf("%lf\n", ComputerA.calculateMIPS(ProgramB));
    printf("%lf\n", ComputerA.calculateMIPS(ProgramC));
    //Computer Computer1(program1);

    //Program Program1(2000, 50, 100, 100);

    //printf("Computer1: %f\n",Computer1.calculateGlobalCPI(Program1));
    //Computer1.printStats();
    return 0;
};
