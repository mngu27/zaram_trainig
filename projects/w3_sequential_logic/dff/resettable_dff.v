module dff_sync(
	output	reg	[3:0]		o_q,
	input		[3:0]		i_d,
	input					i_clk,
	input					i_rstn
);

always @(posedge i_clk) begin
	if(!i_rstn) begin
		o_q <= 4'h0;
	end
	else begin
		o_q <= i_d;
	end
end

endmodule

module dff_async(
	output	reg		[3:0]	o_q,
	input			[3:0]	i_d,
	input					i_clk,
	input					i_rstn
);

always @(posedge i_clk or negedge i_rstn) begin
	if(!i_rstn) begin
		o_q <= 4'h0;
	end
	else begin
		o_q <= i_d;
	end
end

endmodule

