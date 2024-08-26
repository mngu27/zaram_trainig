
module hazard_unit(
    // Data Forwarding
    input       [       4:0]    i_regfile_rs1_addrE,
    input       [       4:0]    i_regfile_rs2_addrE,
    input       [       4:0]    i_regfile_rd_addrM,
    input       [       4:0]    i_regfile_rd_addrW,
    input                       i_ctrl_reg_wr_enM,
    input                       i_ctrl_reg_wr_enW,

    // Stalling 
    input       [       4:0]    i_regfile_rs1_addrD,
    input       [       4:0]    i_regfile_rs2_addrD,
    input       [       4:0]    i_regfile_rd_addrE,
    input              			i_ctrl_result_srcE,

    // Control hazard flush
    input        [      1:0]    i_PCSrcE,
    
    // Data Forwarding
    output  reg [       1:0]        o_hazard_forwardAE,
    output  reg [       1:0]        o_hazard_forwardBE,
    
    // Stalling
    output  reg                     o_hazard_stallF,
    output  reg                     o_hazard_stallD,
    output  reg                     o_hazard_flushE,
    output  reg                     o_hazard_flushD
);

    wire                            lwStall;

always @(*) begin
    if((i_regfile_rs1_addrE == i_regfile_rd_addrM) && i_ctrl_reg_wr_enM && (i_regfile_rs1_addrE != 0)) 
        o_hazard_forwardAE = 2'b10;
    else if ((i_regfile_rs1_addrE == i_regfile_rd_addrW) && i_ctrl_reg_wr_enW && (i_regfile_rs1_addrE != 0)) 
        o_hazard_forwardAE = 2'b01;
    else 
        o_hazard_forwardAE = 2'b00;
end

always @(*) begin
    if((i_regfile_rs2_addrE == i_regfile_rd_addrM) && i_ctrl_reg_wr_enM && (i_regfile_rs2_addrE != 0)) 
        o_hazard_forwardBE = 2'b10;
    else if ((i_regfile_rs2_addrE == i_regfile_rd_addrW) && i_ctrl_reg_wr_enW && (i_regfile_rs2_addrE != 0)) 
        o_hazard_forwardBE = 2'b01;
    else 
        o_hazard_forwardBE = 2'b00;
end


assign lwStall = (((i_regfile_rs1_addrD == i_regfile_rd_addrE) || (i_regfile_rs2_addrD == i_regfile_rd_addrE)) && (i_ctrl_result_srcE));

always @(*) begin
    o_hazard_stallF  = lwStall;
    o_hazard_stallD  = lwStall;
    o_hazard_flushE  = lwStall || i_PCSrcE[1] || i_PCSrcE[0];
    o_hazard_flushD  = i_PCSrcE[1] || i_PCSrcE[0];   
end
endmodule
