//---------------------------------------------------
// Define Global Variable
//---------------------------------------------------
`define CLKFREQ			100
`define	SIMCYCLE		32

//---------------------------------------------------
// Includes
//---------------------------------------------------
`include "riscv_regfile.v"

module riscv_regfile_tb;
//---------------------------------------------------
// DUT Signals & Instantiate
//---------------------------------------------------
	reg							i_clk;
	reg							i_regfile_rd_wen;
	reg			[	   4:0]		i_regfile_rd_addr;
	reg			[`XLEN-1:0]		i_regfile_rd_data;
	reg			[	   4:0]		i_regfile_rs1_addr;
	reg			[	   4:0]		i_regfile_rs2_addr;
	wire		[`XLEN-1:0]		o_regfile_rs1_data;
	wire		[`XLEN-1:0]		o_regfile_rs2_data;

	riscv_regfile
	u_riscv_regfile(
		.i_clk				(i_clk				),
		.i_regfile_rd_wen	(i_regfile_rd_wen	),
		.i_regfile_rd_addr	(i_regfile_rd_addr	),
		.i_regfile_rd_data	(i_regfile_rd_data	),
		.i_regfile_rs1_addr	(i_regfile_rs1_addr	),
		.i_regfile_rs2_addr	(i_regfile_rs2_addr	),
		.o_regfile_rs1_data	(o_regfile_rs1_data	),
		.o_regfile_rs2_data	(o_regfile_rs2_data	)
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
			taskState 			= "Init";
			i_clk 				= 0;
			i_regfile_rd_wen	= 0;
			i_regfile_rd_addr 	= 0;
			i_regfile_rd_data 	= 0;
			i_regfile_rs1_addr 	= 0;
			i_regfile_rs2_addr 	= 0;
		end 
	endtask 

	task regWR;
		input		[	   4:0]	ti_regfile_rd_addr;
		input		[`XLEN-1:0]	ti_regfile_rd_data;
		begin
			taskState 			= "WR";
			i_regfile_rd_addr	= ti_regfile_rd_addr;    
			i_regfile_rd_data	= ti_regfile_rd_data;
			i_regfile_rd_wen	= 1'b1;
		end 
	endtask 

	task regRD;
		input		[	   4:0]	ti_regfile_rs1_addr;
		input		[`XLEN-1:0]	ti_regfile_rs2_addr;
		begin
			taskState 			= "RD";
			i_regfile_rs1_addr	= ti_regfile_rs1_addr;
            i_regfile_rs2_addr	= ti_regfile_rs2_addr;
			i_regfile_rd_wen	= 1'b0;
		end 
	endtask

//---------------------------------------------------
// Test Stimulus
//---------------------------------------------------
	integer		i, j;
	initial begin
		init();

		#(1000/`CLKFREQ);
		for(i = 0; i < `SIMCYCLE; i++) begin
			regWR(i, i);
			#(1000/`CLKFREQ);
		end 

		for(i = 0; i < `SIMCYCLE; i++) begin
			regRD(i, i);
			#(1000/`CLKFREQ);
		end 

		for(i = 0; i < `SIMCYCLE; i++) begin
			regWR(i, $urandom_range(0, 2**31-1));
			#(1000/`CLKFREQ);
			regRD(i, i);
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
			for(i = 0; i < 32; i++) begin
				$dumpvars(0, u_riscv_regfile.registers[i]);
			end
			$dumpvars;
		end
		else begin
			$dumpfile("riscv_regfile_tb.vcd");
			$dumpvars;
		end 
	end 

endmodule
	
