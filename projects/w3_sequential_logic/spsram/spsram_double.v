`include "spsram.v"

module spsram_double(
    input                   i_clk,
    input   [31:0]   		i_data,
    input   [4:0]   		i_addr,
    input                   i_wen,
    input                   i_cen,
    input                   i_oen,
    output  [31:0]  		o_data
);

	wire 					i_cen0;
	wire					i_cen1;
	wire					i_oen0;
	wire					i_oen1;

	assign i_cen0 = ~i_addr[4];
	assign i_oen0 = ~i_addr[4];
	assign i_cen1 =  i_addr[4];
	assign i_oen1 =  i_addr[4];


	spsram
	#(
		.BW_DATA			(32			),
		.BW_ADDR			(4			)
	)
	u_spsram0(
		.i_clk				(i_clk				),
		.i_data				(i_data				),
		.i_addr				(i_addr[3:0]		),
		.i_wen				(i_wen				),
		.i_cen				(i_cen0				),
		.i_oen				(i_oen0				),
		.o_data				(o_data				)
	);


	spsram
	#(
		.BW_DATA			(32			),
		.BW_ADDR			(4			)
	)
	u_spsram1(
		.i_clk				(i_clk				),
		.i_data				(i_data				),
		.i_addr				(i_addr				),
		.i_wen				(i_wen				),
		.i_cen				(i_cen1				),
		.i_oen				(i_oen1				),
		.o_data				(o_data				)
	);

endmodule

