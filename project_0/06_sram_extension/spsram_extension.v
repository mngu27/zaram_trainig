`include "spsram.v"

module spsram_extension
(
    input                   i_clk,
    input   [63:0]		    i_data,
    input   [5:0]   		i_addr,
    input                   i_wen,
    input                   i_cen,
    input                   i_oen,
    output  [63:0]   		o_data
);

	wire	[3:0]			cen;
	wire	[3:0]			oen;

	assign cen[0] = i_cen && (!i_addr[5]) && (!i_addr[4]);
	assign cen[1] = i_cen && (!i_addr[5]) &&  (i_addr[4]);
	assign cen[2] = i_cen &&  (i_addr[5]) && (!i_addr[4]);
	assign cen[3] = i_cen &&  (i_addr[5]) &&  (i_addr[4]);

	assign oen[0] = i_oen && (!i_addr[5]) && (!i_addr[4]);
	assign oen[1] = i_oen && (!i_addr[5]) &&  (i_addr[4]);
	assign oen[2] = i_oen &&  (i_addr[5]) && (!i_addr[4]);
	assign oen[3] = i_oen &&  (i_addr[5]) &&  (i_addr[4]);




	spsram
	#(
		.BW_DATA			(32					),
		.BW_ADDR			(4					)
	)
	u_spsram0(
		.i_clk				(i_clk				),
		.i_data				(i_data[31:0]		),
		.i_addr				(i_addr[3:0]		),
		.i_wen				(i_wen				),
		.i_cen				(cen[0]				),
		.i_oen				(oen[0]				),
		.o_data				(o_data[31:0]		)
	);

		spsram
	#(
		.BW_DATA			(32					),
		.BW_ADDR			(4					)
	)
	u_spsram1(
		.i_clk				(i_clk				),
		.i_data				(i_data[63:32]		),
		.i_addr				(i_addr[3:0]		),
		.i_wen				(i_wen				),
		.i_cen				(cen[0]				),
		.i_oen				(oen[0]				),
		.o_data				(o_data[63:32]		)
	);

	spsram
	#(
		.BW_DATA			(32					),
		.BW_ADDR			(4					)
	)
	u_spsram2(
		.i_clk				(i_clk				),
		.i_data				(i_data[31:0]		),
		.i_addr				(i_addr[3:0]		),
		.i_wen				(i_wen				),
		.i_cen				(cen[1]				),
		.i_oen				(oen[1]				),
		.o_data				(o_data[31:0]		)
	);

		spsram
	#(
		.BW_DATA			(32					),
		.BW_ADDR			(4					)
	)
	u_spsram3(
		.i_clk				(i_clk				),
		.i_data				(i_data[63:32]		),
		.i_addr				(i_addr[3:0]		),
		.i_wen				(i_wen				),
		.i_cen				(cen[1]				),
		.i_oen				(oen[1]				),
		.o_data				(o_data[63:32]		)
	);

	spsram
	#(
		.BW_DATA			(32					),
		.BW_ADDR			(4					)
	)
	u_spsram4(
		.i_clk				(i_clk				),
		.i_data				(i_data[31:0]		),
		.i_addr				(i_addr[3:0]		),
		.i_wen				(i_wen				),
		.i_cen				(cen[2]				),
		.i_oen				(oen[2]				),
		.o_data				(o_data[31:0]		)
	);

		spsram
	#(
		.BW_DATA			(32					),
		.BW_ADDR			(4					)
	)
	u_spsram5(
		.i_clk				(i_clk				),
		.i_data				(i_data[63:32]		),
		.i_addr				(i_addr[3:0]		),
		.i_wen				(i_wen				),
		.i_cen				(cen[2]				),
		.i_oen				(oen[2]				),
		.o_data				(o_data[63:32]		)
	);

	spsram
	#(
		.BW_DATA			(32					),
		.BW_ADDR			(4					)
	)
	u_spsram6(
		.i_clk				(i_clk				),
		.i_data				(i_data[31:0]		),
		.i_addr				(i_addr[3:0]		),
		.i_wen				(i_wen				),
		.i_cen				(cen[3]				),
		.i_oen				(oen[3]				),
		.o_data				(o_data[31:0]		)
	);

		spsram
	#(
		.BW_DATA			(32					),
		.BW_ADDR			(4					)
	)
	u_spsram7(
		.i_clk				(i_clk				),
		.i_data				(i_data[63:32]		),
		.i_addr				(i_addr[3:0]		),
		.i_wen				(i_wen				),
		.i_cen				(cen[3]				),
		.i_oen				(oen[3]				),
		.o_data				(o_data[63:32]		)
	);

	endmodule
