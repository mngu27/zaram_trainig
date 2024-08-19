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
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0U])) {
            tracep->chgWData(oldp+0,(vlTOPp->dut__DOT__FILE_DATA_MIF),256);
        }
        tracep->chgBit(oldp+8,(vlTOPp->i_clk));
        tracep->chgBit(oldp+9,(vlTOPp->i_dmem_wr_en));
        tracep->chgCData(oldp+10,(vlTOPp->i_dmem_addr),8);
        tracep->chgIData(oldp+11,(vlTOPp->i_dmem_data),32);
        tracep->chgCData(oldp+12,(vlTOPp->i_dmem_byte_sel),4);
        tracep->chgIData(oldp+13,(vlTOPp->o_dmem_data),32);
        tracep->chgIData(oldp+14,(vlTOPp->dut__DOT__i),32);
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
