module pipeline_execute(
    input   i_clk,
    input   i_rstn,
    input   i_clr,

    input   RegWriteD,
    input   ResultSrcD,
    input   MemWriteD,
    input   JumpD,
    input   BranchD,
    input   ALUControlD,
    input   ALUSrcD,
    
    input   PCD,
    input   Rs1D,
    input   Rs2D,
    input   RdD,
    input   ExtImmD,
    input   PCPlus4D,

    output reg   RegWriteE,
    output reg   ResultSrcE,
    output reg   MemWriteE,
    output reg   JumpE,
    output reg   BranchE,
    output reg   ALUControlE,
    output reg   ALUSrcE,
    
    output reg   PCE,
    output reg   Rs1E,
    output reg   Rs2E,
    output reg   RdE,
    output reg   ExtImmE,
    output reg   PCPlus4E

);

    always @(posedge i_clk or negedge i_rstn or posedge i_clr) begin
        if(!i_rstn || i_clr) begin
            RegWriteE   <= 0;
            ResultSrcE  <= 0;
            MemWriteE   <= 0;
            JumpE       <= 0;
            BranchE     <= 0;
            ALUControlE <= 0;
            ALUSrcE     <= 0;
            PCE         <= 0;
            Rs1E        <= 0;
            Rs2E        <= 0;
            RdE         <= 0;
            ExtImmE     <= 0;
            PCPlus4E    <= 0;
        end
        else begin
            RegWriteE   <= RegWriteD;
            ResultSrcE  <= ResultSrcD;
            MemWriteE   <= MemWriteD;
            JumpE       <= JumpD;
            BranchE     <= BranchD;
            ALUControlE <= ALUControlD;
            ALUSrcE     <= ALUSrcD;
            PCE         <= PCD;
            Rs1E        <= Rs1D;
            Rs2E        <= Rs2D;
            RdE         <= RdD;
            ExtImmE     <= ExtImmD;
            PCPlus4E    <= PCPlus4D;
        end  
    end

endmodule

