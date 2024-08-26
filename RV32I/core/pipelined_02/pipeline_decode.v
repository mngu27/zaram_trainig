`ifndef			NOINC
`include		"../common/riscv_configs.v"
`endif

module pipeline_decode(
    input                       i_clk,
    input                       i_rstn,
    input                       i_en,
    input                       i_clear,

    input       [`XLEN-1:0]     i_instrF,
    input       [`XLEN-1:0]     i_PCF,
    input       [`XLEN-1:0]     i_PCPlus4F,

    output  reg [`XLEN-1:0]     o_instrD,
    output  reg [`XLEN-1:0]     o_PCD,
    output  reg [`XLEN-1:0]     o_PCPlus4D
);

    always @(posedge i_clk or negedge i_rstn) begin
        if((~i_rstn) || i_clear) begin
            o_instrD      <= 0;
            o_PCD         <= 0;
            o_PCPlus4D    <= 0;
        end
        else begin
            if(i_en) begin
                o_instrD      <= i_instrF;
                o_PCD         <= i_PCF;
                o_PCPlus4D    <= i_PCPlus4F;
			end
            else begin
                o_instrD      <= o_instrD;
                o_PCD         <= o_PCD;
                o_PCPlus4D    <= o_PCPlus4D;
            end
        end
     end

endmodule
