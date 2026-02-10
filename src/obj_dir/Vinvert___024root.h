// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vinvert.h for the primary calling header

#ifndef VERILATED_VINVERT___024ROOT_H_
#define VERILATED_VINVERT___024ROOT_H_  // guard

#include "verilated.h"


class Vinvert__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vinvert___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*7:0*/ invert__DOT____Vlvbound_h75740e58__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 1599420> invert__DOT__mem;
    VlUnpacked<CData/*7:0*/, 1599420> invert__DOT__out;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vinvert__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vinvert___024root(Vinvert__Syms* symsp, const char* v__name);
    ~Vinvert___024root();
    VL_UNCOPYABLE(Vinvert___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
