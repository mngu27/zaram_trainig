`ifndef			NOINC
`include		"../common/riscv_configs.v"
`include		"pipeline_memory.v"
`endif


module riscv_memory(
    input       				i_clk, 
    input       				i_rstn,

    input                       i_ctrl_reg_wr_enE,
    input       [       1:0]    i_ctrl_result_srcE,
    input                       i_ctrl_mem_wr_enE,
	input		[		3:0]    i_ctrl_mem_byte_selE,

    input		[ `XLEN-1:0]	i_alu_resultE,
    input		[ `XLEN-1:0]	i_mem_writedataE,
    input       [       4:0]    i_regfile_rd_addrE,
    input		[ `XLEN-1:0]	i_PCPlus4E,	

    output 		                o_ctrl_reg_wr_enM,
	output 		[       1:0]    o_ctrl_result_srcM,
	output		[		3:0]    o_ctrl_mem_byte_selM,
	output						o_ctrl_mem_wr_enM,

    
	output		[ `XLEN-1:0]	o_alu_resultM,
//    output		[ `XLEN-1:0]	o_mem_readdataM,

    output	 	[       4:0]    o_regfile_rd_addrM,
    output		[ `XLEN-1:0]	o_PCPlus4M,
	output		[ `XLEN-1:0] 	o_mem_writedataM
);

	pipeline_memory
	u_pipeline_memory(
		.i_clk				( i_clk				),
		.i_rstn				( i_rstn			),
    	.i_ctrl_reg_wr_enE	( i_ctrl_reg_wr_enE	),
    	.i_ctrl_result_srcE	( i_ctrl_result_srcE),
    	.i_ctrl_mem_wr_enE	( i_ctrl_mem_wr_enE	),
		.i_ctrl_mem_byte_selE(i_ctrl_mem_byte_selE),
    
    	.i_alu_resultE		( i_alu_resultE		),
    	.i_mem_writedataE	( i_mem_writedataE	),
    	.i_regfile_rd_addrE	( i_regfile_rd_addrE),
		.i_PCPlus4E			 (i_PCPlus4E		),	

    	.o_ctrl_reg_wr_enM	( o_ctrl_reg_wr_enM	),
    	.o_ctrl_result_srcM	( o_ctrl_result_srcM),
    	.o_ctrl_mem_wr_enM	( o_ctrl_mem_wr_enM	),
		.o_ctrl_mem_byte_selM(o_ctrl_mem_byte_selM),
    
    	.o_alu_resultM		( o_alu_resultM		),
    	.o_mem_writedataM	( o_mem_writedataM	),
    	.o_regfile_rd_addrM	( o_regfile_rd_addrM),
    	.o_PCPlus4M			( o_PCPlus4M		)	
);

/*
riscv_dmem
	u_riscv_dmem(
		.i_clk              ( i_clk         		),
		.i_dmem_wr_en       ( ctrl_mem_wr_enM   	),
		.i_dmem_data        ( o_mem_writedataM  	),
		.i_dmem_addr        ( o_alu_resultM  		),
		.i_dmem_byte_sel    ( ctrl_mem_byte_selM	),
		.o_dmem_data        ( o_mem_readdataM  		)
);
*/
endmodule
