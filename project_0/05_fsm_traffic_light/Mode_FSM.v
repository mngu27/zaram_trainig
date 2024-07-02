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
    reg         P, R;

    localparam  S_IDLE          =   1'b0;
    localparam  S_PARADE        =   1'b1;

    always @(posedge i_clk or negedge i_rstn) begin
        if(!i_rstn) begin
            Current_State   <= S_IDLE;
            P               <= 0;
            R               <= 0;
        end
        else begin
            Current_State   <= Next_State;
            P               <= i_P;
            R               <= i_R;
        end
    end

    always @(*) begin
        if(P == 1'b0 && Current_State == S_IDLE) begin
            Next_State = S_IDLE;
        end
        else if(P == 1'b1 && Current_State == S_IDLE) begin
            Next_State = S_PARADE;
        end
        else if(R == 1'b0 && Current_State == S_PARADE) begin
            Next_State = S_PARADE;
        end
        else if(R == 1'b1 && Current_State == S_PARADE) begin
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
