#pragma once
#include "program.h"

class Computer {
    public:
        //computer aspect
        //#include "program.h"
        double clockRateGHz; //Clock rate in GHz
        double cpiArith; //CPI of instruction class Arith
        double cpiStore; //CPI of instruction class Store
        double cpiLoad; //CPI of instruction class Load
        double cpiBranch; //CPI of instruction class Branch

        double numArith = 0; //Arithmetic and logic calculations
        double numStore = 0; //Store data into memory
        double numLoad = 0; //Load data from memory
        double numBranch = 0; //Conditional and unconditional jumps
        int numTotal = 0; //Total number of instructions

        Computer(double x, double y, double z, double a, double b) {
            clockRateGHz = x;
            cpiArith = y;
            cpiStore = z;
            cpiLoad = a;
            cpiBranch = b;
        }

       void printStats()
       {
            printf("clockRateGHz:\t%f\ncpiArith:\t%f\ncpiStore:\t%f\ncpiLoad:\t%f\ncpiBranch:\t%f\n\n", clockRateGHz,cpiArith,cpiStore,cpiLoad,cpiBranch);
       };
       
       double calculateGlobalCPI(Program& data)
       {
            return (((data.numArith*cpiArith) + (data.numBranch*cpiBranch) + (data.numLoad*cpiLoad) + (data.numStore*cpiStore))/data.numTotal);
       };

       double calculateExecutionTime(Program& data) //time in seconds
       {
            return ((data.numTotal* this->calculateGlobalCPI(data))/(clockRateGHz*1000000000));
       };

       double calculateMIPS(Program& data)
       {
            return (clockRateGHz*1000000000/1000000*this->calculateGlobalCPI(data));
       };
};
