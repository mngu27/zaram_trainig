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
        tracep->declBit(c+213,"i_clk", false,-1);
        tracep->declBit(c+214,"i_rstn", false,-1);
        tracep->declBus(c+215,"o_instrF", false,-1, 31,0);
        tracep->declBus(c+216,"o_mem_readdataM", false,-1, 31,0);
        tracep->declBus(c+217,"o_PCF", false,-1, 31,0);
        tracep->declBus(c+218,"o_alu_resultM", false,-1, 31,0);
        tracep->declBit(c+219,"o_ctrl_mem_wr_enM", false,-1);
        tracep->declBus(c+220,"o_ctrl_mem_byte_selM", false,-1, 3,0);
        tracep->declBus(c+221,"o_mem_writedataM", false,-1, 31,0);
        tracep->declBus(c+229,"riscv_top REGISTER_INIT", false,-1, 31,0);
        tracep->declBit(c+213,"riscv_top i_clk", false,-1);
        tracep->declBit(c+214,"riscv_top i_rstn", false,-1);
        tracep->declBus(c+215,"riscv_top o_instrF", false,-1, 31,0);
        tracep->declBus(c+216,"riscv_top o_mem_readdataM", false,-1, 31,0);
        tracep->declBus(c+217,"riscv_top o_PCF", false,-1, 31,0);
        tracep->declBus(c+218,"riscv_top o_alu_resultM", false,-1, 31,0);
        tracep->declBit(c+219,"riscv_top o_ctrl_mem_wr_enM", false,-1);
        tracep->declBus(c+220,"riscv_top o_ctrl_mem_byte_selM", false,-1, 3,0);
        tracep->declBus(c+221,"riscv_top o_mem_writedataM", false,-1, 31,0);
        tracep->declBus(c+229,"riscv_top u_riscv_pipelined_cpu REGISTER_INIT", false,-1, 31,0);
        tracep->declBit(c+213,"riscv_top u_riscv_pipelined_cpu i_clk", false,-1);
        tracep->declBit(c+214,"riscv_top u_riscv_pipelined_cpu i_rstn", false,-1);
        tracep->declBus(c+215,"riscv_top u_riscv_pipelined_cpu i_instrF", false,-1, 31,0);
        tracep->declBus(c+216,"riscv_top u_riscv_pipelined_cpu i_mem_readdataM", false,-1, 31,0);
        tracep->declBus(c+217,"riscv_top u_riscv_pipelined_cpu o_PCF", false,-1, 31,0);
        tracep->declBit(c+219,"riscv_top u_riscv_pipelined_cpu o_ctrl_mem_wr_enM", false,-1);
        tracep->declBus(c+218,"riscv_top u_riscv_pipelined_cpu o_alu_resultM", false,-1, 31,0);
        tracep->declBus(c+220,"riscv_top u_riscv_pipelined_cpu o_ctrl_mem_byte_selM", false,-1, 3,0);
        tracep->declBus(c+221,"riscv_top u_riscv_pipelined_cpu o_mem_writedataM", false,-1, 31,0);
        tracep->declBus(c+222,"riscv_top u_riscv_pipelined_cpu PCPlus4F", false,-1, 31,0);
        tracep->declBus(c+65,"riscv_top u_riscv_pipelined_cpu PCD", false,-1, 31,0);
        tracep->declBus(c+66,"riscv_top u_riscv_pipelined_cpu PCPlus4D", false,-1, 31,0);
        tracep->declBit(c+132,"riscv_top u_riscv_pipelined_cpu ctrl_reg_wr_enD", false,-1);
        tracep->declBit(c+133,"riscv_top u_riscv_pipelined_cpu ctrl_result_srcD", false,-1);
        tracep->declBus(c+134,"riscv_top u_riscv_pipelined_cpu ctrl_mux_selD", false,-1, 1,0);
        tracep->declBit(c+135,"riscv_top u_riscv_pipelined_cpu ctrl_mem_wr_enD", false,-1);
        tracep->declBit(c+136,"riscv_top u_riscv_pipelined_cpu ctrl_jalD", false,-1);
        tracep->declBit(c+137,"riscv_top u_riscv_pipelined_cpu ctrl_jalrD", false,-1);
        tracep->declBit(c+138,"riscv_top u_riscv_pipelined_cpu ctrl_branchD", false,-1);
        tracep->declBus(c+139,"riscv_top u_riscv_pipelined_cpu ctrl_alu_ctrlD", false,-1, 3,0);
        tracep->declBit(c+140,"riscv_top u_riscv_pipelined_cpu ctrl_alu_srcD", false,-1);
        tracep->declBus(c+141,"riscv_top u_riscv_pipelined_cpu ctrl_mem_byte_selD", false,-1, 3,0);
        tracep->declBus(c+142,"riscv_top u_riscv_pipelined_cpu regfile_rs1_addrD", false,-1, 4,0);
        tracep->declBus(c+143,"riscv_top u_riscv_pipelined_cpu regfile_rs2_addrD", false,-1, 4,0);
        tracep->declBus(c+223,"riscv_top u_riscv_pipelined_cpu regfile_rs1_dataD", false,-1, 31,0);
        tracep->declBus(c+224,"riscv_top u_riscv_pipelined_cpu regfile_rs2_dataD", false,-1, 31,0);
        tracep->declBus(c+144,"riscv_top u_riscv_pipelined_cpu ExtImmD", false,-1, 31,0);
        tracep->declBus(c+145,"riscv_top u_riscv_pipelined_cpu regfile_rd_addrD", false,-1, 4,0);
        tracep->declBus(c+146,"riscv_top u_riscv_pipelined_cpu ctrl_funct3D", false,-1, 2,0);
        tracep->declBit(c+147,"riscv_top u_riscv_pipelined_cpu ctrl_reg_wr_enE", false,-1);
        tracep->declBit(c+67,"riscv_top u_riscv_pipelined_cpu ctrl_result_srcE", false,-1);
        tracep->declBus(c+68,"riscv_top u_riscv_pipelined_cpu ctrl_mux_selE", false,-1, 1,0);
        tracep->declBit(c+148,"riscv_top u_riscv_pipelined_cpu ctrl_mem_wr_enE", false,-1);
        tracep->declBus(c+149,"riscv_top u_riscv_pipelined_cpu ctrl_mem_byte_selE", false,-1, 3,0);
        tracep->declBus(c+69,"riscv_top u_riscv_pipelined_cpu regfile_rs1_addrE", false,-1, 4,0);
        tracep->declBus(c+70,"riscv_top u_riscv_pipelined_cpu regfile_rs2_addrE", false,-1, 4,0);
        tracep->declBus(c+150,"riscv_top u_riscv_pipelined_cpu regfile_rd_addrE", false,-1, 4,0);
        tracep->declBus(c+151,"riscv_top u_riscv_pipelined_cpu alu_resultE", false,-1, 31,0);
        tracep->declBus(c+152,"riscv_top u_riscv_pipelined_cpu mem_writedataE", false,-1, 31,0);
        tracep->declBus(c+71,"riscv_top u_riscv_pipelined_cpu PCTargetE", false,-1, 31,0);
        tracep->declBus(c+72,"riscv_top u_riscv_pipelined_cpu PCPlus4E", false,-1, 31,0);
        tracep->declBus(c+153,"riscv_top u_riscv_pipelined_cpu PCSrcE", false,-1, 1,0);
        tracep->declBus(c+73,"riscv_top u_riscv_pipelined_cpu ExtImmE", false,-1, 31,0);
        tracep->declBit(c+154,"riscv_top u_riscv_pipelined_cpu ctrl_reg_wr_enM", false,-1);
        tracep->declBit(c+74,"riscv_top u_riscv_pipelined_cpu ctrl_result_srcM", false,-1);
        tracep->declBus(c+155,"riscv_top u_riscv_pipelined_cpu regfile_rd_addrM", false,-1, 4,0);
        tracep->declBus(c+230,"riscv_top u_riscv_pipelined_cpu PCPlus4M", false,-1, 31,0);
        tracep->declBus(c+231,"riscv_top u_riscv_pipelined_cpu PCTargetM", false,-1, 31,0);
        tracep->declBus(c+156,"riscv_top u_riscv_pipelined_cpu writedata_dataM", false,-1, 31,0);
        tracep->declBit(c+157,"riscv_top u_riscv_pipelined_cpu ctrl_reg_wr_enW", false,-1);
        tracep->declBus(c+158,"riscv_top u_riscv_pipelined_cpu regfile_rd_addrW", false,-1, 4,0);
        tracep->declBus(c+159,"riscv_top u_riscv_pipelined_cpu regfile_rd_dataW", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_pipelined_cpu hazard_forwardAE", false,-1, 1,0);
        tracep->declBus(c+161,"riscv_top u_riscv_pipelined_cpu hazard_forwardBE", false,-1, 1,0);
        tracep->declBit(c+162,"riscv_top u_riscv_pipelined_cpu hazard_stallF", false,-1);
        tracep->declBit(c+162,"riscv_top u_riscv_pipelined_cpu hazard_stallD", false,-1);
        tracep->declBit(c+163,"riscv_top u_riscv_pipelined_cpu hazard_flushE", false,-1);
        tracep->declBit(c+164,"riscv_top u_riscv_pipelined_cpu hazard_flushD", false,-1);
        tracep->declBus(c+229,"riscv_top u_riscv_pipelined_cpu u_riscv_fetch REGISTER_INIT", false,-1, 31,0);
        tracep->declBit(c+213,"riscv_top u_riscv_pipelined_cpu u_riscv_fetch i_clk", false,-1);
        tracep->declBit(c+214,"riscv_top u_riscv_pipelined_cpu u_riscv_fetch i_rstn", false,-1);
        tracep->declBit(c+162,"riscv_top u_riscv_pipelined_cpu u_riscv_fetch i_hazard_stallF", false,-1);
        tracep->declBus(c+153,"riscv_top u_riscv_pipelined_cpu u_riscv_fetch i_PCSrcE", false,-1, 1,0);
        tracep->declBus(c+71,"riscv_top u_riscv_pipelined_cpu u_riscv_fetch i_PCTargetE", false,-1, 31,0);
        tracep->declBus(c+151,"riscv_top u_riscv_pipelined_cpu u_riscv_fetch i_alu_resultE", false,-1, 31,0);
        tracep->declBus(c+222,"riscv_top u_riscv_pipelined_cpu u_riscv_fetch o_PCPlus4F", false,-1, 31,0);
        tracep->declBus(c+217,"riscv_top u_riscv_pipelined_cpu u_riscv_fetch o_PCF", false,-1, 31,0);
        tracep->declBus(c+165,"riscv_top u_riscv_pipelined_cpu u_riscv_fetch PCW", false,-1, 31,0);
        tracep->declArray(c+166,"riscv_top u_riscv_pipelined_cpu u_riscv_fetch PC_concat_data", false,-1, 95,0);
        tracep->declBus(c+232,"riscv_top u_riscv_pipelined_cpu u_riscv_fetch u_riscv_mux_pc N_MUX_IN", false,-1, 31,0);
        tracep->declArray(c+166,"riscv_top u_riscv_pipelined_cpu u_riscv_fetch u_riscv_mux_pc i_mux_concat_data", false,-1, 95,0);
        tracep->declBus(c+153,"riscv_top u_riscv_pipelined_cpu u_riscv_fetch u_riscv_mux_pc i_mux_sel", false,-1, 1,0);
        tracep->declBus(c+165,"riscv_top u_riscv_pipelined_cpu u_riscv_fetch u_riscv_mux_pc o_mux_data", false,-1, 31,0);
        {int i; for (i=0; i<3; i++) {
                tracep->declBus(c+169+i*1,"riscv_top u_riscv_pipelined_cpu u_riscv_fetch u_riscv_mux_pc mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+229,"riscv_top u_riscv_pipelined_cpu u_riscv_fetch u_riscv_register REGISTER_INIT", false,-1, 31,0);
        tracep->declBit(c+213,"riscv_top u_riscv_pipelined_cpu u_riscv_fetch u_riscv_register i_clk", false,-1);
        tracep->declBit(c+214,"riscv_top u_riscv_pipelined_cpu u_riscv_fetch u_riscv_register i_rstn", false,-1);
        tracep->declBit(c+172,"riscv_top u_riscv_pipelined_cpu u_riscv_fetch u_riscv_register i_register_en", false,-1);
        tracep->declBus(c+165,"riscv_top u_riscv_pipelined_cpu u_riscv_fetch u_riscv_register i_register_d", false,-1, 31,0);
        tracep->declBus(c+217,"riscv_top u_riscv_pipelined_cpu u_riscv_fetch u_riscv_register o_register_q", false,-1, 31,0);
        tracep->declBus(c+217,"riscv_top u_riscv_pipelined_cpu u_riscv_fetch u_riscv_adder_pc_plus_4 i_adder_a", false,-1, 31,0);
        tracep->declBus(c+233,"riscv_top u_riscv_pipelined_cpu u_riscv_fetch u_riscv_adder_pc_plus_4 i_adder_b", false,-1, 31,0);
        tracep->declBus(c+222,"riscv_top u_riscv_pipelined_cpu u_riscv_fetch u_riscv_adder_pc_plus_4 o_adder_sum", false,-1, 31,0);
        tracep->declBit(c+213,"riscv_top u_riscv_pipelined_cpu u_riscv_decode i_clk", false,-1);
        tracep->declBit(c+214,"riscv_top u_riscv_pipelined_cpu u_riscv_decode i_rstn", false,-1);
        tracep->declBit(c+162,"riscv_top u_riscv_pipelined_cpu u_riscv_decode i_hazard_stallD", false,-1);
        tracep->declBit(c+164,"riscv_top u_riscv_pipelined_cpu u_riscv_decode i_hazard_flushD", false,-1);
        tracep->declBus(c+215,"riscv_top u_riscv_pipelined_cpu u_riscv_decode i_instrF", false,-1, 31,0);
        tracep->declBus(c+217,"riscv_top u_riscv_pipelined_cpu u_riscv_decode i_PCF", false,-1, 31,0);
        tracep->declBus(c+222,"riscv_top u_riscv_pipelined_cpu u_riscv_decode i_PCPlus4F", false,-1, 31,0);
        tracep->declBus(c+65,"riscv_top u_riscv_pipelined_cpu u_riscv_decode o_PCD", false,-1, 31,0);
        tracep->declBus(c+66,"riscv_top u_riscv_pipelined_cpu u_riscv_decode o_PCPlus4D", false,-1, 31,0);
        tracep->declBit(c+157,"riscv_top u_riscv_pipelined_cpu u_riscv_decode i_ctrl_reg_wr_enW", false,-1);
        tracep->declBus(c+158,"riscv_top u_riscv_pipelined_cpu u_riscv_decode i_regfile_rd_addrW", false,-1, 4,0);
        tracep->declBus(c+159,"riscv_top u_riscv_pipelined_cpu u_riscv_decode i_regfile_rd_dataW", false,-1, 31,0);
        tracep->declBus(c+146,"riscv_top u_riscv_pipelined_cpu u_riscv_decode o_ctrl_funct3D", false,-1, 2,0);
        tracep->declBit(c+132,"riscv_top u_riscv_pipelined_cpu u_riscv_decode o_ctrl_reg_wr_enD", false,-1);
        tracep->declBit(c+133,"riscv_top u_riscv_pipelined_cpu u_riscv_decode o_ctrl_result_srcD", false,-1);
        tracep->declBus(c+134,"riscv_top u_riscv_pipelined_cpu u_riscv_decode o_ctrl_mux_selD", false,-1, 1,0);
        tracep->declBit(c+135,"riscv_top u_riscv_pipelined_cpu u_riscv_decode o_ctrl_mem_wr_enD", false,-1);
        tracep->declBit(c+136,"riscv_top u_riscv_pipelined_cpu u_riscv_decode o_ctrl_jalD", false,-1);
        tracep->declBit(c+137,"riscv_top u_riscv_pipelined_cpu u_riscv_decode o_ctrl_jalrD", false,-1);
        tracep->declBit(c+138,"riscv_top u_riscv_pipelined_cpu u_riscv_decode o_ctrl_branchD", false,-1);
        tracep->declBus(c+139,"riscv_top u_riscv_pipelined_cpu u_riscv_decode o_ctrl_alu_ctrlD", false,-1, 3,0);
        tracep->declBit(c+140,"riscv_top u_riscv_pipelined_cpu u_riscv_decode o_ctrl_alu_srcD", false,-1);
        tracep->declBus(c+141,"riscv_top u_riscv_pipelined_cpu u_riscv_decode o_ctrl_mem_byte_selD", false,-1, 3,0);
        tracep->declBus(c+145,"riscv_top u_riscv_pipelined_cpu u_riscv_decode o_regfile_rd_addrD", false,-1, 4,0);
        tracep->declBus(c+142,"riscv_top u_riscv_pipelined_cpu u_riscv_decode o_regfile_rs1_addrD", false,-1, 4,0);
        tracep->declBus(c+143,"riscv_top u_riscv_pipelined_cpu u_riscv_decode o_regfile_rs2_addrD", false,-1, 4,0);
        tracep->declBus(c+223,"riscv_top u_riscv_pipelined_cpu u_riscv_decode o_regfile_rs1_dataD", false,-1, 31,0);
        tracep->declBus(c+224,"riscv_top u_riscv_pipelined_cpu u_riscv_decode o_regfile_rs2_dataD", false,-1, 31,0);
        tracep->declBus(c+144,"riscv_top u_riscv_pipelined_cpu u_riscv_decode o_ExtImmD", false,-1, 31,0);
        tracep->declBus(c+173,"riscv_top u_riscv_pipelined_cpu u_riscv_decode instrD", false,-1, 31,0);
        tracep->declBus(c+174,"riscv_top u_riscv_pipelined_cpu u_riscv_decode ctrl_src_immD", false,-1, 2,0);
        tracep->declBit(c+213,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_pipeline_decode i_clk", false,-1);
        tracep->declBit(c+214,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_pipeline_decode i_rstn", false,-1);
        tracep->declBit(c+172,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_pipeline_decode i_en", false,-1);
        tracep->declBit(c+164,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_pipeline_decode i_clear", false,-1);
        tracep->declBus(c+215,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_pipeline_decode i_instrF", false,-1, 31,0);
        tracep->declBus(c+217,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_pipeline_decode i_PCF", false,-1, 31,0);
        tracep->declBus(c+222,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_pipeline_decode i_PCPlus4F", false,-1, 31,0);
        tracep->declBus(c+173,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_pipeline_decode o_instrD", false,-1, 31,0);
        tracep->declBus(c+65,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_pipeline_decode o_PCD", false,-1, 31,0);
        tracep->declBus(c+66,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_pipeline_decode o_PCPlus4D", false,-1, 31,0);
        tracep->declBus(c+175,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_riscv_ctrl i_ctrl_opcode", false,-1, 6,0);
        tracep->declBus(c+146,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_riscv_ctrl i_ctrl_funct3", false,-1, 2,0);
        tracep->declBit(c+176,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_riscv_ctrl i_ctrl_funct7_5b", false,-1);
        tracep->declBit(c+132,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_riscv_ctrl o_ctrl_reg_wr_en", false,-1);
        tracep->declBit(c+133,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_riscv_ctrl o_ctrl_result_src", false,-1);
        tracep->declBus(c+134,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_riscv_ctrl o_ctrl_mux_sel", false,-1, 1,0);
        tracep->declBit(c+135,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_riscv_ctrl o_ctrl_mem_wr_en", false,-1);
        tracep->declBit(c+136,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_riscv_ctrl o_ctrl_jal", false,-1);
        tracep->declBit(c+137,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_riscv_ctrl o_ctrl_jalr", false,-1);
        tracep->declBit(c+138,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_riscv_ctrl o_ctrl_branch", false,-1);
        tracep->declBus(c+139,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_riscv_ctrl o_ctrl_alu_ctrl", false,-1, 3,0);
        tracep->declBit(c+140,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_riscv_ctrl o_ctrl_alu_src", false,-1);
        tracep->declBus(c+174,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_riscv_ctrl o_ctrl_src_imm", false,-1, 2,0);
        tracep->declBus(c+141,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_riscv_ctrl o_ctrl_mem_byte_sel", false,-1, 3,0);
        tracep->declArray(c+177,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_riscv_ctrl DEBUG_INSTR", false,-1, 255,0);
        tracep->declBit(c+213,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_riscv_regfile i_clk", false,-1);
        tracep->declBit(c+157,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_riscv_regfile i_regfile_rd_wen", false,-1);
        tracep->declBus(c+158,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_riscv_regfile i_regfile_rd_addr", false,-1, 4,0);
        tracep->declBus(c+159,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_riscv_regfile i_regfile_rd_data", false,-1, 31,0);
        tracep->declBus(c+142,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_riscv_regfile i_regfile_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+143,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_riscv_regfile i_regfile_rs2_addr", false,-1, 4,0);
        tracep->declBus(c+223,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_riscv_regfile o_regfile_rs1_data", false,-1, 31,0);
        tracep->declBus(c+224,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_riscv_regfile o_regfile_rs2_data", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+100+i*1,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_riscv_regfile registers", true,(i+0), 31,0);}}
        tracep->declBus(c+173,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_riscv_immext i_imm_instr", false,-1, 31,0);
        tracep->declBus(c+174,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_riscv_immext i_imm_scr", false,-1, 2,0);
        tracep->declBus(c+144,"riscv_top u_riscv_pipelined_cpu u_riscv_decode u_riscv_immext o_imm_ext", false,-1, 31,0);
        tracep->declBit(c+213,"riscv_top u_riscv_pipelined_cpu u_riscv_execute i_clk", false,-1);
        tracep->declBit(c+214,"riscv_top u_riscv_pipelined_cpu u_riscv_execute i_rstn", false,-1);
        tracep->declBit(c+132,"riscv_top u_riscv_pipelined_cpu u_riscv_execute i_ctrl_reg_wr_enD", false,-1);
        tracep->declBit(c+133,"riscv_top u_riscv_pipelined_cpu u_riscv_execute i_ctrl_result_srcD", false,-1);
        tracep->declBus(c+134,"riscv_top u_riscv_pipelined_cpu u_riscv_execute i_ctrl_mux_selD", false,-1, 1,0);
        tracep->declBit(c+135,"riscv_top u_riscv_pipelined_cpu u_riscv_execute i_ctrl_mem_wr_enD", false,-1);
        tracep->declBit(c+136,"riscv_top u_riscv_pipelined_cpu u_riscv_execute i_ctrl_jalD", false,-1);
        tracep->declBit(c+137,"riscv_top u_riscv_pipelined_cpu u_riscv_execute i_ctrl_jalrD", false,-1);
        tracep->declBit(c+138,"riscv_top u_riscv_pipelined_cpu u_riscv_execute i_ctrl_branchD", false,-1);
        tracep->declBus(c+139,"riscv_top u_riscv_pipelined_cpu u_riscv_execute i_ctrl_alu_ctrlD", false,-1, 3,0);
        tracep->declBit(c+140,"riscv_top u_riscv_pipelined_cpu u_riscv_execute i_ctrl_alu_srcD", false,-1);
        tracep->declBus(c+141,"riscv_top u_riscv_pipelined_cpu u_riscv_execute i_ctrl_mem_byte_selD", false,-1, 3,0);
        tracep->declBus(c+146,"riscv_top u_riscv_pipelined_cpu u_riscv_execute i_ctrl_funct3D", false,-1, 2,0);
        tracep->declBus(c+223,"riscv_top u_riscv_pipelined_cpu u_riscv_execute i_regfile_rs1_dataD", false,-1, 31,0);
        tracep->declBus(c+224,"riscv_top u_riscv_pipelined_cpu u_riscv_execute i_regfile_rs2_dataD", false,-1, 31,0);
        tracep->declBus(c+142,"riscv_top u_riscv_pipelined_cpu u_riscv_execute i_regfile_rs1_addrD", false,-1, 4,0);
        tracep->declBus(c+143,"riscv_top u_riscv_pipelined_cpu u_riscv_execute i_regfile_rs2_addrD", false,-1, 4,0);
        tracep->declBus(c+145,"riscv_top u_riscv_pipelined_cpu u_riscv_execute i_regfile_rd_addrD", false,-1, 4,0);
        tracep->declBus(c+65,"riscv_top u_riscv_pipelined_cpu u_riscv_execute i_PCD", false,-1, 31,0);
        tracep->declBus(c+144,"riscv_top u_riscv_pipelined_cpu u_riscv_execute i_ExtImmD", false,-1, 31,0);
        tracep->declBus(c+66,"riscv_top u_riscv_pipelined_cpu u_riscv_execute i_PCPlus4D", false,-1, 31,0);
        tracep->declBus(c+160,"riscv_top u_riscv_pipelined_cpu u_riscv_execute i_hazard_forwardAE", false,-1, 1,0);
        tracep->declBus(c+161,"riscv_top u_riscv_pipelined_cpu u_riscv_execute i_hazard_forwardBE", false,-1, 1,0);
        tracep->declBit(c+163,"riscv_top u_riscv_pipelined_cpu u_riscv_execute i_hazard_flushE", false,-1);
        tracep->declBus(c+156,"riscv_top u_riscv_pipelined_cpu u_riscv_execute i_writeback_dataM", false,-1, 31,0);
        tracep->declBus(c+159,"riscv_top u_riscv_pipelined_cpu u_riscv_execute i_regfile_rd_dataW", false,-1, 31,0);
        tracep->declBit(c+147,"riscv_top u_riscv_pipelined_cpu u_riscv_execute o_ctrl_reg_wr_enE", false,-1);
        tracep->declBit(c+67,"riscv_top u_riscv_pipelined_cpu u_riscv_execute o_ctrl_result_srcE", false,-1);
        tracep->declBus(c+68,"riscv_top u_riscv_pipelined_cpu u_riscv_execute o_ctrl_mux_selE", false,-1, 1,0);
        tracep->declBit(c+148,"riscv_top u_riscv_pipelined_cpu u_riscv_execute o_ctrl_mem_wr_enE", false,-1);
        tracep->declBus(c+149,"riscv_top u_riscv_pipelined_cpu u_riscv_execute o_ctrl_mem_byte_selE", false,-1, 3,0);
        tracep->declBus(c+69,"riscv_top u_riscv_pipelined_cpu u_riscv_execute o_regfile_rs1_addrE", false,-1, 4,0);
        tracep->declBus(c+70,"riscv_top u_riscv_pipelined_cpu u_riscv_execute o_regfile_rs2_addrE", false,-1, 4,0);
        tracep->declBus(c+150,"riscv_top u_riscv_pipelined_cpu u_riscv_execute o_regfile_rd_addrE", false,-1, 4,0);
        tracep->declBus(c+151,"riscv_top u_riscv_pipelined_cpu u_riscv_execute o_alu_resultE", false,-1, 31,0);
        tracep->declBus(c+152,"riscv_top u_riscv_pipelined_cpu u_riscv_execute o_mem_writedataE", false,-1, 31,0);
        tracep->declBus(c+73,"riscv_top u_riscv_pipelined_cpu u_riscv_execute o_ExtImmE", false,-1, 31,0);
        tracep->declBus(c+71,"riscv_top u_riscv_pipelined_cpu u_riscv_execute o_PCTargetE", false,-1, 31,0);
        tracep->declBus(c+72,"riscv_top u_riscv_pipelined_cpu u_riscv_execute o_PCPlus4E", false,-1, 31,0);
        tracep->declBus(c+153,"riscv_top u_riscv_pipelined_cpu u_riscv_execute o_PCSrcE", false,-1, 1,0);
        tracep->declBit(c+75,"riscv_top u_riscv_pipelined_cpu u_riscv_execute ctrl_jalE", false,-1);
        tracep->declBit(c+76,"riscv_top u_riscv_pipelined_cpu u_riscv_execute ctrl_jalrE", false,-1);
        tracep->declBit(c+77,"riscv_top u_riscv_pipelined_cpu u_riscv_execute ctrl_branchE", false,-1);
        tracep->declBus(c+78,"riscv_top u_riscv_pipelined_cpu u_riscv_execute ctrl_alu_ctrlE", false,-1, 3,0);
        tracep->declBit(c+79,"riscv_top u_riscv_pipelined_cpu u_riscv_execute ctrl_alu_srcE", false,-1);
        tracep->declBus(c+80,"riscv_top u_riscv_pipelined_cpu u_riscv_execute regfile_rs1_dataE", false,-1, 31,0);
        tracep->declBus(c+81,"riscv_top u_riscv_pipelined_cpu u_riscv_execute regfile_rs2_dataE", false,-1, 31,0);
        tracep->declBus(c+82,"riscv_top u_riscv_pipelined_cpu u_riscv_execute PCE", false,-1, 31,0);
        tracep->declBus(c+83,"riscv_top u_riscv_pipelined_cpu u_riscv_execute ctrl_funct3E", false,-1, 2,0);
        tracep->declBus(c+185,"riscv_top u_riscv_pipelined_cpu u_riscv_execute SrcAE", false,-1, 31,0);
        tracep->declBus(c+186,"riscv_top u_riscv_pipelined_cpu u_riscv_execute SrcBE", false,-1, 31,0);
        tracep->declArray(c+187,"riscv_top u_riscv_pipelined_cpu u_riscv_execute srcA_concat_data", false,-1, 95,0);
        tracep->declArray(c+190,"riscv_top u_riscv_pipelined_cpu u_riscv_execute writedata_concat", false,-1, 95,0);
        tracep->declQuad(c+193,"riscv_top u_riscv_pipelined_cpu u_riscv_execute srcB_concat_data", false,-1, 63,0);
        tracep->declBit(c+195,"riscv_top u_riscv_pipelined_cpu u_riscv_execute zeroE", false,-1);
        tracep->declBit(c+196,"riscv_top u_riscv_pipelined_cpu u_riscv_execute take_branch", false,-1);
        tracep->declBit(c+225,"riscv_top u_riscv_pipelined_cpu u_riscv_execute PC_branch", false,-1);
        tracep->declBit(c+213,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute i_clk", false,-1);
        tracep->declBit(c+214,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute i_rstn", false,-1);
        tracep->declBit(c+163,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute i_clear", false,-1);
        tracep->declBit(c+132,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute i_ctrl_reg_wr_enD", false,-1);
        tracep->declBit(c+133,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute i_ctrl_result_srcD", false,-1);
        tracep->declBus(c+134,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute i_ctrl_mux_selD", false,-1, 1,0);
        tracep->declBit(c+135,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute i_ctrl_mem_wr_enD", false,-1);
        tracep->declBit(c+136,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute i_ctrl_jalD", false,-1);
        tracep->declBit(c+137,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute i_ctrl_jalrD", false,-1);
        tracep->declBit(c+138,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute i_ctrl_branchD", false,-1);
        tracep->declBus(c+139,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute i_ctrl_alu_ctrlD", false,-1, 3,0);
        tracep->declBit(c+140,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute i_ctrl_alu_srcD", false,-1);
        tracep->declBus(c+141,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute i_ctrl_mem_byte_selD", false,-1, 3,0);
        tracep->declBus(c+146,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute i_ctrl_funct3D", false,-1, 2,0);
        tracep->declBus(c+223,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute i_regfile_rs1_dataD", false,-1, 31,0);
        tracep->declBus(c+224,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute i_regfile_rs2_dataD", false,-1, 31,0);
        tracep->declBus(c+142,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute i_regfile_rs1_addrD", false,-1, 4,0);
        tracep->declBus(c+143,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute i_regfile_rs2_addrD", false,-1, 4,0);
        tracep->declBus(c+145,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute i_regfile_rd_addrD", false,-1, 4,0);
        tracep->declBus(c+65,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute i_PCD", false,-1, 31,0);
        tracep->declBus(c+144,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute i_ExtImmD", false,-1, 31,0);
        tracep->declBus(c+66,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute i_PCPlus4D", false,-1, 31,0);
        tracep->declBus(c+83,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute o_ctrl_funct3E", false,-1, 2,0);
        tracep->declBit(c+147,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute o_ctrl_reg_wr_enE", false,-1);
        tracep->declBit(c+67,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute o_ctrl_result_srcE", false,-1);
        tracep->declBus(c+68,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute o_ctrl_mux_selE", false,-1, 1,0);
        tracep->declBit(c+148,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute o_ctrl_mem_wr_enE", false,-1);
        tracep->declBit(c+75,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute o_ctrl_jalE", false,-1);
        tracep->declBit(c+76,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute o_ctrl_jalrE", false,-1);
        tracep->declBit(c+77,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute o_ctrl_branchE", false,-1);
        tracep->declBus(c+78,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute o_ctrl_alu_ctrlE", false,-1, 3,0);
        tracep->declBit(c+79,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute o_ctrl_alu_srcE", false,-1);
        tracep->declBus(c+149,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute o_ctrl_mem_byte_selE", false,-1, 3,0);
        tracep->declBus(c+80,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute o_regfile_rs1_dataE", false,-1, 31,0);
        tracep->declBus(c+81,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute o_regfile_rs2_dataE", false,-1, 31,0);
        tracep->declBus(c+69,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute o_regfile_rs1_addrE", false,-1, 4,0);
        tracep->declBus(c+70,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute o_regfile_rs2_addrE", false,-1, 4,0);
        tracep->declBus(c+150,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute o_regfile_rd_addrE", false,-1, 4,0);
        tracep->declBus(c+82,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute o_PCE", false,-1, 31,0);
        tracep->declBus(c+73,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute o_ExtImmE", false,-1, 31,0);
        tracep->declBus(c+72,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_pipeline_execute o_PCPlus4E", false,-1, 31,0);
        tracep->declBus(c+232,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_riscv_mux_srcAE N_MUX_IN", false,-1, 31,0);
        tracep->declArray(c+187,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_riscv_mux_srcAE i_mux_concat_data", false,-1, 95,0);
        tracep->declBus(c+160,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_riscv_mux_srcAE i_mux_sel", false,-1, 1,0);
        tracep->declBus(c+185,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_riscv_mux_srcAE o_mux_data", false,-1, 31,0);
        {int i; for (i=0; i<3; i++) {
                tracep->declBus(c+197+i*1,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_riscv_mux_srcAE mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+232,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_riscv_mux_writedata N_MUX_IN", false,-1, 31,0);
        tracep->declArray(c+190,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_riscv_mux_writedata i_mux_concat_data", false,-1, 95,0);
        tracep->declBus(c+161,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_riscv_mux_writedata i_mux_sel", false,-1, 1,0);
        tracep->declBus(c+152,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_riscv_mux_writedata o_mux_data", false,-1, 31,0);
        {int i; for (i=0; i<3; i++) {
                tracep->declBus(c+200+i*1,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_riscv_mux_writedata mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+234,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_riscv_mux_srcBE N_MUX_IN", false,-1, 31,0);
        tracep->declQuad(c+193,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_riscv_mux_srcBE i_mux_concat_data", false,-1, 63,0);
        tracep->declBus(c+79,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_riscv_mux_srcBE i_mux_sel", false,-1, 0,0);
        tracep->declBus(c+186,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_riscv_mux_srcBE o_mux_data", false,-1, 31,0);
        {int i; for (i=0; i<2; i++) {
                tracep->declBus(c+203+i*1,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_riscv_mux_srcBE mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+82,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_riscv_adder_pc_plus_imm i_adder_a", false,-1, 31,0);
        tracep->declBus(c+73,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_riscv_adder_pc_plus_imm i_adder_b", false,-1, 31,0);
        tracep->declBus(c+71,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_riscv_adder_pc_plus_imm o_adder_sum", false,-1, 31,0);
        tracep->declBus(c+185,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_riscv_alu i_alu_a", false,-1, 31,0);
        tracep->declBus(c+186,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_riscv_alu i_alu_b", false,-1, 31,0);
        tracep->declBus(c+78,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_riscv_alu i_alu_ctrl", false,-1, 3,0);
        tracep->declBit(c+195,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_riscv_alu o_alu_zero", false,-1);
        tracep->declBus(c+151,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_riscv_alu o_alu_result", false,-1, 31,0);
        tracep->declQuad(c+84,"riscv_top u_riscv_pipelined_cpu u_riscv_execute u_riscv_alu DEBUG_ALU_OP", false,-1, 63,0);
        tracep->declBit(c+213,"riscv_top u_riscv_pipelined_cpu u_riscv_memory i_clk", false,-1);
        tracep->declBit(c+214,"riscv_top u_riscv_pipelined_cpu u_riscv_memory i_rstn", false,-1);
        tracep->declBit(c+147,"riscv_top u_riscv_pipelined_cpu u_riscv_memory i_ctrl_reg_wr_enE", false,-1);
        tracep->declBit(c+67,"riscv_top u_riscv_pipelined_cpu u_riscv_memory i_ctrl_result_srcE", false,-1);
        tracep->declBus(c+68,"riscv_top u_riscv_pipelined_cpu u_riscv_memory i_ctrl_mux_selE", false,-1, 1,0);
        tracep->declBit(c+148,"riscv_top u_riscv_pipelined_cpu u_riscv_memory i_ctrl_mem_wr_enE", false,-1);
        tracep->declBus(c+149,"riscv_top u_riscv_pipelined_cpu u_riscv_memory i_ctrl_mem_byte_selE", false,-1, 3,0);
        tracep->declBus(c+151,"riscv_top u_riscv_pipelined_cpu u_riscv_memory i_alu_resultE", false,-1, 31,0);
        tracep->declBus(c+152,"riscv_top u_riscv_pipelined_cpu u_riscv_memory i_mem_writedataE", false,-1, 31,0);
        tracep->declBus(c+150,"riscv_top u_riscv_pipelined_cpu u_riscv_memory i_regfile_rd_addrE", false,-1, 4,0);
        tracep->declBus(c+72,"riscv_top u_riscv_pipelined_cpu u_riscv_memory i_PCPlus4E", false,-1, 31,0);
        tracep->declBus(c+71,"riscv_top u_riscv_pipelined_cpu u_riscv_memory i_PCTargetE", false,-1, 31,0);
        tracep->declBus(c+73,"riscv_top u_riscv_pipelined_cpu u_riscv_memory i_ExtImmE", false,-1, 31,0);
        tracep->declBit(c+154,"riscv_top u_riscv_pipelined_cpu u_riscv_memory o_ctrl_reg_wr_enM", false,-1);
        tracep->declBit(c+74,"riscv_top u_riscv_pipelined_cpu u_riscv_memory o_ctrl_result_srcM", false,-1);
        tracep->declBus(c+220,"riscv_top u_riscv_pipelined_cpu u_riscv_memory o_ctrl_mem_byte_selM", false,-1, 3,0);
        tracep->declBit(c+219,"riscv_top u_riscv_pipelined_cpu u_riscv_memory o_ctrl_mem_wr_enM", false,-1);
        tracep->declBus(c+218,"riscv_top u_riscv_pipelined_cpu u_riscv_memory o_alu_resultM", false,-1, 31,0);
        tracep->declBus(c+155,"riscv_top u_riscv_pipelined_cpu u_riscv_memory o_regfile_rd_addrM", false,-1, 4,0);
        tracep->declBus(c+221,"riscv_top u_riscv_pipelined_cpu u_riscv_memory o_mem_writedataM", false,-1, 31,0);
        tracep->declBus(c+156,"riscv_top u_riscv_pipelined_cpu u_riscv_memory o_writeback_dataM", false,-1, 31,0);
        tracep->declBus(c+86,"riscv_top u_riscv_pipelined_cpu u_riscv_memory PCPlus4M", false,-1, 31,0);
        tracep->declBus(c+87,"riscv_top u_riscv_pipelined_cpu u_riscv_memory PCTargetM", false,-1, 31,0);
        tracep->declBus(c+88,"riscv_top u_riscv_pipelined_cpu u_riscv_memory ctrl_mux_selM", false,-1, 1,0);
        tracep->declBus(c+89,"riscv_top u_riscv_pipelined_cpu u_riscv_memory ExtImmM", false,-1, 31,0);
        tracep->declArray(c+205,"riscv_top u_riscv_pipelined_cpu u_riscv_memory writedata_concat", false,-1, 127,0);
        tracep->declBit(c+213,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_pipeline_memory i_clk", false,-1);
        tracep->declBit(c+214,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_pipeline_memory i_rstn", false,-1);
        tracep->declBit(c+147,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_pipeline_memory i_ctrl_reg_wr_enE", false,-1);
        tracep->declBit(c+67,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_pipeline_memory i_ctrl_result_srcE", false,-1);
        tracep->declBus(c+68,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_pipeline_memory i_ctrl_mux_selE", false,-1, 1,0);
        tracep->declBit(c+148,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_pipeline_memory i_ctrl_mem_wr_enE", false,-1);
        tracep->declBus(c+149,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_pipeline_memory i_ctrl_mem_byte_selE", false,-1, 3,0);
        tracep->declBus(c+151,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_pipeline_memory i_alu_resultE", false,-1, 31,0);
        tracep->declBus(c+152,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_pipeline_memory i_mem_writedataE", false,-1, 31,0);
        tracep->declBus(c+150,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_pipeline_memory i_regfile_rd_addrE", false,-1, 4,0);
        tracep->declBus(c+73,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_pipeline_memory i_ExtImmE", false,-1, 31,0);
        tracep->declBus(c+72,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_pipeline_memory i_PCPlus4E", false,-1, 31,0);
        tracep->declBus(c+71,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_pipeline_memory i_PCTargetE", false,-1, 31,0);
        tracep->declBit(c+154,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_pipeline_memory o_ctrl_reg_wr_enM", false,-1);
        tracep->declBit(c+74,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_pipeline_memory o_ctrl_result_srcM", false,-1);
        tracep->declBus(c+88,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_pipeline_memory o_ctrl_mux_selM", false,-1, 1,0);
        tracep->declBit(c+219,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_pipeline_memory o_ctrl_mem_wr_enM", false,-1);
        tracep->declBus(c+220,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_pipeline_memory o_ctrl_mem_byte_selM", false,-1, 3,0);
        tracep->declBus(c+218,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_pipeline_memory o_alu_resultM", false,-1, 31,0);
        tracep->declBus(c+221,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_pipeline_memory o_mem_writedataM", false,-1, 31,0);
        tracep->declBus(c+155,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_pipeline_memory o_regfile_rd_addrM", false,-1, 4,0);
        tracep->declBus(c+89,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_pipeline_memory o_ExtImmM", false,-1, 31,0);
        tracep->declBus(c+86,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_pipeline_memory o_PCPlus4M", false,-1, 31,0);
        tracep->declBus(c+87,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_pipeline_memory o_PCTargetM", false,-1, 31,0);
        tracep->declBus(c+235,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_riscv_mux_rd_data N_MUX_IN", false,-1, 31,0);
        tracep->declArray(c+205,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_riscv_mux_rd_data i_mux_concat_data", false,-1, 127,0);
        tracep->declBus(c+88,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_riscv_mux_rd_data i_mux_sel", false,-1, 1,0);
        tracep->declBus(c+156,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_riscv_mux_rd_data o_mux_data", false,-1, 31,0);
        {int i; for (i=0; i<4; i++) {
                tracep->declBus(c+209+i*1,"riscv_top u_riscv_pipelined_cpu u_riscv_memory u_riscv_mux_rd_data mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBit(c+213,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback i_clk", false,-1);
        tracep->declBit(c+214,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback i_rstn", false,-1);
        tracep->declBit(c+154,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback i_ctrl_reg_wr_enM", false,-1);
        tracep->declBit(c+74,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback i_ctrl_result_srcM", false,-1);
        tracep->declBus(c+218,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback i_alu_resultM", false,-1, 31,0);
        tracep->declBus(c+216,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback i_mem_readdataM", false,-1, 31,0);
        tracep->declBus(c+230,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback i_PCPlus4M", false,-1, 31,0);
        tracep->declBus(c+155,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback i_regfile_rd_addrM", false,-1, 4,0);
        tracep->declBus(c+231,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback i_PCTargetM", false,-1, 31,0);
        tracep->declBus(c+156,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback i_writeback_dataM", false,-1, 31,0);
        tracep->declBit(c+157,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback o_ctrl_reg_wr_enW", false,-1);
        tracep->declBus(c+158,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback o_regfile_rd_addrW", false,-1, 4,0);
        tracep->declBus(c+159,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback o_regfile_rd_dataW", false,-1, 31,0);
        tracep->declBit(c+90,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback ctrl_result_srcW", false,-1);
        tracep->declBus(c+91,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback alu_resultW", false,-1, 31,0);
        tracep->declBus(c+92,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback mem_readdataW", false,-1, 31,0);
        tracep->declBus(c+93,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback PCPlus4W", false,-1, 31,0);
        tracep->declBus(c+94,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback PCTargetW", false,-1, 31,0);
        tracep->declBus(c+95,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback writeback_dataW", false,-1, 31,0);
        tracep->declQuad(c+96,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback Writeback_concat_data", false,-1, 63,0);
        tracep->declBit(c+213,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback u_pipeline_writeback i_clk", false,-1);
        tracep->declBit(c+214,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback u_pipeline_writeback i_rstn", false,-1);
        tracep->declBit(c+154,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback u_pipeline_writeback i_ctrl_reg_wr_enM", false,-1);
        tracep->declBit(c+74,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback u_pipeline_writeback i_ctrl_result_srcM", false,-1);
        tracep->declBus(c+218,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback u_pipeline_writeback i_alu_resultM", false,-1, 31,0);
        tracep->declBus(c+216,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback u_pipeline_writeback i_mem_readdataM", false,-1, 31,0);
        tracep->declBus(c+230,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback u_pipeline_writeback i_PCPlus4M", false,-1, 31,0);
        tracep->declBus(c+155,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback u_pipeline_writeback i_regfile_rd_addrM", false,-1, 4,0);
        tracep->declBus(c+231,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback u_pipeline_writeback i_PCTargetM", false,-1, 31,0);
        tracep->declBus(c+156,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback u_pipeline_writeback i_writeback_dataM", false,-1, 31,0);
        tracep->declBit(c+157,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback u_pipeline_writeback o_ctrl_reg_wr_enW", false,-1);
        tracep->declBit(c+90,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback u_pipeline_writeback o_ctrl_result_srcW", false,-1);
        tracep->declBus(c+91,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback u_pipeline_writeback o_alu_resultW", false,-1, 31,0);
        tracep->declBus(c+92,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback u_pipeline_writeback o_mem_readdataW", false,-1, 31,0);
        tracep->declBus(c+95,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback u_pipeline_writeback o_writeback_dataW", false,-1, 31,0);
        tracep->declBus(c+93,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback u_pipeline_writeback o_PCPlus4W", false,-1, 31,0);
        tracep->declBus(c+94,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback u_pipeline_writeback o_PCTargetW", false,-1, 31,0);
        tracep->declBus(c+158,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback u_pipeline_writeback o_regfile_rd_addrW", false,-1, 4,0);
        tracep->declBus(c+234,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback u_riscv_mux_result N_MUX_IN", false,-1, 31,0);
        tracep->declQuad(c+96,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback u_riscv_mux_result i_mux_concat_data", false,-1, 63,0);
        tracep->declBus(c+90,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback u_riscv_mux_result i_mux_sel", false,-1, 0,0);
        tracep->declBus(c+159,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback u_riscv_mux_result o_mux_data", false,-1, 31,0);
        {int i; for (i=0; i<2; i++) {
                tracep->declBus(c+98+i*1,"riscv_top u_riscv_pipelined_cpu u_riscv_writeback u_riscv_mux_result mux_input_arr", true,(i+0), 31,0);}}
        tracep->declBus(c+69,"riscv_top u_riscv_pipelined_cpu u_hazard_unit i_regfile_rs1_addrE", false,-1, 4,0);
        tracep->declBus(c+70,"riscv_top u_riscv_pipelined_cpu u_hazard_unit i_regfile_rs2_addrE", false,-1, 4,0);
        tracep->declBus(c+155,"riscv_top u_riscv_pipelined_cpu u_hazard_unit i_regfile_rd_addrM", false,-1, 4,0);
        tracep->declBus(c+158,"riscv_top u_riscv_pipelined_cpu u_hazard_unit i_regfile_rd_addrW", false,-1, 4,0);
        tracep->declBit(c+154,"riscv_top u_riscv_pipelined_cpu u_hazard_unit i_ctrl_reg_wr_enM", false,-1);
        tracep->declBit(c+157,"riscv_top u_riscv_pipelined_cpu u_hazard_unit i_ctrl_reg_wr_enW", false,-1);
        tracep->declBus(c+142,"riscv_top u_riscv_pipelined_cpu u_hazard_unit i_regfile_rs1_addrD", false,-1, 4,0);
        tracep->declBus(c+143,"riscv_top u_riscv_pipelined_cpu u_hazard_unit i_regfile_rs2_addrD", false,-1, 4,0);
        tracep->declBus(c+150,"riscv_top u_riscv_pipelined_cpu u_hazard_unit i_regfile_rd_addrE", false,-1, 4,0);
        tracep->declBit(c+67,"riscv_top u_riscv_pipelined_cpu u_hazard_unit i_ctrl_result_srcE", false,-1);
        tracep->declBus(c+153,"riscv_top u_riscv_pipelined_cpu u_hazard_unit i_PCSrcE", false,-1, 1,0);
        tracep->declBus(c+160,"riscv_top u_riscv_pipelined_cpu u_hazard_unit o_hazard_forwardAE", false,-1, 1,0);
        tracep->declBus(c+161,"riscv_top u_riscv_pipelined_cpu u_hazard_unit o_hazard_forwardBE", false,-1, 1,0);
        tracep->declBit(c+162,"riscv_top u_riscv_pipelined_cpu u_hazard_unit o_hazard_stallF", false,-1);
        tracep->declBit(c+162,"riscv_top u_riscv_pipelined_cpu u_hazard_unit o_hazard_stallD", false,-1);
        tracep->declBit(c+163,"riscv_top u_riscv_pipelined_cpu u_hazard_unit o_hazard_flushE", false,-1);
        tracep->declBit(c+164,"riscv_top u_riscv_pipelined_cpu u_hazard_unit o_hazard_flushD", false,-1);
        tracep->declBit(c+162,"riscv_top u_riscv_pipelined_cpu u_hazard_unit lwStall", false,-1);
        tracep->declBit(c+213,"riscv_top u_riscv_imem i_clk", false,-1);
        tracep->declBus(c+226,"riscv_top u_riscv_imem i_imem_addr", false,-1, 13,0);
        tracep->declBus(c+215,"riscv_top u_riscv_imem o_imem_data", false,-1, 31,0);
        tracep->declArray(c+1,"riscv_top u_riscv_imem FILE_TEXT_MIF", false,-1, 1023,0);
        tracep->declBit(c+213,"riscv_top u_riscv_dmem i_clk", false,-1);
        tracep->declBit(c+219,"riscv_top u_riscv_dmem i_dmem_wr_en", false,-1);
        tracep->declBus(c+221,"riscv_top u_riscv_dmem i_dmem_data", false,-1, 31,0);
        tracep->declBus(c+227,"riscv_top u_riscv_dmem i_dmem_addr", false,-1, 13,0);
        tracep->declBus(c+220,"riscv_top u_riscv_dmem i_dmem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+216,"riscv_top u_riscv_dmem o_dmem_data", false,-1, 31,0);
        tracep->declArray(c+33,"riscv_top u_riscv_dmem FILE_DATA_MIF", false,-1, 1023,0);
        tracep->declBus(c+228,"riscv_top u_riscv_dmem i", false,-1, 31,0);
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
        tracep->fullIData(oldp+65,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCD),32);
        tracep->fullIData(oldp+66,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCPlus4D),32);
        tracep->fullBit(oldp+67,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_result_srcE));
        tracep->fullCData(oldp+68,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_mux_selE),2);
        tracep->fullCData(oldp+69,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rs1_addrE),5);
        tracep->fullCData(oldp+70,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rs2_addrE),5);
        tracep->fullIData(oldp+71,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCTargetE),32);
        tracep->fullIData(oldp+72,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCPlus4E),32);
        tracep->fullIData(oldp+73,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ExtImmE),32);
        tracep->fullBit(oldp+74,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_result_srcM));
        tracep->fullBit(oldp+75,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_jalE));
        tracep->fullBit(oldp+76,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_jalrE));
        tracep->fullBit(oldp+77,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_branchE));
        tracep->fullCData(oldp+78,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_ctrlE),4);
        tracep->fullBit(oldp+79,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_srcE));
        tracep->fullIData(oldp+80,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__regfile_rs1_dataE),32);
        tracep->fullIData(oldp+81,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__regfile_rs2_dataE),32);
        tracep->fullIData(oldp+82,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__PCE),32);
        tracep->fullCData(oldp+83,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_funct3E),3);
        tracep->fullQData(oldp+84,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP),64);
        tracep->fullIData(oldp+86,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_memory__DOT__PCPlus4M),32);
        tracep->fullIData(oldp+87,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_memory__DOT__PCTargetM),32);
        tracep->fullCData(oldp+88,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_memory__DOT__ctrl_mux_selM),2);
        tracep->fullIData(oldp+89,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_memory__DOT__ExtImmM),32);
        tracep->fullBit(oldp+90,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__ctrl_result_srcW));
        tracep->fullIData(oldp+91,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__alu_resultW),32);
        tracep->fullIData(oldp+92,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__mem_readdataW),32);
        tracep->fullIData(oldp+93,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__PCPlus4W),32);
        tracep->fullIData(oldp+94,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__PCTargetW),32);
        tracep->fullIData(oldp+95,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__writeback_dataW),32);
        tracep->fullQData(oldp+96,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__Writeback_concat_data),64);
        tracep->fullIData(oldp+98,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__u_riscv_mux_result__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+99,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__u_riscv_mux_result__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+100,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[0]),32);
        tracep->fullIData(oldp+101,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[1]),32);
        tracep->fullIData(oldp+102,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[2]),32);
        tracep->fullIData(oldp+103,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[3]),32);
        tracep->fullIData(oldp+104,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[4]),32);
        tracep->fullIData(oldp+105,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[5]),32);
        tracep->fullIData(oldp+106,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[6]),32);
        tracep->fullIData(oldp+107,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[7]),32);
        tracep->fullIData(oldp+108,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[8]),32);
        tracep->fullIData(oldp+109,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[9]),32);
        tracep->fullIData(oldp+110,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[10]),32);
        tracep->fullIData(oldp+111,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[11]),32);
        tracep->fullIData(oldp+112,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[12]),32);
        tracep->fullIData(oldp+113,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[13]),32);
        tracep->fullIData(oldp+114,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[14]),32);
        tracep->fullIData(oldp+115,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[15]),32);
        tracep->fullIData(oldp+116,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[16]),32);
        tracep->fullIData(oldp+117,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[17]),32);
        tracep->fullIData(oldp+118,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[18]),32);
        tracep->fullIData(oldp+119,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[19]),32);
        tracep->fullIData(oldp+120,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[20]),32);
        tracep->fullIData(oldp+121,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[21]),32);
        tracep->fullIData(oldp+122,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[22]),32);
        tracep->fullIData(oldp+123,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[23]),32);
        tracep->fullIData(oldp+124,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[24]),32);
        tracep->fullIData(oldp+125,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[25]),32);
        tracep->fullIData(oldp+126,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[26]),32);
        tracep->fullIData(oldp+127,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[27]),32);
        tracep->fullIData(oldp+128,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[28]),32);
        tracep->fullIData(oldp+129,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[29]),32);
        tracep->fullIData(oldp+130,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[30]),32);
        tracep->fullIData(oldp+131,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[31]),32);
        tracep->fullBit(oldp+132,(((0x63U != (0x7fU 
                                              & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)) 
                                   & (0x23U != (0x7fU 
                                                & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)))));
        tracep->fullBit(oldp+133,((3U == (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD))));
        tracep->fullCData(oldp+134,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_mux_selD),2);
        tracep->fullBit(oldp+135,((0x23U == (0x7fU 
                                             & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD))));
        tracep->fullBit(oldp+136,((0x6fU == (0x7fU 
                                             & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD))));
        tracep->fullBit(oldp+137,((0x67U == (0x7fU 
                                             & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD))));
        tracep->fullBit(oldp+138,((0x63U == (0x7fU 
                                             & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD))));
        tracep->fullCData(oldp+139,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_alu_ctrlD),4);
        tracep->fullBit(oldp+140,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_alu_srcD));
        tracep->fullCData(oldp+141,((((3U == (0x7fU 
                                              & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)) 
                                      | (0x23U == (0x7fU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)))
                                      ? ((0x4000U & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)
                                          ? ((0x2000U 
                                              & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)
                                              ? 0xfU
                                              : ((0x1000U 
                                                  & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)
                                                  ? 3U
                                                  : 1U))
                                          : ((0x2000U 
                                              & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)
                                              ? 0xfU
                                              : ((0x1000U 
                                                  & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)
                                                  ? 3U
                                                  : 1U)))
                                      : 0xfU)),4);
        tracep->fullCData(oldp+142,((0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                              >> 0xfU))),5);
        tracep->fullCData(oldp+143,((0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                              >> 0x14U))),5);
        tracep->fullIData(oldp+144,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ExtImmD),32);
        tracep->fullCData(oldp+145,((0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                              >> 7U))),5);
        tracep->fullCData(oldp+146,((7U & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                           >> 0xcU))),3);
        tracep->fullBit(oldp+147,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_reg_wr_enE));
        tracep->fullBit(oldp+148,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_mem_wr_enE));
        tracep->fullCData(oldp+149,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_mem_byte_selE),4);
        tracep->fullCData(oldp+150,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_addrE),5);
        tracep->fullIData(oldp+151,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__alu_resultE),32);
        tracep->fullIData(oldp+152,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__mem_writedataE),32);
        tracep->fullCData(oldp+153,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCSrcE),2);
        tracep->fullBit(oldp+154,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_reg_wr_enM));
        tracep->fullCData(oldp+155,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_addrM),5);
        tracep->fullIData(oldp+156,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__writedata_dataM),32);
        tracep->fullBit(oldp+157,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_reg_wr_enW));
        tracep->fullCData(oldp+158,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_addrW),5);
        tracep->fullIData(oldp+159,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_dataW),32);
        tracep->fullCData(oldp+160,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_forwardAE),2);
        tracep->fullCData(oldp+161,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_forwardBE),2);
        tracep->fullBit(oldp+162,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_hazard_unit__DOT__lwStall));
        tracep->fullBit(oldp+163,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_flushE));
        tracep->fullBit(oldp+164,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_flushD));
        tracep->fullIData(oldp+165,(((2U >= (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCSrcE))
                                      ? vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_fetch__DOT__u_riscv_mux_pc__DOT__mux_input_arr
                                     [vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCSrcE]
                                      : 0U)),32);
        tracep->fullWData(oldp+166,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_fetch__DOT__PC_concat_data),96);
        tracep->fullIData(oldp+169,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_fetch__DOT__u_riscv_mux_pc__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+170,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_fetch__DOT__u_riscv_mux_pc__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+171,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_fetch__DOT__u_riscv_mux_pc__DOT__mux_input_arr[2]),32);
        tracep->fullBit(oldp+172,((1U & (~ (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_hazard_unit__DOT__lwStall)))));
        tracep->fullIData(oldp+173,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD),32);
        tracep->fullCData(oldp+174,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__ctrl_src_immD),3);
        tracep->fullCData(oldp+175,((0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)),7);
        tracep->fullBit(oldp+176,((1U & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                         >> 0x1eU))));
        tracep->fullWData(oldp+177,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR),256);
        tracep->fullIData(oldp+185,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcAE),32);
        tracep->fullIData(oldp+186,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcBE),32);
        tracep->fullWData(oldp+187,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__srcA_concat_data),96);
        tracep->fullWData(oldp+190,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__writedata_concat),96);
        tracep->fullQData(oldp+193,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__srcB_concat_data),64);
        tracep->fullBit(oldp+195,((0U == vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__alu_resultE)));
        tracep->fullBit(oldp+196,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__take_branch));
        tracep->fullIData(oldp+197,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_srcAE__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+198,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_srcAE__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+199,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_srcAE__DOT__mux_input_arr[2]),32);
        tracep->fullIData(oldp+200,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_writedata__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+201,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_writedata__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+202,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_writedata__DOT__mux_input_arr[2]),32);
        tracep->fullIData(oldp+203,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_srcBE__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+204,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_srcBE__DOT__mux_input_arr[1]),32);
        tracep->fullWData(oldp+205,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_memory__DOT__writedata_concat),128);
        tracep->fullIData(oldp+209,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_memory__DOT__u_riscv_mux_rd_data__DOT__mux_input_arr[0]),32);
        tracep->fullIData(oldp+210,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_memory__DOT__u_riscv_mux_rd_data__DOT__mux_input_arr[1]),32);
        tracep->fullIData(oldp+211,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_memory__DOT__u_riscv_mux_rd_data__DOT__mux_input_arr[2]),32);
        tracep->fullIData(oldp+212,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_memory__DOT__u_riscv_mux_rd_data__DOT__mux_input_arr[3]),32);
        tracep->fullBit(oldp+213,(vlTOPp->i_clk));
        tracep->fullBit(oldp+214,(vlTOPp->i_rstn));
        tracep->fullIData(oldp+215,(vlTOPp->o_instrF),32);
        tracep->fullIData(oldp+216,(vlTOPp->o_mem_readdataM),32);
        tracep->fullIData(oldp+217,(vlTOPp->o_PCF),32);
        tracep->fullIData(oldp+218,(vlTOPp->o_alu_resultM),32);
        tracep->fullBit(oldp+219,(vlTOPp->o_ctrl_mem_wr_enM));
        tracep->fullCData(oldp+220,(vlTOPp->o_ctrl_mem_byte_selM),4);
        tracep->fullIData(oldp+221,(vlTOPp->o_mem_writedataM),32);
        tracep->fullIData(oldp+222,(((IData)(4U) + vlTOPp->o_PCF)),32);
        tracep->fullIData(oldp+223,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers
                                    [(0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                               >> 0xfU))]),32);
        tracep->fullIData(oldp+224,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers
                                    [(0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                               >> 0x14U))]),32);
        tracep->fullBit(oldp+225,(((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__take_branch) 
                                   & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_branchE))));
        tracep->fullSData(oldp+226,((0x3fffU & (vlTOPp->o_PCF 
                                                >> 2U))),14);
        tracep->fullSData(oldp+227,((0x3fffU & (vlTOPp->o_alu_resultM 
                                                >> 2U))),14);
        tracep->fullIData(oldp+228,(vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__i),32);
        tracep->fullIData(oldp+229,(0U),32);
        tracep->fullIData(oldp+230,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCPlus4M),32);
        tracep->fullIData(oldp+231,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCTargetM),32);
        tracep->fullIData(oldp+232,(3U),32);
        tracep->fullIData(oldp+233,(4U),32);
        tracep->fullIData(oldp+234,(2U),32);
        tracep->fullIData(oldp+235,(4U),32);
    }
}
