#include <iostream>
#include <vector>
#include "simulator.h"
#include "program.h"
#include "registers.h"


void loadProgram (Program *program)
{
	program->appendInstruction (new OriInstruction (1, 0, 12));
	program->appendInstruction (new OriInstruction (2, 0, 4));
	program->appendInstruction (new OriInstruction (3, 0, 1));
	program->appendInstruction (new AddInstruction (4, 4, 1));
	program->appendInstruction (new SubInstruction (2, 2, 3));
	program->appendInstruction (new BrneInstruction (2, 0, -3));
}


int main (void)
{
	/*Registers A;
    A.print();
    A.setRegister(21, 2);
    A.setPC(102);
    A.print();*/
	//cout << "start\n";
	Registers *registers	= new Registers ();
	Program	*program	= new Program ();

	loadProgram (program);

	Simulator theSimulator = Simulator (registers, program);

	theSimulator.ui ();

	return 0;
}
