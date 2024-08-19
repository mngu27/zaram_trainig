// ------------------------------------------------------------
//	C++ Standard Libaries
// ------------------------------------------------------------
#include <stdlib.h>
#include <iostream>
#include <cstdlib>

// ------------------------------------------------------------
//	For Common Verilator Routines & VCD (value change dump) File
// ------------------------------------------------------------
#include <verilated.h>
#include <verilated_vcd_c.h>

// ------------------------------------------------------------
//	Verilated DUT
// ------------------------------------------------------------
#include "Vdut.h"

// ------------------------------------------------------------
//	Track Simulation
// ------------------------------------------------------------
#define MAX_SIM_TIME 20
vluint64_t sim_time = 0;
vluint64_t pos_clk	= 0;

//	------------------------------------------------------------
//	Main Function
//	------------------------------------------------------------
int main(int argc, char** argv, char** env)
{	
	//	Verilator Info.
	printf("Built with %s %s.\n", Verilated::productName(), Verilated::productVersion());

	//	Verilator Arguments
	Verilated::commandArgs(argc, argv);

	//	DUT Instanciate
    Vdut *dut = new Vdut;

	//	Plus Arguments based VCD
	VerilatedVcdC *vcdTrace = new VerilatedVcdC;
	const char* flag_vcd = Verilated::commandArgsPlusMatch("vcd");
	if (flag_vcd && 0==strcmp(flag_vcd, "+vcd")) {
		Verilated::traceEverOn(true);
		dut->trace (vcdTrace, 99);
		vcdTrace->open("dut.vcd");
	}

	//	Stimulus & Evaluation
	srand(time(NULL));
    while (sim_time < MAX_SIM_TIME)
	{
        dut->i_dmem_byte_sel = 0xf;
        dut->i_clk ^= 1;
		if (dut->i_clk == 0)
		{
    		if (sim_time < MAX_SIM_TIME/2)
			{
        		dut->i_dmem_addr 	= pos_clk;
        		dut->i_dmem_data 	= 0;
        		dut->i_dmem_wr_en	= 0;
			}
			else
			{
        		dut->i_dmem_addr 	= pos_clk;
        		dut->i_dmem_data 	= rand();
        		dut->i_dmem_wr_en	= 1;
			}
		} 
		else
		{
			pos_clk++;
		}

        dut->eval();

		if (dut->i_clk == 1)
		{
    		if (pos_clk < 5)
			{
				printf("[%3ld] i_dmem_addr(%8x) : o_dmem_data(%8x)\n", pos_clk, dut->i_dmem_addr, dut->o_dmem_data);
			}
		} 
        if (flag_vcd && 0==strcmp(flag_vcd, "+vcd")) vcdTrace->dump(sim_time);
        sim_time++;
    }

    if (flag_vcd && 0==strcmp(flag_vcd, "+vcd")) vcdTrace->close();
    delete vcdTrace;
    delete dut;
    exit(EXIT_SUCCESS);
}
