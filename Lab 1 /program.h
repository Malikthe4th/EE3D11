#pragma once
class Program {
    public:
        //program aspect
        int numArith = 0; //Arithmetic and logic calculations
        int numStore = 0; //Store data into memory
        int numLoad = 0; //Load data from memory
        int numBranch = 0; //Conditional and unconditional jumps
        int numTotal = 0; //Total number of instructions

        Program(int x, int y, int z, int a) {
            numArith = x; //Arithmetic and logic calculations
            numStore = y; //Store data into memory
            numLoad = z; //Load data from memory
            numBranch = a; //Conditional and unconditional jumps
            numTotal = x + y + z + a;
        }

        Program(int x, double y, double z, double a) {
            numTotal = x;
            numArith = y*x; //Arithmetic and logic calculations
            numStore = z*x; //Store data into memory
            numLoad = a*x; //Load data from memory
            numBranch = (1 - y - z - a)*x; //Conditional and unconditional jumps
        }


        void printStats() {
            printf("\nArith:\t%d\nStore:\t%d\nLoad:\t%d\nBranch:\t%d\n\nTotal:\t%d\n\n", numArith,numStore,numLoad,numBranch,numTotal);
        };
};
