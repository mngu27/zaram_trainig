module gray_to_bin
#(
	parameter BW_DATA = 8
)
(
	input	[BW_DATA-1:0]	i_data,
	output	[BW_DATA-1:0]	o_data
);

assign o_data[BW_DATA-1] = i_data[BW_DATA -1];

genvar i;
generate 
	for(i = 0; i < BW_DATA-1; i = i +1) begin
		assign o_data[i] = o_data[i+1] ^ i_data[i];
	end
endgenerate


endmodule
