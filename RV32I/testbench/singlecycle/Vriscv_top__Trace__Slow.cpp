// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vriscv_top__Syms.h"


//======================

void Vriscv_top::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vriscv_top::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vriscv_top::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vriscv_top::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vriscv_top::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+144,"o_riscv_imem_pc", false,-1, 31,0);
        tracep->declBus(c+145,"o_riscv_imem_instr", false,-1, 31,0);
        tracep->declBus(c+146,"o_riscv_dmem_addr", false,-1, 31,0);
        tracep->declBit(c+147,"o_riscv_dmem_wr_en", false,-1);
        tracep->declBus(c+148,"o_riscv_dmem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+149,"o_riscv_dmem_wr_data", false,-1, 31,0);
        tracep->declBus(c+150,"o_riscv_dmem_rd_data", false,-1, 31,0);
        tracep->declBit(c+151,"i_clk", false,-1);
        tracep->declBit(c+152,"i_rstn", false,-1);
        tracep->declBus(c+170,"riscv_top REGISTER_INIT", false,-1, 31,0);
        tracep->declBus(c+144,"riscv_top o_riscv_imem_pc", false,-1, 31,0);
        tracep->declBus(c+145,"riscv_top o_riscv_imem_instr", false,-1, 31,0);
        tracep->declBus(c+146,"riscv_top o_riscv_dmem_addr", false,-1, 31,0);
        tracep->declBit(c+147,"riscv_top o_riscv_dmem_wr_en", false,-1);
        tracep->declBus(c+148,"riscv_top o_riscv_dmem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+149,"riscv_top o_riscv_dmem_wr_data", false,-1, 31,0);
        tracep->declBus(c+150,"riscv_top o_riscv_dmem_rd_data", false,-1, 31,0);
        tracep->declBit(c+151,"riscv_top i_clk", false,-1);
        tracep->declBit(c+152,"riscv_top i_rstn", false,-1);
        tracep->declBus(c+170,"riscv_top u_riscv_cpu REGISTER_INIT", false,-1, 31,0);
        tracep->declBus(c+144,"riscv_top u_riscv_cpu o_cpu_imem_pc", false,-1, 31,0);
        tracep->declBus(c+146,"riscv_top u_riscv_cpu o_cpu_dmem_addr", false,-1, 31,0);
        tracep->declBit(c+147,"riscv_top u_riscv_cpu o_cpu_dmem_wr_en", false,-1);
        tracep->declBus(c+148,"riscv_top u_riscv_cpu o_cpu_dmem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+149,"riscv_top u_riscv_cpu o_cpu_dmem_wr_data", false,-1, 31,0);
        tracep->declBus(c+145,"riscv_top u_riscv_cpu i_cpu_imem_instr", false,-1, 31,0);
        tracep->declBus(c+150,"riscv_top u_riscv_cpu i_cpu_dmem_rd_data", false,-1, 31,0);
        tracep->declBit(c+151,"riscv_top u_riscv_cpu i_clk", false,-1);
        tracep->declBit(c+152,"riscv_top u_riscv_cpu i_rstn", false,-1);
        tracep->declBit(c+98,"riscv_top u_riscv_cpu alu_zero", false,-1);
        tracep->declBus(c+99,"riscv_top u_riscv_cpu src_imm", false,-1, 2,0);
        tracep->declBus(c+100,"riscv_top u_riscv_cpu src_pc", false,-1, 1,0);
        tracep->declBus(c+101,"riscv_top u_riscv_cpu src_rd", false,-1, 1,0);
        tracep->declBit(c+153,"riscv_top u_riscv_cpu src_alu_a", false,-1);
        tracep->declBit(c+102,"riscv_top u_riscv_cpu src_alu_b", false,-1);
        tracep->declBit(c+154,"riscv_top u_riscv_cpu reg_wr_en", false,-1);
        tracep->declBus(c+103,"riscv_top u_riscv_cpu alu_ctrl", false,-1, 3,0);
        tracep->declBus(c+104,"riscv_top u_riscv_cpu dmem_addr", false,-1, 31,0);
        tracep->declBus(c+155,"riscv_top u_riscv_cpu dmem_rd_data", false,-1, 31,0);
        tracep->declBus(c+105,"riscv_top u_riscv_cpu dmem_wr_data", false,-1, 31,0);
        tracep->declBit(c+156,"riscv_top u_riscv_cpu dmem_wr_en", false,-1);
        tracep->declBus(c+157,"riscv_top u_riscv_cpu dmem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+170,"riscv_top u_riscv_cpu u_riscv_datapath REGISTER_INIT", false,-1, 31,0);
        tracep->declBus(c+144,"riscv_top u_riscv_cpu u_riscv_datapath o_dp_pc", false,-1, 31,0);
        tracep->declBit(c+98,"riscv_top u_riscv_cpu u_riscv_datapath o_dp_alu_zero", false,-1);
        tracep->declBus(c+104,"riscv_top u_riscv_cpu u_riscv_datapath o_dp_mem_addr", false,-1, 31,0);
        tracep->declBus(c+105,"riscv_top u_riscv_cpu u_riscv_datapath o_dp_mem_wr_data", false,-1, 31,0);
        tracep->declBus(c+155,"riscv_top u_riscv_cpu u_riscv_datapath i_dp_mem_rd_data", false,-1, 31,0);
        tracep->declBus(c+145,"riscv_top u_riscv_cpu u_riscv_datapath i_dp_instr", false,-1, 31,0);
        tracep->declBus(c+99,"riscv_top u_riscv_cpu u_riscv_datapath i_dp_src_imm", false,-1, 2,0);
        tracep->declBus(c+100,"riscv_top u_riscv_cpu u_riscv_datapath i_dp_src_pc", false,-1, 1,0);
        tracep->declBus(c+101,"riscv_top u_riscv_cpu u_riscv_datapath i_dp_src_rd", false,-1, 1,0);
        tracep->declBit(c+153,"riscv_top u_riscv_cpu u_riscv_datapath i_dp_src_alu_a", false,-1);
        tracep->declBit(c+102,"riscv_top u_riscv_cpu u_riscv_datapath i_dp_src_alu_b", false,-1);
        tracep->declBit(c+154,"riscv_top u_riscv_cpu u_riscv_datapath i_dp_reg_wr_en", false,-1);
        tracep->declBus(c+103,"riscv_top u_riscv_cpu u_riscv_datapath i_dp_alu_ctrl", false,-1, 3,0);
        tracep->declBit(c+151,"riscv_top u_riscv_cpu u_riscv_datapath i_clk", false,-1);
        tracep->declBit(c+152,"riscv_top u_riscv_cpu u_riscv_datapath i_rstn", false,-1);
        tracep->declBus(c+106,"riscv_top u_riscv_cpu u_riscv_datapath pc_next", false,-1, 31,0);
        tracep->declBus(c+158,"riscv_top u_riscv_cpu u_riscv_datapath pc_plus_4", false,-1, 31,0);
        tracep->declBus(c+159,"riscv_top u_riscv_cpu u_riscv_datapath pc_plus_imm", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_cpu u_riscv_datapath regfile_rs1_data", false,-1, 31,0);
        tracep->declBus(c+105,"riscv_top u_riscv_cpu u_riscv_datapath regfile_rs2_data", false,-1, 31,0);
        tracep->declBus(c+107,"riscv_top u_riscv_cpu u_riscv_datapath regfile_rd_data", false,-1, 31,0);
        tracep->declBus(c+108,"riscv_top u_riscv_cpu u_riscv_datapath immediate", false,-1, 31,0);
        tracep->declBus(c+109,"riscv_top u_riscv_cpu u_riscv_datapath alu_a", false,-1, 31,0);
        tracep->declBus(c+110,"riscv_top u_riscv_cpu u_riscv_datapath alu_b", false,-1, 31,0);
        tracep->declBus(c+104,"riscv_top u_riscv_cpu u_riscv_datapath alu_result", false,-1, 31,0);
        tracep->declArray(c+111,"riscv_top u_riscv_cpu u_riscv_datapath mux_concat_pc", false,-1, 95,0);
        tracep->declArray(c+114,"riscv_top u_riscv_cpu u_riscv_datapath mux_concat_rd", false,-1, 127,0);
        tracep->declQuad(c+118,"riscv_top u_riscv_cpu u_riscv_datapath mux_concat_alu_a", false,-1, 63,0);
        tracep->declQuad(c+120,"riscv_top u_riscv_cpu u_riscv_datapath mux_concat_alu_b", false,-1, 63,0);
        tracep->declBus(c+171,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_mux_pc N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+106,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_mux_pc o_mux_data", false,-1, 31,0);
        tracep->declArray(c+111,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_mux_pc i_mux_concat_data", false,-1, 95,0);
        tracep->declBus(c+100,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_mux_pc i_mux_sel", false,-1, 1,0);
        {int i; for (i=0; i<3; i++) {
                tracep->declBus(c+122+i*1,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_mux_pc mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+170,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_register_pc REGISTER_INIT", false,-1, 31,0);
        tracep->declBus(c+144,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_register_pc o_register_q", false,-1, 31,0);
        tracep->declBus(c+106,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_register_pc i_register_d", false,-1, 31,0);
        tracep->declBit(c+172,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_register_pc i_register_en", false,-1);
        tracep->declBit(c+151,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_register_pc i_clk", false,-1);
        tracep->declBit(c+152,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_register_pc i_rstn", false,-1);
        tracep->declBus(c+160,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_regfile o_regfile_rs1_data", false,-1, 31,0);
        tracep->declBus(c+105,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_regfile o_regfile_rs2_data", false,-1, 31,0);
        tracep->declBus(c+161,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_regfile i_regfile_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+162,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_regfile i_regfile_rs2_addr", false,-1, 4,0);
        tracep->declBus(c+107,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_regfile i_regfile_rd_data", false,-1, 31,0);
        tracep->declBus(c+163,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_regfile i_regfile_rd_addr", false,-1, 4,0);
        tracep->declBit(c+154,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_regfile i_regfile_rd_wen", false,-1);
        tracep->declBit(c+151,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_regfile i_clk", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+65+i*1,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_regfile registers", true,(i+0), 31,0);}}
        tracep->declBus(c+108,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_immext o_imm_ext", false,-1, 31,0);
        tracep->declBus(c+145,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_immext i_imm_instr", false,-1, 31,0);
        tracep->declBus(c+99,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_immext i_imm_src", false,-1, 2,0);
        tracep->declBus(c+158,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_adder_pc_plus_4 o_adder_sum", false,-1, 31,0);
        tracep->declBus(c+144,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_adder_pc_plus_4 i_adder_a", false,-1, 31,0);
        tracep->declBus(c+173,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_adder_pc_plus_4 i_adder_b", false,-1, 31,0);
        tracep->declBus(c+159,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_adder_pc_plus_imm o_adder_sum", false,-1, 31,0);
        tracep->declBus(c+144,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_adder_pc_plus_imm i_adder_a", false,-1, 31,0);
        tracep->declBus(c+108,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_adder_pc_plus_imm i_adder_b", false,-1, 31,0);
        tracep->declBus(c+104,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_alu o_alu_result", false,-1, 31,0);
        tracep->declBit(c+98,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_alu o_alu_zero", false,-1);
        tracep->declBus(c+109,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_alu i_alu_a", false,-1, 31,0);
        tracep->declBus(c+110,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_alu i_alu_b", false,-1, 31,0);
        tracep->declBus(c+103,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_alu i_alu_ctrl", false,-1, 3,0);
        tracep->declQuad(c+125,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_alu DEBUG_ALU_OP", false,-1, 63,0);
        tracep->declBus(c+174,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_mux_alu_a N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+109,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_mux_alu_a o_mux_data", false,-1, 31,0);
        tracep->declQuad(c+118,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_mux_alu_a i_mux_concat_data", false,-1, 63,0);
        tracep->declBus(c+153,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_mux_alu_a i_mux_sel", false,-1, 0,0);
        {int i; for (i=0; i<2; i++) {
                tracep->declBus(c+127+i*1,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_mux_alu_a mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+174,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_mux_alu_b N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+110,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_mux_alu_b o_mux_data", false,-1, 31,0);
        tracep->declQuad(c+120,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_mux_alu_b i_mux_concat_data", false,-1, 63,0);
        tracep->declBus(c+102,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_mux_alu_b i_mux_sel", false,-1, 0,0);
        {int i; for (i=0; i<2; i++) {
                tracep->declBus(c+129+i*1,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_mux_alu_b mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+175,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_mux_regfile_rd_data N_MUX_IN", false,-1, 31,0);
        tracep->declBus(c+107,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_mux_regfile_rd_data o_mux_data", false,-1, 31,0);
        tracep->declArray(c+114,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_mux_regfile_rd_data i_mux_concat_data", false,-1, 127,0);
        tracep->declBus(c+101,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_mux_regfile_rd_data i_mux_sel", false,-1, 1,0);
        {int i; for (i=0; i<4; i++) {
                tracep->declBus(c+131+i*1,"riscv_top u_riscv_cpu u_riscv_datapath u_riscv_mux_regfile_rd_data mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+100,"riscv_top u_riscv_cpu u_riscv_ctrl o_ctrl_src_pc", false,-1, 1,0);
        tracep->declBus(c+99,"riscv_top u_riscv_cpu u_riscv_ctrl o_ctrl_src_imm", false,-1, 2,0);
        tracep->declBus(c+101,"riscv_top u_riscv_cpu u_riscv_ctrl o_ctrl_src_rd", false,-1, 1,0);
        tracep->declBit(c+153,"riscv_top u_riscv_cpu u_riscv_ctrl o_ctrl_src_alu_a", false,-1);
        tracep->declBit(c+102,"riscv_top u_riscv_cpu u_riscv_ctrl o_ctrl_src_alu_b", false,-1);
        tracep->declBit(c+154,"riscv_top u_riscv_cpu u_riscv_ctrl o_ctrl_reg_wr_en", false,-1);
        tracep->declBit(c+156,"riscv_top u_riscv_cpu u_riscv_ctrl o_ctrl_mem_wr_en", false,-1);
        tracep->declBus(c+157,"riscv_top u_riscv_cpu u_riscv_ctrl o_ctrl_mem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+103,"riscv_top u_riscv_cpu u_riscv_ctrl o_ctrl_alu_ctrl", false,-1, 3,0);
        tracep->declBit(c+98,"riscv_top u_riscv_cpu u_riscv_ctrl i_ctrl_alu_zero", false,-1);
        tracep->declBus(c+164,"riscv_top u_riscv_cpu u_riscv_ctrl i_ctrl_opcode", false,-1, 6,0);
        tracep->declBus(c+165,"riscv_top u_riscv_cpu u_riscv_ctrl i_ctrl_funct3", false,-1, 2,0);
        tracep->declBit(c+166,"riscv_top u_riscv_cpu u_riscv_ctrl i_ctrl_funct7_5b", false,-1);
        tracep->declBit(c+167,"riscv_top u_riscv_cpu u_riscv_ctrl take_branch", false,-1);
        tracep->declArray(c+135,"riscv_top u_riscv_cpu u_riscv_ctrl DEBUG_INSTR", false,-1, 255,0);
        tracep->declBus(c+146,"riscv_top u_riscv_cpu u_riscv_dmem_interface o_dmem_intf_addr", false,-1, 31,0);
        tracep->declBit(c+147,"riscv_top u_riscv_cpu u_riscv_dmem_interface o_dmem_intf_wen", false,-1);
        tracep->declBus(c+104,"riscv_top u_riscv_cpu u_riscv_dmem_interface i_dmem_intf_addr", false,-1, 31,0);
        tracep->declBit(c+156,"riscv_top u_riscv_cpu u_riscv_dmem_interface i_dmem_intf_wen", false,-1);
        tracep->declBus(c+149,"riscv_top u_riscv_cpu u_riscv_dmem_interface o_dmem_intf_wr_data", false,-1, 31,0);
        tracep->declBus(c+148,"riscv_top u_riscv_cpu u_riscv_dmem_interface o_dmem_intf_byte_sel", false,-1, 3,0);
        tracep->declBus(c+155,"riscv_top u_riscv_cpu u_riscv_dmem_interface o_dmem_intf_rd_data", false,-1, 31,0);
        tracep->declBus(c+105,"riscv_top u_riscv_cpu u_riscv_dmem_interface i_dmem_intf_wr_data", false,-1, 31,0);
        tracep->declBus(c+157,"riscv_top u_riscv_cpu u_riscv_dmem_interface i_dmem_intf_byte_sel", false,-1, 3,0);
        tracep->declBus(c+150,"riscv_top u_riscv_cpu u_riscv_dmem_interface i_dmem_intf_rd_data", false,-1, 31,0);
        tracep->declBus(c+165,"riscv_top u_riscv_cpu u_riscv_dmem_interface i_dmem_intf_func3", false,-1, 2,0);
        tracep->declBus(c+143,"riscv_top u_riscv_cpu u_riscv_dmem_interface byte_aligned_dmem_rd_data", false,-1, 31,0);
        tracep->declBus(c+145,"riscv_top u_riscv_imem o_imem_data", false,-1, 31,0);
        tracep->declBus(c+168,"riscv_top u_riscv_imem i_imem_addr", false,-1, 13,0);
        tracep->declArray(c+1,"riscv_top u_riscv_imem FILE_TEXT_MIF", false,-1, 1023,0);
        tracep->declBus(c+150,"riscv_top u_riscv_dmem o_dmem_data", false,-1, 31,0);
        tracep->declBus(c+149,"riscv_top u_riscv_dmem i_dmem_data", false,-1, 31,0);
        tracep->declBus(c+169,"riscv_top u_riscv_dmem i_dmem_addr", false,-1, 13,0);
        tracep->declBus(c+148,"riscv_top u_riscv_dmem i_dmem_byte_sel", false,-1, 3,0);
        tracep->declBit(c+147,"riscv_top u_riscv_dmem i_dmem_wr_en", false,-1);
        tracep->declBit(c+151,"riscv_top u_riscv_dmem i_clk", false,-1);
        tracep->declArray(c+33,"riscv_top u_riscv_dmem FILE_DATA_MIF", false,-1, 1023,0);
        tracep->declBus(c+97,"riscv_top u_riscv_dmem i", false,-1, 31,0);
    }
}

void Vriscv_top::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vriscv_top::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vriscv_top::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullWData(oldp+1,(vlTOPp->riscv_top__DOT__u_riscv_imem__DOT__FILE_TEXT_MIF),1024);
        tracep->fullWData(oldp+33,(vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__FILE_DATA_MIF),1024);
        tracep->fullIData(oldp+65,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[0]),32);
        tracep->fullIData(oldp+66,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[1]),32);
        tracep->fullIData(oldp+67,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[2]),32);
        tracep->fullIData(oldp+68,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[3]),32);
        tracep->fullIData(oldp+69,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[4]),32);
        tracep->fullIData(oldp+70,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[5]),32);
        tracep->fullIData(oldp+71,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[6]),32);
        tracep->fullIData(oldp+72,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[7]),32);
        tracep->fullIData(oldp+73,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[8]),32);
        tracep->fullIData(oldp+74,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[9]),32);
        tracep->fullIData(oldp+75,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[10]),32);
        tracep->fullIData(oldp+76,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[11]),32);
        tracep->fullIData(oldp+77,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[12]),32);
        tracep->fullIData(oldp+78,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[13]),32);
        tracep->fullIData(oldp+79,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[14]),32);
        tracep->fullIData(oldp+80,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[15]),32);
        tracep->fullIData(oldp+81,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[16]),32);
        tracep->fullIData(oldp+82,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[17]),32);
        tracep->fullIData(oldp+83,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[18]),32);
        tracep->fullIData(oldp+84,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[19]),32);
        tracep->fullIData(oldp+85,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[20]),32);
        tracep->fullIData(oldp+86,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[21]),32);
        tracep->fullIData(oldp+87,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[22]),32);
        tracep->fullIData(oldp+88,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[23]),32);
        tracep->fullIData(oldp+89,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[24]),32);
        tracep->fullIData(oldp+90,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[25]),32);
        tracep->fullIData(oldp+91,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[26]),32);
        tracep->fullIData(oldp+92,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[27]),32);
        tracep->fullIData(oldp+93,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[28]),32);
        tracep->fullIData(oldp+94,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[29]),32);
        tracep->fullIData(oldp+95,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[30]),32);
        tracep->fullIData(oldp+96,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[31]),32);
        tracep->fullIData(oldp+97,(vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__i),32);
        tracep->fullBit(oldp+98,((0U == vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result)));
        tracep->fullCData(oldp+99,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_imm),3);
        tracep->fullCData(oldp+100,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_pc),2);
        tracep->fullCData(oldp+101,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_rd),2);
        tracep->fullBit(oldp+102,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_alu_b));
        tracep->fullCData(oldp+103,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__alu_ctrl),4);
        tracep->fullIData(oldp+104,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result),32);
        tracep->fullIData(oldp+105,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__regfile_rs2_data),32);
        tracep->fullIData(oldp+106,(((2U >= (IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_pc))
                                      ? vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_pc__DOT__mux_input_arr
                                     [vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_pc]
                                      : 0U)),32);
        tracep->fullIData(oldp+107,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr
                                    [vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_rd]),32);
        tracep->fullIData(oldp+108,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__immediate),32);
        tracep->fullIData(oldp+109,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_a),32);
        tracep->fullIData(oldp+110,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_b),32);
        tracep->fullWData(oldp+111,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_pc),96);
        tracep->fullWData(oldp+114,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_rd),128);
        tracep->fullQData(oldp+118,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_alu_a),64);
        tracep->fullQData(oldp+120,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_alu_b),64);
        tracep->fullIData(oldp+122,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_pc__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+123,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_pc__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+124,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_pc__DOT__mux_input_arr[2]),32);
        tracep->fullQData(oldp+125,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP),64);
        tracep->fullIData(oldp+127,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_alu_a__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+128,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_alu_a__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+129,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+130,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+131,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+132,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+133,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr[2]),32);
        tracep->fullIData(oldp+134,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr[3]),32);
        tracep->fullWData(oldp+135,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR),256);
        tracep->fullIData(oldp+143,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data),32);
        tracep->fullIData(oldp+144,(vlTOPp->o_riscv_imem_pc),32);
        tracep->fullIData(oldp+145,(vlTOPp->o_riscv_imem_instr),32);
        tracep->fullIData(oldp+146,(vlTOPp->o_riscv_dmem_addr),32);
        tracep->fullBit(oldp+147,(vlTOPp->o_riscv_dmem_wr_en));
        tracep->fullCData(oldp+148,(vlTOPp->o_riscv_dmem_byte_sel),4);
        tracep->fullIData(oldp+149,(vlTOPp->o_riscv_dmem_wr_data),32);
        tracep->fullIData(oldp+150,(vlTOPp->o_riscv_dmem_rd_data),32);
        tracep->fullBit(oldp+151,(vlTOPp->i_clk));
        tracep->fullBit(oldp+152,(vlTOPp->i_rstn));
        tracep->fullBit(oldp+153,((0x17U == (0x7fU 
                                             & vlTOPp->o_riscv_imem_instr))));
        tracep->fullBit(oldp+154,((1U & (~ ((0x23U 
                                             == (0x7fU 
                                                 & vlTOPp->o_riscv_imem_instr)) 
                                            | (0x63U 
                                               == (0x7fU 
                                                   & vlTOPp->o_riscv_imem_instr)))))));
        tracep->fullIData(oldp+155,(((0x4000U & vlTOPp->o_riscv_imem_instr)
                                      ? ((0x2000U & vlTOPp->o_riscv_imem_instr)
                                          ? 0U : ((0x1000U 
                                                   & vlTOPp->o_riscv_imem_instr)
                                                   ? 
                                                  (0xffffU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                                                   : 
                                                  (0xffU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))
                                      : ((0x2000U & vlTOPp->o_riscv_imem_instr)
                                          ? ((0x1000U 
                                              & vlTOPp->o_riscv_imem_instr)
                                              ? 0U : vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                                          : ((0x1000U 
                                              & vlTOPp->o_riscv_imem_instr)
                                              ? ((0xffff0000U 
                                                  & ((- (IData)(
                                                                (1U 
                                                                 & (vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
                                                                    >> 0xfU)))) 
                                                     << 0x10U)) 
                                                 | (0xffffU 
                                                    & vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data))
                                              : ((0xffffff00U 
                                                  & ((- (IData)(
                                                                (1U 
                                                                 & (vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
                                                                    >> 7U)))) 
                                                     << 8U)) 
                                                 | (0xffU 
                                                    & vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))))),32);
        tracep->fullBit(oldp+156,((0x23U == (0x7fU 
                                             & vlTOPp->o_riscv_imem_instr))));
        tracep->fullCData(oldp+157,((((3U == (0x7fU 
                                              & vlTOPp->o_riscv_imem_instr)) 
                                      | (0x23U == (0x7fU 
                                                   & vlTOPp->o_riscv_imem_instr)))
                                      ? ((0x4000U & vlTOPp->o_riscv_imem_instr)
                                          ? ((0x2000U 
                                              & vlTOPp->o_riscv_imem_instr)
                                              ? 0xfU
                                              : ((0x1000U 
                                                  & vlTOPp->o_riscv_imem_instr)
                                                  ? 3U
                                                  : 1U))
                                          : ((0x2000U 
                                              & vlTOPp->o_riscv_imem_instr)
                                              ? 0xfU
                                              : ((0x1000U 
                                                  & vlTOPp->o_riscv_imem_instr)
                                                  ? 3U
                                                  : 1U)))
                                      : 0xfU)),4);
        tracep->fullIData(oldp+158,(((IData)(4U) + vlTOPp->o_riscv_imem_pc)),32);
        tracep->fullIData(oldp+159,((vlTOPp->o_riscv_imem_pc 
                                     + vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__immediate)),32);
        tracep->fullIData(oldp+160,(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers
                                    [(0x1fU & (vlTOPp->o_riscv_imem_instr 
                                               >> 0xfU))]),32);
        tracep->fullCData(oldp+161,((0x1fU & (vlTOPp->o_riscv_imem_instr 
                                              >> 0xfU))),5);
        tracep->fullCData(oldp+162,((0x1fU & (vlTOPp->o_riscv_imem_instr 
                                              >> 0x14U))),5);
        tracep->fullCData(oldp+163,((0x1fU & (vlTOPp->o_riscv_imem_instr 
                                              >> 7U))),5);
        tracep->fullCData(oldp+164,((0x7fU & vlTOPp->o_riscv_imem_instr)),7);
        tracep->fullCData(oldp+165,((7U & (vlTOPp->o_riscv_imem_instr 
                                           >> 0xcU))),3);
        tracep->fullBit(oldp+166,((1U & (vlTOPp->o_riscv_imem_instr 
                                         >> 0x1eU))));
        tracep->fullBit(oldp+167,(((0x63U == (0x7fU 
                                              & vlTOPp->o_riscv_imem_instr)) 
                                   & ((0x4000U & vlTOPp->o_riscv_imem_instr)
                                       ? ((0x2000U 
                                           & vlTOPp->o_riscv_imem_instr)
                                           ? ((0x1000U 
                                               & vlTOPp->o_riscv_imem_instr)
                                               ? (0U 
                                                  == vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result)
                                               : (0U 
                                                  != vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result))
                                           : ((0x1000U 
                                               & vlTOPp->o_riscv_imem_instr)
                                               ? (0U 
                                                  == vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result)
                                               : (0U 
                                                  != vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result)))
                                       : ((~ (vlTOPp->o_riscv_imem_instr 
                                              >> 0xdU)) 
                                          & ((0x1000U 
                                              & vlTOPp->o_riscv_imem_instr)
                                              ? (0U 
                                                 != vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result)
                                              : (0U 
                                                 == vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result)))))));
        tracep->fullSData(oldp+168,((0x3fffU & (vlTOPp->o_riscv_imem_pc 
                                                >> 2U))),14);
        tracep->fullSData(oldp+169,((0x3fffU & (vlTOPp->o_riscv_dmem_addr 
                                                >> 2U))),14);
        tracep->fullIData(oldp+170,(0U),32);
        tracep->fullIData(oldp+171,(3U),32);
        tracep->fullBit(oldp+172,(1U));
        tracep->fullIData(oldp+173,(4U),32);
        tracep->fullIData(oldp+174,(2U),32);
        tracep->fullIData(oldp+175,(4U),32);
    }
}
