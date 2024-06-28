module seq_detect_mealy(
    input           i_clk,
    input           i_rstn,
    input           i_seq,
    output  reg     o_out
);

reg [1:0] CurrentState;
reg [1:0] NextState;
reg       seq;

//-----------------------------------------
// State
//-----------------------------------------
localparam IDLE = 2'b00;
localparam S1   = 2'b01;

always @(posedge i_clk or negedge i_rstn) begin
    if(!i_rstn) begin
        CurrentState <= IDLE;
        seq <= 1'b0;
    end
    else begin
        CurrentState <= NextState;
        seq <= i_seq; // i_seq 1clk delay
    end
end

always @(*) begin
    if(seq == 1'b0) begin
        case (CurrentState)
            IDLE    : NextState = S1;
            S1      : NextState = S1;
            default : NextState = IDLE; 
        endcase
    end
    else begin
        case (CurrentState)
            IDLE    : NextState = IDLE;
            S1      : NextState = IDLE;
            default : NextState = IDLE; 
        endcase
    end
end

always @(*) begin
    case (CurrentState)
        IDLE    : begin
            o_out = 1'b0;
        end
        S1      : begin
            if(seq == 1'b0)
                o_out = 1'b0;
            else
                o_out = 1'b1;
        end 
        default : o_out = 1'b0; 
    endcase
end

endmodule


