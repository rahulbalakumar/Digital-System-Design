// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_cpu_scoreboard.h for the primary calling header

#include "Vtb_cpu_scoreboard__pch.h"
#include "Vtb_cpu_scoreboard___024root.h"

VL_ATTR_COLD void Vtb_cpu_scoreboard___024root___eval_static(Vtb_cpu_scoreboard___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cpu_scoreboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu_scoreboard___024root___eval_static\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_cpu_scoreboard___024root___eval_initial__TOP(Vtb_cpu_scoreboard___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cpu_scoreboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu_scoreboard___024root___eval_initial__TOP\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_cpu_scoreboard__DOT__clk = 0U;
}

VL_ATTR_COLD void Vtb_cpu_scoreboard___024root___eval_final(Vtb_cpu_scoreboard___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cpu_scoreboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu_scoreboard___024root___eval_final\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_cpu_scoreboard___024root___dump_triggers__stl(Vtb_cpu_scoreboard___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_cpu_scoreboard___024root___eval_phase__stl(Vtb_cpu_scoreboard___024root* vlSelf);

VL_ATTR_COLD void Vtb_cpu_scoreboard___024root___eval_settle(Vtb_cpu_scoreboard___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cpu_scoreboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu_scoreboard___024root___eval_settle\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtb_cpu_scoreboard___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_cpu_scoreboard.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_cpu_scoreboard___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_cpu_scoreboard___024root___dump_triggers__stl(Vtb_cpu_scoreboard___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cpu_scoreboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu_scoreboard___024root___dump_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_cpu_scoreboard___024root___stl_sequent__TOP__0(Vtb_cpu_scoreboard___024root* vlSelf);

VL_ATTR_COLD void Vtb_cpu_scoreboard___024root___eval_stl(Vtb_cpu_scoreboard___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cpu_scoreboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu_scoreboard___024root___eval_stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtb_cpu_scoreboard___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtb_cpu_scoreboard___024root___stl_sequent__TOP__0(Vtb_cpu_scoreboard___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cpu_scoreboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu_scoreboard___024root___stl_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_cpu_scoreboard__DOT__mem_read = 0U;
    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__alu_op = 0U;
    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__reg_wr_en = 0U;
    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__z_wr_en = 0U;
    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__y_wr_en = 0U;
    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__mar_wr_en = 0U;
    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__ir_wr_en = 0U;
    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__pc_wr_en = 0U;
    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__mdr_mem_wr_en = 0U;
    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__reg_wr_addr = 0U;
    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__imm_val = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state) 
                  >> 3U)))) {
        if ((4U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state))) {
            if ((2U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state))) {
                if ((1U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state))) {
                    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__alu_op = 0U;
                    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__z_wr_en = 1U;
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state)))) {
                    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__y_wr_en = 1U;
                }
            }
            if ((1U & (~ ((IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state)))) {
                    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__ir_wr_en = 1U;
                }
            }
        } else {
            if ((2U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state))) {
                if ((1U & (~ (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state)))) {
                    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__alu_op = 0U;
                    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__z_wr_en = 1U;
                }
            }
            if ((1U & (~ ((IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state))) {
                    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__y_wr_en = 1U;
                }
            }
        }
        if ((1U & (~ ((IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state))) {
                if ((1U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state))) {
                    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__pc_wr_en = 1U;
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state)))) {
                    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__imm_val = 1U;
                }
            }
        }
    }
    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__bus_sel = 0U;
    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__reg_rd_addr = 0U;
    if ((8U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state))) {
        if ((1U & (~ ((IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state))) {
                if ((1U & (~ (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state)))) {
                    vlSelfRef.tb_cpu_scoreboard__DOT__mem_read = 1U;
                    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__mdr_mem_wr_en = 1U;
                }
                if ((1U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state))) {
                    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__reg_wr_en = 1U;
                    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__reg_wr_addr 
                        = (7U & ((IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__ir_out) 
                                 >> 9U));
                    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__bus_sel = 3U;
                }
            } else {
                if ((1U & (~ (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state)))) {
                    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__reg_wr_en = 1U;
                    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__reg_wr_addr 
                        = (7U & ((IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__ir_out) 
                                 >> 9U));
                }
                vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__bus_sel 
                    = ((1U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state))
                        ? 4U : 2U);
            }
            if ((1U & (~ ((IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state))) {
                    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__mar_wr_en = 1U;
                    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__reg_rd_addr 
                        = (7U & ((IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__ir_out) 
                                 >> 6U));
                }
            }
        }
        vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__next_state 
            = ((4U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state))
                ? 0U : ((2U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state))
                         ? ((1U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state))
                             ? 0U : 0xbU) : ((1U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state))
                                              ? 0xaU
                                              : 0U)));
    } else {
        if ((1U & (~ ((IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state) 
                          >> 1U)))) {
                if ((1U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state))) {
                    vlSelfRef.tb_cpu_scoreboard__DOT__mem_read = 1U;
                    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__mdr_mem_wr_en = 1U;
                }
                if ((1U & (~ (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state)))) {
                    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__mar_wr_en = 1U;
                }
            }
        }
        if ((4U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state))) {
            if ((2U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state))) {
                if ((1U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state))) {
                    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__next_state = 8U;
                    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__reg_rd_addr 
                        = (7U & ((IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__ir_out) 
                                 >> 3U));
                } else {
                    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__next_state = 7U;
                    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__reg_rd_addr 
                        = (7U & ((IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__ir_out) 
                                 >> 6U));
                }
                vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__bus_sel = 4U;
            } else {
                vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__next_state 
                    = ((1U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state))
                        ? ((1U == (0xfU & ((IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__ir_out) 
                                           >> 0xcU)))
                            ? 6U : ((2U == (0xfU & 
                                            ((IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__ir_out) 
                                             >> 0xcU)))
                                     ? 9U : 0U)) : 5U);
                if ((1U & (~ (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state)))) {
                    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__bus_sel = 3U;
                }
            }
        } else if ((2U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state))) {
            if ((1U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state))) {
                vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__next_state = 4U;
                vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__bus_sel = 2U;
            } else {
                vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__next_state = 3U;
                vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__bus_sel = 5U;
            }
        } else {
            vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__next_state 
                = ((1U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state))
                    ? 2U : 1U);
            vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__bus_sel = 1U;
        }
    }
    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__shared_bus 
        = ((4U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__bus_sel))
            ? ((2U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__bus_sel))
                ? 0U : ((1U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__bus_sel))
                         ? (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__imm_val)
                         : ((0U == (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__reg_rd_addr))
                             ? 0U : vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers
                            [vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__reg_rd_addr])))
            : ((2U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__bus_sel))
                ? ((1U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__bus_sel))
                    ? (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__mdr_out)
                    : (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__z_out))
                : ((1U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__bus_sel))
                    ? (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__pc_out)
                    : 0U)));
}

VL_ATTR_COLD void Vtb_cpu_scoreboard___024root___eval_triggers__stl(Vtb_cpu_scoreboard___024root* vlSelf);

VL_ATTR_COLD bool Vtb_cpu_scoreboard___024root___eval_phase__stl(Vtb_cpu_scoreboard___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cpu_scoreboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu_scoreboard___024root___eval_phase__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_cpu_scoreboard___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_cpu_scoreboard___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_cpu_scoreboard___024root___dump_triggers__act(Vtb_cpu_scoreboard___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cpu_scoreboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu_scoreboard___024root___dump_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_cpu_scoreboard.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge tb_cpu_scoreboard.rst_n)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_cpu_scoreboard___024root___dump_triggers__nba(Vtb_cpu_scoreboard___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cpu_scoreboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu_scoreboard___024root___dump_triggers__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_cpu_scoreboard.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge tb_cpu_scoreboard.rst_n)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_cpu_scoreboard___024root___ctor_var_reset(Vtb_cpu_scoreboard___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cpu_scoreboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu_scoreboard___024root___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->tb_cpu_scoreboard__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_cpu_scoreboard__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_cpu_scoreboard__DOT__mem_read = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->tb_cpu_scoreboard__DOT__ram[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->tb_cpu_scoreboard__DOT__dut__DOT__shared_bus = VL_RAND_RESET_I(16);
    vlSelf->tb_cpu_scoreboard__DOT__dut__DOT__pc_out = VL_RAND_RESET_I(16);
    vlSelf->tb_cpu_scoreboard__DOT__dut__DOT__ir_out = VL_RAND_RESET_I(16);
    vlSelf->tb_cpu_scoreboard__DOT__dut__DOT__mar_out = VL_RAND_RESET_I(16);
    vlSelf->tb_cpu_scoreboard__DOT__dut__DOT__y_out = VL_RAND_RESET_I(16);
    vlSelf->tb_cpu_scoreboard__DOT__dut__DOT__z_out = VL_RAND_RESET_I(16);
    vlSelf->tb_cpu_scoreboard__DOT__dut__DOT__mdr_out = VL_RAND_RESET_I(16);
    vlSelf->tb_cpu_scoreboard__DOT__dut__DOT__bus_sel = VL_RAND_RESET_I(3);
    vlSelf->tb_cpu_scoreboard__DOT__dut__DOT__imm_val = VL_RAND_RESET_I(16);
    vlSelf->tb_cpu_scoreboard__DOT__dut__DOT__pc_wr_en = VL_RAND_RESET_I(1);
    vlSelf->tb_cpu_scoreboard__DOT__dut__DOT__ir_wr_en = VL_RAND_RESET_I(1);
    vlSelf->tb_cpu_scoreboard__DOT__dut__DOT__mar_wr_en = VL_RAND_RESET_I(1);
    vlSelf->tb_cpu_scoreboard__DOT__dut__DOT__y_wr_en = VL_RAND_RESET_I(1);
    vlSelf->tb_cpu_scoreboard__DOT__dut__DOT__z_wr_en = VL_RAND_RESET_I(1);
    vlSelf->tb_cpu_scoreboard__DOT__dut__DOT__mdr_mem_wr_en = VL_RAND_RESET_I(1);
    vlSelf->tb_cpu_scoreboard__DOT__dut__DOT__reg_wr_en = VL_RAND_RESET_I(1);
    vlSelf->tb_cpu_scoreboard__DOT__dut__DOT__reg_rd_addr = VL_RAND_RESET_I(3);
    vlSelf->tb_cpu_scoreboard__DOT__dut__DOT__reg_wr_addr = VL_RAND_RESET_I(3);
    vlSelf->tb_cpu_scoreboard__DOT__dut__DOT__alu_op = VL_RAND_RESET_I(3);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state = VL_RAND_RESET_I(4);
    vlSelf->tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__next_state = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigprevexpr___TOP__tb_cpu_scoreboard__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_cpu_scoreboard__DOT__rst_n__0 = VL_RAND_RESET_I(1);
}
