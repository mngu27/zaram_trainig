// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdut__Syms.h"


void Vdut::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vdut__Syms* __restrict vlSymsp = static_cast<Vdut__Syms*>(userp);
    Vdut* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vdut::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vdut__Syms* __restrict vlSymsp = static_cast<Vdut__Syms*>(userp);
    Vdut* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlTOPp->i_clk));
        tracep->chgBit(oldp+1,(vlTOPp->i_rstn));
        tracep->chgCData(oldp+2,(vlTOPp->i_a),4);
        tracep->chgCData(oldp+3,(vlTOPp->i_b),4);
        tracep->chgCData(oldp+4,(vlTOPp->o_y),4);
    }
}

void Vdut::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vdut__Syms* __restrict vlSymsp = static_cast<Vdut__Syms*>(userp);
    Vdut* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
