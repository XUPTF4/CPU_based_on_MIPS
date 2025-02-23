// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VCPU.h for the primary calling header

#ifndef VERILATED_VCPU___024UNIT_H_
#define VERILATED_VCPU___024UNIT_H_  // guard

#include "verilated.h"

class VCPU__Syms;

class VCPU___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    VCPU__Syms* const vlSymsp;

    // CONSTRUCTORS
    VCPU___024unit(VCPU__Syms* symsp, const char* v__name);
    ~VCPU___024unit();
    VL_UNCOPYABLE(VCPU___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
