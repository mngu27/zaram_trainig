`include "Mode_FSM.v"
`include "Light_FSM.v"


module Traffic_Light_Controller
(
    input       i_clk,
    input       i_rstn,
    input       i_P,
    input       i_R,
    input       i_TA,
    input       i_TB,
    output [1:0]		o_LA,
    output [1:0]		o_LB    
);
	
	wire		w_M;
	
	Mode_FSM
	u_Mode_FSM(
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				),
		.i_P				(i_P				),
		.i_R				(i_R				),
		.o_M				(w_M				)
	);

	Light_FSM
	u_Light_FSM(
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				),
		.i_M				(w_M				),
		.i_TA				(i_TA				),
		.i_TB				(i_TB				),
		.o_LA				(o_LA				),
		.o_LB				(o_LB				)
	);

endmodule
