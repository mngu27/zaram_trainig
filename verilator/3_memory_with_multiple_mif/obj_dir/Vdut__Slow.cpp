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

void Vdut::_initial__TOP__2(Vdut__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut::_initial__TOP__2\n"); );
    Vdut* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*95:0*/ __Vtemp1[3];
    // Body
    __Vtemp1[0U] = 0x663d2573U;
    __Vtemp1[1U] = 0x615f6d69U;
    __Vtemp1[2U] = 0x646174U;
    (void)VL_VALUEPLUSARGS_INW(256,VL_CVT_PACK_STR_NW(3, __Vtemp1),
                               vlTOPp->dut__DOT__FILE_DATA_MIF);VL_READMEM_N(true
                                                                             , 32
                                                                             , 256
                                                                             , 0
                                                                             , 
                                                                             VL_CVT_PACK_STR_NW(8, vlTOPp->dut__DOT__FILE_DATA_MIF)
                                                                             , vlTOPp->dut__DOT__dmem_arr
                                                                             , 0
                                                                             , ~0ULL);
}

void Vdut::_eval_initial(Vdut__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut::_eval_initial\n"); );
    Vdut* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__i_clk = vlTOPp->i_clk;
    vlTOPp->_initial__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity[0U] = 1U;
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
    // Body
    vlTOPp->_combo__TOP__3(vlSymsp);
}

void Vdut::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut::_ctor_var_reset\n"); );
    // Body
    i_clk = VL_RAND_RESET_I(1);
    i_dmem_wr_en = VL_RAND_RESET_I(1);
    i_dmem_addr = VL_RAND_RESET_I(8);
    i_dmem_data = VL_RAND_RESET_I(32);
    i_dmem_byte_sel = VL_RAND_RESET_I(4);
    o_dmem_data = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
            dut__DOT__dmem_arr[__Vi0] = VL_RAND_RESET_I(32);
    }}
    VL_RAND_RESET_W(256, dut__DOT__FILE_DATA_MIF);
    dut__DOT__i = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
