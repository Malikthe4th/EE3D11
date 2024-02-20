class Computer {
    public:
        //computer aspect
       double clockRateGHz; //Clock rate in GHz
       double cpiArith; //CPI of instruction class Arith
       double cpiStore; //CPI of instruction class Store
       double cpiLoad; //CPI of instruction class Load
       double cpiBranch; //CPI of instruction class Branch
        Computer(double, double, double, double, double) {
            clockRateGHz = 0;
            cpiArith = 0;
            cpiStore = 0;
            cpiLoad = 0;
            cpiBranch = 0;
        }
       void printStats()
       {
            printf("clockRateGHz:\t%f\ncpiArith:\t%f\ncpiStore:\t%f\ncpiLoad:\t%f\ncpiBranch:\t%f\n",clockRateGHz,cpiArith,cpiStore,cpiLoad,cpiBranch);
       };
       
       double calculateGlobalCPI(int numArith, int numStore, int numLoad, int numBranch, int numTotal)
       {
        if (numTotal >= 0)
        {
            printf("not null\n");
            return ((numArith*cpiArith) + (numBranch*cpiBranch) + (numLoad*cpiLoad) + (numStore*cpiStore));
            
        }
        else
        {
            printf("isnull\n");
            numTotal = numArith + numBranch + numLoad + numStore;
            return (((numArith*cpiArith) + (numBranch*cpiBranch) + (numLoad*cpiLoad) + (numStore*cpiStore))/numTotal);
        };
       };

       double calculateExecutionTime(int numTotal) //time in seconds
       {
            return (numTotal*calculateGlobalCPI()/clockRateGHz*1000000000);
       };

       double calculateMIPS()
       {
            return (clockRateGHz*1000000000/1000000*cpiArith);
       };
};
