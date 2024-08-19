//---------------------------------------------------
// C++ Standards Libraries
//---------------------------------------------------
#include <stdlib.h>
#include <iostream>
#include <cstdlib>

//---------------------------------------------------
// For Common Verilator Routines & VCD (value change dump) File
//---------------------------------------------------
#include <verilated.h>
#include <verilated_vcd_c.h>

//---------------------------------------------------
// Verilated DUT
//---------------------------------------------------
#include "Vdut.h"

//---------------------------------------------------
// Track Simulation
//---------------------------------------------------
#define MAX_SIM_TIME 50
vluint64_t sim_time = 0;

//---------------------------------------------------
// Functions
//---------------------------------------------------
void dutReset(Vdut *dut, vluint64_t &sim_time){
	dut->i_rstn = 0;
	if(sim_time > 10) {
		dut->i_rstn = 1;
	}
}

//---------------------------------------------------
// Main Functions
//---------------------------------------------------
int main(int argc, char** argv, char** env)
{
	// Verilator Info
	printf("Build With %s %s.\n", Verilated::productName(), Verilated::productVersion());

	//Verilator Arguments
	Verilated::commandArgs(argc, argv);

	//	DUT Instanciate
	Vdut *dut = new Vdut;

	//	Plus Arguments based VCD
	VerilatedVcdC *vcdTrace = new VerilatedVcdC;
	const char* flag_vcd = Verilated::commandArgsPlusMatch("vcd");
	if(flag_vcd && 0==strcmp(flag_vcd, "+vcd")) {
		Verilated::traceEverOn(true);
		dut->trace (vcdTrace, 99);
		vcdTrace->open("dut.vcd");
	}

	//	Stimulus & Evaluation
	srand(time(NULL));
	while (sim_time < MAX_SIM_TIME) 
	{
		dutReset(dut, sim_time);
		dut->i_clk ^= 1;
		if(dut->i_clk == 0)
		{
			dut->i_a = rand()%(2^4);
			dut->i_b = rand()%(2^4);
		}
		dut->eval();
		if(dut->i_clk == 1)
		{
			printf("[%3ld] i_a(%2d) + i_b(%2d) = o_y(%2d)\n", sim_time, dut->i_a, dut->i_b, dut->o_y);
		}
		if(flag_vcd && 0==strcmp(flag_vcd, "+vcd")) vcdTrace->dump(sim_time);
		sim_time++;
	}

	if(flag_vcd && 0==strcmp(flag_vcd, "+vcd")) vcdTrace->close();
	delete vcdTrace;
	delete dut;
	exit(EXIT_SUCCESS);
}





