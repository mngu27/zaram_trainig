//-------------------------------------
// Define Global Variables
// ------------------------------------
`define CLKFREQ     100
`define SIMCYCLE    100

`include "shift_register.v"

module shift_register_tb;
//---------------------------------------------------
//DUT Signals & Instantiate
//---------------------------------------------------
	reg					i_clk;
	reg					i_rstn;
	reg					i_load;
	reg			[7:0]	i_d;
	reg 				i_s;
	wire		[7:0]	o_q;	
	wire				o_s;

	shift_register
	u_shift_register(
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				),
		.i_load				(i_load				),
		.i_d				(i_d				),
		.i_s				(i_s				),
		.o_q				(o_q				),
		.o_s				(o_s				)
	);

//---------------------------------------------------
// Clock
//---------------------------------------------------
always #(500/`CLKFREQ) i_clk = ~i_clk;

//---------------------------------------------------
// Tasks
//---------------------------------------------------
reg     [8*32-1:0]  taskState;

task init;
    begin
		taskState 	= "Init";
		i_clk		= 0;
		i_rstn		= 0;
		i_load		= 0;
		i_d			= 0;
		i_s			= 0;
		repeat (4) @(posedge i_clk);
		i_rstn		= 1;
    end
endtask

integer i;

task PISO;
	input 	[7:0] d;
	begin
		taskState = "PISO";
		i_load = 1;
		i_d = d;
		@(posedge i_clk);
		i_load = 0;
		repeat(7) @(posedge i_clk);
	end
endtask

task SIPO;
	input 	[7:0] d;
	begin
		taskState = "SIPO";
		i_load = 0;
		for(i = 0; i < 8; i = i + 1) begin
			i_s = d[7-i];
			@(posedge i_clk);
		end
		i_s = 0;
		@(posedge i_clk);
	end
endtask


//---------------------------------------------------
//Stimulus
//---------------------------------------------------
integer j;

reg		[7:0]	d;

initial begin
	init();
	for (j=0; j<`SIMCYCLE; j++) begin
		i_d = $urandom;
		d	= 0;
		PISO(i_d);
		@(posedge i_clk);
		i_d = 0;
		d	= $urandom;
		SIPO(d);
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
			$dumpfile("shift_register_tb.vcd");
			$dumpvars;
		end
	end

endmodule


