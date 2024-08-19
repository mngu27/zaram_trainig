module counter
#(
	parameter	UPBND	=	31
)
(
	input								i_clk,
	input								i_rstn,
	output reg [$clog2(UPBND+1)-1:0]	o_cnt
);

always @(posedge i_clk or negedge i_rstn) begin
	if(!i_rstn) begin
		o_cnt <= 0;
	end
	else begin	
		if(o_cnt == UPBND) begin
			o_cnt	<= 0;
		end
		else begin
			o_cnt	<= o_cnt + 1;
		end
	end
end

endmodule
