module dut
#(
	parameter	BW_DATA			= 4
)
(
	input						i_clk,
	input						i_rstn,
	input		[BW_DATA-1:0]	i_a,
	input		[BW_DATA-1:0]	i_b,
	output reg	[BW_DATA-1:0]	o_y
);

always @(posedge i_clk or negedge i_rstn) begin
	if(!i_rstn)
		o_y <= 0;
	else 
		o_y <= i_a + i_b;
end

endmodule
