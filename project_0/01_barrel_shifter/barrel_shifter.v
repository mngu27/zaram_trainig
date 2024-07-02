`include "shift.v"


module barrel_shifter(
	input	[2:0]	shift_amount,
	input	[7:0]	i_data,
	output	[7:0]	o_data
);

	wire	[7:0]	w_data;
	wire	[7:0]	y_data;
//---------------------------------------------------
// 4 bit shift
//---------------------------------------------------

genvar i;
generate
	for(i = 0; i < 4; i = i+1) begin
	mux
	u_mux(
		.i_sel				(shift_amount[2]		),
		.i_data0			(i_data[i]		),
		.i_data1			(i_data[i+4]	),
		.o_data				(w_data[i]			)
	);
	end
endgenerate

generate
	for(i = 4; i < 8; i = i+1) begin
	mux
	u_mux(
		.i_sel				(shift_amount[2]		),
		.i_data0			(i_data[i]		),
		.i_data1			(i_data[i-4]	),
		.o_data				(w_data[i]			)
	);
end
endgenerate

//---------------------------------------------------
// 2 bit shift
//---------------------------------------------------

genvar j;
generate
	for(j = 0; j < 6; j = j+1) begin
	mux
	u_mux(
		.i_sel				(shift_amount[1]		),
		.i_data0			(w_data[j]		),
		.i_data1			(w_data[j+2]	),
		.o_data				(y_data[j]			)
	);
	end
endgenerate

generate
	for(j = 6; j < 8; j = j+1) begin
	mux
	u_mux(
		.i_sel				(shift_amount[1]		),
		.i_data0			(w_data[j]		),
		.i_data1			(w_data[j-6]	),
		.o_data				(y_data[j]			)
	);
	end
endgenerate

//---------------------------------------------------
// 1 bit shift
//---------------------------------------------------

genvar k;
generate
	for(k = 0; k < 7; k = k+1) begin
	mux
	u_mux(
		.i_sel				(shift_amount[0]		),
		.i_data0			(y_data[k]		),
		.i_data1			(y_data[k+1]	),
		.o_data				(o_data[k]			)
	);
	end
endgenerate

	mux
	u_mux(
		.i_sel				(shift_amount[0]		),
		.i_data0			(y_data[7]		),
		.i_data1			(y_data[0]	),
		.o_data				(o_data[7]			)
	);




	
/*
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
*/
endmodule
