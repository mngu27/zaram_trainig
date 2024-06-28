module mealy_fsm(
	input		i_clk,
	input		i_rstn,
	input		i_seq,
	output	reg	o_out
);

	localparam STATE0  	= 1'b0;
	localparam STATE1	= 1'b1;

	reg state;


always @(posedge i_clk or negedge i_rstn) begin
	if(!i_rstn) begin
		state <= STATE0;
	end
	else begin
		case(state) 
			STATE0 : begin
				o_out <= 0;
				if(i_seq == 0) state <= STATE1;
			end
			STATE1 : begin
				if(i_seq == 0) o_out <= 0;
				else begin
					o_out <= 1;
					state <= STATE0;
				end
			end
		endcase
	end
end

endmodule

						
