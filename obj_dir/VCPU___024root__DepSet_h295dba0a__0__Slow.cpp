// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCPU.h for the primary calling header

#include "verilated.h"

#include "VCPU___024root.h"

VL_ATTR_COLD void VCPU___024root___eval_static(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_static\n"); );
}

VL_ATTR_COLD void VCPU___024root___eval_initial__TOP(VCPU___024root* vlSelf);

VL_ATTR_COLD void VCPU___024root___eval_initial(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_initial\n"); );
    // Body
    VCPU___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[3U] = 1U;
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__rst = vlSelf->rst;
}

VL_ATTR_COLD void VCPU___024root___eval_initial__TOP(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_h3f8126fa__0;
    // Body
    __Vtemp_h3f8126fa__0[0U] = 0x2e686578U;
    __Vtemp_h3f8126fa__0[1U] = 0x756d6d79U;
    __Vtemp_h3f8126fa__0[2U] = 0x746f5f64U;
    __Vtemp_h3f8126fa__0[3U] = 0x6174685fU;
    __Vtemp_h3f8126fa__0[4U] = 0x433a2f70U;
    VL_READMEM_N(true, 32, 1024, 0, VL_CVT_PACK_STR_NW(5, __Vtemp_h3f8126fa__0)
                 ,  &(vlSelf->CPU__DOT__instMem__DOT__mem)
                 , 0, ~0ULL);
    vlSelf->CPU__DOT__idu_jCe = 0U;
    vlSelf->CPU__DOT__exu_jAddr = 0U;
}

VL_ATTR_COLD void VCPU___024root___eval_final(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_final\n"); );
}

VL_ATTR_COLD void VCPU___024root___eval_triggers__stl(VCPU___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__stl(VCPU___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void VCPU___024root___eval_stl(VCPU___024root* vlSelf);

VL_ATTR_COLD void VCPU___024root___eval_settle(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        VCPU___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                VCPU___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/luyoung/CPU_based_on_MIPS/CPU/CPU.v", 2, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            VCPU___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__stl(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VCPU___024root___stl_sequent__TOP__0(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->__VdfgTmp_h991cba0a__0 = vlSelf->CPU__DOT__instMem__DOT__mem
        [(0x3ffU & vlSelf->CPU__DOT__ifu_pc)];
    if (vlSelf->rst) {
        vlSelf->CPU__DOT__idu__DOT__rd_addr = 0U;
        vlSelf->CPU__DOT__idu_regbAddr = 0U;
    } else {
        vlSelf->CPU__DOT__idu__DOT__rd_addr = (0x1fU 
                                               & (vlSelf->__VdfgTmp_h991cba0a__0 
                                                  >> 0xbU));
        vlSelf->CPU__DOT__idu_regbAddr = (0x1fU & (vlSelf->__VdfgTmp_h991cba0a__0 
                                                   >> 0x10U));
    }
    vlSelf->CPU__DOT__idu_rt_data_o = vlSelf->CPU__DOT__regs__DOT__registers
        [vlSelf->CPU__DOT__idu_regbAddr];
    vlSelf->CPU__DOT__idu__DOT__imm = ((IData)(vlSelf->rst)
                                        ? 0U : (0xffffU 
                                                & vlSelf->__VdfgTmp_h991cba0a__0));
    vlSelf->CPU__DOT__idu__DOT__s_imm = (((- (IData)(
                                                     (1U 
                                                      & ((~ (IData)(vlSelf->rst)) 
                                                         & (vlSelf->__VdfgTmp_h991cba0a__0 
                                                            >> 0xfU))))) 
                                          << 0x10U) 
                                         | (IData)(vlSelf->CPU__DOT__idu__DOT__imm));
    vlSelf->CPU__DOT__idu__DOT__is_lw = 0U;
    vlSelf->CPU__DOT__idu__DOT__is_addi = 0U;
    vlSelf->CPU__DOT__idu__DOT__is_andi = 0U;
    vlSelf->CPU__DOT__idu__DOT__is_ori = 0U;
    vlSelf->CPU__DOT__idu__DOT__is_xori = 0U;
    vlSelf->CPU__DOT__idu__DOT__is_add = 0U;
    vlSelf->CPU__DOT__idu__DOT__is_sub = 0U;
    vlSelf->CPU__DOT__idu__DOT__is_and = 0U;
    vlSelf->CPU__DOT__idu__DOT__is_or = 0U;
    vlSelf->CPU__DOT__idu__DOT__is_xor = 0U;
    vlSelf->CPU__DOT__instMem_data = ((IData)(vlSelf->rst)
                                       ? 0U : vlSelf->__VdfgTmp_h991cba0a__0);
    if ((0U == (0xfc0007c0U & vlSelf->CPU__DOT__instMem_data))) {
        vlSelf->CPU__DOT__idu_regcAddr = vlSelf->CPU__DOT__idu__DOT__rd_addr;
        if ((0x20U == (0x3fU & vlSelf->CPU__DOT__instMem_data))) {
            vlSelf->CPU__DOT__idu__DOT__is_add = 1U;
        }
        if ((0x20U != (0x3fU & vlSelf->CPU__DOT__instMem_data))) {
            if ((0x22U == (0x3fU & vlSelf->CPU__DOT__instMem_data))) {
                vlSelf->CPU__DOT__idu__DOT__is_sub = 1U;
            }
            if ((0x22U != (0x3fU & vlSelf->CPU__DOT__instMem_data))) {
                if ((0x24U == (0x3fU & vlSelf->CPU__DOT__instMem_data))) {
                    vlSelf->CPU__DOT__idu__DOT__is_and = 1U;
                }
                if ((0x24U != (0x3fU & vlSelf->CPU__DOT__instMem_data))) {
                    if ((0x25U == (0x3fU & vlSelf->CPU__DOT__instMem_data))) {
                        vlSelf->CPU__DOT__idu__DOT__is_or = 1U;
                    }
                    if ((0x25U != (0x3fU & vlSelf->CPU__DOT__instMem_data))) {
                        if ((0x26U == (0x3fU & vlSelf->CPU__DOT__instMem_data))) {
                            vlSelf->CPU__DOT__idu__DOT__is_xor = 1U;
                        }
                    }
                }
            }
        }
    } else {
        vlSelf->CPU__DOT__idu_regcAddr = ((0U == (0xffe00000U 
                                                  & vlSelf->CPU__DOT__instMem_data))
                                           ? (IData)(vlSelf->CPU__DOT__idu__DOT__rd_addr)
                                           : (IData)(vlSelf->CPU__DOT__idu_regbAddr));
    }
    vlSelf->CPU__DOT__idu__DOT__is_sll = 0U;
    vlSelf->CPU__DOT__idu__DOT__is_srl = 0U;
    vlSelf->CPU__DOT__idu__DOT__is_sra = 0U;
    if ((0U != (0xfc0007c0U & vlSelf->CPU__DOT__instMem_data))) {
        if ((0U != (0xffe00000U & vlSelf->CPU__DOT__instMem_data))) {
            if ((0x23U == (vlSelf->CPU__DOT__instMem_data 
                           >> 0x1aU))) {
                vlSelf->CPU__DOT__idu__DOT__is_lw = 1U;
            }
            if ((8U == (vlSelf->CPU__DOT__instMem_data 
                        >> 0x1aU))) {
                vlSelf->CPU__DOT__idu__DOT__is_addi = 1U;
            }
            if ((0xcU == (vlSelf->CPU__DOT__instMem_data 
                          >> 0x1aU))) {
                vlSelf->CPU__DOT__idu__DOT__is_andi = 1U;
            }
            if ((0xdU == (vlSelf->CPU__DOT__instMem_data 
                          >> 0x1aU))) {
                vlSelf->CPU__DOT__idu__DOT__is_ori = 1U;
            }
            if ((0xeU == (vlSelf->CPU__DOT__instMem_data 
                          >> 0x1aU))) {
                vlSelf->CPU__DOT__idu__DOT__is_xori = 1U;
            }
        }
        if ((0U == (0xffe00000U & vlSelf->CPU__DOT__instMem_data))) {
            if ((0U == (0x3fU & vlSelf->CPU__DOT__instMem_data))) {
                vlSelf->CPU__DOT__idu__DOT__is_sll = 1U;
            }
            if ((2U == (0x3fU & vlSelf->CPU__DOT__instMem_data))) {
                vlSelf->CPU__DOT__idu__DOT__is_srl = 1U;
            }
            if ((3U == (0x3fU & vlSelf->CPU__DOT__instMem_data))) {
                vlSelf->CPU__DOT__idu__DOT__is_sra = 1U;
            }
        }
    }
    vlSelf->CPU__DOT__exu_regcWr = ((~ (IData)(vlSelf->rst)) 
                                    & ((IData)(vlSelf->rst) 
                                       | (((((((((IData)(vlSelf->CPU__DOT__idu__DOT__is_add) 
                                                 | (IData)(vlSelf->CPU__DOT__idu__DOT__is_sub)) 
                                                | (IData)(vlSelf->CPU__DOT__idu__DOT__is_and)) 
                                               | (IData)(vlSelf->CPU__DOT__idu__DOT__is_or)) 
                                              | (IData)(vlSelf->CPU__DOT__idu__DOT__is_xor)) 
                                             | (IData)(vlSelf->CPU__DOT__idu__DOT__is_sll)) 
                                            | (IData)(vlSelf->CPU__DOT__idu__DOT__is_srl)) 
                                           | (IData)(vlSelf->CPU__DOT__idu__DOT__is_sra)) 
                                          | ((((((IData)(vlSelf->CPU__DOT__idu__DOT__is_addi) 
                                                 | (IData)(vlSelf->CPU__DOT__idu__DOT__is_andi)) 
                                                | (IData)(vlSelf->CPU__DOT__idu__DOT__is_ori)) 
                                               | (IData)(vlSelf->CPU__DOT__idu__DOT__is_xori)) 
                                              | (IData)(vlSelf->CPU__DOT__idu__DOT__is_lw)) 
                                             & ((IData)(vlSelf->CPU__DOT__idu__DOT__is_addi) 
                                                | ((IData)(vlSelf->CPU__DOT__idu__DOT__is_andi) 
                                                   | ((IData)(vlSelf->CPU__DOT__idu__DOT__is_ori) 
                                                      | (IData)(vlSelf->CPU__DOT__idu__DOT__is_xori))))))));
    vlSelf->CPU__DOT__exu_readWr = (((((((~ (IData)(vlSelf->rst)) 
                                         & (~ (IData)(vlSelf->CPU__DOT__idu__DOT__is_addi))) 
                                        & (~ (IData)(vlSelf->CPU__DOT__idu__DOT__is_andi))) 
                                       & (~ (IData)(vlSelf->CPU__DOT__idu__DOT__is_ori))) 
                                      & (~ (IData)(vlSelf->CPU__DOT__idu__DOT__is_xori))) 
                                     & (IData)(vlSelf->CPU__DOT__idu__DOT__is_lw)) 
                                    & ((~ ((((((((IData)(vlSelf->CPU__DOT__idu__DOT__is_add) 
                                                 | (IData)(vlSelf->CPU__DOT__idu__DOT__is_sub)) 
                                                | (IData)(vlSelf->CPU__DOT__idu__DOT__is_and)) 
                                               | (IData)(vlSelf->CPU__DOT__idu__DOT__is_or)) 
                                              | (IData)(vlSelf->CPU__DOT__idu__DOT__is_xor)) 
                                             | (IData)(vlSelf->CPU__DOT__idu__DOT__is_sll)) 
                                            | (IData)(vlSelf->CPU__DOT__idu__DOT__is_srl)) 
                                           | (IData)(vlSelf->CPU__DOT__idu__DOT__is_sra))) 
                                       & (((((IData)(vlSelf->CPU__DOT__idu__DOT__is_addi) 
                                             | (IData)(vlSelf->CPU__DOT__idu__DOT__is_andi)) 
                                            | (IData)(vlSelf->CPU__DOT__idu__DOT__is_ori)) 
                                           | (IData)(vlSelf->CPU__DOT__idu__DOT__is_xori)) 
                                          | (IData)(vlSelf->CPU__DOT__idu__DOT__is_lw))));
    vlSelf->CPU__DOT__mem_memCe = ((~ (IData)(vlSelf->rst)) 
                                   & (IData)(vlSelf->CPU__DOT__exu_readWr));
    if (vlSelf->rst) {
        vlSelf->CPU__DOT__idu_regcAddr = 0U;
        vlSelf->CPU__DOT__idu_op = 0U;
        vlSelf->CPU__DOT__idu__DOT__OP1_SEL = 0U;
    } else if (((((((((IData)(vlSelf->CPU__DOT__idu__DOT__is_add) 
                      | (IData)(vlSelf->CPU__DOT__idu__DOT__is_sub)) 
                     | (IData)(vlSelf->CPU__DOT__idu__DOT__is_and)) 
                    | (IData)(vlSelf->CPU__DOT__idu__DOT__is_or)) 
                   | (IData)(vlSelf->CPU__DOT__idu__DOT__is_xor)) 
                  | (IData)(vlSelf->CPU__DOT__idu__DOT__is_sll)) 
                 | (IData)(vlSelf->CPU__DOT__idu__DOT__is_srl)) 
                | (IData)(vlSelf->CPU__DOT__idu__DOT__is_sra))) {
        if (vlSelf->CPU__DOT__idu__DOT__is_add) {
            vlSelf->CPU__DOT__idu_regcAddr = vlSelf->CPU__DOT__idu__DOT__rd_addr;
            vlSelf->CPU__DOT__idu_op = 1U;
            vlSelf->CPU__DOT__idu__DOT__OP1_SEL = 1U;
        } else if (vlSelf->CPU__DOT__idu__DOT__is_sub) {
            vlSelf->CPU__DOT__idu_op = 2U;
            vlSelf->CPU__DOT__idu__DOT__OP1_SEL = 1U;
        } else if (vlSelf->CPU__DOT__idu__DOT__is_and) {
            vlSelf->CPU__DOT__idu_op = 3U;
            vlSelf->CPU__DOT__idu__DOT__OP1_SEL = 1U;
        } else if (vlSelf->CPU__DOT__idu__DOT__is_or) {
            vlSelf->CPU__DOT__idu_op = 4U;
            vlSelf->CPU__DOT__idu__DOT__OP1_SEL = 1U;
        } else if (vlSelf->CPU__DOT__idu__DOT__is_xor) {
            vlSelf->CPU__DOT__idu_op = 5U;
            vlSelf->CPU__DOT__idu__DOT__OP1_SEL = 1U;
        } else {
            vlSelf->CPU__DOT__idu_op = ((IData)(vlSelf->CPU__DOT__idu__DOT__is_sll)
                                         ? 6U : ((IData)(vlSelf->CPU__DOT__idu__DOT__is_srl)
                                                  ? 7U
                                                  : 8U));
            vlSelf->CPU__DOT__idu__DOT__OP1_SEL = 3U;
        }
    } else if ((((((IData)(vlSelf->CPU__DOT__idu__DOT__is_addi) 
                   | (IData)(vlSelf->CPU__DOT__idu__DOT__is_andi)) 
                  | (IData)(vlSelf->CPU__DOT__idu__DOT__is_ori)) 
                 | (IData)(vlSelf->CPU__DOT__idu__DOT__is_xori)) 
                | (IData)(vlSelf->CPU__DOT__idu__DOT__is_lw))) {
        if (vlSelf->CPU__DOT__idu__DOT__is_addi) {
            vlSelf->CPU__DOT__idu_op = 1U;
            vlSelf->CPU__DOT__idu__DOT__OP1_SEL = 1U;
        } else if (vlSelf->CPU__DOT__idu__DOT__is_andi) {
            vlSelf->CPU__DOT__idu_op = 3U;
            vlSelf->CPU__DOT__idu__DOT__OP1_SEL = 1U;
        } else if (vlSelf->CPU__DOT__idu__DOT__is_ori) {
            vlSelf->CPU__DOT__idu_op = 4U;
            vlSelf->CPU__DOT__idu__DOT__OP1_SEL = 1U;
        } else if (vlSelf->CPU__DOT__idu__DOT__is_xori) {
            vlSelf->CPU__DOT__idu_op = 5U;
            vlSelf->CPU__DOT__idu__DOT__OP1_SEL = 1U;
        } else if (vlSelf->CPU__DOT__idu__DOT__is_lw) {
            vlSelf->CPU__DOT__idu_op = 0xeU;
            vlSelf->CPU__DOT__idu__DOT__OP1_SEL = 1U;
        } else {
            vlSelf->CPU__DOT__idu_op = 0x11U;
            vlSelf->CPU__DOT__idu__DOT__OP1_SEL = 5U;
        }
    } else {
        vlSelf->CPU__DOT__idu_op = 0U;
        vlSelf->CPU__DOT__idu__DOT__OP1_SEL = 0U;
    }
    vlSelf->CPU__DOT__idu_regaData = ((4U & (IData)(vlSelf->CPU__DOT__idu__DOT__OP1_SEL))
                                       ? ((2U & (IData)(vlSelf->CPU__DOT__idu__DOT__OP1_SEL))
                                           ? 0U : (
                                                   (1U 
                                                    & (IData)(vlSelf->CPU__DOT__idu__DOT__OP1_SEL))
                                                    ? vlSelf->CPU__DOT__idu__DOT__s_imm
                                                    : 0U))
                                       : ((2U & (IData)(vlSelf->CPU__DOT__idu__DOT__OP1_SEL))
                                           ? ((1U & (IData)(vlSelf->CPU__DOT__idu__DOT__OP1_SEL))
                                               ? ((IData)(vlSelf->rst)
                                                   ? 0U
                                                   : 
                                                  (0x1fU 
                                                   & (vlSelf->__VdfgTmp_h991cba0a__0 
                                                      >> 6U)))
                                               : ((IData)(vlSelf->CPU__DOT__idu__DOT__imm) 
                                                  << 0x10U))
                                           : ((1U & (IData)(vlSelf->CPU__DOT__idu__DOT__OP1_SEL))
                                               ? vlSelf->CPU__DOT__regs__DOT__registers
                                              [((IData)(vlSelf->rst)
                                                 ? 0U
                                                 : 
                                                (0x1fU 
                                                 & (vlSelf->__VdfgTmp_h991cba0a__0 
                                                    >> 0x15U)))]
                                               : 0U)));
    vlSelf->CPU__DOT__idu__DOT__OP2_SEL = ((IData)(vlSelf->rst)
                                            ? 0U : 
                                           (((((((((IData)(vlSelf->CPU__DOT__idu__DOT__is_add) 
                                                   | (IData)(vlSelf->CPU__DOT__idu__DOT__is_sub)) 
                                                  | (IData)(vlSelf->CPU__DOT__idu__DOT__is_and)) 
                                                 | (IData)(vlSelf->CPU__DOT__idu__DOT__is_or)) 
                                                | (IData)(vlSelf->CPU__DOT__idu__DOT__is_xor)) 
                                               | (IData)(vlSelf->CPU__DOT__idu__DOT__is_sll)) 
                                              | (IData)(vlSelf->CPU__DOT__idu__DOT__is_srl)) 
                                             | (IData)(vlSelf->CPU__DOT__idu__DOT__is_sra))
                                             ? 2U : 
                                            ((((((IData)(vlSelf->CPU__DOT__idu__DOT__is_addi) 
                                                 | (IData)(vlSelf->CPU__DOT__idu__DOT__is_andi)) 
                                                | (IData)(vlSelf->CPU__DOT__idu__DOT__is_ori)) 
                                               | (IData)(vlSelf->CPU__DOT__idu__DOT__is_xori)) 
                                              | (IData)(vlSelf->CPU__DOT__idu__DOT__is_lw))
                                              ? ((IData)(vlSelf->CPU__DOT__idu__DOT__is_addi)
                                                  ? 5U
                                                  : 
                                                 ((IData)(vlSelf->CPU__DOT__idu__DOT__is_andi)
                                                   ? 6U
                                                   : 
                                                  ((IData)(vlSelf->CPU__DOT__idu__DOT__is_ori)
                                                    ? 6U
                                                    : 
                                                   ((IData)(vlSelf->CPU__DOT__idu__DOT__is_xori)
                                                     ? 6U
                                                     : 
                                                    ((IData)(vlSelf->CPU__DOT__idu__DOT__is_lw)
                                                      ? 7U
                                                      : 4U)))))
                                              : 0U)));
    vlSelf->CPU__DOT__idu_regbData = ((4U & (IData)(vlSelf->CPU__DOT__idu__DOT__OP2_SEL))
                                       ? ((2U & (IData)(vlSelf->CPU__DOT__idu__DOT__OP2_SEL))
                                           ? ((1U & (IData)(vlSelf->CPU__DOT__idu__DOT__OP2_SEL))
                                               ? vlSelf->CPU__DOT__idu__DOT__s_imm
                                               : (IData)(vlSelf->CPU__DOT__idu__DOT__imm))
                                           : ((1U & (IData)(vlSelf->CPU__DOT__idu__DOT__OP2_SEL))
                                               ? vlSelf->CPU__DOT__idu__DOT__s_imm
                                               : vlSelf->CPU__DOT__ifu_pc))
                                       : ((2U & (IData)(vlSelf->CPU__DOT__idu__DOT__OP2_SEL))
                                           ? ((1U & (IData)(vlSelf->CPU__DOT__idu__DOT__OP2_SEL))
                                               ? 4U
                                               : vlSelf->CPU__DOT__idu_rt_data_o)
                                           : ((1U & (IData)(vlSelf->CPU__DOT__idu__DOT__OP2_SEL))
                                               ? ((IData)(vlSelf->rst)
                                                   ? 0U
                                                   : 
                                                  (0x3ffffffU 
                                                   & vlSelf->__VdfgTmp_h991cba0a__0))
                                               : 0U)));
    if (vlSelf->rst) {
        vlSelf->CPU__DOT__exu__DOT__alu_out = 0U;
        vlSelf->CPU__DOT__exu_jAddr = 0U;
    } else if ((0x20U & (IData)(vlSelf->CPU__DOT__idu_op))) {
        vlSelf->CPU__DOT__exu__DOT__alu_out = 0U;
        vlSelf->CPU__DOT__exu_jAddr = 0U;
    } else if ((0x10U & (IData)(vlSelf->CPU__DOT__idu_op))) {
        if ((8U & (IData)(vlSelf->CPU__DOT__idu_op))) {
            vlSelf->CPU__DOT__exu__DOT__alu_out = 0U;
            vlSelf->CPU__DOT__exu_jAddr = 0U;
        } else if ((4U & (IData)(vlSelf->CPU__DOT__idu_op))) {
            if ((2U & (IData)(vlSelf->CPU__DOT__idu_op))) {
                vlSelf->CPU__DOT__exu__DOT__alu_out = 0U;
                vlSelf->CPU__DOT__exu_jAddr = 0U;
            } else if ((1U & (IData)(vlSelf->CPU__DOT__idu_op))) {
                vlSelf->CPU__DOT__exu__DOT__alu_out = 0U;
                vlSelf->CPU__DOT__exu_jAddr = 0U;
            } else {
                vlSelf->CPU__DOT__exu__DOT__alu_out 
                    = (vlSelf->CPU__DOT__idu_regaData 
                       + vlSelf->CPU__DOT__idu_regbData);
                vlSelf->CPU__DOT__exu_jAddr = ((0xf0000000U 
                                                & vlSelf->CPU__DOT__idu_regaData) 
                                               | (0xffffffcU 
                                                  & (vlSelf->CPU__DOT__idu_regbData 
                                                     << 2U)));
            }
        } else if ((2U & (IData)(vlSelf->CPU__DOT__idu_op))) {
            if ((1U & (IData)(vlSelf->CPU__DOT__idu_op))) {
                vlSelf->CPU__DOT__exu__DOT__alu_out = 0U;
                vlSelf->CPU__DOT__exu_jAddr = ((0xf0000000U 
                                                & vlSelf->CPU__DOT__idu_regaData) 
                                               | (0xffffffcU 
                                                  & (vlSelf->CPU__DOT__idu_regbData 
                                                     << 2U)));
            } else {
                vlSelf->CPU__DOT__exu__DOT__alu_out 
                    = vlSelf->CPU__DOT__idu_regaData;
                vlSelf->CPU__DOT__exu_jAddr = 0U;
            }
        } else {
            vlSelf->CPU__DOT__exu__DOT__alu_out = (
                                                   (1U 
                                                    & (IData)(vlSelf->CPU__DOT__idu_op))
                                                    ? 
                                                   ((vlSelf->CPU__DOT__idu_regaData 
                                                     << 2U) 
                                                    + vlSelf->CPU__DOT__idu_regbData)
                                                    : 
                                                   ((vlSelf->CPU__DOT__idu_regaData 
                                                     << 2U) 
                                                    + vlSelf->CPU__DOT__idu_regbData));
            vlSelf->CPU__DOT__exu_jAddr = vlSelf->CPU__DOT__exu__DOT__alu_out;
        }
    } else if ((8U & (IData)(vlSelf->CPU__DOT__idu_op))) {
        if ((4U & (IData)(vlSelf->CPU__DOT__idu_op))) {
            vlSelf->CPU__DOT__exu__DOT__alu_out = (
                                                   (2U 
                                                    & (IData)(vlSelf->CPU__DOT__idu_op))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelf->CPU__DOT__idu_op))
                                                     ? 
                                                    (vlSelf->CPU__DOT__idu_regaData 
                                                     + vlSelf->CPU__DOT__idu_regbData)
                                                     : 
                                                    (vlSelf->CPU__DOT__idu_regaData 
                                                     + vlSelf->CPU__DOT__idu_regbData))
                                                    : 0U);
            vlSelf->CPU__DOT__exu_jAddr = 0U;
        } else if ((2U & (IData)(vlSelf->CPU__DOT__idu_op))) {
            vlSelf->CPU__DOT__exu__DOT__alu_out = 0U;
            vlSelf->CPU__DOT__exu_jAddr = 0U;
        } else if ((1U & (IData)(vlSelf->CPU__DOT__idu_op))) {
            vlSelf->CPU__DOT__exu__DOT__alu_out = 0U;
            vlSelf->CPU__DOT__exu_jAddr = ((0xf0000000U 
                                            & vlSelf->CPU__DOT__idu_regaData) 
                                           | (0xffffffcU 
                                              & (vlSelf->CPU__DOT__idu_regbData 
                                                 << 2U)));
        } else {
            vlSelf->CPU__DOT__exu__DOT__alu_out = (
                                                   (0x1fU 
                                                    >= vlSelf->CPU__DOT__idu_regaData)
                                                    ? 
                                                   (vlSelf->CPU__DOT__idu_regbData 
                                                    >> vlSelf->CPU__DOT__idu_regaData)
                                                    : 0U);
            vlSelf->CPU__DOT__exu_jAddr = 0U;
        }
    } else {
        vlSelf->CPU__DOT__exu__DOT__alu_out = ((4U 
                                                & (IData)(vlSelf->CPU__DOT__idu_op))
                                                ? (
                                                   (2U 
                                                    & (IData)(vlSelf->CPU__DOT__idu_op))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelf->CPU__DOT__idu_op))
                                                     ? 
                                                    ((0x1fU 
                                                      >= vlSelf->CPU__DOT__idu_regaData)
                                                      ? 
                                                     (vlSelf->CPU__DOT__idu_regbData 
                                                      >> vlSelf->CPU__DOT__idu_regaData)
                                                      : 0U)
                                                     : 
                                                    ((0x1fU 
                                                      >= vlSelf->CPU__DOT__idu_regaData)
                                                      ? 
                                                     (vlSelf->CPU__DOT__idu_regbData 
                                                      << vlSelf->CPU__DOT__idu_regaData)
                                                      : 0U))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelf->CPU__DOT__idu_op))
                                                     ? 
                                                    (vlSelf->CPU__DOT__idu_regaData 
                                                     ^ vlSelf->CPU__DOT__idu_regbData)
                                                     : 
                                                    (vlSelf->CPU__DOT__idu_regaData 
                                                     | vlSelf->CPU__DOT__idu_regbData)))
                                                : (
                                                   (2U 
                                                    & (IData)(vlSelf->CPU__DOT__idu_op))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelf->CPU__DOT__idu_op))
                                                     ? 
                                                    (vlSelf->CPU__DOT__idu_regaData 
                                                     & vlSelf->CPU__DOT__idu_regbData)
                                                     : 
                                                    (vlSelf->CPU__DOT__idu_regaData 
                                                     - vlSelf->CPU__DOT__idu_regbData))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelf->CPU__DOT__idu_op))
                                                     ? 
                                                    (vlSelf->CPU__DOT__idu_regaData 
                                                     + vlSelf->CPU__DOT__idu_regbData)
                                                     : 0U)));
        vlSelf->CPU__DOT__exu_jAddr = 0U;
    }
    vlSelf->CPU__DOT__idu_jCe = (1U & ((~ ((IData)(vlSelf->CPU__DOT__idu_op) 
                                           >> 5U)) 
                                       & ((0x10U & (IData)(vlSelf->CPU__DOT__idu_op))
                                           ? ((~ ((IData)(vlSelf->CPU__DOT__idu_op) 
                                                  >> 3U)) 
                                              & ((4U 
                                                  & (IData)(vlSelf->CPU__DOT__idu_op))
                                                  ? (IData)(
                                                            (0U 
                                                             == 
                                                             (3U 
                                                              & (IData)(vlSelf->CPU__DOT__idu_op))))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlSelf->CPU__DOT__idu_op))
                                                   ? (IData)(vlSelf->CPU__DOT__idu_op)
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->CPU__DOT__idu_op))
                                                    ? 
                                                   (vlSelf->CPU__DOT__idu_regaData 
                                                    != vlSelf->CPU__DOT__idu_regbData)
                                                    : 
                                                   (vlSelf->CPU__DOT__idu_regaData 
                                                    == vlSelf->CPU__DOT__idu_regbData)))))
                                           : (IData)(
                                                     (9U 
                                                      == 
                                                      (0xfU 
                                                       & (IData)(vlSelf->CPU__DOT__idu_op)))))));
}

VL_ATTR_COLD void VCPU___024root___eval_stl(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        VCPU___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__ico(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__act(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or posedge rst)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__nba(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or posedge rst)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VCPU___024root___ctor_var_reset(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->CPU__DOT__ifu_pc = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__idu_regaData = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__idu_regbData = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__idu_jCe = VL_RAND_RESET_I(1);
    vlSelf->CPU__DOT__idu_regbAddr = VL_RAND_RESET_I(5);
    vlSelf->CPU__DOT__idu_op = VL_RAND_RESET_I(6);
    vlSelf->CPU__DOT__idu_regcAddr = VL_RAND_RESET_I(5);
    vlSelf->CPU__DOT__idu_rt_data_o = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__exu_regcWr = VL_RAND_RESET_I(1);
    vlSelf->CPU__DOT__exu_jAddr = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__exu_readWr = VL_RAND_RESET_I(1);
    vlSelf->CPU__DOT__mem_memCe = VL_RAND_RESET_I(1);
    vlSelf->CPU__DOT__instMem_data = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__dataMem_rdData = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->CPU__DOT__instMem__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->CPU__DOT__regs__DOT__registers[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->CPU__DOT__idu__DOT__rd_addr = VL_RAND_RESET_I(5);
    vlSelf->CPU__DOT__idu__DOT__imm = VL_RAND_RESET_I(16);
    vlSelf->CPU__DOT__idu__DOT__s_imm = VL_RAND_RESET_I(32);
    vlSelf->CPU__DOT__idu__DOT__is_add = VL_RAND_RESET_I(1);
    vlSelf->CPU__DOT__idu__DOT__is_sub = VL_RAND_RESET_I(1);
    vlSelf->CPU__DOT__idu__DOT__is_and = VL_RAND_RESET_I(1);
    vlSelf->CPU__DOT__idu__DOT__is_or = VL_RAND_RESET_I(1);
    vlSelf->CPU__DOT__idu__DOT__is_xor = VL_RAND_RESET_I(1);
    vlSelf->CPU__DOT__idu__DOT__is_sll = VL_RAND_RESET_I(1);
    vlSelf->CPU__DOT__idu__DOT__is_srl = VL_RAND_RESET_I(1);
    vlSelf->CPU__DOT__idu__DOT__is_sra = VL_RAND_RESET_I(1);
    vlSelf->CPU__DOT__idu__DOT__is_addi = VL_RAND_RESET_I(1);
    vlSelf->CPU__DOT__idu__DOT__is_andi = VL_RAND_RESET_I(1);
    vlSelf->CPU__DOT__idu__DOT__is_ori = VL_RAND_RESET_I(1);
    vlSelf->CPU__DOT__idu__DOT__is_xori = VL_RAND_RESET_I(1);
    vlSelf->CPU__DOT__idu__DOT__is_lw = VL_RAND_RESET_I(1);
    vlSelf->CPU__DOT__idu__DOT__OP1_SEL = VL_RAND_RESET_I(3);
    vlSelf->CPU__DOT__idu__DOT__OP2_SEL = VL_RAND_RESET_I(3);
    vlSelf->CPU__DOT__exu__DOT__alu_out = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->CPU__DOT__data_mem__DOT__memory[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->CPU__DOT__data_mem__DOT__temp_mem_data = VL_RAND_RESET_I(32);
    vlSelf->__VdfgTmp_h991cba0a__0 = 0;
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__rst = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
