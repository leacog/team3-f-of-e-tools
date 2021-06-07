#include <stdio.h>
#include <iostream>
#include <verilated.h>
#include "Vtoplevel_sim.h"
#include <bitset>
#include <string>

vluint64_t vtime = 0;
bool clk = false;
int led = 255;
bool newRead = 0;

int main(int argc, char** argv, char** env)
{
	Verilated::commandArgs(argc, argv);
	Vtoplevel_sim* top = new Vtoplevel_sim;

	while (!Verilated::gotFinish())
	{
		clk = not clk;
		top->clk = int(clk);
		top->eval();
		//std::bitset<32> instruction (top->inst_out_line);
		//std::cout << instruction << "\n";
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
