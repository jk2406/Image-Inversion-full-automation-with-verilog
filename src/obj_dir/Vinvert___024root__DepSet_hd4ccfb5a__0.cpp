// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vinvert.h for the primary calling header

#include "Vinvert__pch.h"
#include "Vinvert__Syms.h"
#include "Vinvert___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vinvert___024root___dump_triggers__act(Vinvert___024root* vlSelf);
#endif  // VL_DEBUG

void Vinvert___024root___eval_triggers__act(Vinvert___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinvert___024root___eval_triggers__act\n"); );
    Vinvert__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vinvert___024root___dump_triggers__act(vlSelf);
    }
#endif
}
