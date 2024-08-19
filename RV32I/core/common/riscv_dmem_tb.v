//---------------------------------------------------
// Define Global Variable
//---------------------------------------------------
`define CLKFREQ			100
`define	SIMCYCLE		2**(`DMEM_ADDR_BIT-2)

//---------------------------------------------------
// Includes
//---------------------------------------------------
`include "riscv_dmem.v"

module riscv_dmem_tb;
//---------------------------------------------------
// DUT Signals & Instantiate
//---------------------------------------------------
	reg								i_clk;
	reg								i_dmem_wr_en;
	reg		[  		  `XLEN-1:0]	i_dmem_data;
	reg		[`DMEM_ADDR_BIT-3:0]	i_dmem_addr;
	reg		[  		`XLEN/8-1:0]	i_dmem_byte_sel;
	wire	[  		  `XLEN-1:0]	o_dmem_data;

	riscv_dmem
	u_riscv_dmem(
		.i_clk				(i_clk				),
		.i_dmem_wr_en		(i_dmem_wr_en		),
		.i_dmem_data		(i_dmem_data		),
		.i_dmem_addr		(i_dmem_addr		),
		.i_dmem_byte_sel	(i_dmem_byte_sel	),
		.o_dmem_data		(o_dmem_data		)
	);

//---------------------------------------------------
// Clock 
//---------------------------------------------------
	always #(500/`CLKFREQ) i_clk = ~i_clk;

//---------------------------------------------------
// Task
//---------------------------------------------------
	reg		[8*32-1:0]	taskState;

	task init;
		begin
			taskState 		= "Init";
			i_clk			= 0;
			i_dmem_wr_en	= 0;
			i_dmem_data		= 0;    
			i_dmem_addr		= 0;    
			i_dmem_byte_sel = 0;
		end 
	endtask 

	task memWR;
		input		[`DMEM_ADDR_BIT-1:0]	ti_dmem_addr;
		input		[  		`XLEN/8-1:0]	ti_dmem_byte_sel;
		input		[  		  `XLEN-1:0]	ti_dmem_data;
		begin
			taskState 		= "WR";
			i_dmem_addr		= ti_dmem_addr[`DMEM_ADDR_BIT-1:2];     
			i_dmem_byte_sel = ti_dmem_byte_sel;
			i_dmem_data		= ti_dmem_data;
			i_dmem_wr_en	= 1'b1;
		end 
	endtask 

	task memRD;
		input		[`DMEM_ADDR_BIT-1:0]	ti_dmem_addr;
		begin
			taskState		= "RD";
			i_dmem_addr		= ti_dmem_addr[`DMEM_ADDR_BIT-1:2];
			i_dmem_wr_en	= 0;
		end 
	endtask 

//---------------------------------------------------
// Test Stimulus
//---------------------------------------------------
	integer		i, j;
	initial begin
		init();

		memRD(0);
		#(1000/`CLKFREQ);
		memRD(4);
		#(1000/`CLKFREQ);
		memRD(8);
		#(1000/`CLKFREQ);
		memRD(12);
		#(1000/`CLKFREQ);
		for(i = 0; i < `SIMCYCLE; i++) begin
			memWR(4*i, 4'b1111, i);
			#(1000/`CLKFREQ);
		end
		for(i = 0; i < `SIMCYCLE; i++) begin
			memRD(4*i);
			#(1000/`CLKFREQ);
		end
		for(i = 0; i < 2; i++) begin
			memWR(4*i, 4'b0001, $urandom);
			#(1000/`CLKFREQ);
			memRD(4*i);
			#(1000/`CLKFREQ);
		end 
		for(i = 0; i < 2; i++) begin
			memWR(4*i, 4'b0011, $urandom);
			#(1000/`CLKFREQ);
			memRD(4*i);
			#(1000/`CLKFREQ);
		end 
		$finish;
	end 
	
//---------------------------------------------------
// Dump VCD
//---------------------------------------------------
	reg	[8*32-1:0]	vcd_file;
	initial begin
		if($value$plusargs("vcd_file=%s", vcd_file)) begin
			$dumpfile(vcd_file);
			$dumpvars;
		end
		else begin
			$dumpfile("riscv_dmem_tb.vcd");
			$dumpvars;
		end 
	end 

endmodule
