// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vinvert__pch.h"

//============================================================
// Constructors

Vinvert::Vinvert(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vinvert__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vinvert::Vinvert(const char* _vcname__)
    : Vinvert(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vinvert::~Vinvert() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vinvert___024root___eval_debug_assertions(Vinvert___024root* vlSelf);
#endif  // VL_DEBUG
void Vinvert___024root___eval_static(Vinvert___024root* vlSelf);
void Vinvert___024root___eval_initial(Vinvert___024root* vlSelf);
void Vinvert___024root___eval_settle(Vinvert___024root* vlSelf);
void Vinvert___024root___eval(Vinvert___024root* vlSelf);

void Vinvert::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vinvert::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vinvert___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vinvert___024root___eval_static(&(vlSymsp->TOP));
        Vinvert___024root___eval_initial(&(vlSymsp->TOP));
        Vinvert___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vinvert___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vinvert::eventsPending() { return false; }

uint64_t Vinvert::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vinvert::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vinvert___024root___eval_final(Vinvert___024root* vlSelf);

VL_ATTR_COLD void Vinvert::final() {
    Vinvert___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vinvert::hierName() const { return vlSymsp->name(); }
const char* Vinvert::modelName() const { return "Vinvert"; }
unsigned Vinvert::threads() const { return 1; }
void Vinvert::prepareClone() const { contextp()->prepareClone(); }
void Vinvert::atClone() const {
    contextp()->threadPoolpOnClone();
}
