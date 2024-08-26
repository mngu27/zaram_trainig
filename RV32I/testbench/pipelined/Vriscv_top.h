// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VRISCV_TOP_H_
#define _VRISCV_TOP_H_  // guard

#include "verilated_heavy.h"

//==========

class Vriscv_top__Syms;
class Vriscv_top_VerilatedVcd;


//----------

VL_MODULE(Vriscv_top) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(i_clk,0,0);
    VL_IN8(i_rstn,0,0);
    VL_OUT8(o_ctrl_mem_wr_enM,0,0);
    VL_OUT8(o_ctrl_mem_byte_selM,3,0);
    VL_OUT(o_instrF,31,0);
    VL_OUT(o_mem_readdataM,31,0);
    VL_OUT(o_PCF,31,0);
    VL_OUT(o_alu_resultM,31,0);
    VL_OUT(o_mem_writedataM,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*1:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_mux_selD;
        CData/*3:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_alu_ctrlD;
        CData/*0:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_alu_srcD;
        CData/*0:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_reg_wr_enE;
        CData/*0:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_result_srcE;
        CData/*1:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_mux_selE;
        CData/*0:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_mem_wr_enE;
        CData/*3:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_mem_byte_selE;
        CData/*4:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rs1_addrE;
        CData/*4:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rs2_addrE;
        CData/*4:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_addrE;
        CData/*1:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCSrcE;
        CData/*0:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_reg_wr_enM;
        CData/*0:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_result_srcM;
        CData/*4:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_addrM;
        CData/*0:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_reg_wr_enW;
        CData/*4:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_addrW;
        CData/*1:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_forwardAE;
        CData/*1:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_forwardBE;
        CData/*0:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_flushE;
        CData/*0:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__hazard_flushD;
        CData/*2:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__ctrl_src_immD;
        CData/*0:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_jalE;
        CData/*0:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_jalrE;
        CData/*0:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_branchE;
        CData/*3:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_ctrlE;
        CData/*0:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_alu_srcE;
        CData/*2:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__ctrl_funct3E;
        CData/*0:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__take_branch;
        CData/*1:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_memory__DOT__ctrl_mux_selM;
        CData/*0:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__ctrl_result_srcW;
        CData/*0:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_hazard_unit__DOT__lwStall;
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCD;
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCPlus4D;
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ExtImmD;
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__alu_resultE;
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__mem_writedataE;
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCTargetE;
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCPlus4E;
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ExtImmE;
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCPlus4M;
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__PCTargetM;
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__writedata_dataM;
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__regfile_rd_dataW;
        WData/*95:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_fetch__DOT__PC_concat_data[3];
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD;
        WData/*255:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR[8];
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__regfile_rs1_dataE;
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__regfile_rs2_dataE;
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__PCE;
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcAE;
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__SrcBE;
        WData/*95:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__srcA_concat_data[3];
        WData/*95:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__writedata_concat[3];
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_memory__DOT__PCPlus4M;
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_memory__DOT__PCTargetM;
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_memory__DOT__ExtImmM;
        WData/*127:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_memory__DOT__writedata_concat[4];
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__alu_resultW;
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__mem_readdataW;
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__PCPlus4W;
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__PCTargetW;
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__writeback_dataW;
        WData/*1023:0*/ riscv_top__DOT__u_riscv_imem__DOT__FILE_TEXT_MIF[32];
    };
    struct {
        WData/*1023:0*/ riscv_top__DOT__u_riscv_dmem__DOT__FILE_DATA_MIF[32];
        IData/*31:0*/ riscv_top__DOT__u_riscv_dmem__DOT__i;
        QData/*63:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__srcB_concat_data;
        QData/*63:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP;
        QData/*63:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__Writeback_concat_data;
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_fetch__DOT__u_riscv_mux_pc__DOT__mux_input_arr[3];
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_regfile__DOT__registers[32];
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_srcAE__DOT__mux_input_arr[3];
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_writedata__DOT__mux_input_arr[3];
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_mux_srcBE__DOT__mux_input_arr[2];
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_memory__DOT__u_riscv_mux_rd_data__DOT__mux_input_arr[4];
        IData/*31:0*/ riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_writeback__DOT__u_riscv_mux_result__DOT__mux_input_arr[2];
        IData/*31:0*/ riscv_top__DOT__u_riscv_imem__DOT__imem_arr[16384];
        IData/*31:0*/ riscv_top__DOT__u_riscv_dmem__DOT__dmem_arr[16384];
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*6:0*/ __Vtableidx1;
    CData/*6:0*/ __Vtableidx2;
    CData/*6:0*/ __Vtableidx3;
    CData/*3:0*/ __Vtableidx5;
    CData/*3:0*/ __Vtableidx6;
    CData/*0:0*/ __Vclklast__TOP__i_clk;
    CData/*0:0*/ __Vclklast__TOP__i_rstn;
    SData/*10:0*/ __Vtableidx4;
    IData/*31:0*/ __Vdly__riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__instrD;
    IData/*31:0*/ __Vchglast__TOP__o_mem_readdataM;
    CData/*0:0*/ __Vtablechg4[2048];
    CData/*0:0*/ __Vtablechg6[16];
    CData/*0:0*/ __Vm_traceActivity[4];
    static CData/*1:0*/ __Vtable1_riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_mux_selD[128];
    static CData/*2:0*/ __Vtable2_riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__ctrl_src_immD[128];
    static CData/*0:0*/ __Vtable3_riscv_top__DOT__u_riscv_pipelined_cpu__DOT__ctrl_alu_srcD[128];
    static WData/*255:0*/ __Vtable4_riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_decode__DOT__u_riscv_ctrl__DOT__DEBUG_INSTR[2048][8];
    static CData/*0:0*/ __Vtable5_riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__take_branch[16];
    static QData/*63:0*/ __Vtable6_riscv_top__DOT__u_riscv_pipelined_cpu__DOT__u_riscv_execute__DOT__u_riscv_alu__DOT__DEBUG_ALU_OP[16];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vriscv_top__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vriscv_top);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vriscv_top(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vriscv_top();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vriscv_top__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vriscv_top__Syms* symsp, bool first);
  private:
    static QData _change_request(Vriscv_top__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vriscv_top__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__7(Vriscv_top__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vriscv_top__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vriscv_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vriscv_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vriscv_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(Vriscv_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vriscv_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vriscv_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vriscv_top__Syms* __restrict vlSymsp);
    static void _settle__TOP__5(Vriscv_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
