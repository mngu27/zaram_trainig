module mux(
	input		i_sel,
	input		i_data0,
	input		i_data1,
	output		o_data
);

assign o_data = (i_sel == 1) ? i_data1 : i_data0;

endmodule
