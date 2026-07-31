// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtb_cpu_scoreboard__pch.h"
#include "Vtb_cpu_scoreboard.h"
#include "Vtb_cpu_scoreboard___024root.h"

// FUNCTIONS
Vtb_cpu_scoreboard__Syms::~Vtb_cpu_scoreboard__Syms()
{
}

Vtb_cpu_scoreboard__Syms::Vtb_cpu_scoreboard__Syms(VerilatedContext* contextp, const char* namep, Vtb_cpu_scoreboard* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(42);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_tb_cpu_scoreboard.configure(this, name(), "tb_cpu_scoreboard", "tb_cpu_scoreboard", "<null>", -9, VerilatedScope::SCOPE_OTHER);
    __Vscope_tb_cpu_scoreboard__unnamedblk1.configure(this, name(), "tb_cpu_scoreboard.unnamedblk1", "unnamedblk1", "<null>", -9, VerilatedScope::SCOPE_OTHER);
}
