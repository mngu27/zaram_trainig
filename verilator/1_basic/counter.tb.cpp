//	------------------------------------------------------------
//	C++ Standard Libaries
//	------------------------------------------------------------
#include <stdlib.h>
#include <iostream>

//	------------------------------------------------------------
//	For Common Verilator Routines & VCD (value change dump) File
//	------------------------------------------------------------
#include <verilated.h>
#include <verilated_vcd_c.h>

//	------------------------------------------------------------
//	Verilated DUT
//	------------------------------------------------------------
#include "Vcounter.h"

//	------------------------------------------------------------
//	Track Simulation
//	------------------------------------------------------------
#define MAX_SIM_TIME 50
vluint64_t sim_time = 0;

//	------------------------------------------------------------
//	Main Function
//	------------------------------------------------------------
int main(int argc, char** argv, char** env)
{
	// DUT instanciation
    Vcounter *dut = new Vcounter;

    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("counter.vcd");

	dut->i_rstn = 0;
    while (sim_time < MAX_SIM_TIME)
	{
        dut->i_clk ^= 1;
		if(sim_time > 3)
		{
			dut->i_rstn = 1;
		}
        dut->eval();
        m_trace->dump(sim_time);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}
