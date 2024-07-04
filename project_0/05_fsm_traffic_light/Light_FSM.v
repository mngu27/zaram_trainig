module  Light_FSM(
    input       i_clk,
    input       i_rstn,
    input       i_M,
    input       i_TA,
    input       i_TB,
    output reg [1:0]  o_LA,
    output reg [1:0] o_LB
);

    reg [1:0]       Current_State;
    reg [1:0]       Next_State;

    localparam  STATE_0			=   2'b00;
    localparam  STATE_1         =   2'b01;
    localparam  STATE_2         =   2'b10;
    localparam  STATE_3         =   2'b11;

    localparam  GREEN           =   2'b00;
    localparam  RED             =   2'b01;
    localparam  YELLOW          =   2'b10;
    
	
    always @(posedge i_clk or negedge i_rstn) begin
        if(!i_rstn) begin
            Current_State   <= STATE_0;
        end
        else begin
            Current_State   <= Next_State;
        end
    end

    always @(*) begin
        case(Current_State)
            STATE_0 : begin
                if(i_TA == 1'b0)
                    Next_State = STATE_1;
                else if(i_TA == 1'b1) 
                    Next_State = STATE_0;
            end
            STATE_1 : begin
                Next_State = STATE_2;
            end
            STATE_2 : begin
                if(i_M == 1'b1 || i_TB == 1'b1)       
                    Next_State <= STATE_2;
                else if(i_M == 1'b0 && i_TB == 1'b0)  
                    Next_State <= STATE_3;
			end
			STATE_3 : begin
                Next_State = STATE_0;
            end
            default : begin
                Next_State = STATE_0;
            end 
        endcase
    end

    always @(*) begin
        case(Current_State)
            STATE_0 : begin
                o_LA    =   GREEN;
                o_LB    =   RED;
            end
            STATE_1 : begin
                o_LA    =   YELLOW;
                o_LB    =   RED;  
            end
            STATE_2 :   begin
                o_LA    =   RED;
                o_LB    =   GREEN;
            end
            STATE_3 :   begin
                o_LA    =   RED;
                o_LB    =   YELLOW;
            end
            default :   begin
                o_LA    =   RED;
                o_LB    =   RED;
            end
        endcase
    end
endmodule
