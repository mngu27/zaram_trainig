`ifndef			NOINC
`include		"../common/riscv_configs.v"
`include        "riscv_fetch.v"
`include        "riscv_decode.v"
`include        "riscv_execute.v"
`include        "riscv_memory.v"
`include        "riscv_writeback.v"
`include        "riscv_hazard_unit.v"  
`endif


module	riscv_pipelined_cpu
#(
	parameter 	REGISTER_INIT	= 0
)
(
    input                       i_clk,
    input                       i_rstn,
    input   [`XLEN-1:0]         i_instrF,
    input   [`XLEN-1:0]         i_mem_readdataM,
    output  [`XLEN-1:0]         o_PCF,
	output						o_ctrl_mem_wr_enM,
    output  [`XLEN-1:0]	        o_alu_resultM,
    output	[      3:0]         o_ctrl_mem_byte_selM,
    output  [`XLEN-1:0] 	    o_mem_writedataM
);

	wire    [`XLEN-1:0]     PCPlus4F;

	riscv_fetch
	#(
		.REGISTER_INIT		(REGISTER_INIT		)
	)
	u_riscv_fetch(
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				),
		.i_hazard_stallF	(hazard_stallF	),
		.i_PCSrcE			(PCSrcE			),
		.i_PCTargetE		(PCTargetE		),
		.i_alu_resultE		(alu_resultE		),
		.o_PCPlus4F			(PCPlus4F			),
//		.o_instrF			(instrF			),
		.o_PCF				(o_PCF				)
	);


	wire      [`XLEN-1:0]     PCD;
	wire      [`XLEN-1:0]     PCPlus4D;
	
	wire			          ctrl_reg_wr_enD;
	wire	    [     1:0]	  ctrl_result_srcD;
	wire			          ctrl_mem_wr_enD;
	wire                      ctrl_jalD;
	wire                      ctrl_jalrD;
	wire                      ctrl_branchD;
	wire      [     3:0]      ctrl_alu_ctrlD;
	wire                      ctrl_alu_srcD;
	wire	  [     3:0]	  ctrl_mem_byte_selD;
	wire      [     4:0]      regfile_rs1_addrD;        
	wire      [     4:0]      regfile_rs2_addrD;
	wire      [`XLEN-1:0]     regfile_rs1_dataD;
	wire      [`XLEN-1:0]     regfile_rs2_dataD;
	wire      [`XLEN-1:0]     ExtImmD;
	wire	  [     4:0]	  regfile_rd_addrD;
	wire 	  [	    2:0] 	  ctrl_funct3D;


	riscv_decode
	u_riscv_decode(
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				),
		.i_hazard_stallD	(hazard_stallD	),
		.i_hazard_flushD	(hazard_flushD	),
		.i_instrF			(i_instrF			),
		.i_PCF				(o_PCF				),
		.i_PCPlus4F			(PCPlus4F			),
		.o_ctrl_funct3D		(ctrl_funct3D		),
		.o_PCD				(PCD				),
		.o_PCPlus4D			(PCPlus4D			),
		.i_ctrl_reg_wr_enW	(ctrl_reg_wr_enW	),
		.i_regfile_rd_addrW	(regfile_rd_addrW	),
		.i_regfile_rd_dataW (regfile_rd_dataW	),
		.o_ctrl_reg_wr_enD	(ctrl_reg_wr_enD	),
		.o_ctrl_result_srcD	(ctrl_result_srcD	),
		.o_ctrl_mem_wr_enD	(ctrl_mem_wr_enD	),
		.o_ctrl_jalD		(ctrl_jalD		),
		.o_ctrl_jalrD		(ctrl_jalrD		),
		.o_ctrl_branchD		(ctrl_branchD		),
		.o_ctrl_alu_ctrlD	(ctrl_alu_ctrlD	),
		.o_ctrl_alu_srcD	(ctrl_alu_srcD	),
		.o_ctrl_mem_byte_selD(ctrl_mem_byte_selD),
		.o_regfile_rs1_addrD(regfile_rs1_addrD),
		.o_regfile_rs2_addrD(regfile_rs2_addrD),
		.o_regfile_rs1_dataD(regfile_rs1_dataD),
		.o_regfile_rs2_dataD(regfile_rs2_dataD),
		.o_regfile_rd_addrD (regfile_rd_addrD),
		.o_ExtImmD			(ExtImmD			)
	);

	wire 		                ctrl_reg_wr_enE;
	wire 		[       1:0]    ctrl_result_srcE;
	wire 		                ctrl_mem_wr_enE;
    wire        [       3:0]    ctrl_mem_byte_selE;
	wire		[       4:0]    regfile_rs1_addrE;
	wire		[       4:0]    regfile_rs2_addrE;
	wire        [       4:0]    regfile_rd_addrE;
	wire		[ `XLEN-1:0]    alu_resultE;
	wire		[ `XLEN-1:0]	mem_writedataE;
	wire		[ `XLEN-1:0]	PCTargetE;
	wire		[ `XLEN-1:0]	PCPlus4E;	
	wire		[		1:0]	PCSrcE;

	riscv_execute
	u_riscv_execute(
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				),
		.i_ctrl_reg_wr_enD	(ctrl_reg_wr_enD	),
		.i_ctrl_result_srcD	(ctrl_result_srcD	),
		.i_ctrl_mem_wr_enD	(ctrl_mem_wr_enD	),
		.i_ctrl_jalD		(ctrl_jalD		),
		.i_ctrl_jalrD		(ctrl_jalrD		),
		.i_ctrl_branchD		(ctrl_branchD		),
		.i_ctrl_alu_ctrlD	(ctrl_alu_ctrlD	),
		.i_ctrl_alu_srcD	(ctrl_alu_srcD	),
        .i_ctrl_mem_byte_selD(ctrl_mem_byte_selD),
		.i_ctrl_funct3D		(ctrl_funct3D		),
		.i_regfile_rs1_dataD(regfile_rs1_dataD),
		.i_regfile_rs2_dataD(regfile_rs2_dataD),
		.i_regfile_rs1_addrD(regfile_rs1_addrD),
		.i_regfile_rs2_addrD(regfile_rs2_addrD),
		.i_regfile_rd_addrD	(regfile_rd_addrD	),
		.i_PCD				(PCD				),
		.i_ExtImmD			(ExtImmD			),
		.i_PCPlus4D			(PCPlus4D			),
		.i_hazard_forwardAE	(hazard_forwardAE	),
		.i_hazard_forwardBE	(hazard_forwardBE	),
		.i_hazard_flushE	(hazard_flushE	),
		.i_alu_resultM		(o_alu_resultM		),
		.i_regfile_rd_dataW	(regfile_rd_dataW	),
		.o_ctrl_reg_wr_enE	(ctrl_reg_wr_enE	),
		.o_ctrl_result_srcE	(ctrl_result_srcE),
		.o_ctrl_mem_wr_enE	(ctrl_mem_wr_enE	),
        .o_ctrl_mem_byte_selE(ctrl_mem_byte_selE),
		.o_regfile_rs1_addrE(regfile_rs1_addrE),
		.o_regfile_rs2_addrE(regfile_rs2_addrE),
		.o_regfile_rd_addrE	(regfile_rd_addrE	),
		.o_alu_resultE		(alu_resultE		),
		.o_mem_writedataE	(mem_writedataE	),
		.o_PCTargetE		(PCTargetE		),
		.o_PCPlus4E			(PCPlus4E			),
		.o_PCSrcE			(PCSrcE			)
	);

	wire 		                ctrl_reg_wr_enM;
	wire 		[       1:0]    ctrl_result_srcM;
	wire		[ `XLEN-1:0]	alu_resultM;
	wire	 	[       4:0]    regfile_rd_addrM;
	wire		[ `XLEN-1:0]	PCPlus4M;
	wire		[ `XLEN-1:0]	PCTargetM;

	riscv_memory
	u_riscv_memory(
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				),
		.i_ctrl_reg_wr_enE	(ctrl_reg_wr_enE	),
		.i_ctrl_result_srcE	(ctrl_result_srcE	),
		.i_ctrl_mem_wr_enE	(ctrl_mem_wr_enE	),
        .i_ctrl_mem_byte_selE(ctrl_mem_byte_selE),
		.i_alu_resultE		(alu_resultE		),
		.i_mem_writedataE	(mem_writedataE	),
		.i_regfile_rd_addrE	(regfile_rd_addrE	),
		.i_PCPlus4E			(PCPlus4E			),
		.i_PCTargetE		(PCTargetE			),
		.o_ctrl_reg_wr_enM	(ctrl_reg_wr_enM	),
		.o_ctrl_result_srcM	(ctrl_result_srcM	),
        .o_ctrl_mem_wr_enM  (o_ctrl_mem_wr_enM),
        .o_ctrl_mem_byte_selM(o_ctrl_mem_byte_selM),
		.o_alu_resultM		(o_alu_resultM		),
		//.o_mem_readdataM	(mem_readdataM	),
        .o_mem_writedataM   (o_mem_writedataM),
		.o_regfile_rd_addrM	(regfile_rd_addrM	),
		.o_PCPlus4M			(PCPlus4M			),
		.o_PCTargetM		(PCTargetM			)
	);
	
	wire                      ctrl_reg_wr_enW;
	wire      [       4:0]    regfile_rd_addrW;
	wire      [ `XLEN-1:0]    regfile_rd_dataW  ;

	riscv_writeback
	u_riscv_writeback(
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				),
		.i_ctrl_reg_wr_enM	(ctrl_reg_wr_enM	),
		.i_ctrl_result_srcM	(ctrl_result_srcM	),
		.i_alu_resultM		(o_alu_resultM		),
		.i_mem_readdataM	(i_mem_readdataM	),
		.i_PCPlus4M			(PCPlus4M			),
		.i_PCTargetM		(PCTargetM			),
		.i_regfile_rd_addrM	(regfile_rd_addrM	),
		.o_ctrl_reg_wr_enW	(ctrl_reg_wr_enW	),
		.o_regfile_rd_addrW	(regfile_rd_addrW	),
		.o_regfile_rd_dataW	(regfile_rd_dataW	)
	);
	
	wire	 [       1:0]        hazard_forwardAE;
	wire	 [       1:0]        hazard_forwardBE;
	wire	                     hazard_stallF;
	wire	                     hazard_stallD;
	wire	                     hazard_flushE;
	wire	                     hazard_flushD;

	hazard_unit
	u_hazard_unit(
		.i_regfile_rs1_addrE(regfile_rs1_addrE),
		.i_regfile_rs2_addrE(regfile_rs2_addrE),
		.i_regfile_rd_addrM	(regfile_rd_addrM	),
		.i_regfile_rd_addrW	(regfile_rd_addrW	),
		.i_ctrl_reg_wr_enM	(ctrl_reg_wr_enM	),
		.i_ctrl_reg_wr_enW	(ctrl_reg_wr_enW	),
		.i_regfile_rs1_addrD(regfile_rs1_addrD),
		.i_regfile_rs2_addrD(regfile_rs2_addrD),
		.i_regfile_rd_addrE	(regfile_rd_addrE	),
		.i_ctrl_result_srcE	(ctrl_result_srcE),
		.i_PCSrcE			(PCSrcE			),
		.o_hazard_forwardAE	(hazard_forwardAE	),
		.o_hazard_forwardBE	(hazard_forwardBE	),
		.o_hazard_stallF	(hazard_stallF		),
		.o_hazard_stallD	(hazard_stallD		),
		.o_hazard_flushE	(hazard_flushE		),
		.o_hazard_flushD	(hazard_flushD		)
	);

	endmodule
