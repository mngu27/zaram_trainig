module bin_to_gray
(
	input	[2:0]	i_data,
	output	[2:0]	o_data
);

assign o_data[0] = i_data[1] ^ i_data[0];
assign o_data[1] = i_data[2] ^ i_data[1];
assign o_data[2] = i_data[2];

endmodule
