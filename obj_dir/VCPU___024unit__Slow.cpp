// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCPU.h for the primary calling header

#include "verilated.h"

#include "VCPU__Syms.h"
#include "VCPU___024unit.h"

void VCPU___024unit___ctor_var_reset(VCPU___024unit* vlSelf);

VCPU___024unit::VCPU___024unit(VCPU__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VCPU___024unit___ctor_var_reset(this);
}

void VCPU___024unit::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VCPU___024unit::~VCPU___024unit() {
}
