module CLA(
	input	[31:0]	i_a,
	input	[31:0]	i_b,
	input			i_c,
	output			o_c,
	output	[31:0]	o_s
);

	wire	[6:0]	w_c;

	CLA_4bit_block
	u_CLA_4bit_block_0(
		.i_a				(i_a[3:0]			),
		.i_b				(i_b[3:0]			),
		.i_c				(i_c				),
		.o_c				(w_c[0]				),
		.o_s				(o_s[3:0]			)
	);

	CLA_4bit_block
	u_CLA_4bit_block_1(
		.i_a				(i_a[7:4]			),
		.i_b				(i_b[7:4]			),
		.i_c				(w_c[0]				),
		.o_c				(w_c[1]				),
		.o_s				(o_s[7:4]			)
	);

	CLA_4bit_block
	u_CLA_4bit_block_2(
		.i_a				(i_a[11:8]			),
		.i_b				(i_b[11:8]			),
		.i_c				(w_c[1]				),
		.o_c				(w_c[2]				),
		.o_s				(o_s[11:8]			)
	);

	CLA_4bit_block
	u_CLA_4bit_block_3(
		.i_a				(i_a[15:12]			),
		.i_b				(i_b[15:12]			),
		.i_c				(w_c[2]				),
		.o_c				(w_c[3]				),
		.o_s				(o_s[15:12]			)
	);

	CLA_4bit_block
	u_CLA_4bit_block_4(
		.i_a				(i_a[19:16]			),
		.i_b				(i_b[19:16]			),
		.i_c				(w_c[3]				),
		.o_c				(w_c[4]				),
		.o_s				(o_s[19:16]			)
	);

	CLA_4bit_block
	u_CLA_4bit_block_5(
		.i_a				(i_a[23:20]			),
		.i_b				(i_b[23:20]			),
		.i_c				(w_c[4]				),
		.o_c				(w_c[5]				),
		.o_s				(o_s[23:20]			)
	);

	CLA_4bit_block
	u_CLA_4bit_block_6(
		.i_a				(i_a[27:24]			),
		.i_b				(i_b[27:24]			),
		.i_c				(w_c[5]				),
		.o_c				(w_c[6]				),
		.o_s				(o_s[27:24]			)
	);

	CLA_4bit_block
	u_CLA_4bit_block_7(
		.i_a				(i_a[31:28]			),
		.i_b				(i_b[31:28]			),
		.i_c				(w_c[6]				),
		.o_c				(o_c				),
		.o_s				(o_s[31:28]			)
	);

endmodule


module CLA_4bit_block(
	input	[3:0]	i_a,
	input	[3:0]	i_b,
	input			i_c,
	output			o_c,
	output	[3:0]	o_s
);
	pg
	u_pg(
		.i_a				(i_a				),
		.i_b				(i_b				),
		.i_c				(i_c				),
		.o_c				(o_c				),
		.o_s				(o_s				)
	);

endmodule

module pg(
	input	[3:0]	i_a,
	input	[3:0]	i_b,
	input			i_c,
	output			o_c,
	output	[3:0]	o_s
);

	wire	[3:0]	p;
	wire	[3:0]	g;
	wire 			P;
	wire			G;
	wire	[2:0]	c;

genvar i;
generate 
	for(i = 0; i < 4; i = i + 1) begin
		assign 	p[i] = i_a[i] ^ i_b[i];
		assign 	g[i] = i_a[i] & i_b[i];
	end 
endgenerate

assign c[0] = g[0] || (p[0] && i_c);
assign c[1] = g[1] || (p[1] && c[0]);
assign c[2] = g[2] || (p[2] && c[1]);

assign o_s = p ^ { c, i_c};

assign P = &p;
assign G = g[3] | (p[3] & (g[2] | p[2] & (g[1] | (p[1] & g[0]))));
assign o_c = G | (P & i_c);

endmodule
