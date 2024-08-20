module pipeline_writeback(
    input           i_clk,
    input           i_rstn,
    
    // Control Unit
    input           RegWriteM,
    input   [1:0]   ResultSrcM,

    input           ALUResultM,
    input           ReadDataM,
    input           PCPlus4M,
    input           RdM,

    output reg          RegWriteW,
    output reg  [1:0]   ResultSrcW,
    output reg          ALUResultW,
    output reg          ReadDataW,
    output reg          PCPlus4W,
    output reg          RdW
);

    always @(posedge i_clk or negedge i_rstn) begin
        if(!i_rstn) begin
            RegWriteW   <= 0;
            ResultSrcW  <= 0;
            ALUResultW  <= 0;
            ReadDataW   <= 0;
            PCPlus4W    <= 0;
            RdW         <= 0;
        end
        else begin
            RegWriteW   <= RegWriteM;
            ResultSrcW  <= ResultSrcM;
            ALUResultW  <= ALUResultM;
            ReadDataW   <= ReadDataM;
            PCPlus4W    <= PCPlus4M;
            RdW         <= RdM;
        end
    end

	endmodule
