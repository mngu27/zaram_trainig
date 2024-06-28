`define		CLKFREQ		100
`define		SIMCYCLE	100

`include "dff_edge.v"

module dff_edge_tb;

	reg		i_clk;
	reg		i_rst;
	reg		i_d;
	wire	o_q_neg;
	wire	o_q_pos;

	dff_pos
	u_dff_pos(
		.i_clk				(i_clk				),
		.i_rst				(i_rst				),
		.i_d				(i_d				),
		.o_q				(o_q_pos			)
	);


	dff_neg
	u_dff_neg(
		.i_clk				(i_clk				),
		.i_rstn				(i_rst				),
		.i_d				(i_d				),
		.o_q				(o_q_neg			)
	);

//------------------------------------------------------------------------------------------------------
// Clock
//------------------------------------------------------------------------------------------------------
always #(500/`CLKFREQ) i_clk = ~i_clk;


//------------------------------------------------------------------------------------------------------
// Task
//------------------------------------------------------------


	task init;
		begin
			i_d = 0;
			i_clk = 0;
			i_rst = 0;
		end
	endtask

	task resetReleaseAfterNCycles;
		input	[9:0]	n;
		begin
			#(n*1000/`CLKFREQ);
			i_rst = 1'b1;
		end
	endtask	

integer i, j;

	initial begin
		init();
		resetReleaseAfterNCycles(4);

		for(i = 0; i < `SIMCYCLE; i++) begin
			j	= $urandom_range(0, 10);
			#(((j * 0.1)) * 1000/`CLKFREQ);
			i_d		= $urandom;
			i_rst 	= $urandom;
			#((1-(j * 0.1)) * 1000/`CLKFREQ);
		end
		$finish;
	end

// --------------------------------------------------
//	Dump VCD
// --------------------------------------------------
	reg	[8*32-1:0]	vcd_file;
	initial begin
		if ($value$plusargs("vcd_file=%s", vcd_file)) begin
			$dumpfile(vcd_file);
			$dumpvars;
		end 
		else begin
			$dumpfile("dff_edge_tb.vcd");
			$dumpvars;
		end
	end

endmodule

