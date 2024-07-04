//-------------------------------------
// Define Global Variables
// ------------------------------------
`define CLKFREQ     100
`define SIMCYCLE    `NVEC
`define	NVEC		10

`include "CLA.v"

module CLA_tb;
//---------------------------------------------------
//DUT Signals & Instantiate
//---------------------------------------------------
	reg		[31:0]	i_a;
	reg		[31:0]	i_b;
	reg				i_c;
	wire			o_c;
	wire	[31:0]	o_s;

	CLA
	u_CLA(
		.i_a				(i_a				),
		.i_b				(i_b				),
		.i_c				(i_c				),
		.o_c				(o_c				),
		.o_s				(o_s				)
	);

//---------------------------------------------------
// Test Vector Configuration
//---------------------------------------------------
reg		[31:0]	vi_a[0:`NVEC-1];
reg		[31:0]	vi_b[0:`NVEC-1];
reg				vi_c[0:`NVEC-1];
reg		[31:0]	vo_s[0:`NVEC-1];
reg				vo_c[0:`NVEC-1];

initial begin
	$readmemb("./vec/i_a.vec",	vi_a);
	$readmemb("./vec/i_b.vec",	vi_b);
	$readmemb("./vec/i_c.vec",	vi_c);
	$readmemb("./vec/o_s.vec",	vo_s);
	$readmemb("./vec/o_c.vec",	vo_c);
end	

//---------------------------------------------------
// Task
//---------------------------------------------------
reg		[8*32-1:0]	taskState;
integer				err = 0;

task init;
	begin
		taskState		= "Init";
		i_a				= 0;
		i_b				= 0;
		i_c				= 0;
	end	
endtask

task vecInsert;
	input		[$clog2(`NVEC)-1:0]	i;
	begin
		$sformat(taskState, "VEC[=]", i);
		i_a				= vi_a[i];
		i_b				= vi_b[i];
		i_c				= vi_c[i];
	end 
endtask

task vecVerify;
	input		[$clog2(`NVEC)-1:0]	i;
	begin
		#(0.1*1000/`CLKFREQ);
		if(o_s != vo_s[i]) begin
			$display("[Idx: =] Mismatched o_s", i); 
		end
		if(o_c != vo_c[i]) begin
			$display("[Idx: =] Mismatched o_c", i); 
		end
		if((o_s != vo_s[i]) || (o_c != vo_c[i])) begin	
			err = err + 1;
		end
		#(0.9*1000/`CLKFREQ);
	end	
endtask	

//---------------------------------------------------
//Stimulus
//---------------------------------------------------
integer i;

initial begin
	init();
	for (i=0; i<`SIMCYCLE; i++) begin
		vecInsert(i);
		vecVerify(i);
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
			$dumpfile("CLA_tb.vcd");
			$dumpvars;
		end
	end

endmodule

