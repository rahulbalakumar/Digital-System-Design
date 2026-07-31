// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_cpu_scoreboard.h for the primary calling header

#include "Vtb_cpu_scoreboard__pch.h"
#include "Vtb_cpu_scoreboard__Syms.h"
#include "Vtb_cpu_scoreboard___024root.h"

void Vtb_cpu_scoreboard___024root___ctor_var_reset(Vtb_cpu_scoreboard___024root* vlSelf);

Vtb_cpu_scoreboard___024root::Vtb_cpu_scoreboard___024root(Vtb_cpu_scoreboard__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_cpu_scoreboard___024root___ctor_var_reset(this);
}

void Vtb_cpu_scoreboard___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_cpu_scoreboard___024root::~Vtb_cpu_scoreboard___024root() {
}
