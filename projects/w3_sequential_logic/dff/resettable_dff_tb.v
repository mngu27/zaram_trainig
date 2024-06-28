`define		CLKFREQ		100
`define		SIMCYCLE	100

`include "resettable_dff.v"

module resettable_dff_tb;


	wire	[3:0]		o_q_sync;
	wire	[3:0] 		o_q_async;
	reg		[3:0]		i_d;
	reg					i_clk;
	reg					i_rstn;

	dff_sync
	u_dff_sync(
		.o_q				(o_q_sync			),
		.i_d				(i_d				),
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				)
	);

	dff_async
	u_dff_async(
		.o_q				(o_q_async			),
		.i_d				(i_d				),
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				)
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
			i_rstn = 0;
		end
	endtask

	task resetReleaseAfterNCycles;
		input	[9:0]	n;
		begin
			#(n*1000/`CLKFREQ);
			i_rstn = 1'b1;
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
			i_rstn 	= $urandom;
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
			$dumpfile("resettable_dff_tb.vcd");
			$dumpvars;
		end
	end

endmodule

