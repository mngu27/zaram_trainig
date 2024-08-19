// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdut__Syms.h"


//======================

void Vdut::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vdut::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vdut__Syms* __restrict vlSymsp = static_cast<Vdut__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vdut::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vdut::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vdut__Syms* __restrict vlSymsp = static_cast<Vdut__Syms*>(userp);
    Vdut* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vdut::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vdut__Syms* __restrict vlSymsp = static_cast<Vdut__Syms*>(userp);
    Vdut* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"i_clk", false,-1);
        tracep->declBit(c+2,"i_rstn", false,-1);
        tracep->declBus(c+3,"i_a", false,-1, 3,0);
        tracep->declBus(c+4,"i_b", false,-1, 3,0);
        tracep->declBus(c+5,"o_y", false,-1, 3,0);
        tracep->declBus(c+6,"dut BW_DATA", false,-1, 31,0);
        tracep->declBit(c+1,"dut i_clk", false,-1);
        tracep->declBit(c+2,"dut i_rstn", false,-1);
        tracep->declBus(c+3,"dut i_a", false,-1, 3,0);
        tracep->declBus(c+4,"dut i_b", false,-1, 3,0);
        tracep->declBus(c+5,"dut o_y", false,-1, 3,0);
    }
}

void Vdut::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vdut::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vdut__Syms* __restrict vlSymsp = static_cast<Vdut__Syms*>(userp);
    Vdut* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vdut::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vdut__Syms* __restrict vlSymsp = static_cast<Vdut__Syms*>(userp);
    Vdut* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->i_clk));
        tracep->fullBit(oldp+2,(vlTOPp->i_rstn));
        tracep->fullCData(oldp+3,(vlTOPp->i_a),4);
        tracep->fullCData(oldp+4,(vlTOPp->i_b),4);
        tracep->fullCData(oldp+5,(vlTOPp->o_y),4);
        tracep->fullIData(oldp+6,(4U),32);
    }
}
