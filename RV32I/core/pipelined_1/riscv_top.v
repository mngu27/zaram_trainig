`ifndef			NOINC
`include		"../common/riscv_configs.v"
`include        "riscv_pipelined_cpu.v"
`include		"../common/riscv_imem.v"
`include		"../common/riscv_dmem.v"
`endif



module	riscv_top
#(
	parameter 	REGISTER_INIT	= 0
)
(
 	input                       i_clk,
    input                       i_rstn,

    output  [`XLEN-1:0]         o_instrF,
    output  [`XLEN-1:0]         o_mem_readdataM,
    output  [`XLEN-1:0]         o_PCF,
    output  [`XLEN-1:0]	        o_alu_resultM,
	output						o_ctrl_mem_wr_enM,
    output	[      3:0]         o_ctrl_mem_byte_selM,
    output  [`XLEN-1:0] 	    o_mem_writedataM

);

	riscv_pipelined_cpu
	#(
		.REGISTER_INIT		(REGISTER_INIT		)
	)
	u_riscv_pipelined_cpu(
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				),
		.i_instrF			(o_instrF			),
		.i_mem_readdataM	(o_mem_readdataM	),
		.o_PCF				(o_PCF				),
		.o_ctrl_mem_wr_enM	(o_ctrl_mem_wr_enM	),
		.o_alu_resultM		(o_alu_resultM		),
		.o_ctrl_mem_byte_selM(o_ctrl_mem_byte_selM),
		.o_mem_writedataM	(o_mem_writedataM	)
	);

	riscv_imem
	u_riscv_imem(
		.i_clk				(i_clk									),
		.i_imem_addr		(o_PCF[`IMEM_ADDR_BIT-1:2]	),
		.o_imem_data		(o_instrF)
	);

	riscv_dmem
	u_riscv_dmem(
		.i_clk				(i_clk								),
		.i_dmem_wr_en		(o_ctrl_mem_wr_enM					),
		.i_dmem_data		(o_mem_writedataM					),
		.i_dmem_addr		(o_alu_resultM[`DMEM_ADDR_BIT-1:2]	),
		.i_dmem_byte_sel	(o_ctrl_mem_byte_selM					),
		.o_dmem_data		(o_mem_readdataM					)
	);

endmodule
