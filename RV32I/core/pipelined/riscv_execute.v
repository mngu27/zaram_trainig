`ifndef			NOINC
`include		"../common/riscv_configs.v"
`include		"../common/riscv_mux.v"
`include		"../common/riscv_adder.v"
`include		"../common/riscv_alu.v"
`include		"pipeline_execute.v"
`endif

module riscv_execute(
	input                       i_clk,
    input                       i_rstn,
    
	input                       i_ctrl_reg_wr_enD,
    input       [       1:0]    i_ctrl_result_srcD,
    input                       i_ctrl_mem_wr_enD,
    input                       i_ctrl_jalD,
    input                       i_ctrl_jalrD,
    input                       i_ctrl_branchD,
    input       [       2:0]    i_ctrl_alu_ctrlD,
    input                       i_ctrl_alu_srcD,
	input		[		3:0]    i_ctrl_mem_byte_selD,
	input 	 	[	    2:0] 	i_ctrl_funct3D,


    input       [ `XLEN-1:0]    i_regfile_rs1_dataD,
    input       [ `XLEN-1:0]    i_regfile_rs2_dataD,
     
    input       [       4:0]    i_regfile_rs1_addrD,
    input       [       4:0]    i_regfile_rs2_addrD,
    input       [       4:0]    i_regfile_rd_addrD,
    input       [ `XLEN-1:0]    i_PCD,
    input       [ `XLEN-1:0]    i_ExtImmD,
    input       [ `XLEN-1:0]    i_PCPlus4D,

	input		[		1:0]	i_hazard_forwardAE,
	input		[		1:0]	i_hazard_forwardBE,
	input						i_hazard_flushE,

	input		[ `XLEN-1:0]	i_alu_resultM,
	input		[ `XLEN-1:0]	i_regfile_rd_dataW,


    output 		                o_ctrl_reg_wr_enE,
    output 		[       1:0]    o_ctrl_result_srcE,
    output 		                o_ctrl_mem_wr_enE,
	output		[		3:0]    o_ctrl_mem_byte_selE,

	output		[       4:0]    o_regfile_rs1_addrE,
	output		[       4:0]    o_regfile_rs2_addrE,
	output      [       4:0]    o_regfile_rd_addrE,

	output		[ `XLEN-1:0]    o_alu_resultE,
	output		[ `XLEN-1:0]	o_mem_writedataE,

	output		[ `XLEN-1:0]	o_PCTargetE,
	output		[ `XLEN-1:0]	o_PCPlus4E,	
	output		[		1:0]	o_PCSrcE
);

 	wire                  ctrl_jalE;
    wire                  ctrl_jalrE;
    wire                  ctrl_branchE;
    wire  [       2:0]    ctrl_alu_ctrlE;
    wire                  ctrl_alu_srcE;
	wire  [ `XLEN-1:0]    regfile_rs1_dataE;
    wire  [ `XLEN-1:0]    regfile_rs2_dataE;
	wire  [ `XLEN-1:0]    PCE;
	wire  [ `XLEN-1:0]    ExtImmE;


pipeline_execute
u_pipeline_execute(
    .i_clk					( i_clk				),
    .i_rstn					( i_rstn			),
    .i_clear				( i_hazard_flushE	),

    .i_ctrl_reg_wr_enD		( i_ctrl_reg_wr_enD	),
    .i_ctrl_result_srcD		( i_ctrl_result_srcD),
    .i_ctrl_mem_wr_enD		( i_ctrl_mem_wr_enD	),
    .i_ctrl_jalD			( i_ctrl_jalD		),
    .i_ctrl_jalrD			( i_ctrl_jalrD		),
    .i_ctrl_branchD			( i_ctrl_branchD	),
    .i_ctrl_alu_ctrlD		( i_ctrl_alu_ctrlD	),
    .i_ctrl_alu_srcD		( i_ctrl_alu_srcD	),
	.i_ctrl_mem_byte_selD	( i_ctrl_mem_byte_selD),
	.i_ctrl_funct3D			( i_ctrl_funct3D),
    .i_regfile_rs1_dataD	( i_regfile_rs1_dataD),
    .i_regfile_rs2_dataD	( i_regfile_rs2_dataD),
     
    .i_regfile_rs1_addrD	( i_regfile_rs1_addrD),
    .i_regfile_rs2_addrD	( i_regfile_rs2_addrD),
    .i_regfile_rd_addrD		( i_regfile_rd_addrD),
    .i_PCD					( i_PCD				),
    .i_ExtImmD				( i_ExtImmD			),
    .i_PCPlus4D				( i_PCPlus4D		),

	.o_ctrl_funct3E			( o_ctrl_funct3E		),
    .o_ctrl_reg_wr_enE		( o_ctrl_reg_wr_enE	),
    .o_ctrl_result_srcE		( o_ctrl_result_srcE),
    .o_ctrl_mem_wr_enE		( o_ctrl_mem_wr_enE	),
    .o_ctrl_jalE			( ctrl_jalE			),
    .o_ctrl_jalrE			( ctrl_jalrE		),
    .o_ctrl_branchE			( ctrl_branchE		),
    .o_ctrl_alu_ctrlE		( ctrl_alu_ctrlE	),
    .o_ctrl_alu_srcE		( ctrl_alu_srcE		),
	.o_ctrl_mem_byte_selE	( o_ctrl_mem_byte_selE),

    .o_regfile_rs1_dataE	( regfile_rs1_dataE  ),
    .o_regfile_rs2_dataE	( regfile_rs2_dataE  ),
    .o_regfile_rs1_addrE	( o_regfile_rs1_addrE),
    .o_regfile_rs2_addrE	( o_regfile_rs2_addrE),
    .o_regfile_rd_addrE		( o_regfile_rd_addrE ),
    .o_PCE					( PCE				 ),
    .o_ExtImmE				( ExtImmE			 ),
    .o_PCPlus4E				( o_PCPlus4E		 )
);

	wire	[			2:0]	ctrl_funct3E;
    wire    [    `XLEN-1:0]	SrcAE;
    wire    [    `XLEN-1:0]	SrcBE;

    wire	[(3*`XLEN)-1:0]	srcA_concat_data;
	wire	[(3*`XLEN)-1:0]	writedata_concat;
    wire    [(2*`XLEN)-1:0] srcB_concat_data;
   
    assign srcA_concat_data	= {i_alu_resultM, i_regfile_rd_dataW, regfile_rs1_dataE};
    assign writedata_concat	= {i_alu_resultM, i_regfile_rd_dataW, regfile_rs2_dataE};
    assign srcB_concat_data = {ExtImmE, o_mem_writedataE};

    ////// Hazard ///////
    riscv_mux
#(
	.N_MUX_IN               ( 3                 ) 
)   u_riscv_mux_srcAE
(	
	.i_mux_concat_data      ( srcA_concat_data    ),
	.i_mux_sel              ( i_hazard_forwardAE  ),
    .o_mux_data             ( SrcAE               )
);

    riscv_mux
#(
	.N_MUX_IN               ( 3                 ) 
)   u_riscv_mux_writedata
(	
	.i_mux_concat_data      ( writedata_concat    	),
	.i_mux_sel              ( i_hazard_forwardBE	),
    .o_mux_data             ( o_mem_writedataE      )
);

	//// Rd2 select /////
    riscv_mux
#(
	.N_MUX_IN               ( 2                 ) 
)   u_riscv_mux_srcBE
(	
	.i_mux_concat_data      ( srcB_concat_data	),
	.i_mux_sel              ( ctrl_alu_srcE     ),
    .o_mux_data             ( SrcBE             )
);

	///// PC + immm /////
    riscv_adder
	u_riscv_adder_pc_plus_imm(
		.i_adder_a			( PCE			),
		.i_adder_b			( ExtImmE			),
		.o_adder_sum		( o_PCTargetE		)
	);

	wire	zeroE;

    riscv_alu
	u_riscv_alu(
		.i_alu_a			( SrcAE				),
		.i_alu_b			( SrcBE				),
		.i_alu_ctrl			( ctrl_alu_ctrlE	),
		.o_alu_zero			( zeroE				),
		.o_alu_result		( o_alu_resultE		)
	);
	// branch alu zero
	reg take_branch;

	always @ (*) begin
		case(ctrl_funct3E)
			`FUNCT3_BRANCH_BEQ	   : take_branch = zeroE; 
			`FUNCT3_BRANCH_BNE	   : take_branch = !zeroE;
			`FUNCT3_BRANCH_BLT	   : take_branch = !zeroE;
			`FUNCT3_BRANCH_BGE	   : take_branch = zeroE ;
			`FUNCT3_BRANCH_BLTU    : take_branch = !zeroE;
			`FUNCT3_BRANCH_BGEU    : take_branch = zeroE;
			default				   : take_branch = 1'b0;
		endcase
	end
	//// jal, jalr, branch -> PC jump ////
	wire 	PC_branch;
    assign 	PC_branch = zeroE && ctrl_branchE;

    assign  o_PCSrcE = ctrl_jalrE    ?   2'b10 
                  : ctrl_jalE || (PC_branch&&take_branch) ? 2'b01 
                  : 2'b00;


endmodule
