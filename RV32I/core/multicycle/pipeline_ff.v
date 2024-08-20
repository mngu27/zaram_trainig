//`ifdef			NOINC
`include		"../common/riscv_configs.v"
//`endif

module pipeline_ff (
    input                   i_clk,
    input                   i_rstn,
    input                   i_en,
    input       [`XLEN-1:0] i_pcw,

    output  reg [`XLEN-1:0] o_pcf
);
    
    always @(posedge i_clk or negedge i_rstn) begin
        if(!i_rstn)
            o_pcf   <= 0;
        else 
            if(i_en)
                o_pcf   <=  i_pcw;
            else
                o_pcf   <=  o_pcf;
    end

endmodule
