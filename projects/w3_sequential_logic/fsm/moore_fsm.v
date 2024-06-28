module moore_fsm(
	input	i_clk,
	input	i_rstn,
	input	i_seq,
	output	reg	o_out
);

reg	[2:0]	cState;
reg	[2:0]	nState;
reg			seq;

//State
localparam	S_IDLE	=	3'b000;
localparam	S_H		=	3'b001;
localparam	S_HL	=	3'b010;
localparam	S_HLH	= 	3'b011;
localparam	S_HLHH	=	3'b100;


