// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VINVERT__SYMS_H_
#define VERILATED_VINVERT__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vinvert.h"

// INCLUDE MODULE CLASSES
#include "Vinvert___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vinvert__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vinvert* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vinvert___024root              TOP;

    // CONSTRUCTORS
    Vinvert__Syms(VerilatedContext* contextp, const char* namep, Vinvert* modelp);
    ~Vinvert__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
