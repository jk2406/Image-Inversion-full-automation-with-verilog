// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vinvert.h for the primary calling header

#include "Vinvert__pch.h"
#include "Vinvert___024root.h"

VL_ATTR_COLD void Vinvert___024root___eval_static(Vinvert___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinvert___024root___eval_static\n"); );
    Vinvert__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vinvert___024root___eval_initial__TOP(Vinvert___024root* vlSelf);

VL_ATTR_COLD void Vinvert___024root___eval_initial(Vinvert___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinvert___024root___eval_initial\n"); );
    Vinvert__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vinvert___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void Vinvert___024root___eval_initial__TOP(Vinvert___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinvert___024root___eval_initial__TOP\n"); );
    Vinvert__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ invert__DOT__fd;
    invert__DOT__fd = 0;
    IData/*31:0*/ invert__DOT__i;
    invert__DOT__i = 0;
    // Body
    VL_READMEM_N(true, 8, 1599420, 0, std::string{"test.hex"}
                 ,  &(vlSelfRef.invert__DOT__mem), 0
                 , ~0ULL);
    invert__DOT__i = 0U;
    while (VL_GTS_III(32, 0x1867bcU, invert__DOT__i)) {
        vlSelfRef.invert__DOT____Vlvbound_h75740e58__0 
            = (0xffU & (~ ((0x1867bbU >= (0x1fffffU 
                                          & invert__DOT__i))
                            ? vlSelfRef.invert__DOT__mem
                           [(0x1fffffU & invert__DOT__i)]
                            : 0U)));
        if (VL_LIKELY(((0x1867bbU >= (0x1fffffU & invert__DOT__i))))) {
            vlSelfRef.invert__DOT__out[(0x1fffffU & invert__DOT__i)] 
                = vlSelfRef.invert__DOT____Vlvbound_h75740e58__0;
        }
        invert__DOT__i = ((IData)(1U) + invert__DOT__i);
    }
    invert__DOT__fd = VL_FOPEN_NN(std::string{"output.hex"}
                                  , std::string{"w"});
    ;
    if (VL_UNLIKELY(((0U == invert__DOT__fd)))) {
        VL_WRITEF_NX("Cannot create output hex file!\n",0);
        VL_FINISH_MT("/mnt/d/SystemVerilog/VivadoCodes/ImageProcessingProjects/Affine/src/design.sv", 30, "");
    }
    invert__DOT__i = 0U;
    while (VL_GTS_III(32, 0x1867bcU, invert__DOT__i)) {
        VL_FWRITEF_NX(invert__DOT__fd,"%02x\n",0,8,
                      ((0x1867bbU >= (0x1fffffU & invert__DOT__i))
                        ? vlSelfRef.invert__DOT__out
                       [(0x1fffffU & invert__DOT__i)]
                        : 0U));
        invert__DOT__i = ((IData)(1U) + invert__DOT__i);
    }
    VL_FCLOSE_I(invert__DOT__fd); VL_WRITEF_NX("Inverted hex written to output.hex\n",0);
    VL_FINISH_MT("/mnt/d/SystemVerilog/VivadoCodes/ImageProcessingProjects/Affine/src/design.sv", 37, "");
}

VL_ATTR_COLD void Vinvert___024root___eval_final(Vinvert___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinvert___024root___eval_final\n"); );
    Vinvert__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vinvert___024root___eval_settle(Vinvert___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinvert___024root___eval_settle\n"); );
    Vinvert__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vinvert___024root___dump_triggers__act(Vinvert___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinvert___024root___dump_triggers__act\n"); );
    Vinvert__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vinvert___024root___dump_triggers__nba(Vinvert___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinvert___024root___dump_triggers__nba\n"); );
    Vinvert__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vinvert___024root___ctor_var_reset(Vinvert___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vinvert___024root___ctor_var_reset\n"); );
    Vinvert__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    for (int __Vi0 = 0; __Vi0 < 1599420; ++__Vi0) {
        vlSelf->invert__DOT__mem[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1599420; ++__Vi0) {
        vlSelf->invert__DOT__out[__Vi0] = 0;
    }
    vlSelf->invert__DOT____Vlvbound_h75740e58__0 = 0;
}
