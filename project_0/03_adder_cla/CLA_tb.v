//-------------------------------------
// Define Global Variables
// ------------------------------------
`define CLKFREQ     100
`define SIMCYCLE    100

`include "CLA.v"

module CLA_tb;
//---------------------------------------------------
//DUT Signals & Instantiate
//---------------------------------------------------
	reg		[31:0]	i_a;
	reg		[31:0]	i_b;
	reg				i_c;
	wire			o_c;
	wire	[31:0]	o_s;

	CLA
	u_CLA(
		.i_a				(i_a				),
		.i_b				(i_b				),
		.i_c				(i_c				),
		.o_c				(o_c				),
		.o_s				(o_s				)
	);





//---------------------------------------------------
//Stimulus
//---------------------------------------------------
integer j;

initial begin
	i_a = 0;
	i_b = 0;
	i_c = 0;

	for (j=0; j<`SIMCYCLE; j++) begin
		i_a = i_a + 1;
		i_b = i_b + 2;
		i_c = 1;
		#(1000/`CLKFREQ);
	end
	#(1000/`CLKFREQ);
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
		end else begin
			$dumpfile("CLA_tb.vcd");
			$dumpvars;
		end
	end

endmodule

