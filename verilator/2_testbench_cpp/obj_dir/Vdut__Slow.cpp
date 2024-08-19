// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "Vdut.h"
#include "Vdut__Syms.h"

//==========

VL_CTOR_IMP(Vdut) {
    Vdut__Syms* __restrict vlSymsp = __VlSymsp = new Vdut__Syms(this, name());
    Vdut* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vdut::__Vconfigure(Vdut__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vdut::~Vdut() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vdut::_eval_initial(Vdut__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut::_eval_initial\n"); );
    Vdut* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__i_clk = vlTOPp->i_clk;
    vlTOPp->__Vclklast__TOP__i_rstn = vlTOPp->i_rstn;
}

void Vdut::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut::final\n"); );
    // Variables
    Vdut__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vdut* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vdut::_eval_settle(Vdut__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut::_eval_settle\n"); );
    Vdut* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vdut::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut::_ctor_var_reset\n"); );
    // Body
    i_clk = VL_RAND_RESET_I(1);
    i_rstn = VL_RAND_RESET_I(1);
    i_a = VL_RAND_RESET_I(4);
    i_b = VL_RAND_RESET_I(4);
    o_y = VL_RAND_RESET_I(4);
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
