
// --------------------------------------------------
//	Define Global Variables
// --------------------------------------------------
`define	CLKFREQ		100		// Clock Freq. (Unit: MHz)
`define	SIMCYCLE	`NVEC	// Sim. Cycles
`define NVEC		200		// # of Test Vector
`define	IMEM_INIT
`define	IMEM_INIT_FILE		"riscv_program.mif"
`define NOINC
`define DEBUG

// --------------------------------------------------
//	Includes
// --------------------------------------------------
`include	"../common/riscv_configs.v"
`include	"../common/riscv_adder.v"
`include	"../common/riscv_alu.v"
`include	"../common/riscv_dmem.v"
//`include	"../common/riscv_dmem_interface.v"
`include	"../common/riscv_imem.v"
`include	"../common/riscv_immext.v"
`include	"../common/riscv_mux.v"
`include	"../common/riscv_regfile.v"
`include	"../common/riscv_register.v"
`include	"riscv_top.v"
`include	"pipeline_decode.v"
`include	"pipeline_execute.v"
`include	"pipeline_memory.v"
`include	"pipeline_writeback.v"
`include	"riscv_ctrl.v"
`include	"riscv_decode.v"
`include	"riscv_execute.v"
`include	"riscv_fetch.v"
`include	"riscv_hazard_unit.v"
`include	"riscv_memory.v"
`include	"riscv_pipelined_cpu.v"
`include	"riscv_writeback.v"

module riscv_top_tb;
// --------------------------------------------------
//	DUT Signals & Instantiate
// --------------------------------------------------
	
	reg                       i_clk;
	reg                       i_rstn;
	wire  [`XLEN-1:0]         o_instrF;
	wire  [`XLEN-1:0]         o_mem_readdataM;
	wire  [`XLEN-1:0]         o_PCF;
	wire  [`XLEN-1:0]	        o_alu_resultM;
	wire						o_ctrl_mem_wr_enM;
	wire	[      3:0]     o_ctrl_mem_byte_selM;
	wire  [`XLEN-1:0] 	    o_mem_writedataM;

	riscv_top 
	#(
		.REGISTER_INIT		(0		)
	)
	u_riscv_top(
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				),
		.o_instrF			(o_instrF			),
		.o_mem_readdataM	(o_mem_readdataM	),
		.o_PCF				(o_PCF				),
		.o_alu_resultM		(o_alu_resultM		),
		.o_ctrl_mem_wr_enM	(o_ctrl_mem_wr_enM	),
		.o_ctrl_mem_byte_selM(o_ctrl_mem_byte_selM),
		.o_mem_writedataM	(o_mem_writedataM	)
	);


// --------------------------------------------------
//	Clock
// --------------------------------------------------
	always	#(500/`CLKFREQ)		i_clk = ~i_clk;

// --------------------------------------------------
//	Tasks
// --------------------------------------------------
	reg		[8*32-1:0]	taskState;
	integer				err	= 0;

	task init;
		begin
			taskState		= "Init";
			i_clk					= 0;
			i_rstn					= 0;
		end
	endtask

	task resetNCycle;
		input	[9:0]	i;
		begin
			taskState		= "Reset";
			i_rstn	= 1'b0;
			#(i*1000/`CLKFREQ);
			i_rstn	= 1'b1;
		end
	endtask

// --------------------------------------------------
//	Test Stimulus
// --------------------------------------------------
	integer		i, j;
	initial begin
		init();
		resetNCycle(4);
		for (i=0; i<`SIMCYCLE; i++) begin
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
			for (i=0; i<2**(`DMEM_ADDR_BIT-2)-1; i++) begin
				$dumpvars(0, u_riscv_top.u_riscv_dmem.dmem_arr[i]);
			end
			for (i=0; i<32; i++) begin
				$dumpvars(0, u_riscv_top.u_riscv_pipelined_cpu.riscv_fetch.registers[i]);
			end
		end else begin
			$dumpfile("riscv_top_tb.vcd");
			$dumpvars;
		end
	end

endmodule
