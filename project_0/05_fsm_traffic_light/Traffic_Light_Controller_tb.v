//-------------------------------------
// Define Global Variables
// ------------------------------------
`define CLKFREQ     100
`define SIMCYCLE    100

`include "Traffic_Light_Controller.v"

module Traffic_Light_Controller_tb;
//---------------------------------------------------
//DUT Signals & Instantiate
//---------------------------------------------------
	reg       	i_clk;
	reg       	i_rstn;
	reg       	P;
	reg       	R;
	reg       	TA;
	reg       	TB;
	wire [1:0]		LA;
	wire [1:0]		LB;

	Traffic_Light_Controller
	u_Traffic_Light_Controller(
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				),
		.i_P				(P				),
		.i_R				(R				),
		.i_TA				(TA				),
		.i_TB				(TB				),
		.o_LA				(LA				),
		.o_LB				(LB				)
	);

//---------------------------------------------------
// Clock
//---------------------------------------------------
always #(500/`CLKFREQ) i_clk = ~i_clk;

//---------------------------------------------------
// Tasks
//---------------------------------------------------
reg     [8*32-1:0]  taskState;

task init;
    begin
		taskState 	= "Init";
		i_clk		= 0;
		i_rstn		= 0;
		P 		= 0;
        R 		= 0;
        TA		= 0;
        TB		= 0;
		repeat (4) @(posedge i_clk);
		i_rstn		= 1;
    end
endtask

task A_load_has_car;
	begin
		taskState = "TA_on";
		TA = 1'b1;
	end
endtask

task A_load_has_no_car;
	begin
		taskState = "TA_off";
		TA = 1'b0;
	end
endtask

task B_load_has_car;
	begin
		taskState = "TB_on";
		TB = 1'b1;
	end
endtask

task B_load_has_no_car;
	begin
		taskState = "TB_off";
		TB = 1'b0;
	end
endtask

task enter_parade;
	begin
		taskState = "Parade";
		P = 1'b1;
		R = 1'b0;
	end
endtask

task leave_parade;
	begin
		taskState = "parade_off";
		P = 1'b0;
		R = 1'b1;
	end
endtask


//---------------------------------------------------
//Stimulus
//---------------------------------------------------
integer i;

reg		[2:0]	d;

initial begin
	init();
	for (i=0; i<`SIMCYCLE; i++) begin
	A_load_has_car;
	d=$urandom_range(3'd1, 3'd4);
	repeat(d) @(posedge i_clk);
	A_load_has_no_car;
	d=$urandom_range(3'd1, 3'd4);
	repeat(d) @(posedge i_clk);
	enter_parade;
	d=$urandom_range(3'd1, 3'd4);
	repeat(d) @(posedge i_clk);
	B_load_has_car;
	d=$urandom_range(3'd1, 3'd4);
	repeat(d) @(posedge i_clk);
	B_load_has_no_car;
	d=$urandom_range(3'd1, 3'd4);
	repeat(d) @(posedge i_clk);
	leave_parade;
	d=$urandom_range(3'd1, 3'd4);
	repeat(d) @(posedge i_clk);


	end
	#(1000/`CLKFREQ);
	$finish;
end

// --------------------------------------------------
//	Dump VCD
// --------------------------------------------------
	reg	[8*32-1:0]	vcd_file;
	initial begin
		if ($value$plusargs("vcd_file=%s", vcd_file)) begin
			$dumpfile(vcd_file);
			$dumpvars;
		end else begin
			$dumpfile("Traffic_Light_Controller_tb.vcd");
			$dumpvars;
		end
	end



endmodule
