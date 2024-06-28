`define		CLKFREQ		100
`define		SIMCYCLE	10

`include	"counter.v"

module counter_tb;
//---------------------------------
// DUT Signals & Institate
//----------------------------------
	parameter	UPBND				= 32;
	reg								i_clk;
	reg								i_rstn;
	reg								i_mode;
	wire	 [$clog2(UPBND+1)-1:0]	o_cnt;

	updowncnt
	#(
		.UPBND				(UPBND				)
	)
	u_upcnt(
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				),
		.i_mode				(i_mode				),
		.o_cnt				(o_cnt				)
	);
//---------------------------------
// Clock
//----------------------------------
always #(500/`CLKFREQ) i_clk = ~i_clk;

//---------------------------------
// Task
//----------------------------------
reg [8*32-1:0] taskState;

task init;
	begin
		taskState	= "INIT";
		i_clk 		= 0;
		i_rstn 		= 0;
		i_mode		= 0;
	end
endtask
//---------------------------------
// Stimulus
//----------------------------------
integer i, j;

	initial begin
		init();

		for(i = 0; i < `SIMCYCLE; i++) begin
			j	= $urandom_range(0, 10);
			#(((j * 0.1)) * 1000/`CLKFREQ);
			
			#((1-(j * 0.1)) * 1000/`CLKFREQ);
		end
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
		end 
		else begin
			$dumpfile("latch_vs_dff_tb.vcd");
			$dumpvars;
		end
	end

endmodule
