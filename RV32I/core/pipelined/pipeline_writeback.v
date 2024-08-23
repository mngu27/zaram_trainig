`ifndef			NOINC
`include		"../common/riscv_configs.v"
`endif


module pipeline_writeback(
    input                       i_clk,
    input                       i_rstn,
    
    input                       i_ctrl_reg_wr_enM,
    input       [       1:0]    i_ctrl_result_srcM,
    input		[ `XLEN-1:0]	i_alu_resultM,
    input		[ `XLEN-1:0]	i_mem_readdataM,
    input		[ `XLEN-1:0]	i_PCPlus4M,	
    input       [       4:0]    i_regfile_rd_addrM,

    output reg                  o_ctrl_reg_wr_enW,
    output reg  [       1:0]    o_ctrl_result_srcW,
    output reg	[ `XLEN-1:0]	o_alu_resultW,
    output reg	[ `XLEN-1:0]	o_mem_readdataW,
    output reg	[ `XLEN-1:0]	o_PCPlus4W,	
    output reg  [       4:0]    o_regfile_rd_addrW
);

    always @(posedge i_clk or negedge i_rstn) begin
        if(!i_rstn) begin
            o_ctrl_reg_wr_enW   <= 0;
            o_ctrl_result_srcW  <= 0;
            o_alu_resultW       <= 0;
            o_mem_readdataW     <= 0;
            o_PCPlus4W          <= 0;
            o_regfile_rd_addrW  <= 0;
        end
        else begin
            o_ctrl_reg_wr_enW   <= i_ctrl_reg_wr_enM;
            o_ctrl_result_srcW  <= i_ctrl_result_srcM;
            o_alu_resultW       <= i_alu_resultM;
            o_mem_readdataW     <= i_mem_readdataM;
            o_PCPlus4W          <= i_PCPlus4M;          
            o_regfile_rd_addrW  <= i_regfile_rd_addrM;   
            end
    end

endmodule
