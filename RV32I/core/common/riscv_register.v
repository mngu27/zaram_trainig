`include	"riscv_configs.v"

module riscv_register
#(
	parameter	REGISTER_INIT	=	0
)
(
	input					i_clk,
	input					i_rstn,
	input					i_register_en,
	input		[`XLEN-1:0]	i_register_d,
	output	reg	[`XLEN-1:0]	o_register_q
);

always @(posedge i_clk or negedge i_rstn) begin
	if(!i_rstn) begin
		o_register_q	<= REGISTER_INIT;
	end
	else begin
		if(i_register_en) begin
			o_register_q	<=	i_register_d;
		end
		else begin
			o_register_q	<= o_register_q;
		end
	end
end

endmodule
