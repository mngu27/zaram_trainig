`define		CLKFREQ		100
`define		SIMCYCLE	10
`define		UPBND		15
`define		DOWNBND		15

`include "up_down_cnt.v"

module up_down_cnt_tb;
//---------------------------------
// DUT Signals & Institate
//----------------------------------

	wire		[$clog2(DOWNBND+1)-1:0]	o_cnt_down;	
	wire		[$clog2(UPBND+1)-1:0]	o_cnt_up;
	reg									i_clk;
	reg									i_rstn;

	upcnt
	#(
		.UPBND				(UPBND				)
	)
	u_upcnt(
		.o_cnt				(o_cnt_up			),
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				)
	);


	downcnt
	#(
		.DOWNBND			(DOWNBND			)
	)
	u_downcnt(
		.o_cnt				(o_cnt_down			),
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				)
	);

always #(500/`CLKFREQ) i_clk = ~i_clk;

	task init;
		begin
			i_clk = 0;
			i_rstn = 0;
		end
	endtask

integer i, j;

	initial begin
		init();

		for(i = 0; i < `SIMCYCLE; i++) begin
			j	= $urandom_range(0, 10);
			#(((j * 0.1)) * 1000/`CLKFREQ);
			i_d	= $urandom;
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
			$dumpfile("latch_vs_dff_tb.vcd");
			$dumpvars;
		end
	end

endmodule

