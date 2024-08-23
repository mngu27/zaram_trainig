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
            tracep->chgCData(oldp+64,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_result_srcM),2);
            tracep->chgIData(oldp+65,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCPlus4M),32);
            tracep->chgIData(oldp+66,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_dataW),32);
            tracep->chgCData(oldp+67,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__ctrl_result_srcW),2);
            tracep->chgIData(oldp+68,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__alu_resultW),32);
            tracep->chgIData(oldp+69,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__mem_readdataW),32);
            tracep->chgIData(oldp+70,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__PCPlus4W),32);
            tracep->chgWData(oldp+71,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__Writeback_concat_data),96);
            tracep->chgIData(oldp+74,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__u_riscv_mux_result__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+75,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__u_riscv_mux_result__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+76,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__u_riscv_mux_result__DOT__mux_input_arr[2]),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgCData(oldp+77,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rs1_addrE),5);
            tracep->chgCData(oldp+78,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rs2_addrE),5);
            tracep->chgIData(oldp+79,((vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__PCE 
                                       + vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ExtImmE)),32);
            tracep->chgIData(oldp+80,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCPlus4E),32);
            tracep->chgBit(oldp+81,((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT____Vcellout__u_riscv_execute__o_ctrl_result_srcE))));
            tracep->chgCData(oldp+82,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT____Vcellout__u_riscv_execute__o_ctrl_result_srcE),2);
            tracep->chgBit(oldp+83,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_jalE));
            tracep->chgBit(oldp+84,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_jalrE));
            tracep->chgBit(oldp+85,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_branchE));
            tracep->chgCData(oldp+86,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_ctrlE),3);
            tracep->chgBit(oldp+87,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_srcE));
            tracep->chgIData(oldp+88,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__regfile_rs1_dataE),32);
            tracep->chgIData(oldp+89,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__regfile_rs2_dataE),32);
            tracep->chgIData(oldp+90,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__PCE),32);
            tracep->chgIData(oldp+91,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ExtImmE),32);
            tracep->chgBit(oldp+92,((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT____Vcellout__u_pipeline_execute__o_ctrl_funct3E))));
            tracep->chgCData(oldp+93,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT____Vcellout__u_pipeline_execute__o_ctrl_funct3E),3);
            tracep->chgCData(oldp+94,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_ctrlE),5);
            tracep->chgQData(oldp+95,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP),64);
            tracep->chgCData(oldp+97,((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT____Vcellout__u_riscv_execute__o_ctrl_result_srcE))),2);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgIData(oldp+98,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[0]),32);
            tracep->chgIData(oldp+99,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[1]),32);
            tracep->chgIData(oldp+100,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[2]),32);
            tracep->chgIData(oldp+101,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[3]),32);
            tracep->chgIData(oldp+102,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[4]),32);
            tracep->chgIData(oldp+103,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[5]),32);
            tracep->chgIData(oldp+104,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[6]),32);
            tracep->chgIData(oldp+105,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[7]),32);
            tracep->chgIData(oldp+106,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[8]),32);
            tracep->chgIData(oldp+107,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[9]),32);
            tracep->chgIData(oldp+108,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[10]),32);
            tracep->chgIData(oldp+109,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[11]),32);
            tracep->chgIData(oldp+110,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[12]),32);
            tracep->chgIData(oldp+111,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[13]),32);
            tracep->chgIData(oldp+112,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[14]),32);
            tracep->chgIData(oldp+113,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[15]),32);
            tracep->chgIData(oldp+114,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[16]),32);
            tracep->chgIData(oldp+115,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[17]),32);
            tracep->chgIData(oldp+116,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[18]),32);
            tracep->chgIData(oldp+117,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[19]),32);
            tracep->chgIData(oldp+118,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[20]),32);
            tracep->chgIData(oldp+119,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[21]),32);
            tracep->chgIData(oldp+120,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[22]),32);
            tracep->chgIData(oldp+121,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[23]),32);
            tracep->chgIData(oldp+122,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[24]),32);
            tracep->chgIData(oldp+123,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[25]),32);
            tracep->chgIData(oldp+124,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[26]),32);
            tracep->chgIData(oldp+125,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[27]),32);
            tracep->chgIData(oldp+126,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[28]),32);
            tracep->chgIData(oldp+127,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[29]),32);
            tracep->chgIData(oldp+128,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[30]),32);
            tracep->chgIData(oldp+129,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[31]),32);
            tracep->chgIData(oldp+130,(vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__i),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[4U])) {
            tracep->chgIData(oldp+131,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCD),32);
            tracep->chgIData(oldp+132,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCPlus4D),32);
            tracep->chgBit(oldp+133,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_reg_wr_enM));
            tracep->chgCData(oldp+134,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_addrM),5);
            tracep->chgBit(oldp+135,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_reg_wr_enW));
            tracep->chgCData(oldp+136,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_addrW),5);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[5U])) {
            tracep->chgBit(oldp+137,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_reg_wr_enE));
            tracep->chgBit(oldp+138,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_mem_wr_enE));
            tracep->chgCData(oldp+139,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_mem_byte_selE),4);
            tracep->chgCData(oldp+140,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_addrE),5);
            tracep->chgIData(oldp+141,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__alu_resultE),32);
            tracep->chgCData(oldp+142,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCSrcE),2);
            tracep->chgCData(oldp+143,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_forwardAE),2);
            tracep->chgCData(oldp+144,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_forwardBE),2);
            tracep->chgBit(oldp+145,((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCSrcE))));
            tracep->chgBit(oldp+146,(((2U >= (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_forwardBE))
                                       ? (1U & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_writedata__DOT__mux_input_arr
                                          [vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_forwardBE])
                                       : 0U)));
            tracep->chgIData(oldp+147,(((2U >= (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCSrcE))
                                         ? vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_fetch__DOT__u_riscv_mux_pc__DOT__mux_input_arr
                                        [vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCSrcE]
                                         : 0U)),32);
            tracep->chgWData(oldp+148,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_fetch__DOT__PC_concat_data),96);
            tracep->chgIData(oldp+151,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_fetch__DOT__u_riscv_mux_pc__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+152,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_fetch__DOT__u_riscv_mux_pc__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+153,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_fetch__DOT__u_riscv_mux_pc__DOT__mux_input_arr[2]),32);
            tracep->chgIData(oldp+154,(((2U >= (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_forwardBE))
                                         ? vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_writedata__DOT__mux_input_arr
                                        [vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_forwardBE]
                                         : 0U)),32);
            tracep->chgIData(oldp+155,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcAE),32);
            tracep->chgIData(oldp+156,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcBE),32);
            tracep->chgWData(oldp+157,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__srcA_concat_data),96);
            tracep->chgWData(oldp+160,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__writedata_concat),96);
            tracep->chgQData(oldp+163,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__srcB_concat_data),64);
            tracep->chgBit(oldp+165,((0U == vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__alu_resultE)));
            tracep->chgBit(oldp+166,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__take_branch));
            tracep->chgIData(oldp+167,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_srcAE__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+168,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_srcAE__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+169,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_srcAE__DOT__mux_input_arr[2]),32);
            tracep->chgIData(oldp+170,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_writedata__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+171,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_writedata__DOT__mux_input_arr[1]),32);
            tracep->chgIData(oldp+172,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_writedata__DOT__mux_input_arr[2]),32);
            tracep->chgIData(oldp+173,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_srcBE__DOT__mux_input_arr[0]),32);
            tracep->chgIData(oldp+174,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_srcBE__DOT__mux_input_arr[1]),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[6U])) {
            tracep->chgBit(oldp+175,(((0x63U != (0x7fU 
                                                 & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)) 
                                      & (0x23U != (0x7fU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)))));
            tracep->chgCData(oldp+176,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_result_srcD),2);
            tracep->chgBit(oldp+177,((0x23U == (0x7fU 
                                                & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD))));
            tracep->chgBit(oldp+178,((0x6fU == (0x7fU 
                                                & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD))));
            tracep->chgBit(oldp+179,((0x67U == (0x7fU 
                                                & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD))));
            tracep->chgBit(oldp+180,((0x63U == (0x7fU 
                                                & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD))));
            tracep->chgCData(oldp+181,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_alu_ctrlD),3);
            tracep->chgCData(oldp+182,((((3U == (0x7fU 
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
            tracep->chgCData(oldp+183,((0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                                 >> 0xfU))),5);
            tracep->chgCData(oldp+184,((0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                                 >> 0x14U))),5);
            tracep->chgIData(oldp+185,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ExtImmD),32);
            tracep->chgCData(oldp+186,((0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                                 >> 7U))),5);
            tracep->chgCData(oldp+187,((7U & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                              >> 0xcU))),3);
            tracep->chgIData(oldp+188,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD),32);
            tracep->chgBit(oldp+189,((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_ctrl__o_ctrl_src_imm))));
            tracep->chgCData(oldp+190,((0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)),7);
            tracep->chgBit(oldp+191,((1U & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                            >> 0x1eU))));
            tracep->chgCData(oldp+192,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_ctrl__o_ctrl_src_imm),3);
            tracep->chgWData(oldp+193,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR),256);
            tracep->chgCData(oldp+201,((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT____Vcellout__u_riscv_ctrl__o_ctrl_src_imm))),3);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[7U])) {
            tracep->chgBit(oldp+202,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_hazard_unit__DOT__lwStall));
            tracep->chgBit(oldp+203,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_flushE));
            tracep->chgBit(oldp+204,((1U & (~ (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_hazard_unit__DOT__lwStall)))));
        }
        tracep->chgBit(oldp+205,(vlTOPp->i_clk));
        tracep->chgBit(oldp+206,(vlTOPp->i_rstn));
        tracep->chgIData(oldp+207,(vlTOPp->o_instrF),32);
        tracep->chgIData(oldp+208,(vlTOPp->o_mem_readdataM),32);
        tracep->chgIData(oldp+209,(vlTOPp->o_PCF),32);
        tracep->chgIData(oldp+210,(vlTOPp->o_alu_resultM),32);
        tracep->chgBit(oldp+211,(vlTOPp->o_ctrl_mem_wr_enM));
        tracep->chgCData(oldp+212,(vlTOPp->o_ctrl_mem_byte_selM),4);
        tracep->chgIData(oldp+213,(vlTOPp->o_mem_writedataM),32);
        tracep->chgIData(oldp+214,(((IData)(4U) + vlTOPp->o_PCF)),32);
        tracep->chgIData(oldp+215,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers
                                   [(0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                              >> 0xfU))]),32);
        tracep->chgIData(oldp+216,(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers
                                   [(0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                              >> 0x14U))]),32);
        tracep->chgBit(oldp+217,(((0U == vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__alu_resultE) 
                                  & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_branchE))));
        tracep->chgSData(oldp+218,((0x3fffU & (vlTOPp->o_PCF 
                                               >> 2U))),14);
        tracep->chgSData(oldp+219,((0x3fffU & (vlTOPp->o_alu_resultM 
                                               >> 2U))),14);
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
        vlTOPp->__Vm_traceActivity[4U] = 0U;
        vlTOPp->__Vm_traceActivity[5U] = 0U;
        vlTOPp->__Vm_traceActivity[6U] = 0U;
        vlTOPp->__Vm_traceActivity[7U] = 0U;
    }
}
