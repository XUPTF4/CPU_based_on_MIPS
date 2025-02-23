// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCPU.h for the primary calling header

#include "verilated.h"

#include "VCPU___024root.h"

VL_INLINE_OPT void VCPU___024root___ico_sequent__TOP__0(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___ico_sequent__TOP__0\n"); );
    // Body
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

void VCPU___024root___eval_ico(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        VCPU___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void VCPU___024root___eval_act(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_act\n"); );
}

VL_INLINE_OPT void VCPU___024root___nba_sequent__TOP__0(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vdlyvset__CPU__DOT__regs__DOT__registers__v0;
    __Vdlyvset__CPU__DOT__regs__DOT__registers__v0 = 0;
    CData/*4:0*/ __Vdlyvdim0__CPU__DOT__regs__DOT__registers__v32;
    __Vdlyvdim0__CPU__DOT__regs__DOT__registers__v32 = 0;
    IData/*31:0*/ __Vdlyvval__CPU__DOT__regs__DOT__registers__v32;
    __Vdlyvval__CPU__DOT__regs__DOT__registers__v32 = 0;
    CData/*0:0*/ __Vdlyvset__CPU__DOT__regs__DOT__registers__v32;
    __Vdlyvset__CPU__DOT__regs__DOT__registers__v32 = 0;
    // Body
    __Vdlyvset__CPU__DOT__regs__DOT__registers__v0 = 0U;
    __Vdlyvset__CPU__DOT__regs__DOT__registers__v32 = 0U;
    if (vlSelf->rst) {
        __Vdlyvset__CPU__DOT__regs__DOT__registers__v0 = 1U;
    } else if (((~ (IData)(vlSelf->rst)) & (IData)(vlSelf->CPU__DOT__exu_regcWr))) {
        __Vdlyvval__CPU__DOT__regs__DOT__registers__v32 
            = ((IData)(vlSelf->CPU__DOT__exu_readWr)
                ? vlSelf->CPU__DOT__dataMem_rdData : vlSelf->CPU__DOT__exu__DOT__alu_out);
        __Vdlyvset__CPU__DOT__regs__DOT__registers__v32 = 1U;
        __Vdlyvdim0__CPU__DOT__regs__DOT__registers__v32 
            = vlSelf->CPU__DOT__idu_regcAddr;
    }
    if (__Vdlyvset__CPU__DOT__regs__DOT__registers__v0) {
        vlSelf->CPU__DOT__regs__DOT__registers[0U] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[1U] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[2U] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[3U] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[4U] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[5U] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[6U] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[7U] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[8U] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[9U] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[0xaU] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[0xbU] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[0xcU] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[0xdU] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[0xeU] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[0xfU] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[0x10U] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[0x11U] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[0x12U] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[0x13U] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[0x14U] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[0x15U] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[0x16U] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[0x17U] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[0x18U] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[0x19U] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[0x1aU] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[0x1bU] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[0x1cU] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[0x1dU] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[0x1eU] = 0U;
        vlSelf->CPU__DOT__regs__DOT__registers[0x1fU] = 0U;
    }
    if (__Vdlyvset__CPU__DOT__regs__DOT__registers__v32) {
        vlSelf->CPU__DOT__regs__DOT__registers[__Vdlyvdim0__CPU__DOT__regs__DOT__registers__v32] 
            = __Vdlyvval__CPU__DOT__regs__DOT__registers__v32;
    }
    vlSelf->CPU__DOT__ifu_pc = ((IData)(vlSelf->rst)
                                 ? 0U : ((IData)(vlSelf->CPU__DOT__idu_jCe)
                                          ? vlSelf->CPU__DOT__exu_jAddr
                                          : ((IData)(4U) 
                                             + vlSelf->CPU__DOT__ifu_pc)));
    vlSelf->__VdfgTmp_h991cba0a__0 = vlSelf->CPU__DOT__instMem__DOT__mem
        [(0x3ffU & vlSelf->CPU__DOT__ifu_pc)];
    if (vlSelf->rst) {
        vlSelf->CPU__DOT__idu__DOT__rd_addr = 0U;
        vlSelf->CPU__DOT__idu_regbAddr = 0U;
        vlSelf->CPU__DOT__idu__DOT__imm = 0U;
        vlSelf->CPU__DOT__instMem_data = 0U;
    } else {
        vlSelf->CPU__DOT__idu__DOT__rd_addr = (0x1fU 
                                               & (vlSelf->__VdfgTmp_h991cba0a__0 
                                                  >> 0xbU));
        vlSelf->CPU__DOT__idu_regbAddr = (0x1fU & (vlSelf->__VdfgTmp_h991cba0a__0 
                                                   >> 0x10U));
        vlSelf->CPU__DOT__idu__DOT__imm = (0xffffU 
                                           & vlSelf->__VdfgTmp_h991cba0a__0);
        vlSelf->CPU__DOT__instMem_data = vlSelf->__VdfgTmp_h991cba0a__0;
    }
    vlSelf->CPU__DOT__idu_rt_data_o = vlSelf->CPU__DOT__regs__DOT__registers
        [vlSelf->CPU__DOT__idu_regbAddr];
    vlSelf->CPU__DOT__idu__DOT__s_imm = (((- (IData)(
                                                     (1U 
                                                      & ((~ (IData)(vlSelf->rst)) 
                                                         & (vlSelf->__VdfgTmp_h991cba0a__0 
                                                            >> 0xfU))))) 
                                          << 0x10U) 
                                         | (IData)(vlSelf->CPU__DOT__idu__DOT__imm));
    vlSelf->CPU__DOT__idu_regcAddr = ((0U == (0xfc0007c0U 
                                              & vlSelf->CPU__DOT__instMem_data))
                                       ? (IData)(vlSelf->CPU__DOT__idu__DOT__rd_addr)
                                       : ((0U == (0xffe00000U 
                                                  & vlSelf->CPU__DOT__instMem_data))
                                           ? (IData)(vlSelf->CPU__DOT__idu__DOT__rd_addr)
                                           : (IData)(vlSelf->CPU__DOT__idu_regbAddr)));
}

VL_INLINE_OPT void VCPU___024root___nba_sequent__TOP__1(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___nba_sequent__TOP__1\n"); );
    // Body
    if (((IData)(vlSelf->CPU__DOT__mem_memCe) & (IData)(vlSelf->CPU__DOT__exu_readWr))) {
        vlSelf->CPU__DOT__dataMem_rdData = ((1U == 
                                             ((IData)(vlSelf->rst)
                                               ? 0U
                                               : ((
                                                   (((((((IData)(vlSelf->CPU__DOT__idu__DOT__is_add) 
                                                         | (IData)(vlSelf->CPU__DOT__idu__DOT__is_sub)) 
                                                        | (IData)(vlSelf->CPU__DOT__idu__DOT__is_and)) 
                                                       | (IData)(vlSelf->CPU__DOT__idu__DOT__is_or)) 
                                                      | (IData)(vlSelf->CPU__DOT__idu__DOT__is_xor)) 
                                                     | (IData)(vlSelf->CPU__DOT__idu__DOT__is_sll)) 
                                                    | (IData)(vlSelf->CPU__DOT__idu__DOT__is_srl)) 
                                                   | (IData)(vlSelf->CPU__DOT__idu__DOT__is_sra))
                                                   ? 0U
                                                   : 
                                                  ((((((IData)(vlSelf->CPU__DOT__idu__DOT__is_addi) 
                                                       | (IData)(vlSelf->CPU__DOT__idu__DOT__is_andi)) 
                                                      | (IData)(vlSelf->CPU__DOT__idu__DOT__is_ori)) 
                                                     | (IData)(vlSelf->CPU__DOT__idu__DOT__is_xori)) 
                                                    | (IData)(vlSelf->CPU__DOT__idu__DOT__is_lw))
                                                    ? 
                                                   ((IData)(vlSelf->CPU__DOT__idu__DOT__is_addi)
                                                     ? 0U
                                                     : 
                                                    ((IData)(vlSelf->CPU__DOT__idu__DOT__is_andi)
                                                      ? 0U
                                                      : 
                                                     ((IData)(vlSelf->CPU__DOT__idu__DOT__is_ori)
                                                       ? 0U
                                                       : 
                                                      ((IData)(vlSelf->CPU__DOT__idu__DOT__is_xori)
                                                        ? 0U
                                                        : 
                                                       ((IData)(vlSelf->CPU__DOT__idu__DOT__is_lw)
                                                         ? 0xfU
                                                         : 0U)))))
                                                    : 0U))))
                                             ? (0xffU 
                                                & vlSelf->CPU__DOT__data_mem__DOT__temp_mem_data)
                                             : ((3U 
                                                 == 
                                                 ((IData)(vlSelf->rst)
                                                   ? 0U
                                                   : 
                                                  (((((((((IData)(vlSelf->CPU__DOT__idu__DOT__is_add) 
                                                          | (IData)(vlSelf->CPU__DOT__idu__DOT__is_sub)) 
                                                         | (IData)(vlSelf->CPU__DOT__idu__DOT__is_and)) 
                                                        | (IData)(vlSelf->CPU__DOT__idu__DOT__is_or)) 
                                                       | (IData)(vlSelf->CPU__DOT__idu__DOT__is_xor)) 
                                                      | (IData)(vlSelf->CPU__DOT__idu__DOT__is_sll)) 
                                                     | (IData)(vlSelf->CPU__DOT__idu__DOT__is_srl)) 
                                                    | (IData)(vlSelf->CPU__DOT__idu__DOT__is_sra))
                                                    ? 0U
                                                    : 
                                                   ((((((IData)(vlSelf->CPU__DOT__idu__DOT__is_addi) 
                                                        | (IData)(vlSelf->CPU__DOT__idu__DOT__is_andi)) 
                                                       | (IData)(vlSelf->CPU__DOT__idu__DOT__is_ori)) 
                                                      | (IData)(vlSelf->CPU__DOT__idu__DOT__is_xori)) 
                                                     | (IData)(vlSelf->CPU__DOT__idu__DOT__is_lw))
                                                     ? 
                                                    ((IData)(vlSelf->CPU__DOT__idu__DOT__is_addi)
                                                      ? 0U
                                                      : 
                                                     ((IData)(vlSelf->CPU__DOT__idu__DOT__is_andi)
                                                       ? 0U
                                                       : 
                                                      ((IData)(vlSelf->CPU__DOT__idu__DOT__is_ori)
                                                        ? 0U
                                                        : 
                                                       ((IData)(vlSelf->CPU__DOT__idu__DOT__is_xori)
                                                         ? 0U
                                                         : 
                                                        ((IData)(vlSelf->CPU__DOT__idu__DOT__is_lw)
                                                          ? 0xfU
                                                          : 0U)))))
                                                     : 0U))))
                                                 ? 
                                                (0xffffU 
                                                 & vlSelf->CPU__DOT__data_mem__DOT__temp_mem_data)
                                                 : vlSelf->CPU__DOT__data_mem__DOT__temp_mem_data));
    }
    if (vlSelf->CPU__DOT__mem_memCe) {
        vlSelf->CPU__DOT__data_mem__DOT__temp_mem_data 
            = vlSelf->CPU__DOT__data_mem__DOT__memory
            [(0x3ffU & vlSelf->CPU__DOT__exu__DOT__alu_out)];
    }
}

VL_INLINE_OPT void VCPU___024root___nba_sequent__TOP__2(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___nba_sequent__TOP__2\n"); );
    // Body
    vlSelf->CPU__DOT__idu__DOT__is_addi = 0U;
    vlSelf->CPU__DOT__idu__DOT__is_andi = 0U;
    vlSelf->CPU__DOT__idu__DOT__is_ori = 0U;
    vlSelf->CPU__DOT__idu__DOT__is_xori = 0U;
    vlSelf->CPU__DOT__idu__DOT__is_lw = 0U;
    vlSelf->CPU__DOT__idu__DOT__is_add = 0U;
    vlSelf->CPU__DOT__idu__DOT__is_sub = 0U;
    vlSelf->CPU__DOT__idu__DOT__is_and = 0U;
    vlSelf->CPU__DOT__idu__DOT__is_or = 0U;
    vlSelf->CPU__DOT__idu__DOT__is_xor = 0U;
    if ((0U == (0xfc0007c0U & vlSelf->CPU__DOT__instMem_data))) {
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
    }
    vlSelf->CPU__DOT__idu__DOT__is_sll = 0U;
    vlSelf->CPU__DOT__idu__DOT__is_srl = 0U;
    vlSelf->CPU__DOT__idu__DOT__is_sra = 0U;
    if ((0U != (0xfc0007c0U & vlSelf->CPU__DOT__instMem_data))) {
        if ((0U != (0xffe00000U & vlSelf->CPU__DOT__instMem_data))) {
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
            if ((0x23U == (vlSelf->CPU__DOT__instMem_data 
                           >> 0x1aU))) {
                vlSelf->CPU__DOT__idu__DOT__is_lw = 1U;
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

void VCPU___024root___eval_nba(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VCPU___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VCPU___024root___nba_sequent__TOP__1(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VCPU___024root___nba_sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
}

void VCPU___024root___eval_triggers__ico(VCPU___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__ico(VCPU___024root* vlSelf);
#endif  // VL_DEBUG
void VCPU___024root___eval_triggers__act(VCPU___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__act(VCPU___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VCPU___024root___dump_triggers__nba(VCPU___024root* vlSelf);
#endif  // VL_DEBUG

void VCPU___024root___eval(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<2> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        VCPU___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                VCPU___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("/home/luyoung/CPU_based_on_MIPS/CPU/CPU.v", 2, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            VCPU___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            VCPU___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    VCPU___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/luyoung/CPU_based_on_MIPS/CPU/CPU.v", 2, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                VCPU___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                VCPU___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/luyoung/CPU_based_on_MIPS/CPU/CPU.v", 2, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            VCPU___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void VCPU___024root___eval_debug_assertions(VCPU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
