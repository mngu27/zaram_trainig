module gray_to_bin
(
	input	[2:0]	i_data,
	output	[2:0]	o_data
);


assign o_data[0] = o_data[1] ^ i_data[0];
assign o_data[1] = o_data[2] ^ i_data[1];
assign o_data[2] = i_data[2];
endmodule
