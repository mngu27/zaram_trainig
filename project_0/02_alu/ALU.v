module ALU
#(
    parameter  BW_DATA = 32
)
(
    input   [BW_DATA-1:0]   i_a,
    input   [BW_DATA-1:0]   i_b,
    input   [        2:0]   i_f,
    output  [BW_DATA-1:0]   o_y
);

    wire    [BW_DATA-1:0]   w_y0;
    wire    [BW_DATA-1:0]   w_y1;
    wire    [BW_DATA-1:0]   w_y2;
    wire    [BW_DATA-1:0]   w_y3;
    wire    [BW_DATA-1:0]   w_y4;
	wire    [BW_DATA-1:0]   w_y5;
	wire					w_cout;

	NOT
	#(
		.BW_DATA			(BW_DATA			)
	)
	u_not(
		.i_a				(i_b				),
		.o_y				(w_y0				)
	);

	Mux2to1
	#(
		.BW_DATA			(BW_DATA			)
	)
	u_mux2to1(
		.i_sel				(i_f[2]				),
		.i_a				(i_b				),
		.i_b				(w_y0				),
		.o_y				(w_y1				)
	);

	AND
	#(
		.BW_DATA			(BW_DATA			)
	)
	u_and(
		.i_a				(i_a				),
		.i_b				(w_y1				),
		.o_y				(w_y2				)
	);

	OR
		#(
		.BW_DATA			(BW_DATA			)
	)
	u_or(
		.i_a				(i_a				),
		.i_b				(w_y1				),
		.o_y				(w_y3				)
	);

	ADDER
	#(
		.BW_DATA			(BW_DATA			)
	)
	u_adder(
		.i_a				(i_a				),
		.i_b				(w_y1				),
		.i_c				(i_f[2]				),
		.o_c				(w_cout				),
		.o_s				(w_y4				)
	);

	/////Zero Extension /////
	assign w_y5 = {{(BW_DATA-1){1'b0}}, w_y4[BW_DATA-1]};


	
	Mux4to1
	#(
		.BW_DATA			(BW_DATA			)
	)
	u_mux4to1(
		.i_sel				(i_f[1:0]			),
		.i_a				(w_y2				),
		.i_b				(w_y3				),
		.i_c				(w_y4				),
		.i_d				(w_y5				),
		.o_y				(o_y				)
	);





    
endmodule 

module NOT
#(
    parameter  BW_DATA = 32
)
(
    input   [BW_DATA-1:0]   i_a,
    output  [BW_DATA-1:0]   o_y
);

    assign o_y = ~(i_a);

endmodule

module AND
#(
    parameter  BW_DATA = 32
)
(
    input   [BW_DATA-1:0]   i_a,
    input   [BW_DATA-1:0]   i_b,
    output  [BW_DATA-1:0]   o_y
);

    assign o_y = i_a & i_b;

endmodule

module OR 
#(
    parameter  BW_DATA = 32
)
(
    input   [BW_DATA-1:0]   i_a,
    input   [BW_DATA-1:0]   i_b,
    output  [BW_DATA-1:0]   o_y
);

    assign o_y = i_a | i_b;

endmodule

module ADDER 
#(
    parameter  BW_DATA = 32
)
(
    input   [BW_DATA-1:0]   i_a,
    input   [BW_DATA-1:0]   i_b,
    input                   i_c,
    output                  o_c,
    output  [BW_DATA-1:0]   o_s
);

    assign  {o_c, o_s}  =   i_a + i_b + i_c;

endmodule

module Mux2to1 
#(
    parameter  BW_DATA = 32
)
(
    input   				i_sel,
    input   [BW_DATA-1:0]   i_a,
    input   [BW_DATA-1:0]   i_b,
    output  [BW_DATA-1:0]   o_y
);

assign o_y = (i_sel) ? i_b : i_a;
    
endmodule

module Mux4to1 
#(
    parameter  BW_DATA = 32
)
(
    input       [        1:0]   i_sel,
    input       [BW_DATA-1:0]   i_a,
    input       [BW_DATA-1:0]   i_b,
    input       [BW_DATA-1:0]   i_c,
    input       [BW_DATA-1:0]   i_d,
    output  reg [BW_DATA-1:0]   o_y
);

always @(*) begin
    case(i_sel)
        2'b00 : o_y = i_a;
        2'b01 : o_y = i_b;
        2'b10 : o_y = i_c;
        2'b11 : o_y = i_d;
    endcase
end

endmodule
