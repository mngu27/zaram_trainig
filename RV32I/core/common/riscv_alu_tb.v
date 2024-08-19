//---------------------------------------------------
// Define Global Variable
//---------------------------------------------------
`define DEBUG
`define CLKFREQ			100
`define	SIMCYCLE		4

//---------------------------------------------------
// Includes
//---------------------------------------------------
`include "riscv_alu.v"

module riscv_alu_tb;
//---------------------------------------------------
// DUT Signals & Instantiate
//---------------------------------------------------
	reg			[`XLEN-1:0] i_alu_a;
	reg			[`XLEN-1:0] i_alu_b;
	reg			[	   4:0] i_alu_ctrl;
	wire					o_alu_zero;
	wire		[`XLEN-1:0]	o_alu_result;

	riscv_alu
	u_riscv_alu(
		.i_alu_a			(i_alu_a			),
		.i_alu_b			(i_alu_b			),
		.i_alu_ctrl			(i_alu_ctrl			),
		.o_alu_zero			(o_alu_zero			),
		.o_alu_result		(o_alu_result		)
	);

//---------------------------------------------------
// Task
//---------------------------------------------------
	reg		[8*32-1:0]	taskState;

	task init;
		begin
			i_alu_a		= 0;
			i_alu_b		= 0;
			i_alu_ctrl	= 0;
		end 
	endtask 

	task ADD;
		input [`XLEN-1:0] ti_alu_a; 
        input [`XLEN-1:0] ti_alu_b;
		begin
			taskState = "ADD";
			i_alu_ctrl = `ALU_CTRL_ADD;
			i_alu_a = ti_alu_a;
            i_alu_b = ti_alu_b;
		end 
	endtask 

	task SUB;
		input [`XLEN-1:0] ti_alu_a; 
        input [`XLEN-1:0] ti_alu_b;
		begin
			taskState = "SUB";
			i_alu_ctrl = `ALU_CTRL_SUB;
			i_alu_a = ti_alu_a;
            i_alu_b = ti_alu_b;
		end 
	endtask 

	task XOR;
		input [`XLEN-1:0] ti_alu_a; 
        input [`XLEN-1:0] ti_alu_b;
		begin
			taskState = "XOR";
			i_alu_ctrl = `ALU_CTRL_XOR;
			i_alu_a = ti_alu_a;
            i_alu_b = ti_alu_b;
		end 
	endtask 

	task OR;
		input [`XLEN-1:0] ti_alu_a; 
        input [`XLEN-1:0] ti_alu_b;
		begin
			taskState = "OR";
			i_alu_ctrl = `ALU_CTRL_OR;
			i_alu_a = ti_alu_a;
            i_alu_b = ti_alu_b;
		end 
	endtask 

	task AND;
		input [`XLEN-1:0] ti_alu_a; 
        input [`XLEN-1:0] ti_alu_b;
		begin
			taskState = "AND";
			i_alu_ctrl = `ALU_CTRL_AND;
			i_alu_a = ti_alu_a;
            i_alu_b = ti_alu_b;
		end 
	endtask 

	task SLL;
		input [`XLEN-1:0] ti_alu_a; 
        input [`XLEN-1:0] ti_alu_b;
		begin
			taskState = "SLL";
			i_alu_ctrl = `ALU_CTRL_SLL;
			i_alu_a = ti_alu_a;
            i_alu_b = ti_alu_b;
		end 
	endtask 

	task SRA;
		input [`XLEN-1:0] ti_alu_a; 
        input [`XLEN-1:0] ti_alu_b;
		begin
			taskState = "SRA";
			i_alu_ctrl = `ALU_CTRL_SRA;
			i_alu_a = ti_alu_a;
            i_alu_b = ti_alu_b;
		end 
	endtask 

	task SRL;
		input [`XLEN-1:0] ti_alu_a; 
        input [`XLEN-1:0] ti_alu_b;
		begin
			taskState = "SRL";
			i_alu_ctrl = `ALU_CTRL_SRL;
			i_alu_a = ti_alu_a;
            i_alu_b = ti_alu_b;
		end 
	endtask 

	task SLT;
		input [`XLEN-1:0] ti_alu_a; 
        input [`XLEN-1:0] ti_alu_b;
		begin
			taskState = "SLT";
			i_alu_ctrl = `ALU_CTRL_SLT;
			i_alu_a = ti_alu_a;
            i_alu_b = ti_alu_b;
		end 
	endtask

	task SLTU;
		input [`XLEN-1:0] ti_alu_a; 
        input [`XLEN-1:0] ti_alu_b;
		begin
			taskState = "SLTU";
			i_alu_ctrl = `ALU_CTRL_SLTU;
			i_alu_a = ti_alu_a;
            i_alu_b = ti_alu_b;
		end 
	endtask
//---------------------------------------------------
// Test Stimulus
//---------------------------------------------------
	integer		i, j;
	initial begin
		init();

		#(4*1000/`CLKFREQ);

		for(i=0; i<`SIMCYCLE; i++) begin
			#(1000/`CLKFREQ); ADD($urandom, $urandom);
			#(1000/`CLKFREQ); SUB($urandom, $urandom);
		end
		for(i=0; i<`SIMCYCLE; i++) begin
			#(1000/`CLKFREQ); XOR($urandom, $urandom);
			#(1000/`CLKFREQ); OR ($urandom, $urandom);
			#(1000/`CLKFREQ); AND($urandom, $urandom);
		end
		for(i=0; i<`SIMCYCLE; i++) begin
			#(1000/`CLKFREQ); SLT ($urandom, $urandom);
			#(1000/`CLKFREQ); SLTU($urandom, $urandom);
		end
		for(i=0; i<`SIMCYCLE; i++) begin
			#(1000/`CLKFREQ); SLL($urandom, i);
			#(1000/`CLKFREQ); SRL($urandom, i);
			#(1000/`CLKFREQ); SRA($urandom, i);
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
			$dumpfile("alu_tb.vcd");
			$dumpvars;
		end 
	end 

endmodule
	
