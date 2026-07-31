// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_cpu_scoreboard.h for the primary calling header

#include "Vtb_cpu_scoreboard__pch.h"
#include "Vtb_cpu_scoreboard__Syms.h"
#include "Vtb_cpu_scoreboard___024root.h"

VL_INLINE_OPT VlCoroutine Vtb_cpu_scoreboard___024root___eval_initial__TOP__Vtiming__0(Vtb_cpu_scoreboard___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cpu_scoreboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu_scoreboard___024root___eval_initial__TOP__Vtiming__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ tb_cpu_scoreboard__DOT__unnamedblk1__DOT__expected_r1;
    tb_cpu_scoreboard__DOT__unnamedblk1__DOT__expected_r1 = 0;
    SData/*15:0*/ tb_cpu_scoreboard__DOT__unnamedblk1__DOT__expected_r2;
    tb_cpu_scoreboard__DOT__unnamedblk1__DOT__expected_r2 = 0;
    SData/*15:0*/ tb_cpu_scoreboard__DOT__unnamedblk1__DOT__expected_r3;
    tb_cpu_scoreboard__DOT__unnamedblk1__DOT__expected_r3 = 0;
    IData/*31:0*/ tb_cpu_scoreboard__DOT__unnamedblk1__DOT__errors;
    tb_cpu_scoreboard__DOT__unnamedblk1__DOT__errors = 0;
    IData/*31:0*/ tb_cpu_scoreboard__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i;
    tb_cpu_scoreboard__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 0;
    // Body
    tb_cpu_scoreboard__DOT__unnamedblk1__DOT__errors = 0U;
    vlSelfRef.tb_cpu_scoreboard__DOT__rst_n = 0U;
    tb_cpu_scoreboard__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i = 0U;
    while (VL_GTS_III(32, 0x100U, tb_cpu_scoreboard__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i)) {
        vlSelfRef.tb_cpu_scoreboard__DOT__ram[(0xffU 
                                               & tb_cpu_scoreboard__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i)] = 0U;
        tb_cpu_scoreboard__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i 
            = ((IData)(1U) + tb_cpu_scoreboard__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i);
    }
    vlSelfRef.tb_cpu_scoreboard__DOT__ram[0U] = 0x2340U;
    vlSelfRef.tb_cpu_scoreboard__DOT__ram[1U] = 0x2580U;
    vlSelfRef.tb_cpu_scoreboard__DOT__ram[2U] = 0x1650U;
    vlSelfRef.tb_cpu_scoreboard__DOT__ram[0xaU] = 0x78U;
    vlSelfRef.tb_cpu_scoreboard__DOT__ram[0xbU] = 0x82U;
    co_await vlSelfRef.__VdlySched.delay(0x4e20ULL, 
                                         nullptr, "tb/tb_cpu_scoreboard.sv", 
                                         57);
    vlSelfRef.tb_cpu_scoreboard__DOT__rst_n = 1U;
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "tb/tb_cpu_scoreboard.sv", 
                                         59);
    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers[5U] = 0xaU;
    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers[6U] = 0xbU;
    co_await vlSelfRef.__VdlySched.delay(0xf4240ULL, 
                                         nullptr, "tb/tb_cpu_scoreboard.sv", 
                                         64);
    VL_WRITEF_NX("---------------------------\n  RUNNING CPU SCOREBOARD   \n---------------------------\n",0);
    tb_cpu_scoreboard__DOT__unnamedblk1__DOT__expected_r1 
        = vlSelfRef.tb_cpu_scoreboard__DOT__ram[0xaU];
    tb_cpu_scoreboard__DOT__unnamedblk1__DOT__expected_r2 
        = vlSelfRef.tb_cpu_scoreboard__DOT__ram[0xbU];
    tb_cpu_scoreboard__DOT__unnamedblk1__DOT__expected_r3 
        = (0xffffU & ((IData)(tb_cpu_scoreboard__DOT__unnamedblk1__DOT__expected_r1) 
                      + (IData)(tb_cpu_scoreboard__DOT__unnamedblk1__DOT__expected_r2)));
    if (VL_LIKELY((vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers
                   [1U] == (IData)(tb_cpu_scoreboard__DOT__unnamedblk1__DOT__expected_r1)))) {
        VL_WRITEF_NX("[PASS] R1 check: Expected = %0#, Actual = %0#\n",0,
                     16,tb_cpu_scoreboard__DOT__unnamedblk1__DOT__expected_r1,
                     16,vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers
                     [1U]);
    } else {
        VL_WRITEF_NX("[%0t] %%Error: tb_cpu_scoreboard.sv:78: Assertion failed in %Ntb_cpu_scoreboard.unnamedblk1: [FAIL] R1 check : Expected = %0#, Actual = %0#\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     16,(IData)(tb_cpu_scoreboard__DOT__unnamedblk1__DOT__expected_r1),
                     16,vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers
                     [1U]);
        VL_STOP_MT("tb/tb_cpu_scoreboard.sv", 78, "");
        tb_cpu_scoreboard__DOT__unnamedblk1__DOT__errors 
            = ((IData)(1U) + tb_cpu_scoreboard__DOT__unnamedblk1__DOT__errors);
    }
    if (VL_LIKELY((vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers
                   [2U] == (IData)(tb_cpu_scoreboard__DOT__unnamedblk1__DOT__expected_r2)))) {
        VL_WRITEF_NX("[PASS] R2 check: Expected = %0#, Actual = %0#\n",0,
                     16,tb_cpu_scoreboard__DOT__unnamedblk1__DOT__expected_r2,
                     16,vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers
                     [2U]);
    } else {
        VL_WRITEF_NX("[%0t] %%Error: tb_cpu_scoreboard.sv:86: Assertion failed in %Ntb_cpu_scoreboard.unnamedblk1: [FAIL] R2 check : Expected = %0#, Actual = %0#\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     16,(IData)(tb_cpu_scoreboard__DOT__unnamedblk1__DOT__expected_r2),
                     16,vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers
                     [2U]);
        VL_STOP_MT("tb/tb_cpu_scoreboard.sv", 86, "");
        tb_cpu_scoreboard__DOT__unnamedblk1__DOT__errors 
            = ((IData)(1U) + tb_cpu_scoreboard__DOT__unnamedblk1__DOT__errors);
    }
    if (VL_LIKELY((vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers
                   [3U] == (IData)(tb_cpu_scoreboard__DOT__unnamedblk1__DOT__expected_r3)))) {
        VL_WRITEF_NX("[PASS] R3 (ADD) check: Expected = %0#, Actual = %0#\n",0,
                     16,tb_cpu_scoreboard__DOT__unnamedblk1__DOT__expected_r3,
                     16,vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers
                     [3U]);
    } else {
        VL_WRITEF_NX("[%0t] %%Error: tb_cpu_scoreboard.sv:94: Assertion failed in %Ntb_cpu_scoreboard.unnamedblk1: [FAIL] R3 (ADD) check : Expected = %0#, Actual = %0#\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     16,(IData)(tb_cpu_scoreboard__DOT__unnamedblk1__DOT__expected_r3),
                     16,vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers
                     [3U]);
        VL_STOP_MT("tb/tb_cpu_scoreboard.sv", 94, "");
        tb_cpu_scoreboard__DOT__unnamedblk1__DOT__errors 
            = ((IData)(1U) + tb_cpu_scoreboard__DOT__unnamedblk1__DOT__errors);
    }
    VL_WRITEF_NX("------------------------------\n",0);
    if ((0U == tb_cpu_scoreboard__DOT__unnamedblk1__DOT__errors)) {
        VL_WRITEF_NX("TESTBENCH STATUS: ALL TESTS PASSED!\n",0);
    } else {
        VL_WRITEF_NX("TESTBENCH STATUS: FAILED WITH %0d ERRORS!\n",0,
                     32,tb_cpu_scoreboard__DOT__unnamedblk1__DOT__errors);
    }
    VL_WRITEF_NX("------------------------------\n",0);
    VL_FINISH_MT("tb/tb_cpu_scoreboard.sv", 106, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_cpu_scoreboard___024root___dump_triggers__act(Vtb_cpu_scoreboard___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_cpu_scoreboard___024root___eval_triggers__act(Vtb_cpu_scoreboard___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cpu_scoreboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu_scoreboard___024root___eval_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.tb_cpu_scoreboard__DOT__clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_cpu_scoreboard__DOT__clk__0))));
    vlSelfRef.__VactTriggered.set(1U, ((~ (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__rst_n)) 
                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_cpu_scoreboard__DOT__rst_n__0)));
    vlSelfRef.__VactTriggered.set(2U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__tb_cpu_scoreboard__DOT__clk__0 
        = vlSelfRef.tb_cpu_scoreboard__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_cpu_scoreboard__DOT__rst_n__0 
        = vlSelfRef.tb_cpu_scoreboard__DOT__rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_cpu_scoreboard___024root___dump_triggers__act(vlSelf);
    }
#endif
}
