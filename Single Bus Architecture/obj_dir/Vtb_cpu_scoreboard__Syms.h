// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTB_CPU_SCOREBOARD__SYMS_H_
#define VERILATED_VTB_CPU_SCOREBOARD__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtb_cpu_scoreboard.h"

// INCLUDE MODULE CLASSES
#include "Vtb_cpu_scoreboard___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtb_cpu_scoreboard__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtb_cpu_scoreboard* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtb_cpu_scoreboard___024root   TOP;

    // SCOPE NAMES
    VerilatedScope __Vscope_tb_cpu_scoreboard;
    VerilatedScope __Vscope_tb_cpu_scoreboard__unnamedblk1;

    // CONSTRUCTORS
    Vtb_cpu_scoreboard__Syms(VerilatedContext* contextp, const char* namep, Vtb_cpu_scoreboard* modelp);
    ~Vtb_cpu_scoreboard__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
