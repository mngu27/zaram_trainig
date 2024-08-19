`ifndef		NOINC
`include 	"../common/riscv_configs.v"
`include	"../common/riscv_adder.v"
`include	"../common/riscv_alu.v"
`include	"../common/riscv_immext.v"
`include	"../common/riscv_mux.v"
`include	"../common/riscv_regfile.v"
`include	"../common/riscv_register.v"
`endif

module riscv_datapath
#(
	parameter 	REGISTER_INIT	= 0
)
(
	input						i_clk,
	input						i_rstn,
	input	[`XLEN-1:0]			i_dp_mem_rd_data,
	input	[`XLEN-1:0]			i_dp_instr,
	input	[	   2:0]			i_dp_src_imm,
	input	[	   1:0]			i_dp_src_pc,
	input	[	   1:0]			i_dp_src_rd,
	input						i_dp_src_alu_a,
	input						i_dp_src_alu_b,
	input						i_dp_reg_wr_en,
	input						i_dp_alu_ctrl,

	output	[`XLEN-1:0]			o_dp_pc,
	output						o_dp_alu_zero,
	output	[`XLEN-1:0]			o_dp_mem_addr,
	output	[`XLEN-1:0]			o_dp_mem_wr_data
);

// PC Register
	wire	[`XLEN-1:0]			pc_next;
	wire	[`XLEN-1:0]			pc_plus_4;
	wire	[`XLEN-1:0]			pc_plus_imm;

// Register File
	wire	[`XLEN-1:0]			regfile_rs1_data;
	wire	[`XLEN-1:0]			regfile_rs2_data;
	wire	[`XLEN-1:0]			regfile_rd_data;

// Immediate
	wire	[`XLEN-1:0]			immediate;

// ALU
	wire	[`XLEN-1:0]			alu_a;
	wire	[`XLEN-1:0]			alu_b;
	wire	[`XLEN-1:0]			alu_result;

	assign						o_dp_mem_addr		= alu_result;
	assign						o_dp_mem_wr_data	= regfile_rs2_data;

// MUX Concat
	wire	[(3*`XLEN)-1:0]		mux_concat_pc;
	wire	[(4*`XLEN)-1:0]		mux_concat_rd;
	wire	[(2*`XLEN)-1:0]		mux_concat_alu_a;
	wire	[(2*`XLEN)-1:0]		mux_concat_alu_b;

	assign 	mux_concat_pc 		= {alu_result, 	pc_plus_imm, 	pc_plus_4};
	assign	mux_concat_rd		= {immediate,	pc_plus_4,		i_dp_mem_rd_data,	alu_result};
	assign	mux_concat_alu_a 	= {o_dp_pc,		regfile_rs1_data};
	assign	mux_concat_alu_b	= {immediate,	regfile_rs2_data};

	riscv_mux
	#(
		.N_MUX_IN			(3					)
	)
	u_riscv_mux_pc(
		.i_mux_concat_data	(mux_concat_pc		),
		.i_mux_sel			(i_dp_src_pc		),
		.o_mux_data			(pc_next			)
	);

	riscv_register
	#(
		.REGISTER_INIT		(REGISTER_INIT		)
	)
	u_riscv_register(
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				),
		.i_register_en		(1'b1				),
		.i_register_d		(pc_next			),
		.o_register_q		(o_dp_pc			)
	);

	riscv_regfile
	u_riscv_regfile(
		.i_clk				(i_clk				),
		.i_regfile_rd_wen	(i_dp_reg_wr_en		),
		.i_regfile_rd_addr	(i_dp_instr[11:7]	),
		.i_regfile_rd_data	(regfile_rd_data	),
		.i_regfile_rs1_addr	(i_dp_instr[19:15]	),
		.i_regfile_rs2_addr	(i_dp_instr[24:20]	),
		.o_regfile_rs1_data	(regfile_rs1_data	),
		.o_regfile_rs2_data	(regfile_rs2_data	)
	);

	riscv_immext
	u_riscv_immext(
		.i_imm_instr		(i_dp_instr			),
		.i_imm_scr			(i_dp_src_imm		),
		.o_imm_ext			(immediate			)
	);

	riscv_adder
	u_riscv_adder_pc_plus_4(
		.i_adder_a			(o_dp_pc			),
		.i_adder_b			(32'd4				),
		.o_adder_sum		(pc_plus_4			)
	);

	riscv_adder
	u_riscv_adder_pc_plus_imm(
		.i_adder_a			(o_dp_pc			),
		.i_adder_b			(immediate			),
		.o_adder_sum		(pc_plus_imm		)
	);

	riscv_alu
	u_riscv_alu(
		.i_alu_a			(alu_a				),
		.i_alu_b			(alu_b				),
		.i_alu_ctrl			(i_dp_alu_ctrl		),
		.o_alu_zero			(o_dp_alu_zero		),
		.o_alu_result		(alu_result			)
	);

	riscv_mux
	#(
		.N_MUX_IN			(2					)
	)
	u_riscv_mux_alu_a(
		.i_mux_concat_data	(mux_concat_alu_a	),
		.i_mux_sel			(i_dp_src_alu_a		),
		.o_mux_data			(alu_a				)
	);

	riscv_mux
	#(
		.N_MUX_IN			(2					)
	)
	u_riscv_mux_alu_b(
		.i_mux_concat_data	(mux_concat_alu_b	),
		.i_mux_sel			(i_dp_src_alu_b		),
		.o_mux_data			(alu_b				)
	);

	riscv_mux
	#(
		.N_MUX_IN			(4					)
	)
	u_riscv_mux_regfile_rd_data(
		.i_mux_concat_data	(mux_concat_rd		),
		.i_mux_sel			(i_dp_src_rd		),
		.o_mux_data			(regfile_rd_data	)
	);





