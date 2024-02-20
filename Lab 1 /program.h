class Program {
    public:
        //program aspect
        int numArith; //Arithmetic and logic calculations
        int numStore; //Store data into memory
        int numLoad; //Load data from memory
        int numBranch; //Conditional and unconditional jumps
        int numTotal; //Total number of instructions

        Program(int, int, int, int) {
            numArith = 0; //Arithmetic and logic calculations
            numStore = 0; //Store data into memory
            numLoad = 0; //Load data from memory
            numBranch = 0; //Conditional and unconditional jumps
        }

        void printStats()
        {
            printf("Arith:\t%d\nStore:\t%d\nLoad:\t%d\nBranch:\t%d\n\nTotal:\t%d\n",numArith,numStore,numLoad,numBranch,numTotal);
        };
};
