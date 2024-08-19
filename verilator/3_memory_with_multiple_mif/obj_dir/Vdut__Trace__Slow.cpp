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
        tracep->declBit(c+9,"i_clk", false,-1);
        tracep->declBit(c+10,"i_dmem_wr_en", false,-1);
        tracep->declBus(c+11,"i_dmem_addr", false,-1, 7,0);
        tracep->declBus(c+12,"i_dmem_data", false,-1, 31,0);
        tracep->declBus(c+13,"i_dmem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+14,"o_dmem_data", false,-1, 31,0);
        tracep->declBit(c+9,"dut i_clk", false,-1);
        tracep->declBit(c+10,"dut i_dmem_wr_en", false,-1);
        tracep->declBus(c+11,"dut i_dmem_addr", false,-1, 7,0);
        tracep->declBus(c+12,"dut i_dmem_data", false,-1, 31,0);
        tracep->declBus(c+13,"dut i_dmem_byte_sel", false,-1, 3,0);
        tracep->declBus(c+14,"dut o_dmem_data", false,-1, 31,0);
        tracep->declArray(c+1,"dut FILE_DATA_MIF", false,-1, 255,0);
        tracep->declBus(c+15,"dut i", false,-1, 31,0);
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
        tracep->fullWData(oldp+1,(vlTOPp->dut__DOT__FILE_DATA_MIF),256);
        tracep->fullBit(oldp+9,(vlTOPp->i_clk));
        tracep->fullBit(oldp+10,(vlTOPp->i_dmem_wr_en));
        tracep->fullCData(oldp+11,(vlTOPp->i_dmem_addr),8);
        tracep->fullIData(oldp+12,(vlTOPp->i_dmem_data),32);
        tracep->fullCData(oldp+13,(vlTOPp->i_dmem_byte_sel),4);
        tracep->fullIData(oldp+14,(vlTOPp->o_dmem_data),32);
        tracep->fullIData(oldp+15,(vlTOPp->dut__DOT__i),32);
    }
}
