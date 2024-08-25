`ifndef			NOINC
`include		"../common/riscv_configs.v"
`endif


module pipeline_memory(
    input                       i_clk, 
    input                       i_rstn,

    input                       i_ctrl_reg_wr_enE,
    input       [       1:0]    i_ctrl_result_srcE,
    input                       i_ctrl_mem_wr_enE,
    input		[		3:0]    i_ctrl_mem_byte_selE,

    input		[ `XLEN-1:0]	i_alu_resultE,
    input		[ `XLEN-1:0]	i_mem_writedataE,
    input       [       4:0]    i_regfile_rd_addrE,
    input		[ `XLEN-1:0]	i_PCPlus4E,	
	input		[ `XLEN-1:0]	i_PCTargetE,
    
	output reg                  o_ctrl_reg_wr_enM,
    output reg  [       1:0]    o_ctrl_result_srcM,
    output reg                  o_ctrl_mem_wr_enM,
    output reg	[		3:0]    o_ctrl_mem_byte_selM,

    output reg	[ `XLEN-1:0]	o_alu_resultM,
    output reg	[ `XLEN-1:0]	o_mem_writedataM,
    output reg  [       4:0]    o_regfile_rd_addrM,
    output reg	[ `XLEN-1:0]	o_PCPlus4M,
	output reg	[ `XLEN-1:0]	o_PCTargetM
);

    always @(posedge i_clk or negedge i_rstn) begin
        if(!i_rstn) begin
            o_ctrl_reg_wr_enM       <= 0;
            o_ctrl_result_srcM      <= 0;
            o_ctrl_mem_wr_enM       <= 0;
            o_ctrl_mem_byte_selM    <= 0;
            o_alu_resultM           <= 0;
            o_mem_writedataM        <= 0;
            o_regfile_rd_addrM      <= 0;
            o_PCPlus4M              <= 0;
			o_PCTargetM				<= 0;
        end 
        else begin
            o_ctrl_reg_wr_enM       <= i_ctrl_reg_wr_enE;
            o_ctrl_result_srcM      <= i_ctrl_result_srcE;
            o_ctrl_mem_wr_enM       <= i_ctrl_mem_wr_enE;
            o_ctrl_mem_byte_selM    <= i_ctrl_mem_byte_selE;
            o_alu_resultM           <= i_alu_resultE;
            o_mem_writedataM        <= i_mem_writedataE;
            o_regfile_rd_addrM      <= i_regfile_rd_addrE;
            o_PCPlus4M              <= i_PCPlus4E;
			o_PCTargetM				<= i_PCTargetE;
            end
    end

endmodule 
