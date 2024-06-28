//-------------------------------------
// Define Global Variables
// ------------------------------------
`define CLKFREQ     100
`define SIMCYCLE    100
`define BW_DATA     64
`define BW_ADDR     6

`define SPSRAM_ASYNC

//-------------------------------------
// Includes
// ------------------------------------
`include "spsram.v"

module spsram_tb;
//-------------------------------------
// DUT Signals & Instantiate
// ------------------------------------
    reg                    i_clk;
    reg   [`BW_DATA-1:0]   i_data;
    reg   [`BW_ADDR-1:0]   i_addr;
    reg                    i_wen;
    reg                    i_cen;
    reg                    i_oen;
    wire  [`BW_DATA-1:0]   o_data;
    
    spsram
    #(
        .BW_DATA    (   `BW_DATA     ),
        .BW_ADDR    (   `BW_ADDR     )
)
	u_spsram(
        .i_clk      (   i_clk       ),
        .i_data     (   i_data      ),
        .i_addr     (   i_addr      ),
        .i_wen      (   i_wen       ),
        .i_cen      (   i_cen       ),
        .i_oen      (   i_oen       ),
        .o_data     (   o_data      )
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
        i_clk   = 0;
        i_data  = 0;
        i_addr  = 0;
        i_wen   = 0;
        i_cen   = 0;
        i_oen   = 0;
    end
endtask

task memWR;
    input   [`BW_ADDR-1:0]  ti_addr;
    input   [`BW_DATA-1:0]  ti_data;
    begin
        @(negedge i_clk) begin
            taskState   = "WR";
            i_data      = ti_data;
            i_addr      = ti_addr;
            i_wen       = 1'b1;
            i_cen       = 1'b1;
            i_oen       = 1'b0;
        end
    end
endtask

task memRD;
    input   [`BW_ADDR-1:0]  ti_addr;
    begin
        @(negedge i_clk) begin
            taskState   = "RD";
            i_addr      = ti_addr;
            i_wen       = 1'b0;
            i_cen       = 1'b1;
            i_oen       = 1'b1;
        end
    end
endtask
//---------------------------------------------------
// Test Stimulus
//---------------------------------------------------
integer  i, j;
initial begin
    init();
    #(4*100/`CLKFREQ);

    for(i = 0; i < `SIMCYCLE; i++) begin
       memWR(i, i);
    end
    for(i = 0; i < `SIMCYCLE; i++) begin
       memRD(i);
    end
	#100;
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
        $dumpfile("spsram_tb.vcd");
        $dumpvars;     
    end
end

endmodule
