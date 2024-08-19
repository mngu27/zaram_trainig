// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "Vdut.h"
#include "Vdut__Syms.h"

//==========

void Vdut::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdut::eval\n"); );
    Vdut__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vdut* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("dut.v", 9, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vdut::_eval_initial_loop(Vdut__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("dut.v", 9, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vdut::_sequent__TOP__1(Vdut__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut::_sequent__TOP__1\n"); );
    Vdut* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdlyvdim0__dut__DOT__dmem_arr__v0;
    CData/*4:0*/ __Vdlyvlsb__dut__DOT__dmem_arr__v0;
    CData/*7:0*/ __Vdlyvval__dut__DOT__dmem_arr__v0;
    CData/*0:0*/ __Vdlyvset__dut__DOT__dmem_arr__v0;
    CData/*7:0*/ __Vdlyvdim0__dut__DOT__dmem_arr__v1;
    CData/*4:0*/ __Vdlyvlsb__dut__DOT__dmem_arr__v1;
    CData/*7:0*/ __Vdlyvval__dut__DOT__dmem_arr__v1;
    CData/*0:0*/ __Vdlyvset__dut__DOT__dmem_arr__v1;
    CData/*7:0*/ __Vdlyvdim0__dut__DOT__dmem_arr__v2;
    CData/*4:0*/ __Vdlyvlsb__dut__DOT__dmem_arr__v2;
    CData/*7:0*/ __Vdlyvval__dut__DOT__dmem_arr__v2;
    CData/*0:0*/ __Vdlyvset__dut__DOT__dmem_arr__v2;
    CData/*7:0*/ __Vdlyvdim0__dut__DOT__dmem_arr__v3;
    CData/*4:0*/ __Vdlyvlsb__dut__DOT__dmem_arr__v3;
    CData/*7:0*/ __Vdlyvval__dut__DOT__dmem_arr__v3;
    CData/*0:0*/ __Vdlyvset__dut__DOT__dmem_arr__v3;
    CData/*7:0*/ __Vdlyvdim0__dut__DOT__dmem_arr__v4;
    CData/*0:0*/ __Vdlyvset__dut__DOT__dmem_arr__v4;
    IData/*31:0*/ __Vdlyvval__dut__DOT__dmem_arr__v4;
    // Body
    if (vlTOPp->i_dmem_wr_en) {
        vlTOPp->dut__DOT__i = 4U;
    }
    __Vdlyvset__dut__DOT__dmem_arr__v0 = 0U;
    __Vdlyvset__dut__DOT__dmem_arr__v1 = 0U;
    __Vdlyvset__dut__DOT__dmem_arr__v2 = 0U;
    __Vdlyvset__dut__DOT__dmem_arr__v3 = 0U;
    __Vdlyvset__dut__DOT__dmem_arr__v4 = 0U;
    if (vlTOPp->i_dmem_wr_en) {
        if ((1U & (IData)(vlTOPp->i_dmem_byte_sel))) {
            __Vdlyvval__dut__DOT__dmem_arr__v0 = (0xffU 
                                                  & vlTOPp->i_dmem_data);
            __Vdlyvset__dut__DOT__dmem_arr__v0 = 1U;
            __Vdlyvlsb__dut__DOT__dmem_arr__v0 = 0U;
            __Vdlyvdim0__dut__DOT__dmem_arr__v0 = vlTOPp->i_dmem_addr;
        }
        if ((2U & (IData)(vlTOPp->i_dmem_byte_sel))) {
            __Vdlyvval__dut__DOT__dmem_arr__v1 = (0xffU 
                                                  & (vlTOPp->i_dmem_data 
                                                     >> 8U));
            __Vdlyvset__dut__DOT__dmem_arr__v1 = 1U;
            __Vdlyvlsb__dut__DOT__dmem_arr__v1 = 8U;
            __Vdlyvdim0__dut__DOT__dmem_arr__v1 = vlTOPp->i_dmem_addr;
        }
        if ((4U & (IData)(vlTOPp->i_dmem_byte_sel))) {
            __Vdlyvval__dut__DOT__dmem_arr__v2 = (0xffU 
                                                  & (vlTOPp->i_dmem_data 
                                                     >> 0x10U));
            __Vdlyvset__dut__DOT__dmem_arr__v2 = 1U;
            __Vdlyvlsb__dut__DOT__dmem_arr__v2 = 0x10U;
            __Vdlyvdim0__dut__DOT__dmem_arr__v2 = vlTOPp->i_dmem_addr;
        }
        if ((8U & (IData)(vlTOPp->i_dmem_byte_sel))) {
            __Vdlyvval__dut__DOT__dmem_arr__v3 = (0xffU 
                                                  & (vlTOPp->i_dmem_data 
                                                     >> 0x18U));
            __Vdlyvset__dut__DOT__dmem_arr__v3 = 1U;
            __Vdlyvlsb__dut__DOT__dmem_arr__v3 = 0x18U;
            __Vdlyvdim0__dut__DOT__dmem_arr__v3 = vlTOPp->i_dmem_addr;
        }
    } else {
        __Vdlyvval__dut__DOT__dmem_arr__v4 = vlTOPp->dut__DOT__dmem_arr
            [vlTOPp->i_dmem_addr];
        __Vdlyvset__dut__DOT__dmem_arr__v4 = 1U;
        __Vdlyvdim0__dut__DOT__dmem_arr__v4 = vlTOPp->i_dmem_addr;
    }
    if (__Vdlyvset__dut__DOT__dmem_arr__v0) {
        vlTOPp->dut__DOT__dmem_arr[__Vdlyvdim0__dut__DOT__dmem_arr__v0] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__dut__DOT__dmem_arr__v0))) 
                & vlTOPp->dut__DOT__dmem_arr[__Vdlyvdim0__dut__DOT__dmem_arr__v0]) 
               | ((IData)(__Vdlyvval__dut__DOT__dmem_arr__v0) 
                  << (IData)(__Vdlyvlsb__dut__DOT__dmem_arr__v0)));
    }
    if (__Vdlyvset__dut__DOT__dmem_arr__v1) {
        vlTOPp->dut__DOT__dmem_arr[__Vdlyvdim0__dut__DOT__dmem_arr__v1] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__dut__DOT__dmem_arr__v1))) 
                & vlTOPp->dut__DOT__dmem_arr[__Vdlyvdim0__dut__DOT__dmem_arr__v1]) 
               | ((IData)(__Vdlyvval__dut__DOT__dmem_arr__v1) 
                  << (IData)(__Vdlyvlsb__dut__DOT__dmem_arr__v1)));
    }
    if (__Vdlyvset__dut__DOT__dmem_arr__v2) {
        vlTOPp->dut__DOT__dmem_arr[__Vdlyvdim0__dut__DOT__dmem_arr__v2] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__dut__DOT__dmem_arr__v2))) 
                & vlTOPp->dut__DOT__dmem_arr[__Vdlyvdim0__dut__DOT__dmem_arr__v2]) 
               | ((IData)(__Vdlyvval__dut__DOT__dmem_arr__v2) 
                  << (IData)(__Vdlyvlsb__dut__DOT__dmem_arr__v2)));
    }
    if (__Vdlyvset__dut__DOT__dmem_arr__v3) {
        vlTOPp->dut__DOT__dmem_arr[__Vdlyvdim0__dut__DOT__dmem_arr__v3] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__dut__DOT__dmem_arr__v3))) 
                & vlTOPp->dut__DOT__dmem_arr[__Vdlyvdim0__dut__DOT__dmem_arr__v3]) 
               | ((IData)(__Vdlyvval__dut__DOT__dmem_arr__v3) 
                  << (IData)(__Vdlyvlsb__dut__DOT__dmem_arr__v3)));
    }
    if (__Vdlyvset__dut__DOT__dmem_arr__v4) {
        vlTOPp->dut__DOT__dmem_arr[__Vdlyvdim0__dut__DOT__dmem_arr__v4] 
            = __Vdlyvval__dut__DOT__dmem_arr__v4;
    }
}

VL_INLINE_OPT void Vdut::_combo__TOP__3(Vdut__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut::_combo__TOP__3\n"); );
    Vdut* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->o_dmem_data = vlTOPp->dut__DOT__dmem_arr
        [vlTOPp->i_dmem_addr];
}

void Vdut::_eval(Vdut__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut::_eval\n"); );
    Vdut* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__i_clk = vlTOPp->i_clk;
}

VL_INLINE_OPT QData Vdut::_change_request(Vdut__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut::_change_request\n"); );
    Vdut* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vdut::_change_request_1(Vdut__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut::_change_request_1\n"); );
    Vdut* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vdut::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((i_clk & 0xfeU))) {
        Verilated::overWidthError("i_clk");}
    if (VL_UNLIKELY((i_dmem_wr_en & 0xfeU))) {
        Verilated::overWidthError("i_dmem_wr_en");}
    if (VL_UNLIKELY((i_dmem_byte_sel & 0xf0U))) {
        Verilated::overWidthError("i_dmem_byte_sel");}
}
#endif  // VL_DEBUG
