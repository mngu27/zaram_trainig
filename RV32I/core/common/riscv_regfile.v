`ifndef		NOINC
`include	"riscv_configs.v"
`endif


module	riscv_regfile(
	input						i_clk,
	input						i_regfile_rd_wen,
	input		[	   4:0]		i_regfile_rd_addr,
	input		[`XLEN-1:0]		i_regfile_rd_data,
	input		[	   4:0]		i_regfile_rs1_addr,
	input		[	   4:0]		i_regfile_rs2_addr,
	output		[`XLEN-1:0]		o_regfile_rs1_data,
	output		[`XLEN-1:0]		o_regfile_rs2_data
);

	//32 base registers
	reg			[`XLEN-1:0]		registers[0:31];

	//Read Ports for rs1, rs2
	assign		o_regfile_rs1_data = registers[i_regfile_rs1_addr];
	assign		o_regfile_rs2_data = registers[i_regfile_rs2_addr];

	//HW x0
	initial		registers[0] = `XLEN'b0;

	always @(posedge i_clk) begin
		//Write Enable && (Write Addr is not zero)
		if(i_regfile_rd_wen && (i_regfile_rd_addr != 0)) begin
			registers[i_regfile_rd_addr] <= i_regfile_rd_data;
		end
		else begin
			registers[i_regfile_rd_addr] <= registers[i_regfile_rd_addr];
		end
	end

endmodule
