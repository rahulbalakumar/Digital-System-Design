// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_cpu_scoreboard.h for the primary calling header

#include "Vtb_cpu_scoreboard__pch.h"
#include "Vtb_cpu_scoreboard___024root.h"

VL_ATTR_COLD void Vtb_cpu_scoreboard___024root___eval_initial__TOP(Vtb_cpu_scoreboard___024root* vlSelf);
VlCoroutine Vtb_cpu_scoreboard___024root___eval_initial__TOP__Vtiming__0(Vtb_cpu_scoreboard___024root* vlSelf);
VlCoroutine Vtb_cpu_scoreboard___024root___eval_initial__TOP__Vtiming__1(Vtb_cpu_scoreboard___024root* vlSelf);

void Vtb_cpu_scoreboard___024root___eval_initial(Vtb_cpu_scoreboard___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cpu_scoreboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu_scoreboard___024root___eval_initial\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_cpu_scoreboard___024root___eval_initial__TOP(vlSelf);
    Vtb_cpu_scoreboard___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_cpu_scoreboard___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__tb_cpu_scoreboard__DOT__clk__0 
        = vlSelfRef.tb_cpu_scoreboard__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_cpu_scoreboard__DOT__rst_n__0 
        = vlSelfRef.tb_cpu_scoreboard__DOT__rst_n;
}

VL_INLINE_OPT VlCoroutine Vtb_cpu_scoreboard___024root___eval_initial__TOP__Vtiming__1(Vtb_cpu_scoreboard___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cpu_scoreboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu_scoreboard___024root___eval_initial__TOP__Vtiming__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(0x1388ULL, 
                                             nullptr, 
                                             "tb/tb_cpu_scoreboard.sv", 
                                             17);
        vlSelfRef.tb_cpu_scoreboard__DOT__clk = (1U 
                                                 & (~ (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__clk)));
    }
}

void Vtb_cpu_scoreboard___024root___act_sequent__TOP__0(Vtb_cpu_scoreboard___024root* vlSelf);

void Vtb_cpu_scoreboard___024root___eval_act(Vtb_cpu_scoreboard___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cpu_scoreboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu_scoreboard___024root___eval_act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtb_cpu_scoreboard___024root___act_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtb_cpu_scoreboard___024root___act_sequent__TOP__0(Vtb_cpu_scoreboard___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cpu_scoreboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu_scoreboard___024root___act_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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

void Vtb_cpu_scoreboard___024root___nba_sequent__TOP__0(Vtb_cpu_scoreboard___024root* vlSelf);

void Vtb_cpu_scoreboard___024root___eval_nba(Vtb_cpu_scoreboard___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cpu_scoreboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu_scoreboard___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_cpu_scoreboard___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((7ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_cpu_scoreboard___024root___act_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtb_cpu_scoreboard___024root___nba_sequent__TOP__0(Vtb_cpu_scoreboard___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cpu_scoreboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu_scoreboard___024root___nba_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ __VdlyVal__tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers__v0;
    __VdlyVal__tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers__v0 = 0;
    CData/*2:0*/ __VdlyDim0__tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers__v0;
    __VdlyDim0__tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers__v0;
    __VdlySet__tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers__v1;
    __VdlySet__tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers__v1 = 0;
    // Body
    __VdlySet__tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers__v0 = 0U;
    __VdlySet__tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers__v1 = 0U;
    if (vlSelfRef.tb_cpu_scoreboard__DOT__rst_n) {
        if (vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__reg_wr_en) {
            if ((0U != (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__reg_wr_addr))) {
                __VdlyVal__tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers__v0 
                    = vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__shared_bus;
                __VdlyDim0__tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers__v0 
                    = vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__reg_wr_addr;
                __VdlySet__tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers__v0 = 1U;
            }
        }
        if (vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__pc_wr_en) {
            vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__pc_out 
                = vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__shared_bus;
        }
        if (vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__ir_wr_en) {
            vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__ir_out 
                = vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__shared_bus;
        }
        if (vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__mdr_mem_wr_en) {
            vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__mdr_out 
                = ((IData)(vlSelfRef.tb_cpu_scoreboard__DOT__mem_read)
                    ? vlSelfRef.tb_cpu_scoreboard__DOT__ram
                   [(0xffU & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__mar_out))]
                    : 0U);
        }
        if (vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__z_wr_en) {
            vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__z_out 
                = (0xffffU & ((4U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__alu_op))
                               ? ((2U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__alu_op))
                                   ? 0U : ((1U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__alu_op))
                                            ? (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__shared_bus)
                                            : (~ (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__shared_bus))))
                               : ((2U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__alu_op))
                                   ? ((1U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__alu_op))
                                       ? ((IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__y_out) 
                                          | (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__shared_bus))
                                       : ((IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__y_out) 
                                          & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__shared_bus)))
                                   : ((1U & (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__alu_op))
                                       ? ((IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__y_out) 
                                          - (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__shared_bus))
                                       : ((IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__y_out) 
                                          + (IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__shared_bus))))));
        }
        vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state 
            = vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__next_state;
        if (vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__mar_wr_en) {
            vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__mar_out 
                = vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__shared_bus;
        }
        if (vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__y_wr_en) {
            vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__y_out 
                = vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__shared_bus;
        }
    } else {
        __VdlySet__tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers__v1 = 1U;
        vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__pc_out = 0U;
        vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__ir_out = 0U;
        vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__mdr_out = 0U;
        vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__z_out = 0U;
        vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_control_unit__DOT__current_state = 0U;
        vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__mar_out = 0U;
        vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__y_out = 0U;
    }
    if (__VdlySet__tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers__v0) {
        vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers[__VdlyDim0__tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers__v0] 
            = __VdlyVal__tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers__v0;
    }
    if (__VdlySet__tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers__v1) {
        vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers[0U] = 0U;
        vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers[1U] = 0U;
        vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers[2U] = 0U;
        vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers[3U] = 0U;
        vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers[4U] = 0U;
        vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers[5U] = 0U;
        vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers[6U] = 0U;
        vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__u_reg_file__DOT__registers[7U] = 0U;
    }
    vlSelfRef.tb_cpu_scoreboard__DOT__mem_read = 0U;
    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__alu_op = 0U;
    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__reg_wr_en = 0U;
    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__z_wr_en = 0U;
    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__ir_wr_en = 0U;
    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__pc_wr_en = 0U;
    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__mdr_mem_wr_en = 0U;
    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__reg_wr_addr = 0U;
    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__imm_val = 0U;
    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__bus_sel = 0U;
    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__reg_rd_addr = 0U;
    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__mar_wr_en = 0U;
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
                    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__reg_rd_addr 
                        = (7U & ((IData)(vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__ir_out) 
                                 >> 6U));
                    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__mar_wr_en = 1U;
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
    vlSelfRef.tb_cpu_scoreboard__DOT__dut__DOT__y_wr_en = 0U;
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
}

void Vtb_cpu_scoreboard___024root___timing_resume(Vtb_cpu_scoreboard___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cpu_scoreboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu_scoreboard___024root___timing_resume\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_cpu_scoreboard___024root___eval_triggers__act(Vtb_cpu_scoreboard___024root* vlSelf);

bool Vtb_cpu_scoreboard___024root___eval_phase__act(Vtb_cpu_scoreboard___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cpu_scoreboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu_scoreboard___024root___eval_phase__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_cpu_scoreboard___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtb_cpu_scoreboard___024root___timing_resume(vlSelf);
        Vtb_cpu_scoreboard___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_cpu_scoreboard___024root___eval_phase__nba(Vtb_cpu_scoreboard___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cpu_scoreboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu_scoreboard___024root___eval_phase__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_cpu_scoreboard___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_cpu_scoreboard___024root___dump_triggers__nba(Vtb_cpu_scoreboard___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_cpu_scoreboard___024root___dump_triggers__act(Vtb_cpu_scoreboard___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_cpu_scoreboard___024root___eval(Vtb_cpu_scoreboard___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cpu_scoreboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu_scoreboard___024root___eval\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_cpu_scoreboard___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_cpu_scoreboard.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_cpu_scoreboard___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/tb_cpu_scoreboard.sv", 3, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtb_cpu_scoreboard___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtb_cpu_scoreboard___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_cpu_scoreboard___024root___eval_debug_assertions(Vtb_cpu_scoreboard___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cpu_scoreboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cpu_scoreboard___024root___eval_debug_assertions\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
