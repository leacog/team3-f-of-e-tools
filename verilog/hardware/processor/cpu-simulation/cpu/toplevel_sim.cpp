#include <stdio.h>
#include <iostream>
#include <verilated.h>
#include "Vtoplevel_sim.h"
#include <bitset>
#include <string>
#include <iomanip>

vluint64_t vtime = 0;
bool clk = false;
int led = 255;
bool newRead = 0;
int instr = 0;

int main(int argc, char** argv, char** env)
{
	Verilated::commandArgs(argc, argv);
	Vtoplevel_sim* top = new Vtoplevel_sim;

	while (!Verilated::gotFinish())
	{
		clk = not clk;
		top->clk = int(clk);
		top->eval();
		if(instr < 20){
			int instruction = (top->inst_out_line);
			std::cout << std::setfill ('0') << std::setw(8) << std::hex << instruction << "\n";
			std::bitset<32> address (top->address_out_line);
			std::cout << address << "\n" << "\n";
			instr ++;
		}
		if (int(top->led) == 0x0F && !newRead)
		{
			newRead = true;		
		}
		if (0x0F != int(top->led) && newRead)
		{
			led = int(top->led);
			printf("%i\n", led);
			newRead = false;
		}
		vtime++;
	}

        delete top;
        exit(0);
}
