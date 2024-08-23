`ifndef		NOINC
`include	"riscv_configs.v"
`endif

module riscv_adder(
	input	[`XLEN-1:0]	i_adder_a,
	input	[`XLEN-1:0]	i_adder_b,
	output	[`XLEN-1:0]	o_adder_sum
);

assign o_adder_sum = i_adder_a + i_adder_b;

endmodule
