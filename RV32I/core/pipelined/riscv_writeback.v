`ifndef			NOINC
`include		"../common/riscv_configs.v"
`include		"pipeline_writeback.v"
`include		"../common/riscv_mux.v"
`endif

module riscv_writeback(
    input                       i_clk,
    input                       i_rstn,
    
    input                       i_ctrl_reg_wr_enM,
    input          				i_ctrl_result_srcM,
    input		[ `XLEN-1:0]	i_alu_resultM,
    input		[ `XLEN-1:0]	i_mem_readdataM,
    input		[ `XLEN-1:0]	i_PCPlus4M,	
    input       [       4:0]    i_regfile_rd_addrM,
	input		[ `XLEN-1:0]	i_PCTargetM,
	input		[ `XLEN-1:0]	i_writeback_dataM,

    output                      o_ctrl_reg_wr_enW,
    output      [       4:0]    o_regfile_rd_addrW,
    output      [ `XLEN-1:0]    o_regfile_rd_dataW  
);

    wire            			ctrl_result_srcW;
    wire    	[ `XLEN-1:0]	alu_resultW;
    wire    	[ `XLEN-1:0]	mem_readdataW;
    wire    	[ `XLEN-1:0]	PCPlus4W;
	wire		[ `XLEN-1:0]	PCTargetW;
	wire 		[ `XLEN-1:0]	writeback_dataW;


pipeline_writeback
    u_pipeline_writeback(
        .i_clk                  ( i_clk                 ),
        .i_rstn                 ( i_rstn                ),
    
        .i_ctrl_reg_wr_enM      ( i_ctrl_reg_wr_enM     ),
        .i_ctrl_result_srcM     ( i_ctrl_result_srcM    ),
        .i_alu_resultM          ( i_alu_resultM         ),
        .i_mem_readdataM        ( i_mem_readdataM       ),
        .i_PCPlus4M             ( i_PCPlus4M            ),
		.i_PCTargetM			( i_PCTargetM			),
        .i_regfile_rd_addrM     ( i_regfile_rd_addrM    ),
		.i_writeback_dataM		( i_writeback_dataM		),

        .o_ctrl_reg_wr_enW      ( o_ctrl_reg_wr_enW     ),
        .o_ctrl_result_srcW     ( ctrl_result_srcW      ),
        .o_alu_resultW          ( alu_resultW           ),
        .o_mem_readdataW        ( mem_readdataW         ),
        .o_PCPlus4W             ( PCPlus4W              ),
		.o_PCTargetW			( PCTargetW				),
        .o_regfile_rd_addrW     ( o_regfile_rd_addrW    ),
		.o_writeback_dataW		( writeback_dataW		)
    );

    wire    [(2*`XLEN)-1:0]         Writeback_concat_data;
    assign  Writeback_concat_data = {mem_readdataW, writeback_dataW};

    riscv_mux
#(
	.N_MUX_IN               ( 2                        ) 
)   u_riscv_mux_result
(	
	.i_mux_concat_data      ( Writeback_concat_data     ),
	.i_mux_sel              ( ctrl_result_srcW        ),
    .o_mux_data             ( o_regfile_rd_dataW        )
);

endmodule
