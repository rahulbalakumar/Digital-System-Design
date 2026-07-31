// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_cpu_scoreboard.h for the primary calling header

#ifndef VERILATED_VTB_CPU_SCOREBOARD___024ROOT_H_
#define VERILATED_VTB_CPU_SCOREBOARD___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_cpu_scoreboard__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_cpu_scoreboard___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_cpu_scoreboard__DOT__clk;
    CData/*0:0*/ tb_cpu_scoreboard__DOT__rst_n;
    CData/*0:0*/ tb_cpu_scoreboard__DOT__mem_read;
    CData/*2:0*/ tb_cpu_scoreboard__DOT__dut__DOT__bus_sel;
    CData/*0:0*/ tb_cpu_scoreboard__DOT__dut__DOT__pc_wr_en;
    CData/*0:0*/ tb_cpu_scoreboard__DOT__dut__DOT__ir_wr_en;
    CData/*0:0*/ tb_cpu_scoreboard__DOT__dut__DOT__mar_wr_en;
    CData/*0:0*/ tb_cpu_scoreboard__DOT__dut__DOT__y_wr_en;
    CData/*0:0*/ tb_cpu_scoreboard__DOT__dut__DOT__z_wr_en;
    CData/*0:0*/ tb_cpu_scoreboard__DOT__dut__DOT__mdr_mem_wr_en;
    CData/*0:0*/ tb_cpu_scoreboard__DOT__dut__DOT__reg_wr_en;
    CData/*2:0*/ tb_cpu_scoreboard__DOT__dut__DOT__reg_rd_addr;
    CData/*2:0*/ tb_cpu_scoreboard__DOT__dut__DOT__reg_wr_addr;
    CData/*2:0*/ tb_cpu_scoreboard__DOT__dut__DOT__alu_op;
    CData/*3:0*/ tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state;
    CData/*3:0*/ tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__next_state;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_cpu_scoreboard__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_cpu_scoreboard__DOT__rst_n__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ tb_cpu_scoreboard__DOT__dut__DOT__shared_bus;
    SData/*15:0*/ tb_cpu_scoreboard__DOT__dut__DOT__pc_out;
    SData/*15:0*/ tb_cpu_scoreboard__DOT__dut__DOT__ir_out;
    SData/*15:0*/ tb_cpu_scoreboard__DOT__dut__DOT__mar_out;
    SData/*15:0*/ tb_cpu_scoreboard__DOT__dut__DOT__y_out;
    SData/*15:0*/ tb_cpu_scoreboard__DOT__dut__DOT__z_out;
    SData/*15:0*/ tb_cpu_scoreboard__DOT__dut__DOT__mdr_out;
    SData/*15:0*/ tb_cpu_scoreboard__DOT__dut__DOT__imm_val;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<SData/*15:0*/, 256> tb_cpu_scoreboard__DOT__ram;
    VlUnpacked<SData/*15:0*/, 8> tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers;
    VlDelayScheduler __VdlySched;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_cpu_scoreboard__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_cpu_scoreboard___024root(Vtb_cpu_scoreboard__Syms* symsp, const char* v__name);
    ~Vtb_cpu_scoreboard___024root();
    VL_UNCOPYABLE(Vtb_cpu_scoreboard___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
