# Arithmetic Logic Unit(ALU)
## Operation Principle
	- An Arithmetic Logic Unit(ALU) requires arithmetic and boolean logcial opration.
	- ALU can choose which opration do depending on value of f
	- f has 3 bit. so f has 3'b000 to 3'b111.
	- The MSB of f(f[2]) representive plus or minus of value.
		- when f[2] is high. that means flip of input b 
	|F[2:0]|Function|
	|:---:|:---:|
	|000|A & B|
	|001|A \| B|
	|010|A + B|
	|011|not used|
	|100|A & ~B|
	|101|A | ~B|
	|110|A - B|
	|111|SLT|
	- only f[2] is high, f[1:0] = 11 -> SLT(Set Less Then)
		- a >= b 	-> reseult = 'd0 
		- a < b 	-> reseult = 'd1
# Verilog
### DUT
```verilog 

module ALU
#(
    parameter  BW_DATA = 32
)
(
    input   [BW_DATA-1:0]   i_a,
    input   [BW_DATA-1:0]   i_b,
    input   [        2:0]   i_f,
    output  [BW_DATA-1:0]   o_y
);

    wire    [BW_DATA-1:0]   w_y0;
    wire    [BW_DATA-1:0]   w_y1;
    wire    [BW_DATA-1:0]   w_y2;
    wire    [BW_DATA-1:0]   w_y3;
    wire    [BW_DATA-1:0]   w_y4;
	wire    [BW_DATA-1:0]   w_y5;
	wire					w_cout;

	NOT
	#(
		.BW_DATA			(BW_DATA			)
	)
	u_not(
		.i_a				(i_b				),
		.o_y				(w_y0				)
	);

	Mux2to1
	#(
		.BW_DATA			(BW_DATA			)
	)
	u_mux2to1(
		.i_sel				(i_f[2]				),
		.i_a				(i_b				),
		.i_b				(w_y0				),
		.o_y				(w_y1				)
	);

	AND
	#(
		.BW_DATA			(BW_DATA			)
	)
	u_and(
		.i_a				(i_a				),
		.i_b				(w_y1				),
		.o_y				(w_y2				)
	);

	OR
		#(
		.BW_DATA			(BW_DATA			)
	)
	u_or(
		.i_a				(i_a				),
		.i_b				(w_y1				),
		.o_y				(w_y3				)
	);

	ADDER
	#(
		.BW_DATA			(BW_DATA			)
	)
	u_adder(
		.i_a				(i_a				),
		.i_b				(w_y1				),
		.i_c				(i_f[2]				),
		.o_c				(w_cout				),
		.o_s				(w_y4				)
	);

	/////Zero Extension /////
	assign w_y5 = {{(BW_DATA-1){1'b0}}, w_y4[BW_DATA-1]};


	
	Mux4to1
	#(
		.BW_DATA			(BW_DATA			)
	)
	u_mux4to1(
		.i_sel				(i_f[1:0]			),
		.i_a				(w_y2				),
		.i_b				(w_y3				),
		.i_c				(w_y4				),
		.i_d				(w_y5				),
		.o_y				(o_y				)
	);

endmodule 

module NOT
#(
    parameter  BW_DATA = 32
)
(
    input   [BW_DATA-1:0]   i_a,
    output  [BW_DATA-1:0]   o_y
);

    assign o_y = ~(i_a);

endmodule

module AND
#(
    parameter  BW_DATA = 32
)
(
    input   [BW_DATA-1:0]   i_a,
    input   [BW_DATA-1:0]   i_b,
    output  [BW_DATA-1:0]   o_y
);

    assign o_y = i_a & i_b;

endmodule

module OR 
#(
    parameter  BW_DATA = 32
)
(
    input   [BW_DATA-1:0]   i_a,
    input   [BW_DATA-1:0]   i_b,
    output  [BW_DATA-1:0]   o_y
);

    assign o_y = i_a | i_b;

endmodule

module ADDER 
#(
    parameter  BW_DATA = 32
)
(
    input   [BW_DATA-1:0]   i_a,
    input   [BW_DATA-1:0]   i_b,
    input                   i_c,
    output                  o_c,
    output  [BW_DATA-1:0]   o_s
);

    assign  {o_c, o_s}  =   i_a + i_b + i_c;

endmodule

module Mux2to1 
#(
    parameter  BW_DATA = 32
)
(
    input   				i_sel,
    input   [BW_DATA-1:0]   i_a,
    input   [BW_DATA-1:0]   i_b,
    output  [BW_DATA-1:0]   o_y
);

assign o_y = (i_sel) ? i_b : i_a;
    
endmodule

module Mux4to1 
#(
    parameter  BW_DATA = 32
)
(
    input       [        1:0]   i_sel,
    input       [BW_DATA-1:0]   i_a,
    input       [BW_DATA-1:0]   i_b,
    input       [BW_DATA-1:0]   i_c,
    input       [BW_DATA-1:0]   i_d,
    output  reg [BW_DATA-1:0]   o_y
);

always @(*) begin
    case(i_sel)
        2'b00 : o_y = i_a;
        2'b01 : o_y = i_b;
        2'b10 : o_y = i_c;
        2'b11 : o_y = i_d;
    endcase
end

endmodule
```
### Testbench
```verilog

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
			i_f = i_f + 3'b001;
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
```

## Simulation Result
	- i_a = 0000_0003,	i_b = 0000_0006
	- @ 310ns
		- f = 3'd0 	-> i_a & i_b = 0000_0002
	- @ 320ns
		- f = 3'd1	-> i_a | i_b = 0000_0007
	- @ 330ns
		- f = 3'd6	-> i_a - i_b = 0000_0003 + FFFF_FFF9 + 1 = FFFF_FFFD
	- @ 340ns
		- f = 3'd5	-> i_a | ~i _b = FFFF_FFFB
	- @ 370ns
		- f = 3'd7 -> i_a < i_b -> 0000_0001
	- @ 400ns
		- f = 3'd4 -> i_a & (~i_b) -> 0000_0001

![Waveform0] (./test_waveform.png)
