`include "shift.v"


module barrel_shifter(
	input			left,
	input	[1:0]	shift,
	input	[3:0]	i_data,
	output	[3:0]	o_data
);

wire	[3:0]	p_data;
wire 	[1:0]	shift_mount;

assign shift_mount[0] = left ^ shift[0];
assign shift_mount[1] = left ^ shift[1];

shift u_shift0(
	.en		(shift_mount[0] ),
	.i_data	(i_data			),
	.o_data	(p_data			)
);

shift u_shift1(
	.en		(shift_mount[1] ),
	.i_data	(p_data			),
	.o_data	(o_data			)
);

endmodule
