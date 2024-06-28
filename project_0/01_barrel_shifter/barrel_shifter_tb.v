`define		CLKFREQ		100
`define		SIMCYCLE	100

`include "barrel_shifter.v"

module barrel_shifter_tb;
//---------------------------------------------------
// DUT Signals & Intanciate
//---------------------------------------------------
	reg				left;
	reg		[1:0]	shift;
	reg		[3:0]	i_data;
	wire	[3:0]	o_data;

	barrel_shifter
	u_barrel_shifter(
		.left				(left				),
		.shift				(shift				),
		.i_data				(i_data				),
		.o_data				(o_data				)
	);

//---------------------------------------------------
//Stimulus
//---------------------------------------------------
integer i, j;

initial begin
	for (i=0; i<`SIMCYCLE; i++) begin
		i_data = $urandom;
		#(500/`CLKFREQ);
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
			$dumpfile("barrel_shifter_tb.vcd");
			$dumpvars;
		end
	end

endmodule


