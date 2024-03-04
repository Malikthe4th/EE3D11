#pragma once
#ifndef _REGISTERS_H_
#define _REGISTERS_H_
#include <iostream>
#include <vector>
using namespace std;

class Registers
{
    public:
        int PC = 0;
        int reg[30];
        Registers(){
            for(int i = 0; i < 31; i++){
                reg[i] = 0;
            }
        }
        ~Registers(){};

        void setRegister (int regNum, int value){
            reg[regNum] = value;
            cout << "register set at " << regNum << "\n";
        }

        int getRegister (int regNum){
            return reg[regNum];
        }

        void setPC (int value){
            PC = value;
        }

        int getPC (){
        return PC;
        };

        void print (){
            cout << "Program counter:\t" << PC << "\n";
            for(int i = 30; i >= 0; i--){
                if (reg[i] != 0){
                cout << "Register number and value:\t" << i << "\t" << reg[i] << "\n";
                }
            }
        }
};


#endif	/* _REGISTERS_H_ */
