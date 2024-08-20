
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
	pipeline_execute
	u_pipeline_execute(
		.i_clk				(i_clk				),
		.i_rstn				(i_rstn				),
		.i_clr				(i_clr				),
		.RegWriteD			(RegWriteD			),
		.ResultSrcD			(ResultSrcD			),
		.MemWriteD			(MemWriteD			),
		.JumpD				(JumpD				),
		.BranchD			(BranchD			),
		.ALUControlD		(ALUControlD		),
		.ALUSrcD			(ALUSrcD			),
		.Rd1D				(Rd1D				),
		.Rd2D				(Rd2D				),
		.PCD				(PCD				),
		.Rs1D				(Rs1D				),
		.Rs2D				(Rs2D				),
		.RdD				(RdD				),
		.ExtImmD			(ExtImmD			),
		.PCPlus4D			(PCPlus4D			),
		.RegWriteE			(RegWriteE			),
		.ResultSrcE			(ResultSrcE			),
		.MemWriteE			(MemWriteE			),
		.JumpE				(JumpE				),
		.BranchE			(BranchE			),
		.ALUControlE		(ALUControlE		),
		.ALUSrcE			(ALUSrcE			),
		.Rd1E				(Rd1E				),
		.Rd2E				(Rd2E				),
		.PCE				(PCE				),
		.Rs1E				(Rs1E				),
		.Rs2E				(Rs2E				),
		.RdE				(RdE				),
		.ExtImmE			(ExtImmE			),
		.PCPlus4E			(PCPlus4E			)
	);


