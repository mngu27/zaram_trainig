`ifndef		NOINC
`include	"riscv_configs.v"
`endif

module	riscv_alu(
	input		[`XLEN-1:0] i_alu_a,
	input		[`XLEN-1:0] i_alu_b,
	input		[	   3:0] i_alu_ctrl,
	output					o_alu_zero,
	output	reg	[`XLEN-1:0]	o_alu_result
);

always @(*) begin
	case(i_alu_ctrl)
		`ALU_CTRL_ADD	:	o_alu_result = i_alu_a + i_alu_b;
		`ALU_CTRL_SUB	:	o_alu_result = i_alu_a - i_alu_b;
		`ALU_CTRL_XOR	:	o_alu_result = i_alu_a ^ i_alu_b;
		`ALU_CTRL_OR	: 	o_alu_result = i_alu_a | i_alu_b;
		`ALU_CTRL_AND	:	o_alu_result = i_alu_a & i_alu_b;
		`ALU_CTRL_SLL	:	o_alu_result = i_alu_a << i_alu_b[4:0];
		`ALU_CTRL_SRL	:	o_alu_result = i_alu_a >> i_alu_b[4:0];
		`ALU_CTRL_SRA	:	o_alu_result = $signed(i_alu_a) >>> $signed(i_alu_b[4:0]);
		`ALU_CTRL_SLT	:	o_alu_result = ($signed(i_alu_a) < $signed(i_alu_b)) ? 32'd1 :32'd0;
		`ALU_CTRL_SLTU	:	o_alu_result = (i_alu_a < i_alu_b) ? 32'd1 : 32'd0;
		default			:	o_alu_result = 32'dx;
	endcase
end 

assign	o_alu_zero = (o_alu_result == 0) ? 1'b1 : 1'b0;

`ifdef	DEBUG
	reg			[8*8-1:0]	DEBUG_ALU_OP;
always @(*) begin
	case(i_alu_ctrl)
		`ALU_CTRL_ADD	:	DEBUG_ALU_OP	= "ADD ";
		`ALU_CTRL_SUB	:	DEBUG_ALU_OP	= "SUB ";
		`ALU_CTRL_XOR	:	DEBUG_ALU_OP	= "XOR ";
		`ALU_CTRL_OR	:	DEBUG_ALU_OP	= "OR ";
		`ALU_CTRL_AND	:	DEBUG_ALU_OP	= "AND ";
		`ALU_CTRL_SLL	:	DEBUG_ALU_OP	= "SLL ";
		`ALU_CTRL_SRL	:	DEBUG_ALU_OP	= "SRL ";
		`ALU_CTRL_SRA	:	DEBUG_ALU_OP	= "SRA ";
		`ALU_CTRL_SLT	:	DEBUG_ALU_OP	= "SLT ";
		`ALU_CTRL_SLTU	:	DEBUG_ALU_OP	= "SLTU ";
	endcase
end 
`endif 

endmodule
