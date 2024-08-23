`ifndef			NOINC
`include		"../common/riscv_configs.v"
`include		"pipeline_writeback.v"
`include		"../common/riscv_mux.v"
`endif

module riscv_writeback(
    input                       i_clk,
    input                       i_rstn,
    
    input                       i_ctrl_reg_wr_enM,
    input       [       1:0]    i_ctrl_result_srcM,
    input		[ `XLEN-1:0]	i_alu_resultM,
    input		[ `XLEN-1:0]	i_mem_readdataM,
    input		[ `XLEN-1:0]	i_PCPlus4M,	
    input       [       4:0]    i_regfile_rd_addrM,

    output                      o_ctrl_reg_wr_enW,
    output      [       4:0]    o_regfile_rd_addrW,
    output      [ `XLEN-1:0]    o_regfile_rd_dataW  
);

    wire        [       1:0]    ctrl_result_srcW;
    wire    	[ `XLEN-1:0]	alu_resultW;
    wire    	[ `XLEN-1:0]	mem_readdataW;
    wire    	[ `XLEN-1:0]	PCPlus4W;	


pipeline_writeback
    u_pipeline_writeback(
        .i_clk                  ( i_clk                 ),
        .i_rstn                 ( i_rstn                ),
    
        .i_ctrl_reg_wr_enM      ( i_ctrl_reg_wr_enM     ),
        .i_ctrl_result_srcM     ( i_ctrl_result_srcM    ),
        .i_alu_resultM          ( i_alu_resultM         ),
        .i_mem_readdataM        ( i_mem_readdataM       ),
        .i_PCPlus4M             ( i_PCPlus4M            ),	
        .i_regfile_rd_addrM     ( i_regfile_rd_addrM    ),

        .o_ctrl_reg_wr_enW      ( o_ctrl_reg_wr_enW     ),
        .o_ctrl_result_srcW     ( ctrl_result_srcW      ),
        .o_alu_resultW          ( alu_resultW           ),
        .o_mem_readdataW        ( mem_readdataW         ),
        .o_PCPlus4W             ( PCPlus4W              ),	
        .o_regfile_rd_addrW     ( o_regfile_rd_addrW    )
    );

    wire    [(3*`XLEN)-1:0]         Writeback_concat_data;
    assign  Writeback_concat_data = {PCPlus4W, mem_readdataW, alu_resultW};

    riscv_mux
#(
	.N_MUX_IN               ( 3                         ) 
)   u_riscv_mux_result
(	
	.i_mux_concat_data      ( Writeback_concat_data     ),
	.i_mux_sel              ( i_ctrl_result_srcM        ),
    .o_mux_data             ( o_regfile_rd_dataW        )
);

endmodule
