module Mode_FSM
(
    input       i_clk,
    input       i_rstn,
    input       i_P,
    input       i_R,
    output reg  o_M
);

    reg         Current_State;
    reg         Next_State;

    localparam  S_IDLE          =   1'b0;
    localparam  S_PARADE        =   1'b1;

    always @(posedge i_clk or negedge i_rstn) begin
        if(!i_rstn) begin
            Current_State   <= S_IDLE;
        end
        else begin
            Current_State   <= Next_State;
        end
    end

    always @(*) begin
		case(Current_State)
			S_IDLE 		: Next_State = (i_P) ? S_PARADE : S_IDLE;
			S_PARADE 	: Next_State = (i_R) ? S_IDLE	: S_PARADE;
		endcase	
    end

    always @(*) begin
        case(Current_State)
            S_PARADE    :   o_M = 1'b1;
            default     :   o_M = 1'b0;
        endcase
    end
endmodule
