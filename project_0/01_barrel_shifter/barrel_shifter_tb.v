`define		CLKFREQ		100
`define		SIMCYCLE	100

`include "barrel_shifter.v"

module barrel_shifter_tb;
//---------------------------------------------------
// DUT Signals & Intanciate
//---------------------------------------------------
	reg		[2:0]	shift_amount;
	reg		[7:0]	i_data;
	wire	[7:0]	o_data;

	barrel_shifter
	u_barrel_shifter(
		.shift_amount		(shift_amount		),
		.i_data				(i_data				),
		.o_data				(o_data				)
	);

//---------------------------------------------------
// Tasks
//---------------------------------------------------
reg	[8*32-1:0] taskState;

task init;
	begin
		taskState = "Init";
		shift_amount = 0;
		i_data = 0;
	end
endtask





//---------------------------------------------------
//Stimulus
//---------------------------------------------------
integer i, j;

initial begin
	init();

	for (i=0; i<`SIMCYCLE; i++) begin
		i_data = $urandom;
		shift_amount = $urandom;
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


