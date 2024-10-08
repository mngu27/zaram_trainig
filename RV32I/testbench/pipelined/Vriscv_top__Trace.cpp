// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vriscv_top__Syms.h"


void Vriscv_top::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vriscv_top::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0U])) {
            tracep->chgWData(oldp+0,(vlTOPp->riscv_top__DOT__u_riscv_imem__DOT__FILE_TEXT_MIF),1024);
            tracep->chgWData(oldp+32,(vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__FILE_DATA_MIF),1024);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+64,(vlTOPp->riscv_top__DOT__ctrl_mem_wr_enM));
            tracep->chgIData(oldp+65,(vlTOPp->riscv_top__DOT__mem_writedataM),32);
            tracep->chgCData(oldp+66,(vlTOPp->riscv_top__DOT__ctrl_mem_byte_selM),4);
            tracep->chgIData(oldp+67,(vlTOPp->riscv_top__DOT__alu_resultM),32);
            tracep->chgIData(oldp+68,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCD),32);
            tracep->chgIData(oldp+69,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCPlus4D),32);
            tracep->chgBit(oldp+70,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_result_srcE));
            tracep->chgCData(oldp+71,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_mux_selE),2);
            tracep->chgBit(oldp+72,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_mem_wr_enE));
            tracep->chgCData(oldp+73,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_mem_byte_selE),4);
            tracep->chgCData(oldp+74,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_funct3E),3);
            tracep->chgCData(oldp+75,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rs1_addrE),5);
            tracep->chgCData(oldp+76,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rs2_addrE),5);
            tracep->chgIData(oldp+77,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCTargetE),32);
            tracep->chgIData(oldp+78,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCPlus4E),32);
            tracep->chgIData(oldp+79,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ExtImmE),32);
            tracep->chgBit(oldp+80,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_result_srcM));
            tracep->chgIData(oldp+81,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__writedata_dataM),32);
            tracep->chgBit(oldp+82,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_jalE));
            tracep->chgBit(oldp+83,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_jalrE));
            tracep->chgBit(oldp+84,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_branchE));
            tracep->chgCData(oldp+85,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_ctrlE),4);
            tracep->chgBit(oldp+86,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_srcE));
            tracep->chgIData(oldp+87,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__regfile_rs1_dataE),32);
            tracep->chgIData(oldp+88,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__regfile_rs2_dataE),32);
            tracep->chgIData(oldp+89,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__PCE),32);
            tracep->chgQData(oldp+90,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP),64);
            tracep->chgIData(oldp+92,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_memory__DOT__PCPlus4M),32);
            tracep->chgIData(oldp+93,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_memory__DOT__PCTargetM),32);
            tracep->chgCData(oldp+94,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_memory__DOT__ctrl_mux_selM),2);
            tracep->chgIData(oldp+95,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_memory__DOT__ExtImmM),32);
            tracep->chgWData(oldp+96,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_memory__DOT__writedata_concat),128);
            tracep->chgIData(oldp+100,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_memory__DOT__u_riscv_mux_rd_data__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+101,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_memory__DOT__u_riscv_mux_rd_data__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+102,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_memory__DOT__u_riscv_mux_rd_data__DOT__mux_input_arr[2]),32);
            tracep->chgIData(oldp+103,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_memory__DOT__u_riscv_mux_rd_data__DOT__mux_input_arr[3]),32);
            tracep->chgBit(oldp+104,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__ctrl_result_srcW));
            tracep->chgIData(oldp+105,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__alu_resultW),32);
            tracep->chgIData(oldp+106,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__mem_readdataW),32);
            tracep->chgIData(oldp+107,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__PCPlus4W),32);
            tracep->chgIData(oldp+108,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__PCTargetW),32);
            tracep->chgIData(oldp+109,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__writeback_dataW),32);
            tracep->chgQData(oldp+110,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__Writeback_concat_data),64);
            tracep->chgIData(oldp+112,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__u_riscv_mux_result__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+113,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__u_riscv_mux_result__DOT__mux_input_arr[1]),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgIData(oldp+114,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[0]),32);
            tracep->chgIData(oldp+115,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[1]),32);
            tracep->chgIData(oldp+116,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[2]),32);
            tracep->chgIData(oldp+117,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[3]),32);
            tracep->chgIData(oldp+118,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[4]),32);
            tracep->chgIData(oldp+119,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[5]),32);
            tracep->chgIData(oldp+120,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[6]),32);
            tracep->chgIData(oldp+121,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[7]),32);
            tracep->chgIData(oldp+122,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[8]),32);
            tracep->chgIData(oldp+123,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[9]),32);
            tracep->chgIData(oldp+124,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[10]),32);
            tracep->chgIData(oldp+125,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[11]),32);
            tracep->chgIData(oldp+126,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[12]),32);
            tracep->chgIData(oldp+127,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[13]),32);
            tracep->chgIData(oldp+128,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[14]),32);
            tracep->chgIData(oldp+129,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[15]),32);
            tracep->chgIData(oldp+130,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[16]),32);
            tracep->chgIData(oldp+131,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[17]),32);
            tracep->chgIData(oldp+132,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[18]),32);
            tracep->chgIData(oldp+133,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[19]),32);
            tracep->chgIData(oldp+134,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[20]),32);
            tracep->chgIData(oldp+135,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[21]),32);
            tracep->chgIData(oldp+136,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[22]),32);
            tracep->chgIData(oldp+137,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[23]),32);
            tracep->chgIData(oldp+138,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[24]),32);
            tracep->chgIData(oldp+139,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[25]),32);
            tracep->chgIData(oldp+140,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[26]),32);
            tracep->chgIData(oldp+141,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[27]),32);
            tracep->chgIData(oldp+142,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[28]),32);
            tracep->chgIData(oldp+143,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[29]),32);
            tracep->chgIData(oldp+144,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[30]),32);
            tracep->chgIData(oldp+145,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[31]),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgBit(oldp+146,(((0x63U != (0x7fU 
                                                 & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)) 
                                      & (0x23U != (0x7fU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)))));
            tracep->chgBit(oldp+147,((3U == (0x7fU 
                                             & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD))));
            tracep->chgCData(oldp+148,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_mux_selD),2);
            tracep->chgBit(oldp+149,((0x23U == (0x7fU 
                                                & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD))));
            tracep->chgBit(oldp+150,((0x6fU == (0x7fU 
                                                & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD))));
            tracep->chgBit(oldp+151,((0x67U == (0x7fU 
                                                & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD))));
            tracep->chgBit(oldp+152,((0x63U == (0x7fU 
                                                & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD))));
            tracep->chgCData(oldp+153,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_alu_ctrlD),4);
            tracep->chgBit(oldp+154,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_alu_srcD));
            tracep->chgCData(oldp+155,((((3U == (0x7fU 
                                                 & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)) 
                                         | (0x23U == 
                                            (0x7fU 
                                             & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)))
                                         ? ((0x4000U 
                                             & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)
                                             ? ((0x2000U 
                                                 & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)
                                                 ? 0xfU
                                                 : 
                                                ((0x1000U 
                                                  & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)
                                                  ? 3U
                                                  : 1U))
                                             : ((0x2000U 
                                                 & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)
                                                 ? 0xfU
                                                 : 
                                                ((0x1000U 
                                                  & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)
                                                  ? 3U
                                                  : 1U)))
                                         : 0xfU)),4);
            tracep->chgCData(oldp+156,((0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                                 >> 0xfU))),5);
            tracep->chgCData(oldp+157,((0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                                 >> 0x14U))),5);
            tracep->chgIData(oldp+158,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ExtImmD),32);
            tracep->chgCData(oldp+159,((0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                                 >> 7U))),5);
            tracep->chgCData(oldp+160,((7U & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                              >> 0xcU))),3);
            tracep->chgBit(oldp+161,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_reg_wr_enE));
            tracep->chgCData(oldp+162,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_addrE),5);
            tracep->chgIData(oldp+163,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__alu_resultE),32);
            tracep->chgIData(oldp+164,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__mem_writedataE),32);
            tracep->chgCData(oldp+165,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCSrcE),2);
            tracep->chgBit(oldp+166,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_reg_wr_enM));
            tracep->chgCData(oldp+167,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_addrM),5);
            tracep->chgBit(oldp+168,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_reg_wr_enW));
            tracep->chgCData(oldp+169,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_addrW),5);
            tracep->chgIData(oldp+170,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_dataW),32);
            tracep->chgCData(oldp+171,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_forwardAE),2);
            tracep->chgCData(oldp+172,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_forwardBE),2);
            tracep->chgBit(oldp+173,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_hazard_unit__DOT__lwStall));
            tracep->chgBit(oldp+174,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_flushE));
            tracep->chgBit(oldp+175,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_flushD));
            tracep->chgIData(oldp+176,(((2U >= (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCSrcE))
                                         ? vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_fetch__DOT__u_riscv_mux_pc__DOT__mux_input_arr
                                        [vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCSrcE]
                                         : 0U)),32);
            tracep->chgWData(oldp+177,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_fetch__DOT__PC_concat_data),96);
            tracep->chgIData(oldp+180,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_fetch__DOT__u_riscv_mux_pc__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+181,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_fetch__DOT__u_riscv_mux_pc__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+182,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_fetch__DOT__u_riscv_mux_pc__DOT__mux_input_arr[2]),32);
            tracep->chgBit(oldp+183,((1U & (~ (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_hazard_unit__DOT__lwStall)))));
            tracep->chgIData(oldp+184,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD),32);
            tracep->chgCData(oldp+185,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__ctrl_src_immD),3);
            tracep->chgCData(oldp+186,((0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)),7);
            tracep->chgBit(oldp+187,((1U & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                            >> 0x1eU))));
            tracep->chgWData(oldp+188,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR),256);
            tracep->chgIData(oldp+196,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcAE),32);
            tracep->chgIData(oldp+197,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcBE),32);
            tracep->chgWData(oldp+198,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__srcA_concat_data),96);
            tracep->chgWData(oldp+201,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__writedata_concat),96);
            tracep->chgQData(oldp+204,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__srcB_concat_data),64);
            tracep->chgBit(oldp+206,((0U == vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__alu_resultE)));
            tracep->chgBit(oldp+207,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__take_branch));
            tracep->chgIData(oldp+208,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_srcAE__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+209,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_srcAE__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+210,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_srcAE__DOT__mux_input_arr[2]),32);
            tracep->chgIData(oldp+211,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_writedata__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+212,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_writedata__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+213,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_writedata__DOT__mux_input_arr[2]),32);
            tracep->chgIData(oldp+214,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_srcBE__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+215,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_srcBE__DOT__mux_input_arr[1]),32);
        }
        tracep->chgBit(oldp+216,(vlTOPp->i_clk));
        tracep->chgBit(oldp+217,(vlTOPp->i_rstn));
        tracep->chgIData(oldp+218,(vlTOPp->o_mem_readdataM),32);
        tracep->chgIData(oldp+219,(vlTOPp->o_instrF),32);
        tracep->chgIData(oldp+220,(vlTOPp->o_PCF),32);
        tracep->chgIData(oldp+221,(vlTOPp->o_alu_resultM),32);
        tracep->chgBit(oldp+222,(vlTOPp->o_ctrl_mem_wr_enM));
        tracep->chgCData(oldp+223,(vlTOPp->o_ctrl_mem_byte_selM),4);
        tracep->chgIData(oldp+224,(vlTOPp->o_mem_writedataM),32);
        tracep->chgCData(oldp+225,(vlTOPp->o_ctrl_funct3M),3);
        tracep->chgIData(oldp+226,(vlTOPp->riscv_top__DOT__mem_readdataM),32);
        tracep->chgIData(oldp+227,(((IData)(4U) + vlTOPp->o_PCF)),32);
        tracep->chgIData(oldp+228,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers
                                   [(0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                              >> 0xfU))]),32);
        tracep->chgIData(oldp+229,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers
                                   [(0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                              >> 0x14U))]),32);
        tracep->chgBit(oldp+230,(((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__take_branch) 
                                  & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_branchE))));
        tracep->chgSData(oldp+231,((0x3fffU & (vlTOPp->o_PCF 
                                               >> 2U))),14);
        tracep->chgIData(oldp+232,(vlTOPp->riscv_top__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data),32);
        tracep->chgSData(oldp+233,((0x3fffU & (vlTOPp->o_alu_resultM 
                                               >> 2U))),14);
        tracep->chgIData(oldp+234,(vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__i),32);
    }
}

void Vriscv_top::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vriscv_top__Syms* __restrict vlSymsp = static_cast<Vriscv_top__Syms*>(userp);
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
        vlTOPp->__Vm_traceActivity[3U] = 0U;
    }
}
