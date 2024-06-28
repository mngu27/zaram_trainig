module bin_to_gray
#(
	parameter N = 8
)
(
	input	[N-1:0]	i_data,
	output	[N-1:0]	o_data
);


assign o_data[N-1] = i_data[N-1];

genvar i;

generate 
	for(i = 0; i < N-1; i++) begin
		assign o_data[i] = i_data[i+1] ^ i_data[i];
	end
endgenerate







/*
assign o_data[0] = i_data[1] ^ i_data[0];
assign o_data[1] = i_data[2] ^ i_data[1];
assign o_data[2] = i_data[2];
*/

endmodule
