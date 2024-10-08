module barrel_shifter(
	input	[2:0]	k,
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
		.i_sel				(k[2]		),
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
		.i_sel				(k[2]		),
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
		.i_sel				(k[1]		),
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
		.i_sel				(k[1]		),
		.i_data0			(w_data[j]		),
		.i_data1			(w_data[j-6]	),
		.o_data				(y_data[j]			)
	);
	end
endgenerate

//---------------------------------------------------
// 1 bit shift
//---------------------------------------------------

genvar l;
generate
	for(l = 0; l < 7; l = l+1) begin
	mux
	u_mux(
		.i_sel				(k[0]		),
		.i_data0			(y_data[l]		),
		.i_data1			(y_data[l+1]	),
		.o_data				(o_data[l]			)
	);
	end
endgenerate

	mux
	u_mux(
		.i_sel				(k[0]		),
		.i_data0			(y_data[7]		),
		.i_data1			(y_data[0]	),
		.o_data				(o_data[7]			)
	);

	
endmodule


module mux(
	input		i_sel,
	input		i_data0,
	input		i_data1,
	output		o_data
);

assign o_data = (i_sel == 1) ? i_data1 : i_data0;

endmodule


