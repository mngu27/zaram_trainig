//`ifdef			NOINC
`include		"../common/riscv_configs.v"
//`endif


module pipeline_decode(
    input                       i_clk,
    input                       i_rstn,
    input                       i_en,

    input       [`XLEN-1:0]     instrF,
    input       [`XLEN-1:0]     PCF,
    input       [`XLEN-1:0]     PCPLUS4F,

    output  reg [`XLEN-1:0]     instrD,
    output  reg [`XLEN-1:0]     PCD,
    output  reg [`XLEN-1:0]     PCPLUS4D
);

    always @(posedge i_clk or negedge i_rstn) begin
        if(!i_rstn) begin
            instrD      <= 0;
            PCD         <= 0;
            PCPLUS4D    <= 0;
        end
        else begin
            if(i_en) begin
                instrD      <= instrF;
                PCD         <= PCF;
                PCPLUS4D    <= PCPLUS4F;
            end
            else begin
                instrD      <= instrD;
                PCD         <= PCD;
                PCPLUS4D    <= PCPLUS4D;
            end
        end
     end

endmodule
