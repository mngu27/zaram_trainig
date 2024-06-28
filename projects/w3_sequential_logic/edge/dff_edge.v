module dff_neg(
	input		i_clk,
	input		i_rstn,
	input		i_d,
	output reg	o_q
);

always @(posedge i_clk or negedge i_rstn) begin
	if(!i_rstn) begin
		o_q <= 0;
	end
	else begin
		o_q <= i_d;
	end
end

endmodule


module dff_pos(
	input		i_clk,
	input		i_rst,
	input		i_d,
	output reg	o_q
);

always @(posedge i_clk or posedge i_rst) begin
	if(!i_rst) begin
		o_q <= 0;
	end
	else begin
		o_q <= i_d;
	end
end

endmodule

