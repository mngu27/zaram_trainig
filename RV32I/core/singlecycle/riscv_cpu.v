`ifndef		NOINC
`include 	"../common/riscv_configs.v"
`include	"../common/riscv_dmem_interface.v"
`include	"riscv_ctrl.v"
`include	"riscv_datapath.v"
`endif

module riscv_cpu
#(
		parameter 	REGISTER_INIT	= 0
)
(
	input						i_clk,
	input						i_rstn,
	input	[`XLEN-1:0]			i_cpu_dmem_rd_data,
	input	[`XLEN-1:0]			i_cpu_imem_instr,

	output	[`XLEN-1:0]			o_cpu_imem_pc,
	output	[`XLEN-1:0]			o_cpu_dmem_addr,
	output						o_cpu_dmem_wr_en,
	output	[	   3:0]			o_cpu_dmem_byte_sel,
	output	[`XLEN-1:0]			o_cpu_dmem_wr_data
);

	wire						alu_zero;
	wire	[	   2:0]			src_imm;
	wire	[	   1:0]			src_pc;
	wire	[	   1:0]			src_rd;
	wire						src_alu_a;
	wire						src_alu_b;
	wire						reg_wr_en;
	wire	[	   3:0]			alu_ctrl;

	wire	[`XLEN-1:0]			dmem_addr;
	wire	[`XLEN-1:0]			dmem_rd_data;
	wire	[`XLEN-1:0]			dmem_wr_data;
	wire						dmem_wr_en;
	wire	[	   3:0]			dmem_byte_sel;


	riscv_datapath
	#(
		.REGISTER_INIT		(REGISTER_INIT		)
	)
	u_riscv_datapath(
		.i_clk				(i_clk					),
		.i_rstn				(i_rstn					),
		.i_dp_mem_rd_data	(dmem_rd_data			),
		.i_dp_instr			(i_cpu_imem_instr		),
		.i_dp_src_imm		(src_imm				),
		.i_dp_src_pc		(src_pc					),
		.i_dp_src_rd		(src_rd					),
		.i_dp_src_alu_a		(src_alu_a				),
		.i_dp_src_alu_b		(src_alu_b				),
		.i_dp_reg_wr_en		(reg_wr_en				),
		.i_dp_alu_ctrl		(alu_ctrl				),

		.o_dp_pc			(o_cpu_imem_pc			),
		.o_dp_alu_zero		(alu_zero				),
		.o_dp_mem_addr		(dmem_addr				),
		.o_dp_mem_wr_data	(dmem_wr_data			)
	);
	
	riscv_ctrl
	u_riscv_ctrl(
		.i_ctrl_opcode		(i_cpu_imem_instr[ 6: 0]	),
		.i_ctrl_funct3		(i_cpu_imem_instr[14:12]	),
		.i_ctrl_funct7_5b	(i_cpu_imem_instr[   30]	),
		.i_ctrl_alu_zero	(alu_zero					),
		.o_ctrl_src_pc		(src_pc						),
		.o_ctrl_src_imm		(src_imm					),
		.o_ctrl_src_rd		(src_rd						),
		.o_ctrl_src_alu_a	(src_alu_a					),
		.o_ctrl_src_alu_b	(src_alu_b					),
		.o_ctrl_reg_wr_en	(reg_wr_en					),
		.o_ctrl_mem_wr_en	(dmem_wr_en					),
		.o_ctrl_mem_byte_sel(dmem_byte_sel				),
		.o_ctrl_alu_ctrl	(alu_ctrl					)
	);

	riscv_dmem_interface
	u_riscv_dmem_interface(
		.i_dmem_intf_wen		(dmem_wr_en				),
		.i_dmem_intf_addr		(dmem_addr				),
		.o_dmem_intf_wen		(o_cpu_dmem_wr_en		),
		.o_dmem_intf_addr		(o_cpu_dmem_addr		),
		.i_clk					(i_clk					),
		.i_dmem_intf_func3		(i_cpu_imem_instr[14:12]),
		.i_dmem_intf_rd_data	(i_cpu_dmem_rd_data		),
		.i_dmem_intf_wr_data	(dmem_wr_data			),
		.i_dmem_intf_byte_sel	(dmem_byte_sel			),
		.o_dmem_intf_rd_data	(o_cpu_dmem_rd_data		),
		.o_dmem_intf_wr_data	(o_cpu_dmem_wr_data		),
		.o_dmem_intf_byte_sel	(o_cpu_dmem_byte_sel	)
	);


