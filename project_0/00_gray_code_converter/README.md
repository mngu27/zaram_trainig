# Gray Code Converter
## Operation Principle
- Consecutive numbers differ in only one bit position
- Bin -> Gray
	- G[N-1] 	= B[N-1]
	- G[i]		= B[i+1] ^ B[i] (N-1>i>=G0)

- Gray -> Bin
	- B[N-1] 	= G[N-1]
	- B[i]		= B[i+1] ^ G[i] (N-1>i>=0)

## Verilog Code
### DUT
```verilog
	module gray_to_bin
	(
	input	[2:0]	i_data,
	output	[2:0]	o_data
	);


	assign o_data[0] = o_data[1] ^ i_data[0];
	assign o_data[1] = o_data[2] ^ i_data[1];
	assign o_data[2] = i_data[2];

	endmodule
```
```verilog
	module bin_to_gray
	(
	input	[2:0]	i_data,
	output	[2:0]	o_data
	);

	assign o_data[0] = i_data[1] ^ i_data[0];
	assign o_data[1] = i_data[2] ^ i_data[1];
	assign o_data[2] = i_data[2];

	endmodule
```

### Testbench
```verilog
	
`define		CLKFREQ		100
`define		SIMCYCLE	100

`include "bin_to_gray.v"
`include "gray_to_bin.v"

module test;
//---------------------------------------------------
// DUT Signals & Intanciate
//---------------------------------------------------
	reg		[2:0]	i_data;
	wire	[2:0]	o_data_bin;
	wire	[2:0]	o_data_gray;

	bin_to_gray
	u_bin_to_gray(
		.i_data				(i_data				),
		.o_data				(o_data_gray		)
	);


	gray_to_bin
	u_gray_to_bin(
		.i_data				(o_data_gray		),
		.o_data				(o_data_bin			)
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
			$dumpfile("bin_to_gray_tb.vcd");
			$dumpvars;
		end
	end

endmodule
```
## Simulation Result
