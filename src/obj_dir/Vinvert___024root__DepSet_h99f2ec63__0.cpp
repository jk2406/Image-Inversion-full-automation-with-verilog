// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vinvert.h for the primary calling header

#include "Vinvert__pch.h"
#include "Vinvert___024root.h"

void Vinvert___024root___eval_act(Vinvert___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinvert___024root___eval_act\n"); );
    Vinvert__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vinvert___024root___eval_nba(Vinvert___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinvert___024root___eval_nba\n"); );
    Vinvert__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vinvert___024root___eval_triggers__act(Vinvert___024root* vlSelf);

bool Vinvert___024root___eval_phase__act(Vinvert___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinvert___024root___eval_phase__act\n"); );
    Vinvert__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<0> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vinvert___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vinvert___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vinvert___024root___eval_phase__nba(Vinvert___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinvert___024root___eval_phase__nba\n"); );
    Vinvert__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vinvert___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vinvert___024root___dump_triggers__nba(Vinvert___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vinvert___024root___dump_triggers__act(Vinvert___024root* vlSelf);
#endif  // VL_DEBUG

void Vinvert___024root___eval(Vinvert___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinvert___024root___eval\n"); );
    Vinvert__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vinvert___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/mnt/d/SystemVerilog/VivadoCodes/ImageProcessingProjects/Affine/src/design.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vinvert___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/mnt/d/SystemVerilog/VivadoCodes/ImageProcessingProjects/Affine/src/design.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vinvert___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vinvert___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vinvert___024root___eval_debug_assertions(Vinvert___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinvert___024root___eval_debug_assertions\n"); );
    Vinvert__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
