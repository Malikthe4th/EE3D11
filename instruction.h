//#pragma once
#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_
#include <iostream>
#include <vector>
//#include "simulator.h"
//#include "program.h"
#include "registers.h"

using namespace std;

class Instruction
{ 
    public:
        int i1, i2, i3;
        Instruction(){};
        Instruction(int j1, int j2, int j3){
            i1 = j1;
            i2 = j2;
            i3 = j3;
        };
        virtual ~Instruction(){};
        virtual void disassemble() = 0;
        virtual int execute (Registers* point) = 0;
};

class AddInstruction : public Instruction{
    public:
        int i1, i2, i3;
        AddInstruction(int j1, int j2, int j3){
            i1 = j1;
            i2 = j2;
            i3 = j3;
            //cout << i1 << "\t" << i2 << "\t" << i3 << "\n\n";
        };

        void disassemble(){
            cout << "Add\t" << "$" << i1 << ",\t" << "$" << i2 << ",\t" << "$" << i3 << "\n\n";
        }

        int execute(Registers* point){
            point->setRegister(i1, point->getRegister(i2)+point->getRegister(i3));
            point->setPC(point->getPC() + 1);
            return (point->getPC());
        };
};

class SubInstruction : public Instruction{
    public:
        int i1, i2, i3;
        SubInstruction(int j1, int j2, int j3){
            i1 = j1;
            i2 = j2;
            i3 = j3;
            //cout << i1 << "\t" << i2 << "\t" << i3 << "\n\n";
        };

        void disassemble(){
            cout << "Sub\t" << "$" << i1 << ",\t" << "$" << i2 << ",\t" << "$" << i3 << "\n\n";
        }

        int execute(Registers* point){
            point->setRegister(i1, point->getRegister(i2)-point->getRegister(i3));
            point->setPC(point->getPC() + 1);
            return (point->getPC());
        };
};

class OriInstruction : public Instruction{
    public:
        int i1, i2, i3;
        OriInstruction(int j1, int j2, int j3){
            i1 = j1;
            i2 = j2;
            i3 = j3;
            //cout << i1 << "\t" << i2 << "\t" << i3 << "\n\n";
        };

        void disassemble(){
        cout << "Ori\t" << "$" << i1 << ",\t" << "$" << i2 << ",\t" << i3 << "\n\n";
        }

        int execute(Registers* point){
            point->setRegister(i1, point->getRegister(i2) | i3);
            point->setPC(point->getPC() + 1);
            return (point->getPC());
        };
};

class BrneInstruction : public Instruction{
    public:
        int i1, i2, i3;
        BrneInstruction(int j1, int j2, int j3){
            i1 = j1;
            i2 = j2;
            i3 = j3;
            //cout << i1 << "\t" << i2 << "\t" << i3 << "\n\n";
        };

        void disassemble(){
        cout << "Brne\t" << "$" << i1 << ",\t" << "$" << i2 << ",\t" << i3 << "\n\n";
        }

        int execute(Registers* point){
            if (point->getRegister(i1) != point->getRegister(i2)){
                point->setPC(point->getPC() + 1 + i3);
                return (point->getPC());
            }
            else{
                point->setPC(point->getPC() + 1);
                return (point->getPC());
            }
        };
};
#endif	/* _INSTRUCTION_H_ */