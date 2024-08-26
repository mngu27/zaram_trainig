`ifndef			NOINC
`include		"../common/riscv_configs.v"
`endif


module pipeline_execute(
    input                       i_clk,
    input                       i_rstn,
    input                       i_clear,

    input                       i_ctrl_reg_wr_enD,
    input           			i_ctrl_result_srcD,
	input		[		1:0]	i_ctrl_mux_selD,
    input                       i_ctrl_mem_wr_enD,
    input                       i_ctrl_jalD,
    input                       i_ctrl_jalrD,
    input                       i_ctrl_branchD,
    input       [       3:0]    i_ctrl_alu_ctrlD,
    input                       i_ctrl_alu_srcD,
    input		[		3:0]    i_ctrl_mem_byte_selD,
	input 	 	[	    2:0] 	i_ctrl_funct3D,

    input       [ `XLEN-1:0]    i_regfile_rs1_dataD,
    input       [ `XLEN-1:0]    i_regfile_rs2_dataD,
     
    input       [       4:0]    i_regfile_rs1_addrD,
    input       [       4:0]    i_regfile_rs2_addrD,
    input       [       4:0]    i_regfile_rd_addrD,
    input       [ `XLEN-1:0]    i_PCD,
    input       [ `XLEN-1:0]    i_ExtImmD,
    input       [ `XLEN-1:0]    i_PCPlus4D,

	output reg 	[	    2:0] 	o_ctrl_funct3E,
    output reg                  o_ctrl_reg_wr_enE,
    output reg      			o_ctrl_result_srcE,
    output reg	[		1:0]	o_ctrl_mux_selE,
	output reg                  o_ctrl_mem_wr_enE,
    output reg                  o_ctrl_jalE,
    output reg                  o_ctrl_jalrE,
    output reg                  o_ctrl_branchE,
    output reg  [       3:0]    o_ctrl_alu_ctrlE,
    output reg                  o_ctrl_alu_srcE,
    output reg	[		3:0]    o_ctrl_mem_byte_selE,

    output reg  [ `XLEN-1:0]    o_regfile_rs1_dataE,
    output reg  [ `XLEN-1:0]    o_regfile_rs2_dataE,

    output reg  [       4:0]    o_regfile_rs1_addrE,
    output reg  [       4:0]    o_regfile_rs2_addrE,
    output reg  [       4:0]    o_regfile_rd_addrE,
    output reg  [ `XLEN-1:0]    o_PCE,
    output reg  [ `XLEN-1:0]    o_ExtImmE,
    output reg  [ `XLEN-1:0]    o_PCPlus4E
);

    always @(posedge i_clk or negedge i_rstn) begin
        if((~i_rstn) || i_clear) begin
            o_ctrl_reg_wr_enE       <= 0;
            o_ctrl_result_srcE      <= 0;
            o_ctrl_mux_selE			<= 0;
			o_ctrl_mem_wr_enE       <= 0;
            o_ctrl_jalE             <= 0;
            o_ctrl_jalrE            <= 0;
            o_ctrl_branchE          <= 0;
            o_ctrl_alu_ctrlE        <= 0;
            o_ctrl_alu_srcE         <= 0;
            o_ctrl_mem_byte_selE    <= 0;
            o_regfile_rs1_dataE     <= 0;
            o_regfile_rs2_dataE     <= 0;
            o_regfile_rs1_addrE     <= 0;
            o_regfile_rs2_addrE     <= 0;
            o_regfile_rd_addrE      <= 0;
            o_PCE                   <= 0;
            o_ExtImmE               <= 0;
            o_PCPlus4E              <= 0;
			o_ctrl_funct3E			<= 0;
        end
        else begin
            o_ctrl_reg_wr_enE       <= i_ctrl_reg_wr_enD      ;
            o_ctrl_result_srcE      <= i_ctrl_result_srcD     ;
            o_ctrl_mux_selE			<= i_ctrl_mux_selD		  ;
			o_ctrl_mem_wr_enE       <= i_ctrl_mem_wr_enD      ;
            o_ctrl_jalE             <= i_ctrl_jalD            ;
            o_ctrl_jalrE            <= i_ctrl_jalrD           ;
            o_ctrl_branchE          <= i_ctrl_branchD         ;
            o_ctrl_alu_ctrlE        <= i_ctrl_alu_ctrlD       ;
            o_ctrl_alu_srcE         <= i_ctrl_alu_srcD        ;
            o_ctrl_mem_byte_selE    <= i_ctrl_mem_byte_selD   ;
            o_regfile_rs1_dataE     <= i_regfile_rs1_dataD    ;
            o_regfile_rs2_dataE     <= i_regfile_rs2_dataD    ;
            o_regfile_rs1_addrE     <= i_regfile_rs1_addrD    ;
            o_regfile_rs2_addrE     <= i_regfile_rs2_addrD    ;
            o_regfile_rd_addrE      <= i_regfile_rd_addrD     ;
            o_PCE                   <= i_PCD                  ;
            o_ExtImmE               <= i_ExtImmD              ;
            o_PCPlus4E              <= i_PCPlus4D             ;
        	o_ctrl_funct3E			<= i_ctrl_funct3D;
		end  
    end

endmodule
