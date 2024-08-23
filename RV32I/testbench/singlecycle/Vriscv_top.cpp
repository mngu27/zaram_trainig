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
            VL_FATAL_MT("/root/verilog_tutorials/RV32I/core/singlecycle/riscv_top.v", 14, "",
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
            VL_FATAL_MT("/root/verilog_tutorials/RV32I/core/singlecycle/riscv_top.v", 14, "",
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
    CData/*4:0*/ __Vdlyvdim0__riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers__v0;
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
    IData/*31:0*/ __Vdlyvval__riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers__v0;
    IData/*31:0*/ __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v4;
    // Body
    __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0 = 0U;
    __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1 = 0U;
    __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2 = 0U;
    __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3 = 0U;
    __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v4 = 0U;
    if (vlTOPp->o_riscv_dmem_wr_en) {
        vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__i = 4U;
    }
    if (vlTOPp->o_riscv_dmem_wr_en) {
        if ((1U & (IData)(vlTOPp->o_riscv_dmem_byte_sel))) {
            __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0 
                = (0xffU & vlTOPp->o_riscv_dmem_wr_data);
            __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0 = 1U;
            __Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0 = 0U;
            __Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v0 
                = (0x3fffU & (vlTOPp->o_riscv_dmem_addr 
                              >> 2U));
        }
        if ((2U & (IData)(vlTOPp->o_riscv_dmem_byte_sel))) {
            __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1 
                = (0xffU & (vlTOPp->o_riscv_dmem_wr_data 
                            >> 8U));
            __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1 = 1U;
            __Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1 = 8U;
            __Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v1 
                = (0x3fffU & (vlTOPp->o_riscv_dmem_addr 
                              >> 2U));
        }
        if ((4U & (IData)(vlTOPp->o_riscv_dmem_byte_sel))) {
            __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2 
                = (0xffU & (vlTOPp->o_riscv_dmem_wr_data 
                            >> 0x10U));
            __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2 = 1U;
            __Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2 = 0x10U;
            __Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v2 
                = (0x3fffU & (vlTOPp->o_riscv_dmem_addr 
                              >> 2U));
        }
        if ((8U & (IData)(vlTOPp->o_riscv_dmem_byte_sel))) {
            __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3 
                = (0xffU & (vlTOPp->o_riscv_dmem_wr_data 
                            >> 0x18U));
            __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3 = 1U;
            __Vdlyvlsb__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3 = 0x18U;
            __Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v3 
                = (0x3fffU & (vlTOPp->o_riscv_dmem_addr 
                              >> 2U));
        }
    } else {
        __Vdlyvval__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v4 
            = vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr
            [(0x3fffU & (vlTOPp->o_riscv_dmem_addr 
                         >> 2U))];
        __Vdlyvset__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v4 = 1U;
        __Vdlyvdim0__riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr__v4 
            = (0x3fffU & (vlTOPp->o_riscv_dmem_addr 
                          >> 2U));
    }
    __Vdlyvval__riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers__v0 
        = (((~ ((0x23U == (0x7fU & vlTOPp->o_riscv_imem_instr)) 
                | (0x63U == (0x7fU & vlTOPp->o_riscv_imem_instr)))) 
            & (0U != (0x1fU & (vlTOPp->o_riscv_imem_instr 
                               >> 7U)))) ? vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr
           [vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_rd]
            : vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers
           [(0x1fU & (vlTOPp->o_riscv_imem_instr >> 7U))]);
    __Vdlyvdim0__riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers__v0 
        = (0x1fU & (vlTOPp->o_riscv_imem_instr >> 7U));
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
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers[__Vdlyvdim0__riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers__v0] 
        = __Vdlyvval__riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers__v0;
}

VL_INLINE_OPT void Vriscv_top::_sequent__TOP__3(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_sequent__TOP__3\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->o_riscv_imem_pc = ((IData)(vlTOPp->i_rstn)
                                ? ((2U >= (IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_pc))
                                    ? vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_pc__DOT__mux_input_arr
                                   [vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_pc]
                                    : 0U) : 0U);
    vlTOPp->o_riscv_imem_instr = vlTOPp->riscv_top__DOT__u_riscv_imem__DOT__imem_arr
        [(0x3fffU & (vlTOPp->o_riscv_imem_pc >> 2U))];
    vlTOPp->o_riscv_dmem_wr_en = (0x23U == (0x7fU & vlTOPp->o_riscv_imem_instr));
    vlTOPp->__Vtableidx3 = (0x7fU & vlTOPp->o_riscv_imem_instr);
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_rd 
        = vlTOPp->__Vtable3_riscv_top__DOT__u_riscv_cpu__DOT__src_rd
        [vlTOPp->__Vtableidx3];
    vlTOPp->__Vtableidx5 = ((0x400U & (vlTOPp->o_riscv_imem_instr 
                                       >> 0x14U)) | 
                            ((0x380U & (vlTOPp->o_riscv_imem_instr 
                                        >> 5U)) | (0x7fU 
                                                   & vlTOPp->o_riscv_imem_instr)));
    if (vlTOPp->__Vtablechg5[vlTOPp->__Vtableidx5]) {
        vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR[0U] 
            = vlTOPp->__Vtable5_riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR
            [vlTOPp->__Vtableidx5][0U];
        vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR[1U] 
            = vlTOPp->__Vtable5_riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR
            [vlTOPp->__Vtableidx5][1U];
        vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR[2U] 
            = vlTOPp->__Vtable5_riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR
            [vlTOPp->__Vtableidx5][2U];
        vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR[3U] 
            = vlTOPp->__Vtable5_riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR
            [vlTOPp->__Vtableidx5][3U];
        vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR[4U] 
            = vlTOPp->__Vtable5_riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR
            [vlTOPp->__Vtableidx5][4U];
        vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR[5U] 
            = vlTOPp->__Vtable5_riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR
            [vlTOPp->__Vtableidx5][5U];
        vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR[6U] 
            = vlTOPp->__Vtable5_riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR
            [vlTOPp->__Vtableidx5][6U];
        vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR[7U] 
            = vlTOPp->__Vtable5_riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR
            [vlTOPp->__Vtableidx5][7U];
    }
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__alu_ctrl 
        = (((0x33U == (0x7fU & vlTOPp->o_riscv_imem_instr)) 
            | (0x13U == (0x7fU & vlTOPp->o_riscv_imem_instr)))
            ? ((0x4000U & vlTOPp->o_riscv_imem_instr)
                ? ((0x2000U & vlTOPp->o_riscv_imem_instr)
                    ? ((0x1000U & vlTOPp->o_riscv_imem_instr)
                        ? 7U : 6U) : ((0x1000U & vlTOPp->o_riscv_imem_instr)
                                       ? ((0x40000000U 
                                           & vlTOPp->o_riscv_imem_instr)
                                           ? 0xdU : 5U)
                                       : 4U)) : ((0x2000U 
                                                  & vlTOPp->o_riscv_imem_instr)
                                                  ? 
                                                 ((0x1000U 
                                                   & vlTOPp->o_riscv_imem_instr)
                                                   ? 3U
                                                   : 2U)
                                                  : 
                                                 ((0x1000U 
                                                   & vlTOPp->o_riscv_imem_instr)
                                                   ? 1U
                                                   : 
                                                  (((vlTOPp->o_riscv_imem_instr 
                                                     >> 0x1eU) 
                                                    & (0x33U 
                                                       == 
                                                       (0x7fU 
                                                        & vlTOPp->o_riscv_imem_instr)))
                                                    ? 8U
                                                    : 0U))))
            : ((0x63U == (0x7fU & vlTOPp->o_riscv_imem_instr))
                ? ((0x4000U & vlTOPp->o_riscv_imem_instr)
                    ? ((0x2000U & vlTOPp->o_riscv_imem_instr)
                        ? 3U : 2U) : ((0x2000U & vlTOPp->o_riscv_imem_instr)
                                       ? 0xfU : 8U))
                : 0U));
    vlTOPp->__Vtableidx4 = (0x7fU & vlTOPp->o_riscv_imem_instr);
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_alu_b 
        = vlTOPp->__Vtable4_riscv_top__DOT__u_riscv_cpu__DOT__src_alu_b
        [vlTOPp->__Vtableidx4];
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_alu_a 
        = (((QData)((IData)(vlTOPp->o_riscv_imem_pc)) 
            << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers
                                        [(0x1fU & (vlTOPp->o_riscv_imem_instr 
                                                   >> 0xfU))])));
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__regfile_rs2_data 
        = vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_regfile__DOT__registers
        [(0x1fU & (vlTOPp->o_riscv_imem_instr >> 0x14U))];
    vlTOPp->__Vtableidx2 = (0x7fU & vlTOPp->o_riscv_imem_instr);
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_imm 
        = vlTOPp->__Vtable2_riscv_top__DOT__u_riscv_cpu__DOT__src_imm
        [vlTOPp->__Vtableidx2];
    vlTOPp->__Vtableidx1 = vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__alu_ctrl;
    if (vlTOPp->__Vtablechg1[vlTOPp->__Vtableidx1]) {
        vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP 
            = vlTOPp->__Vtable1_riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP
            [vlTOPp->__Vtableidx1];
    }
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_alu_a__DOT__mux_input_arr[0U] 
        = (IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_alu_a);
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_alu_a__DOT__mux_input_arr[1U] 
        = (IData)((vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_alu_a 
                   >> 0x20U));
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__immediate 
        = ((4U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_imm))
            ? ((2U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_imm))
                ? 0U : ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_imm))
                         ? (0xfffff000U & vlTOPp->o_riscv_imem_instr)
                         : ((0xfff00000U & ((- (IData)(
                                                       (1U 
                                                        & (vlTOPp->o_riscv_imem_instr 
                                                           >> 0x1fU)))) 
                                            << 0x14U)) 
                            | ((0xff000U & vlTOPp->o_riscv_imem_instr) 
                               | ((0x800U & (vlTOPp->o_riscv_imem_instr 
                                             >> 9U)) 
                                  | (0x7feU & (vlTOPp->o_riscv_imem_instr 
                                               >> 0x14U)))))))
            : ((2U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_imm))
                ? ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_imm))
                    ? ((0xfffff000U & ((- (IData)((1U 
                                                   & (vlTOPp->o_riscv_imem_instr 
                                                      >> 0x1fU)))) 
                                       << 0xcU)) | 
                       ((0x800U & (vlTOPp->o_riscv_imem_instr 
                                   << 4U)) | ((0x7e0U 
                                               & (vlTOPp->o_riscv_imem_instr 
                                                  >> 0x14U)) 
                                              | (0x1eU 
                                                 & (vlTOPp->o_riscv_imem_instr 
                                                    >> 7U)))))
                    : ((0xfffff000U & ((- (IData)((1U 
                                                   & (vlTOPp->o_riscv_imem_instr 
                                                      >> 0x1fU)))) 
                                       << 0xcU)) | 
                       ((0xfe0U & (vlTOPp->o_riscv_imem_instr 
                                   >> 0x14U)) | (0x1fU 
                                                 & (vlTOPp->o_riscv_imem_instr 
                                                    >> 7U)))))
                : ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_imm))
                    ? ((0xfffff000U & ((- (IData)((1U 
                                                   & (vlTOPp->o_riscv_imem_instr 
                                                      >> 0x1fU)))) 
                                       << 0xcU)) | 
                       (0xfffU & (vlTOPp->o_riscv_imem_instr 
                                  >> 0x14U))) : 0U)));
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_a 
        = vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_alu_a__DOT__mux_input_arr
        [(0x17U == (0x7fU & vlTOPp->o_riscv_imem_instr))];
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_alu_b 
        = (((QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__immediate)) 
            << 0x20U) | (QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__regfile_rs2_data)));
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr[0U] 
        = (IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_alu_b);
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr[1U] 
        = (IData)((vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_alu_b 
                   >> 0x20U));
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_b 
        = vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_alu_b__DOT__mux_input_arr
        [vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_alu_b];
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result 
        = ((8U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__alu_ctrl))
            ? ((4U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__alu_ctrl))
                ? ((2U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__alu_ctrl))
                    ? 0U : ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__alu_ctrl))
                             ? VL_SHIFTRS_III(32,32,5, vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_a, 
                                              (0x1fU 
                                               & vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_b))
                             : 0U)) : ((2U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__alu_ctrl))
                                        ? 0U : ((1U 
                                                 & (IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__alu_ctrl))
                                                 ? 0U
                                                 : 
                                                (vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_a 
                                                 - vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_b))))
            : ((4U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__alu_ctrl))
                ? ((2U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__alu_ctrl))
                    ? ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__alu_ctrl))
                        ? (vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_a 
                           & vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_b)
                        : (vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_a 
                           | vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_b))
                    : ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__alu_ctrl))
                        ? (vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_a 
                           >> (0x1fU & vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_b))
                        : (vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_a 
                           ^ vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_b)))
                : ((2U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__alu_ctrl))
                    ? ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__alu_ctrl))
                        ? ((vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_a 
                            < vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_b)
                            ? 1U : 0U) : (VL_LTS_III(1,32,32, vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_a, vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_b)
                                           ? 1U : 0U))
                    : ((1U & (IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__alu_ctrl))
                        ? (vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_a 
                           << (0x1fU & vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_b))
                        : (vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_a 
                           + vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_b)))));
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__src_pc 
        = ((0x63U == (0x7fU & vlTOPp->o_riscv_imem_instr))
            ? (((0x63U == (0x7fU & vlTOPp->o_riscv_imem_instr)) 
                & ((0x4000U & vlTOPp->o_riscv_imem_instr)
                    ? ((0x2000U & vlTOPp->o_riscv_imem_instr)
                        ? ((0x1000U & vlTOPp->o_riscv_imem_instr)
                            ? (0U == vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result)
                            : (0U != vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result))
                        : ((0x1000U & vlTOPp->o_riscv_imem_instr)
                            ? (0U == vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result)
                            : (0U != vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result)))
                    : ((~ (vlTOPp->o_riscv_imem_instr 
                           >> 0xdU)) & ((0x1000U & vlTOPp->o_riscv_imem_instr)
                                         ? (0U != vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result)
                                         : (0U == vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result)))))
                ? 1U : 0U) : ((0x6fU == (0x7fU & vlTOPp->o_riscv_imem_instr))
                               ? 1U : ((0x67U == (0x7fU 
                                                  & vlTOPp->o_riscv_imem_instr))
                                        ? 2U : 0U)));
    vlTOPp->o_riscv_dmem_wr_data = ((0x1fU >= (0x18U 
                                               & (vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result 
                                                  << 3U)))
                                     ? (vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__regfile_rs2_data 
                                        << (0x18U & 
                                            (vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result 
                                             << 3U)))
                                     : 0U);
    vlTOPp->o_riscv_dmem_byte_sel = ((3U >= (3U & vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result))
                                      ? (0xfU & (((
                                                   (3U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->o_riscv_imem_instr)) 
                                                   | (0x23U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->o_riscv_imem_instr)))
                                                   ? 
                                                  ((0x4000U 
                                                    & vlTOPp->o_riscv_imem_instr)
                                                    ? 
                                                   ((0x2000U 
                                                     & vlTOPp->o_riscv_imem_instr)
                                                     ? 0xfU
                                                     : 
                                                    ((0x1000U 
                                                      & vlTOPp->o_riscv_imem_instr)
                                                      ? 3U
                                                      : 1U))
                                                    : 
                                                   ((0x2000U 
                                                     & vlTOPp->o_riscv_imem_instr)
                                                     ? 0xfU
                                                     : 
                                                    ((0x1000U 
                                                      & vlTOPp->o_riscv_imem_instr)
                                                      ? 3U
                                                      : 1U)))
                                                   : 0xfU) 
                                                 << 
                                                 (3U 
                                                  & vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result)))
                                      : 0U);
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_pc[0U] 
        = ((IData)(4U) + vlTOPp->o_riscv_imem_pc);
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_pc[1U] 
        = (IData)((((QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result)) 
                    << 0x20U) | (QData)((IData)((vlTOPp->o_riscv_imem_pc 
                                                 + vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__immediate)))));
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_pc[2U] 
        = (IData)(((((QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result)) 
                     << 0x20U) | (QData)((IData)((vlTOPp->o_riscv_imem_pc 
                                                  + vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__immediate)))) 
                   >> 0x20U));
    vlTOPp->o_riscv_dmem_addr = vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result;
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_pc__DOT__mux_input_arr[0U] 
        = vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_pc[0U];
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_pc__DOT__mux_input_arr[1U] 
        = vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_pc[1U];
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_pc__DOT__mux_input_arr[2U] 
        = vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_pc[2U];
    vlTOPp->o_riscv_dmem_rd_data = vlTOPp->riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr
        [(0x3fffU & (vlTOPp->o_riscv_dmem_addr >> 2U))];
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
        = ((0x1fU >= (0x18U & (vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result 
                               << 3U))) ? (vlTOPp->o_riscv_dmem_rd_data 
                                           >> (0x18U 
                                               & (vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result 
                                                  << 3U)))
            : 0U);
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_rd[0U] 
        = vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__alu_result;
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_rd[1U] 
        = ((0x4000U & vlTOPp->o_riscv_imem_instr) ? 
           ((0x2000U & vlTOPp->o_riscv_imem_instr) ? 0U
             : ((0x1000U & vlTOPp->o_riscv_imem_instr)
                 ? (0xffffU & vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                 : (0xffU & vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))
            : ((0x2000U & vlTOPp->o_riscv_imem_instr)
                ? ((0x1000U & vlTOPp->o_riscv_imem_instr)
                    ? 0U : vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)
                : ((0x1000U & vlTOPp->o_riscv_imem_instr)
                    ? ((0xffff0000U & ((- (IData)((1U 
                                                   & (vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
                                                      >> 0xfU)))) 
                                       << 0x10U)) | 
                       (0xffffU & vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data))
                    : ((0xffffff00U & ((- (IData)((1U 
                                                   & (vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data 
                                                      >> 7U)))) 
                                       << 8U)) | (0xffU 
                                                  & vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_dmem_interface__DOT__byte_aligned_dmem_rd_data)))));
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_rd[2U] 
        = (IData)((((QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__immediate)) 
                    << 0x20U) | (QData)((IData)(((IData)(4U) 
                                                 + vlTOPp->o_riscv_imem_pc)))));
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_rd[3U] 
        = (IData)(((((QData)((IData)(vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__immediate)) 
                     << 0x20U) | (QData)((IData)(((IData)(4U) 
                                                  + vlTOPp->o_riscv_imem_pc)))) 
                   >> 0x20U));
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr[0U] 
        = vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_rd[0U];
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr[1U] 
        = vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_rd[1U];
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr[2U] 
        = vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_rd[2U];
    vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__u_riscv_mux_regfile_rd_data__DOT__mux_input_arr[3U] 
        = vlTOPp->riscv_top__DOT__u_riscv_cpu__DOT__u_riscv_datapath__DOT__mux_concat_rd[3U];
}

void Vriscv_top::_eval(Vriscv_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vriscv_top::_eval\n"); );
    Vriscv_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_clk)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if ((((IData)(vlTOPp->i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_clk))) 
         | ((~ (IData)(vlTOPp->i_rstn)) & (IData)(vlTOPp->__Vclklast__TOP__i_rstn)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
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
