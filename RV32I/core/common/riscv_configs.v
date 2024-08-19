// ---------------------------------------------------
// RISC-V Integer Bit & Memory Specification
// ---------------------------------------------------
`define XLEN					32
`define	DMEM_ADDR_BIT			8
`define IMEM_ADDR_BIT			8

`define DMEM_INIT	
`define	DMEM_INIT_FILE			"riscv_dmem.mif"
`define	IMEM_INIT
`define	IMEM_INIT_FILE			"riscv_imem.mif"


// ---------------------------------------------------
// Immidiate Source
// ---------------------------------------------------
`define	SRC_IMM_R				3'b000
`define	SRC_IMM_I				3'b001
`define	SRC_IMM_S				3'b010
`define	SRC_IMM_B				3'b011
`define	SRC_IMM_U				3'b100
`define	SRC_IMM_J				3'b101


// ---------------------------------------------------
// ALU State
// ---------------------------------------------------
// 										{funct[7], funct3}
`define	ALU_CTRL_ADD 					4'b0000
`define	ALU_CTRL_SUB					4'b1000 
`define	ALU_CTRL_XOR					4'b0100 
`define	ALU_CTRL_OR 					4'b0110 
`define	ALU_CTRL_AND					4'b0111
`define	ALU_CTRL_SLL					4'b0001 
`define	ALU_CTRL_SRL					4'b0101 
`define	ALU_CTRL_SRA					4'b1101 
`define	ALU_CTRL_SLT					4'b0010 
`define	ALU_CTRL_SLTU					4'b0011

// ---------------------------------------------------
// Instructions opcodes
// ---------------------------------------------------
`define OPCODE_R_OP						7'b0110011
`define OPCODE_I_OP						7'b0010011
`define OPCODE_I_LOAD					7'b0000011
`define OPCODE_S_STORE					7'b0100011
`define OPCODE_B_BRANCH					7'b1100011
`define OPCODE_J_JAL					7'b1101111
`define OPCODE_I_JALR					7'b1100111
`define OPCODE_U_LUI					7'b0110111
`define OPCODE_U_AUIPC					7'b0010111

// ---------------------------------------------------
// Source (NEXT)PC 
// ---------------------------------------------------
`define SRC_PC_PC_4						2'b00
`define SRC_PC_PC_IMM					2'b01
`define SRC_PC_RS_IMM					2'b10

// ---------------------------------------------------
//	Source RD(Register file Write Data) 
// ---------------------------------------------------
`define SRC_RD_ALU						2'b00
`define SRC_RD_DME						2'b01
`define SRC_RD_PC4						2'b10
`define SRC_RD_IMM						2'b11

// ---------------------------------------------------
//	Source ALU
// ---------------------------------------------------
`define SRC_ALU_A_RS1					1'b0
`define SRC_ALU_A_PC					1'b1
`define SRC_ALU_B_RS2					1'b0
`define SRC_ALU_B_IMM					1'b1 

// ---------------------------------------------------
//	Funct3	for ALU
// ---------------------------------------------------
`define FUNCT3_ALU_ADD_SUB				3'b000 
`define FUNCT3_ALU_XOR					3'b001
`define FUNCT3_ALU_OR					3'b110
`define FUNCT3_ALU_AND					3'b111
`define FUNCT3_ALU_SLL					3'b001
`define FUNCT3_ALU_SRL_SRA				3'b101
`define FUNCT3_ALU_SLT					3'b010
`define FUNCT3_ALU_SLTU					3'b011

// ---------------------------------------------------
//	Funct3	for Branch
// ---------------------------------------------------
`define FUNCT3_BRANCH_BEQ				3'b000 
`define FUNCT3_BRANCH_BNE				3'b001 
`define FUNCT3_BRANCH_BLT				3'b100 
`define FUNCT3_BRANCH_BGE				3'b101 
`define FUNCT3_BRANCH_BLUT				3'b110 
`define FUNCT3_BRANCH_BGEU				3'b111 

// ---------------------------------------------------
//	Funct3	for LOAD/STORE
// ---------------------------------------------------
`define FUNCT3_MEM_BYTE					3'b000 				
`define FUNCT3_MEM_HALF					3'b001 
`define FUNCT3_MEM_WORD					3'b010 
`define FUNCT3_MEM_BYTEU				3'b100
`define FUNCT3_MEM_HALFU				3'b101 
