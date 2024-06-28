module shift(
	input			en,
	input	[3:0]	i_data,
	output	[3:0]	o_data
);

assign o_data = (en == 1) ? {i_data[3], i_data[2:0] } : i_data;

endmodule
