// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcounter__Syms.h"


//======================

void Vcounter::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vcounter::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vcounter__Syms* __restrict vlSymsp = static_cast<Vcounter__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vcounter::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vcounter::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vcounter__Syms* __restrict vlSymsp = static_cast<Vcounter__Syms*>(userp);
    Vcounter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vcounter::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vcounter__Syms* __restrict vlSymsp = static_cast<Vcounter__Syms*>(userp);
    Vcounter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"i_clk", false,-1);
        tracep->declBit(c+2,"i_rstn", false,-1);
        tracep->declBus(c+3,"o_cnt", false,-1, 4,0);
        tracep->declBus(c+4,"counter UPBND", false,-1, 31,0);
        tracep->declBit(c+1,"counter i_clk", false,-1);
        tracep->declBit(c+2,"counter i_rstn", false,-1);
        tracep->declBus(c+3,"counter o_cnt", false,-1, 4,0);
    }
}

void Vcounter::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vcounter::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vcounter__Syms* __restrict vlSymsp = static_cast<Vcounter__Syms*>(userp);
    Vcounter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vcounter::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vcounter__Syms* __restrict vlSymsp = static_cast<Vcounter__Syms*>(userp);
    Vcounter* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->i_clk));
        tracep->fullBit(oldp+2,(vlTOPp->i_rstn));
        tracep->fullCData(oldp+3,(vlTOPp->o_cnt),5);
        tracep->fullIData(oldp+4,(0x1fU),32);
    }
}
