module pipeline_memory(
    input       i_clk, 
    input       i_rstn,

    input   RegWriteE,
    input   ResultSrcE,
    input   MemWriteE,
    
    input   ALUResultE,
    input   WriteDataE,
    input   RdE,
    input   PCPlus4E,

    output reg   RegWriteM,
    output reg   ResultSrcM,
    output reg   MemWriteM,
    
    output reg   ALUResultM,
    output reg   WriteDataM,
    output reg   RdM,
    output reg   PCPlus4M

);

    always @(posedge i_clk or negedge i_rstn) begin
        if(!i_rstn) begin
            RegWriteM   <= 0;
            ResultSrcM  <= 0;
            MemWriteM   <= 0;
            ALUResultM  <= 0;
            WriteDataM  <= 0;
            RdM         <= 0;
            PCPlus4M    <= 0;
        end 
        else begin
            RegWriteM   <= RegWriteE;
            ResultSrcM  <= ResultSrcE;
            MemWriteM   <= MemWriteE;
            ALUResultM  <= ALUResultE;
            WriteDataM  <= WriteDataE;
            RdM         <= RdE;
            PCPlus4M    <= PCPlus4E;
        end
    end

endmodule
