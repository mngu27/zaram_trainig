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
        if(i_P == 1'b0 && Current_State == S_IDLE) begin
            Next_State = S_IDLE;
        end
        else if(i_P == 1'b1 && Current_State == S_IDLE) begin
            Next_State = S_PARADE;
        end
        else if(i_R == 1'b0 && Current_State == S_PARADE) begin
            Next_State = S_PARADE;
        end
        else if(i_R == 1'b1 && Current_State == S_PARADE) begin
            Next_State = S_IDLE;
        end
    end

    always @(*) begin
        case(Current_State)
            S_PARADE    :   o_M = 1'b1;
            default     :   o_M = 1'b0;
        endcase
    end
endmodule
