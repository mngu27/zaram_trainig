
module riscv_execute(
    input   i_clk,
    input   i_rstn,
    input   i_clr,

    input   i_RegWriteD,
    input   i_ResultSrcD,
    input   i_MemWriteD,
    input   i_JumpD,
    input   i_BranchD,
    input   i_ALUControlD,
    input   i_ALUSrcD,
    
    input   i_PCD,
    input   i_Rs1D,
    input   i_Rs2D,
    input   i_RdD,
    input   i_ExtImmD,
    input   i_PCPlus4D,

    output   o_RegWriteE,
    output   o_ResultSrcE,
    output   o_MemWriteE,

    output  o_ALUResultE,
    output  o_RdE,
    output  o_PCPlus4E,

);

