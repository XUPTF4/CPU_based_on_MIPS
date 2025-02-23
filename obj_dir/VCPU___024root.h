// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VCPU.h for the primary calling header

#ifndef VERILATED_VCPU___024ROOT_H_
#define VERILATED_VCPU___024ROOT_H_  // guard

#include "verilated.h"

class VCPU__Syms;

class VCPU___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*0:0*/ CPU__DOT__idu_jCe;
    CData/*4:0*/ CPU__DOT__idu_regbAddr;
    CData/*5:0*/ CPU__DOT__idu_op;
    CData/*4:0*/ CPU__DOT__idu_regcAddr;
    CData/*0:0*/ CPU__DOT__exu_regcWr;
    CData/*0:0*/ CPU__DOT__exu_readWr;
    CData/*0:0*/ CPU__DOT__mem_memCe;
    CData/*4:0*/ CPU__DOT__idu__DOT__rd_addr;
    CData/*0:0*/ CPU__DOT__idu__DOT__is_add;
    CData/*0:0*/ CPU__DOT__idu__DOT__is_sub;
    CData/*0:0*/ CPU__DOT__idu__DOT__is_and;
    CData/*0:0*/ CPU__DOT__idu__DOT__is_or;
    CData/*0:0*/ CPU__DOT__idu__DOT__is_xor;
    CData/*0:0*/ CPU__DOT__idu__DOT__is_sll;
    CData/*0:0*/ CPU__DOT__idu__DOT__is_srl;
    CData/*0:0*/ CPU__DOT__idu__DOT__is_sra;
    CData/*0:0*/ CPU__DOT__idu__DOT__is_addi;
    CData/*0:0*/ CPU__DOT__idu__DOT__is_andi;
    CData/*0:0*/ CPU__DOT__idu__DOT__is_ori;
    CData/*0:0*/ CPU__DOT__idu__DOT__is_xori;
    CData/*0:0*/ CPU__DOT__idu__DOT__is_lw;
    CData/*2:0*/ CPU__DOT__idu__DOT__OP1_SEL;
    CData/*2:0*/ CPU__DOT__idu__DOT__OP2_SEL;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __Vtrigrprev__TOP__rst;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ CPU__DOT__idu__DOT__imm;
    IData/*31:0*/ CPU__DOT__ifu_pc;
    IData/*31:0*/ CPU__DOT__idu_regaData;
    IData/*31:0*/ CPU__DOT__idu_regbData;
    IData/*31:0*/ CPU__DOT__idu_rt_data_o;
    IData/*31:0*/ CPU__DOT__exu_jAddr;
    IData/*31:0*/ CPU__DOT__instMem_data;
    IData/*31:0*/ CPU__DOT__dataMem_rdData;
    IData/*31:0*/ CPU__DOT__idu__DOT__s_imm;
    IData/*31:0*/ CPU__DOT__exu__DOT__alu_out;
    IData/*31:0*/ CPU__DOT__data_mem__DOT__temp_mem_data;
    IData/*31:0*/ __VdfgTmp_h991cba0a__0;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 1024> CPU__DOT__instMem__DOT__mem;
    VlUnpacked<IData/*31:0*/, 32> CPU__DOT__regs__DOT__registers;
    VlUnpacked<IData/*31:0*/, 1024> CPU__DOT__data_mem__DOT__memory;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    VCPU__Syms* const vlSymsp;

    // CONSTRUCTORS
    VCPU___024root(VCPU__Syms* symsp, const char* v__name);
    ~VCPU___024root();
    VL_UNCOPYABLE(VCPU___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
