`ifndef			NOINC
`include		"../common/riscv_configs.v"
`include		"../common/riscv_mux.v"
`include		"../common/riscv_register.v"
`include		"../common/riscv_adder.v"
`endif

module riscv_fetch
#(
	parameter 	REGISTER_INIT	= 0
)
(
    input                   i_clk,
    input                   i_rstn,
    input                   i_hazard_stallF,
    input   [      1:0]     i_PCSrcE,
    input   [`XLEN-1:0]     i_PC_TargetE,
    input   [`XLEN-1:0]     i_alu_resultE,

    output  [`XLEN-1:0]     o_PCPlus4F,
    //output  [`XLEN-1:0]     o_instrF,
    output  [`XLEN-1:0]     o_PCF
);

    wire    [    `XLEN-1:0]     PCW;
    wire    [(3*`XLEN)-1:0]     PC_concat_data;

    assign  PC_concat_data = {i_alu_resultE, i_PC_TargetE, o_PCPlus4F};

    riscv_mux
	#(
		.N_MUX_IN               ( 3                 ) 
	)   u_riscv_mux_pc
	(	
		.i_mux_concat_data      ( PC_concat_data    ),
		.i_mux_sel              ( i_PCSrcE          ),
	    .o_mux_data             ( PCW               )
	);

	riscv_register
	#(
		.REGISTER_INIT		(REGISTER_INIT		)
	)
	u_riscv_register(
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				),
		.i_register_en		(!i_hazard_stallF	),
		.i_register_d		(PCW				),
		.o_register_q		(o_PCF				)
	);

/*
	riscv_imem
	u_riscv_imem(
		.i_clk				(i_clk									),
		.i_imem_addr		(o_PCF[`IMEM_ADDR_BIT-1:2]	            ),
		.o_imem_data		(o_instrF           					)
	);
*/
	
	riscv_adder
	u_riscv_adder_pc_plus_4(
		.i_adder_a			(o_PCF			),
		.i_adder_b			(32'd4				),
		.o_adder_sum		(o_PCPlus4F			)
	);

	endmodule
