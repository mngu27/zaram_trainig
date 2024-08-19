`include "riscv_configs.v"

module	riscv_imem(
	input							i_clk,
	input	[`IMEM_ADDR_BIT-3:0]	i_imem_addr,
	output	[		  `XLEN-1:0]	o_imem_data
);

	reg		[`XLEN-1:0]	imem_arr[0:2**(`IMEM_ADDR_BIT-2)-1];

`ifdef	IMEM_INIT
	initial		$readmemh(`IMEM_INIT_FILE, imem_arr);
`endif

	assign		o_imem_data	= imem_arr[i_imem_addr];


endmodule
