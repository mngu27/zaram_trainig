// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vriscv_top.h for the primary calling header

#include "Vriscv_top.h"
#include "Vriscv_top__Syms.h"

//==========

void Vriscv_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vriscv_top::eval\n"); );
    Vriscv_top__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/root/zaram_trainig/RV32I/core/pipelined/riscv_top.v", 10, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vriscv_top::_eval_initial_loop(Vriscv_top__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/root/zaram_trainig/RV32I/core/pipelined/riscv_top.v", 10, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vriscv_top::_sequent__TOP__2(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_sequent__TOP__2\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    IData/*31:0*/ __Vdly__riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCD;
    IData/*31:0*/ __Vdly__riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCPlus4D;
    // Body
    __Vdly__riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCPlus4D 
        = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCPlus4D;
    __Vdly__riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCD 
        = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCD;
    vlTOPp->__Vdly__riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
        = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD;
    if ((1U & ((~ (IData)(vlTOPp->i_rstn)) | (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_flushD)))) {
        __Vdly__riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCPlus4D = 0U;
        __Vdly__riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCD = 0U;
    } else {
        __Vdly__riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCPlus4D 
            = ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_hazard_unit__DOT__lwStall)
                ? vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCPlus4D
                : ((IData)(4U) + vlTOPp->o_PCF));
        __Vdly__riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCD 
            = ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_hazard_unit__DOT__lwStall)
                ? vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCD
                : vlTOPp->o_PCF);
    }
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_jalE 
        = ((~ ((~ (IData)(vlTOPp->i_rstn)) | (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_flushE))) 
           & (0x6fU == (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)));
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_jalrE 
        = ((~ ((~ (IData)(vlTOPp->i_rstn)) | (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_flushE))) 
           & (0x67U == (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)));
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_branchE 
        = ((~ ((~ (IData)(vlTOPp->i_rstn)) | (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_flushE))) 
           & (0x63U == (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)));
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_funct3E 
        = ((1U & ((~ (IData)(vlTOPp->i_rstn)) | (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_flushE)))
            ? 0U : (7U & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                          >> 0xcU)));
    vlTOPp->__Vdly__riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
        = ((1U & ((~ (IData)(vlTOPp->i_rstn)) | (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_flushD)))
            ? 0U : ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_hazard_unit__DOT__lwStall)
                     ? vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD
                     : vlTOPp->o_instrF));
    vlTOPp->o_PCF = ((IData)(vlTOPp->i_rstn) ? ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_hazard_unit__DOT__lwStall)
                                                 ? vlTOPp->o_PCF
                                                 : 
                                                ((2U 
                                                  >= (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCSrcE))
                                                  ? 
                                                 vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_fetch__DOT__u_riscv_mux_pc__DOT__mux_input_arr
                                                 [vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCSrcE]
                                                  : 0U))
                      : 0U);
    if ((1U & ((~ (IData)(vlTOPp->i_rstn)) | (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_flushE)))) {
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__PCE = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_ctrlE = 0U;
    } else {
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__PCE 
            = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCD;
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_ctrlE 
            = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_alu_ctrlD;
    }
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_srcE 
        = ((~ ((~ (IData)(vlTOPp->i_rstn)) | (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_flushE))) 
           & ((0x33U != (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)) 
              & (0x63U != (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD))));
    if ((1U & ((~ (IData)(vlTOPp->i_rstn)) | (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_flushE)))) {
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rs1_addrE = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ExtImmE = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__regfile_rs1_dataE = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rs2_addrE = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__regfile_rs2_dataE = 0U;
    } else {
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rs1_addrE 
            = (0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                        >> 0xfU));
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ExtImmE 
            = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ExtImmD;
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__regfile_rs1_dataE 
            = (0x3fffffffU & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers
               [(0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                          >> 0xfU))]);
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rs2_addrE 
            = (0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                        >> 0x14U));
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__regfile_rs2_dataE 
            = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers
            [(0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                       >> 0x14U))];
    }
    if (vlTOPp->i_rstn) {
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__ctrl_result_srcW 
            = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_result_srcM;
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__mem_readdataW 
            = vlTOPp->o_mem_readdataM;
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__PCPlus4W 
            = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCPlus4M;
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__PCTargetW 
            = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCTargetM;
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__alu_resultW 
            = vlTOPp->o_alu_resultM;
    } else {
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__ctrl_result_srcW = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__mem_readdataW = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__PCPlus4W = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__PCTargetW = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__alu_resultW = 0U;
    }
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCD 
        = __Vdly__riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCD;
    vlTOPp->o_instrF = vlTOPp->riscv_top__DOT__u_riscv_imem__DOT__imem_arr
        [(0x3fffU & (vlTOPp->o_PCF >> 2U))];
    vlTOPp->__Vtableidx5 = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_ctrlE;
    if (vlTOPp->__Vtablechg5[vlTOPp->__Vtableidx5]) {
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP 
            = vlTOPp->__Vtable5_riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP
            [vlTOPp->__Vtableidx5];
    }
    if (vlTOPp->i_rstn) {
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_result_srcM 
            = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_result_srcE;
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCPlus4M 
            = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCPlus4E;
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCTargetM 
            = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCTargetE;
    } else {
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_result_srcM = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCPlus4M = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCTargetM = 0U;
    }
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__Writeback_concat_data[0U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__alu_resultW;
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__Writeback_concat_data[1U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__mem_readdataW;
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__Writeback_concat_data[2U] 
        = (IData)((((QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__PCTargetW)) 
                    << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__PCPlus4W))));
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__Writeback_concat_data[3U] 
        = (IData)(((((QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__PCTargetW)) 
                     << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__PCPlus4W))) 
                   >> 0x20U));
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCTargetE 
        = (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__PCE 
           + vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ExtImmE);
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__u_riscv_mux_result__DOT__mux_input_arr[0U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__Writeback_concat_data[0U];
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__u_riscv_mux_result__DOT__mux_input_arr[1U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__Writeback_concat_data[1U];
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__u_riscv_mux_result__DOT__mux_input_arr[2U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__Writeback_concat_data[2U];
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__u_riscv_mux_result__DOT__mux_input_arr[3U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__Writeback_concat_data[3U];
    if ((1U & ((~ (IData)(vlTOPp->i_rstn)) | (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_flushE)))) {
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_result_srcE = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCPlus4E = 0U;
    } else {
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_result_srcE 
            = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_result_srcD;
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCPlus4E 
            = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCPlus4D;
    }
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCPlus4D 
        = __Vdly__riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCPlus4D;
}

VL_INLINE_OPT void Vriscv_top::_sequent__TOP__3(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_sequent__TOP__3\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0;
    CData/*7:0*/ __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0;
    CData/*0:0*/ __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0;
    CData/*4:0*/ __Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1;
    CData/*7:0*/ __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1;
    CData/*0:0*/ __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1;
    CData/*4:0*/ __Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2;
    CData/*7:0*/ __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2;
    CData/*0:0*/ __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2;
    CData/*4:0*/ __Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3;
    CData/*7:0*/ __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3;
    CData/*0:0*/ __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3;
    CData/*0:0*/ __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v4;
    SData/*13:0*/ __Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0;
    SData/*13:0*/ __Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1;
    SData/*13:0*/ __Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2;
    SData/*13:0*/ __Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3;
    SData/*13:0*/ __Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v4;
    IData/*31:0*/ __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v4;
    // Body
    if (vlTOPp->o_ctrl_mem_wr_enM) {
        vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__i = 4U;
    }
    __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0 = 0U;
    __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1 = 0U;
    __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2 = 0U;
    __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3 = 0U;
    __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v4 = 0U;
    if (vlTOPp->o_ctrl_mem_wr_enM) {
        if ((1U & (IData)(vlTOPp->o_ctrl_mem_byte_selM))) {
            __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0 
                = (0xffU & vlTOPp->o_mem_writedataM);
            __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0 = 1U;
            __Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0 = 0U;
            __Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0 
                = (0x3fffU & (vlTOPp->o_alu_resultM 
                              >> 2U));
        }
        if ((2U & (IData)(vlTOPp->o_ctrl_mem_byte_selM))) {
            __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1 
                = (0xffU & (vlTOPp->o_mem_writedataM 
                            >> 8U));
            __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1 = 1U;
            __Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1 = 8U;
            __Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1 
                = (0x3fffU & (vlTOPp->o_alu_resultM 
                              >> 2U));
        }
        if ((4U & (IData)(vlTOPp->o_ctrl_mem_byte_selM))) {
            __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2 
                = (0xffU & (vlTOPp->o_mem_writedataM 
                            >> 0x10U));
            __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2 = 1U;
            __Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2 = 0x10U;
            __Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2 
                = (0x3fffU & (vlTOPp->o_alu_resultM 
                              >> 2U));
        }
        if ((8U & (IData)(vlTOPp->o_ctrl_mem_byte_selM))) {
            __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3 
                = (0xffU & (vlTOPp->o_mem_writedataM 
                            >> 0x18U));
            __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3 = 1U;
            __Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3 = 0x18U;
            __Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3 
                = (0x3fffU & (vlTOPp->o_alu_resultM 
                              >> 2U));
        }
    } else {
        __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v4 
            = vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr
            [(0x3fffU & (vlTOPp->o_alu_resultM >> 2U))];
        __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v4 = 1U;
        __Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v4 
            = (0x3fffU & (vlTOPp->o_alu_resultM >> 2U));
    }
    if (__Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0) {
        vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr[__Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0))) 
                & vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr
                [__Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0]) 
               | ((IData)(__Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0) 
                  << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0)));
    }
    if (__Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1) {
        vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr[__Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1))) 
                & vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr
                [__Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1]) 
               | ((IData)(__Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1) 
                  << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1)));
    }
    if (__Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2) {
        vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr[__Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2))) 
                & vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr
                [__Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2]) 
               | ((IData)(__Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2) 
                  << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2)));
    }
    if (__Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3) {
        vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr[__Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3))) 
                & vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr
                [__Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3]) 
               | ((IData)(__Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3) 
                  << (IData)(__Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3)));
    }
    if (__Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v4) {
        vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr[__Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v4] 
            = __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v4;
    }
}

VL_INLINE_OPT void Vriscv_top::_sequent__TOP__4(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_sequent__TOP__4\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers__v0;
    IData/*31:0*/ __Vdlyvval__riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers__v0;
    // Body
    __Vdlyvval__riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers__v0 
        = (((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_reg_wr_enW) 
            & (0U != (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_addrW)))
            ? vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_dataW
            : vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers
           [vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_addrW]);
    __Vdlyvdim0__riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers__v0 
        = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_addrW;
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[__Vdlyvdim0__riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers__v0] 
        = __Vdlyvval__riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers__v0;
}

VL_INLINE_OPT void Vriscv_top::_sequent__TOP__6(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_sequent__TOP__6\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_dataW 
        = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__u_riscv_mux_result__DOT__mux_input_arr
        [vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_result_srcM];
    if (vlTOPp->i_rstn) {
        vlTOPp->o_ctrl_mem_byte_selM = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_mem_byte_selE;
        vlTOPp->o_ctrl_mem_wr_enM = ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_mem_wr_enE) 
                                     & 1U);
        vlTOPp->o_mem_writedataM = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__mem_writedataE;
        vlTOPp->o_alu_resultM = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__alu_resultE;
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_reg_wr_enW 
            = ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_reg_wr_enM) 
               & 1U);
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_addrW 
            = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_addrM;
    } else {
        vlTOPp->o_ctrl_mem_byte_selM = 0U;
        vlTOPp->o_ctrl_mem_wr_enM = 0U;
        vlTOPp->o_mem_writedataM = 0U;
        vlTOPp->o_alu_resultM = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_reg_wr_enW = 0U;
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_addrW = 0U;
    }
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_mem_byte_selE 
        = ((1U & ((~ (IData)(vlTOPp->i_rstn)) | (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_flushE)))
            ? 0U : (((3U == (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)) 
                     | (0x23U == (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)))
                     ? ((0x4000U & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)
                         ? ((0x2000U & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)
                             ? 0xfU : ((0x1000U & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)
                                        ? 3U : 1U))
                         : ((0x2000U & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)
                             ? 0xfU : ((0x1000U & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)
                                        ? 3U : 1U)))
                     : 0xfU));
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_mem_wr_enE 
        = ((~ ((~ (IData)(vlTOPp->i_rstn)) | (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_flushE))) 
           & (0x23U == (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)));
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__srcA_concat_data[0U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__regfile_rs1_dataE;
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__srcA_concat_data[1U] 
        = (IData)((((QData)((IData)(vlTOPp->o_alu_resultM)) 
                    << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_dataW))));
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__srcA_concat_data[2U] 
        = (IData)(((((QData)((IData)(vlTOPp->o_alu_resultM)) 
                     << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_dataW))) 
                   >> 0x20U));
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__writedata_concat[0U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__regfile_rs2_dataE;
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__writedata_concat[1U] 
        = (IData)((((QData)((IData)(vlTOPp->o_alu_resultM)) 
                    << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_dataW))));
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__writedata_concat[2U] 
        = (IData)(((((QData)((IData)(vlTOPp->o_alu_resultM)) 
                     << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_dataW))) 
                   >> 0x20U));
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_reg_wr_enM 
        = ((IData)(vlTOPp->i_rstn) & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_reg_wr_enE));
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_addrM 
        = ((IData)(vlTOPp->i_rstn) ? (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_addrE)
            : 0U);
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_srcAE__DOT__mux_input_arr[0U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__srcA_concat_data[0U];
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_srcAE__DOT__mux_input_arr[1U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__srcA_concat_data[1U];
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_srcAE__DOT__mux_input_arr[2U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__srcA_concat_data[2U];
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_writedata__DOT__mux_input_arr[0U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__writedata_concat[0U];
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_writedata__DOT__mux_input_arr[1U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__writedata_concat[1U];
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_writedata__DOT__mux_input_arr[2U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__writedata_concat[2U];
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_reg_wr_enE 
        = ((~ ((~ (IData)(vlTOPp->i_rstn)) | (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_flushE))) 
           & ((0x63U != (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)) 
              & (0x23U != (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD))));
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_addrE 
        = ((1U & ((~ (IData)(vlTOPp->i_rstn)) | (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_flushE)))
            ? 0U : (0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                             >> 7U)));
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_forwardAE 
        = (((((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rs1_addrE) 
              == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_addrM)) 
             & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_reg_wr_enM)) 
            & (0U != (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rs1_addrE)))
            ? 2U : (((((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rs1_addrE) 
                       == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_addrW)) 
                      & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_reg_wr_enW)) 
                     & (0U != (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rs1_addrE)))
                     ? 1U : 0U));
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_forwardBE 
        = (((((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rs2_addrE) 
              == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_addrM)) 
             & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_reg_wr_enM)) 
            & (0U != (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rs2_addrE)))
            ? 2U : (((((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rs2_addrE) 
                       == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_addrW)) 
                      & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_reg_wr_enW)) 
                     & (0U != (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rs2_addrE)))
                     ? 1U : 0U));
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
        = vlTOPp->__Vdly__riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD;
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcAE 
        = ((2U >= (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_forwardAE))
            ? vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_srcAE__DOT__mux_input_arr
           [vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_forwardAE]
            : 0U);
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__mem_writedataE 
        = ((2U >= (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_forwardBE))
            ? vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_writedata__DOT__mux_input_arr
           [vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_forwardBE]
            : 0U);
    if (((0x33U == (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)) 
         | (0x13U == (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)))) {
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_alu_ctrlD 
            = ((0x4000U & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)
                ? ((0x2000U & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)
                    ? ((0x1000U & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)
                        ? 7U : 6U) : ((0x1000U & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)
                                       ? ((0x40000000U 
                                           & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)
                                           ? 0xdU : 5U)
                                       : 4U)) : ((0x2000U 
                                                  & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)
                                                  ? 
                                                 ((0x1000U 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)
                                                   ? 3U
                                                   : 2U)
                                                  : 
                                                 ((0x1000U 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)
                                                   ? 1U
                                                   : 
                                                  (((vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                                     >> 0x1eU) 
                                                    & (0x33U 
                                                       == 
                                                       (0x7fU 
                                                        & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)))
                                                    ? 8U
                                                    : 0U))));
    } else {
        if ((0x63U == (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD))) {
            if (((0U == (7U & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                               >> 0xcU))) | (1U == 
                                             (7U & 
                                              (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                               >> 0xcU))))) {
                vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_alu_ctrlD = 8U;
            } else {
                if (((4U == (7U & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                   >> 0xcU))) | (5U 
                                                 == 
                                                 (7U 
                                                  & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                                     >> 0xcU))))) {
                    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_alu_ctrlD = 2U;
                } else {
                    if (((6U == (7U & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                       >> 0xcU))) | 
                         (7U == (7U & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                       >> 0xcU))))) {
                        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_alu_ctrlD = 3U;
                    }
                }
            }
        } else {
            vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_alu_ctrlD = 0U;
        }
    }
    vlTOPp->__Vtableidx1 = (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD);
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_result_srcD 
        = vlTOPp->__Vtable1_riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_result_srcD
        [vlTOPp->__Vtableidx1];
    vlTOPp->__Vtableidx3 = ((0x400U & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                       >> 0x14U)) | 
                            ((0x380U & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                        >> 5U)) | (0x7fU 
                                                   & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)));
    if (vlTOPp->__Vtablechg3[vlTOPp->__Vtableidx3]) {
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR[0U] 
            = vlTOPp->__Vtable3_riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR
            [vlTOPp->__Vtableidx3][0U];
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR[1U] 
            = vlTOPp->__Vtable3_riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR
            [vlTOPp->__Vtableidx3][1U];
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR[2U] 
            = vlTOPp->__Vtable3_riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR
            [vlTOPp->__Vtableidx3][2U];
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR[3U] 
            = vlTOPp->__Vtable3_riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR
            [vlTOPp->__Vtableidx3][3U];
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR[4U] 
            = vlTOPp->__Vtable3_riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR
            [vlTOPp->__Vtableidx3][4U];
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR[5U] 
            = vlTOPp->__Vtable3_riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR
            [vlTOPp->__Vtableidx3][5U];
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR[6U] 
            = vlTOPp->__Vtable3_riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR
            [vlTOPp->__Vtableidx3][6U];
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR[7U] 
            = vlTOPp->__Vtable3_riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR
            [vlTOPp->__Vtableidx3][7U];
    }
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_hazard_unit__DOT__lwStall 
        = ((((0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                       >> 0xfU)) == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_addrE)) 
            | ((0x1fU & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                         >> 0x14U)) == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_addrE))) 
           & (1U == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_result_srcE)));
    vlTOPp->__Vtableidx2 = (0x7fU & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD);
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__ctrl_src_immD 
        = vlTOPp->__Vtable2_riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__ctrl_src_immD
        [vlTOPp->__Vtableidx2];
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__srcB_concat_data 
        = (((QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ExtImmE)) 
            << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__mem_writedataE)));
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ExtImmD 
        = ((4U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__ctrl_src_immD))
            ? ((2U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__ctrl_src_immD))
                ? 0U : ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__ctrl_src_immD))
                         ? (0xfffff000U & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD)
                         : ((0xfff00000U & ((- (IData)(
                                                       (1U 
                                                        & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                                           >> 0x1fU)))) 
                                            << 0x14U)) 
                            | ((0xff000U & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD) 
                               | ((0x800U & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                             >> 9U)) 
                                  | (0x7feU & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                               >> 0x14U)))))))
            : ((2U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__ctrl_src_immD))
                ? ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__ctrl_src_immD))
                    ? ((0xfffff000U & ((- (IData)((1U 
                                                   & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                                      >> 0x1fU)))) 
                                       << 0xcU)) | 
                       ((0x800U & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                   << 4U)) | ((0x7e0U 
                                               & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                                  >> 0x14U)) 
                                              | (0x1eU 
                                                 & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                                    >> 7U)))))
                    : ((0xfffff000U & ((- (IData)((1U 
                                                   & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                                      >> 0x1fU)))) 
                                       << 0xcU)) | 
                       ((0xfe0U & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                   >> 0x14U)) | (0x1fU 
                                                 & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                                    >> 7U)))))
                : ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__ctrl_src_immD))
                    ? ((0xfffff000U & ((- (IData)((1U 
                                                   & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                                      >> 0x1fU)))) 
                                       << 0xcU)) | 
                       (0xfffU & (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD 
                                  >> 0x14U))) : 0U)));
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_srcBE__DOT__mux_input_arr[0U] 
        = (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__srcB_concat_data);
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_srcBE__DOT__mux_input_arr[1U] 
        = (IData)((vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__srcB_concat_data 
                   >> 0x20U));
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcBE 
        = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_srcBE__DOT__mux_input_arr
        [vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_srcE];
    if (((((((((0U == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_ctrlE)) 
               | (8U == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_ctrlE))) 
              | (4U == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_ctrlE))) 
             | (6U == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_ctrlE))) 
            | (7U == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_ctrlE))) 
           | (1U == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_ctrlE))) 
          | (5U == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_ctrlE))) 
         | (0xdU == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_ctrlE)))) {
        vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__alu_resultE 
            = ((0U == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_ctrlE))
                ? (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcAE 
                   + vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcBE)
                : ((8U == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_ctrlE))
                    ? (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcAE 
                       - vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcBE)
                    : ((4U == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_ctrlE))
                        ? (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcAE 
                           ^ vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcBE)
                        : ((6U == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_ctrlE))
                            ? (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcAE 
                               | vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcBE)
                            : ((7U == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_ctrlE))
                                ? (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcAE 
                                   & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcBE)
                                : ((1U == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_ctrlE))
                                    ? (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcAE 
                                       << (0x1fU & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcBE))
                                    : ((5U == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_ctrlE))
                                        ? (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcAE 
                                           >> (0x1fU 
                                               & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcBE))
                                        : VL_SHIFTRS_III(32,32,5, vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcAE, 
                                                         (0x1fU 
                                                          & vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcBE)))))))));
    } else {
        if ((2U == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_ctrlE))) {
            vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__alu_resultE 
                = VL_LTS_III(32,32,32, vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcAE, vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcBE);
        } else {
            if ((3U == (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_ctrlE))) {
                vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__alu_resultE 
                    = (vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcAE 
                       < vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcBE);
            }
        }
    }
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_fetch__DOT__PC_concat_data[0U] 
        = ((IData)(4U) + vlTOPp->o_PCF);
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_fetch__DOT__PC_concat_data[1U] 
        = (IData)((((QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__alu_resultE)) 
                    << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCTargetE))));
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_fetch__DOT__PC_concat_data[2U] 
        = (IData)(((((QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__alu_resultE)) 
                     << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCTargetE))) 
                   >> 0x20U));
    vlTOPp->__Vtableidx4 = (((0U == vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__alu_resultE) 
                             << 3U) | (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_funct3E));
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__take_branch 
        = vlTOPp->__Vtable4_riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__take_branch
        [vlTOPp->__Vtableidx4];
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_fetch__DOT__u_riscv_mux_pc__DOT__mux_input_arr[0U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_fetch__DOT__PC_concat_data[0U];
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_fetch__DOT__u_riscv_mux_pc__DOT__mux_input_arr[1U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_fetch__DOT__PC_concat_data[1U];
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_fetch__DOT__u_riscv_mux_pc__DOT__mux_input_arr[2U] 
        = vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_fetch__DOT__PC_concat_data[2U];
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCSrcE 
        = ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_jalrE)
            ? 2U : (((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_jalE) 
                     | ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__take_branch) 
                        & (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_branchE)))
                     ? 1U : 0U));
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_flushD 
        = (1U & (((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCSrcE) 
                  >> 1U) | (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCSrcE)));
    vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_flushE 
        = (1U & (((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_hazard_unit__DOT__lwStall) 
                  | ((IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCSrcE) 
                     >> 1U)) | (IData)(vlTOPp->riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCSrcE)));
}

VL_INLINE_OPT void Vriscv_top::_combo__TOP__7(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_combo__TOP__7\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->o_mem_readdataM = ((IData)(vlTOPp->o_ctrl_mem_wr_enM)
                                ? vlTOPp->o_mem_readdataM
                                : vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr
                               [(0x3fffU & (vlTOPp->o_alu_resultM 
                                            >> 2U))]);
}

void Vriscv_top::_eval(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_eval\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_clk))) 
         | ((~ (IData)(vlTOPp->i_rstn)) & (IData)(vlTOPp->__Vclklast__TOP__i_rstn)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if (((IData)(vlTOPp->i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_clk)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if (((~ (IData)(vlTOPp->i_clk)) & (IData)(vlTOPp->__Vclklast__TOP__i_clk))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    if ((((IData)(vlTOPp->i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_clk))) 
         | ((~ (IData)(vlTOPp->i_rstn)) & (IData)(vlTOPp->__Vclklast__TOP__i_rstn)))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
        vlTOPp->__Vm_traceActivity[3U] = 1U;
    }
    vlTOPp->_combo__TOP__7(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__i_clk = vlTOPp->i_clk;
    vlTOPp->__Vclklast__TOP__i_rstn = vlTOPp->i_rstn;
}

VL_INLINE_OPT QData Vriscv_top::_change_request(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_change_request\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vriscv_top::_change_request_1(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_change_request_1\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->o_mem_readdataM ^ vlTOPp->__Vchglast__TOP__o_mem_readdataM));
    VL_DEBUG_IF( if(__req && ((vlTOPp->o_mem_readdataM ^ vlTOPp->__Vchglast__TOP__o_mem_readdataM))) VL_DBG_MSGF("        CHANGE: /root/zaram_trainig/RV32I/core/pipelined/riscv_top.v:19: o_mem_readdataM\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__o_mem_readdataM = vlTOPp->o_mem_readdataM;
    return __req;
}

#ifdef VL_DEBUG
void Vriscv_top::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((i_clk & 0xfeU))) {
        Verilated::overWidthError("i_clk");}
    if (VL_UNLIKELY((i_rstn & 0xfeU))) {
        Verilated::overWidthError("i_rstn");}
}
#endif  // VL_DEBUG
