`ifndef			NOINC
`include		"../common/riscv_configs.v"
`include		"../common/riscv_regfile.v"
`include		"pipeline_decode.v"
`include		"riscv_ctrl.v"
`endif


module riscv_decode (
    input                       i_clk,
    input                       i_rstn,
	input						i_hazard_stallD,
	input						i_hazard_flushD,

    input       [`XLEN-1:0]     i_instrF,
    input       [`XLEN-1:0]     i_PCF,
    input       [`XLEN-1:0]     i_PCPlus4F,

    output      [`XLEN-1:0]     o_PCD,
    output      [`XLEN-1:0]     o_PCPlus4D,

    input                       i_ctrl_reg_wr_enW,
    input       [     4:0]      i_regfile_rd_addrW,
	output 	 	[	  2:0] 		o_ctrl_funct3D,
    
	output			            o_ctrl_reg_wr_enD,
    output	    [     1:0]	    o_ctrl_result_srcD,
	output			            o_ctrl_mem_wr_enD,
    output                      o_ctrl_jalD,
    output                      o_ctrl_jalrD,
    output                      o_ctrl_branchD,
    output      [     2:0]      o_ctrl_alu_ctrlD,
    output                      o_ctrl_alu_srcD,
	output		[	  3:0]      o_ctrl_mem_byte_selD,

	output      [     4:0]      o_regfile_rd_addrD, 
    output      [     4:0]      o_regfile_rs1_addrD,        
    output      [     4:0]      o_regfile_rs2_addrD,

    output      [`XLEN-1:0]     o_regfile_rs1_dataD,
    output      [`XLEN-1:0]     o_regfile_rs2_dataD,
    output      [`XLEN-1:0]     o_ExtImmD    
);

    wire    [`XLEN-1:0]     instrD;
    wire                    ctrl_src_immD;

    assign          o_regfile_rs1_addrD = instrD[19:15];
    assign          o_regfile_rs2_addrD = instrD[24:20];
	assign          o_regfile_rd_addrD  = instrD[11:7];
	assign 			o_ctrl_funct3D = instrD[14:12];

 pipeline_decode
 u_pipeline_decode(
    .i_clk          (   i_clk           ),
    .i_rstn         (   i_rstn          ),
    .i_en           (   !i_hazard_stallD ),
	.i_clear		(	i_hazard_flushD),

    .i_instrF         (   i_instrF        ),
    .i_PCF            (   i_PCF           ),
    .i_PCPlus4F       (   i_PCPlus4F      ),

    .o_instrD         (   instrD          ),
    .o_PCD            (   o_PCD           ),
    .o_PCPlus4D       (   o_PCPlus4D      )
);


riscv_ctrl
u_riscv_ctrl(
	.i_ctrl_opcode          (   instrD[6:0]         ),
	.i_ctrl_funct3          (   instrD[14:12]       ),
	.i_ctrl_funct7_5b       (   instrD[30]          ),

	.o_ctrl_reg_wr_en       (   o_ctrl_reg_wr_enD   ),
    .o_ctrl_result_src      (   o_ctrl_result_srcD  ),
	.o_ctrl_mem_wr_en       (   o_ctrl_mem_wr_enD   ),
    .o_ctrl_jal             (   o_ctrl_jalD         ),
    .o_ctrl_jalr            (   o_ctrl_jalrD        ),
    .o_ctrl_branch          (   o_ctrl_branchD      ),
    .o_ctrl_alu_ctrl        (   o_ctrl_alu_ctrlD    ),
    .o_ctrl_alu_src         (   o_ctrl_alu_srcD     ),
    .o_ctrl_src_imm         (   ctrl_src_immD       ),
	.o_ctrl_mem_byte_sel    (   o_ctrl_mem_byte_selD)
);

riscv_regfile
	u_riscv_regfile(
		.i_clk				(   i_clk			    ),
		.i_regfile_rd_wen	(   i_ctrl_reg_wr_enW	),
		.i_regfile_rd_addr	(   i_regfile_rd_addrW  ),
		.i_regfile_rd_data	(   i_ResultW          	),
		.i_regfile_rs1_addr	(   o_regfile_rs1_addrD	),
		.i_regfile_rs2_addr	(   o_regfile_rs2_addrD	),
		.o_regfile_rs1_data	(   o_regfile_rs1_dataD	),
		.o_regfile_rs2_data	(   o_regfile_rs2_dataD	)
	);

riscv_immext
	u_riscv_immext(
		.i_imm_instr		(   instrD			    ),
		.i_imm_scr			(   ctrl_src_immD       ),
		.o_imm_ext			(   o_ExtImmD			)
	);

endmodule
