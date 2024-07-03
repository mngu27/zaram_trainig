//-------------------------------------
// Define Global Variables
// ------------------------------------
`define CLKFREQ     100
`define SIMCYCLE    100

`include "ALU.v"

module ALU_tb;
//---------------------------------------------------
//DUT Signals & Instantiate
//---------------------------------------------------

parameter	BW_DATA	= 32;	

reg   [BW_DATA-1:0]   i_a;
reg   [BW_DATA-1:0]   i_b;
reg   [        2:0]   i_f;
wire  [BW_DATA-1:0]   o_y;

ALU
#(
	.BW_DATA			(BW_DATA			)
)
u_ALU(
	.i_a				(i_a				),
	.i_b				(i_b				),
	.i_f				(i_f				),
	.o_y				(o_y				)
);

//---------------------------------------------------
//Tasks
//---------------------------------------------------
reg     [20*32-1:0]  taskState;

task init;
    begin
		taskState 	= "Init";
        i_a			= 0;
        i_b		    = 0;
        i_f		    = 0;
    end
endtask

integer i;

task ALU_function;
	input 	[BW_DATA-1:0] 	a;
	input	[BW_DATA-1:0]	b;
	begin
		taskState = "ALU_FUNC";
		i_a = a;
		i_b = b;
		i_f = 0;
		#(1000/`CLKFREQ);
		for(i = 0; i < 7; i = i +1) begin
			i_f = $urandom;
			#(1000/`CLKFREQ);
		end
	end
endtask

task ALU_function_000;
	input 	[BW_DATA-1:0] 	a;
	input	[BW_DATA-1:0]	b;
	begin
		taskState = "AND";
		i_a = a;
		i_b = b;
		i_f = 3'b000;
	end
endtask

task ALU_function_001;
	input 	[BW_DATA-1:0] 	a;
	input	[BW_DATA-1:0]	b;
	begin
		taskState = "OR";
		i_a = a;
		i_b = b;
		i_f = 3'b001;
	end
endtask

task ALU_function_010;
	input 	[BW_DATA-1:0] 	a;
	input	[BW_DATA-1:0]	b;
	begin
		taskState = "ADD";
		i_a = a;
		i_b = b;
		i_f = 3'b010;
	end
endtask

task ALU_function_011;
	input 	[BW_DATA-1:0] 	a;
	input	[BW_DATA-1:0]	b;
	begin
		taskState  = "Reserved";
		i_a = a;
		i_b = b;
		i_f = 3'b011;
	end
endtask

task ALU_function_100;
	input 	[BW_DATA-1:0] 	a;
	input	[BW_DATA-1:0]	b;
	begin
		taskState = "Not_AND";
		i_a = a;
		i_b = b;
		i_f = 3'b100;
	end
endtask

task ALU_function_101;
	input 	[BW_DATA-1:0] 	a;
	input	[BW_DATA-1:0]	b;
	begin
		taskState = "Not_OR";
		i_a = a;
		i_b = b;
		i_f = 3'b101;
	end
endtask

task ALU_function_110;
	input 	[BW_DATA-1:0] 	a;
	input	[BW_DATA-1:0]	b;
	begin
		taskState = "Substract";
		i_a = a;
		i_b = b;
		i_f = 3'b110;
	end
endtask

task ALU_function_111;
	input 	[BW_DATA-1:0] 	a;
	input	[BW_DATA-1:0]	b;
	begin
		taskState = "SLT";
		i_a = a;
		i_b = b;
		i_f = 3'b111;
	end
endtask



//---------------------------------------------------
//Stimulus
//---------------------------------------------------
integer j;

initial begin
	init();
	#(1000/`CLKFREQ);
	for (j=0; j<`SIMCYCLE; j++) begin
		i_a = i_a + 1;
		i_b = i_b + 2;
		ALU_function(i_a, i_b);
		//#(1000/`CLKFREQ);
		ALU_function_000(i_a, i_b);
		#(1000/`CLKFREQ);
		ALU_function_100(i_a, i_b);
		#(1000/`CLKFREQ);
		ALU_function_001(i_a, i_b);
		#(1000/`CLKFREQ);
		ALU_function_101(i_a, i_b);
		#(1000/`CLKFREQ);
		ALU_function_010(i_a, i_b);
		#(1000/`CLKFREQ);
		ALU_function_110(i_a, i_b);
		#(1000/`CLKFREQ);
		ALU_function_111(i_a, i_b);
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
			$dumpfile("AUL_tb.vcd");
			$dumpvars;
		end
	end

endmodule



