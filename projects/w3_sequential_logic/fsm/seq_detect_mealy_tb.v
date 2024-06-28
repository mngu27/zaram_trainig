`define     CLKFREQ     100
`define     SIMCYCLE    10

`include "seq_detect_mealy.v"

module seq_detect_mealy_tb;
//---------------------------------------------------
// DUT Signals & Instantiate
//---------------------------------------------------

reg           i_clk;
reg           i_rstn;
reg           i_seq;
wire          o_out;


seq_detect_mealy u_seq_detect_mealy(
    .i_clk  ( i_clk ),
    .i_rstn ( i_rstn),
    .i_seq  ( i_seq ),
    .o_out  ( o_out )
);

//---------------------------------------------------
// Clock
//---------------------------------------------------
always #(500/`CLKFREQ) i_clk = ~i_clk;

//---------------------------------------------------
// Tasks
//---------------------------------------------------
task init;
    begin
        i_clk = 0;
        i_rstn = 0;
        i_seq = 0;
        #(100/`CLKFREQ);
        i_rstn = 1'b1;
    end
endtask

//---------------------------------------------------
// Test Stimulus
//---------------------------------------------------
integer  i, j;
initial begin
    init();
    for(i = 0; i < `SIMCYCLE; i++) begin
        j       = $urandom_range(0, 10);
        #((  (j*0.1)) * 1000/`CLKFREQ);
        i_seq   = $urandom;
        #((1-(j*0.1)) * 1000/`CLKFREQ);
    end
    $finish;
end

//---------------------------------------------------
// Dump VCD
//---------------------------------------------------

reg [8*32-1:0] vcd_file;
initial begin
    if($value$plusargs("vcd_file=%s", vcd_file)) begin
        $dumpfile(vcd_file);
        $dumpvars;
    end
    else begin
        $dumpfile("seq_detect_mealy_tb.vcd");
        $dumpvars;     
    end
end

endmodule
