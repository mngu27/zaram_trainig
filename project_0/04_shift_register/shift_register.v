module shift_register(
	input				i_clk,
	input				i_rstn,
	input				i_load,
	input		[7:0]	i_d,
	input 				i_s,
	output		[7:0]	o_q,	
	output				o_s
);

	wire		[7:0] 	w_out;

	mux2to1
	u_mux2to1_0(
		.i_sel				(i_load				),
		.i_data0			(i_s				),
		.i_data1			(i_d[0]				),
		.o_data				(w_out[0]			)
	);

	dff
	u_dff0(
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				),
		.i_data				(w_out[0]			),
		.o_data				(o_q[0]				)
	);

genvar i;
generate
	for(i = 0; i < 7; i = i + 1) begin
	mux2to1
	u_mux2to1(
		.i_sel				(i_load				),
		.i_data0			(o_q[i]				),
		.i_data1			(i_d[i+1]			),
		.o_data				(w_out[i+1]			)
	);
		dff
	u_dff(
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				),
		.i_data				(w_out[i+1]			),
		.o_data				(o_q[i+1]			)
	);
end
endgenerate

	assign o_s = o_q[7];

endmodule


module mux2to1(
	input		i_sel,
	input		i_data0,
	input		i_data1,
	output		o_data
);

assign o_data = (i_sel) ? i_data1 : i_data0;

endmodule

module dff(
	input			i_clk,
	input			i_rstn,
	input			i_data,
	output reg		o_data
);

always @(posedge i_clk or negedge i_rstn) begin
	if(!i_rstn) begin
		o_data <= 0;
	end
	else begin
		o_data <= i_data;
	end
end

endmodule
