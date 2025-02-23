// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "VCPU__Syms.h"


void VCPU___024root__trace_chg_sub_0(VCPU___024root* vlSelf, VerilatedFst::Buffer* bufp);

void VCPU___024root__trace_chg_top_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root__trace_chg_top_0\n"); );
    // Init
    VCPU___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VCPU___024root*>(voidSelf);
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VCPU___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void VCPU___024root__trace_chg_sub_0(VCPU___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgCData(oldp+0,(vlSelf->CPU__DOT__idu_regbAddr),5);
        bufp->chgIData(oldp+1,(vlSelf->CPU__DOT__idu_rt_data_o),32);
        bufp->chgIData(oldp+2,(vlSelf->CPU__DOT__instMem_data),32);
        bufp->chgCData(oldp+3,(vlSelf->CPU__DOT__idu__DOT__rd_addr),5);
        bufp->chgSData(oldp+4,(vlSelf->CPU__DOT__idu__DOT__imm),16);
        bufp->chgIData(oldp+5,(vlSelf->CPU__DOT__idu__DOT__s_imm),32);
        bufp->chgIData(oldp+6,(vlSelf->CPU__DOT__idu__DOT__imm),32);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[3U]))) {
        bufp->chgIData(oldp+7,(vlSelf->CPU__DOT__idu_regaData),32);
        bufp->chgIData(oldp+8,(vlSelf->CPU__DOT__idu_regbData),32);
        bufp->chgBit(oldp+9,(vlSelf->CPU__DOT__idu_jCe));
        bufp->chgCData(oldp+10,(vlSelf->CPU__DOT__idu_op),6);
        bufp->chgIData(oldp+11,(vlSelf->CPU__DOT__exu__DOT__alu_out),32);
        bufp->chgBit(oldp+12,(vlSelf->CPU__DOT__exu_regcWr));
        bufp->chgIData(oldp+13,(vlSelf->CPU__DOT__exu_jAddr),32);
        bufp->chgBit(oldp+14,(vlSelf->CPU__DOT__exu_readWr));
        bufp->chgBit(oldp+15,(vlSelf->CPU__DOT__mem_memCe));
        bufp->chgBit(oldp+16,(vlSelf->CPU__DOT__idu__DOT__is_add));
        bufp->chgBit(oldp+17,(vlSelf->CPU__DOT__idu__DOT__is_sub));
        bufp->chgBit(oldp+18,(vlSelf->CPU__DOT__idu__DOT__is_and));
        bufp->chgBit(oldp+19,(vlSelf->CPU__DOT__idu__DOT__is_or));
        bufp->chgBit(oldp+20,(vlSelf->CPU__DOT__idu__DOT__is_xor));
        bufp->chgBit(oldp+21,(vlSelf->CPU__DOT__idu__DOT__is_sll));
        bufp->chgBit(oldp+22,(vlSelf->CPU__DOT__idu__DOT__is_srl));
        bufp->chgBit(oldp+23,(vlSelf->CPU__DOT__idu__DOT__is_sra));
        bufp->chgBit(oldp+24,(vlSelf->CPU__DOT__idu__DOT__is_addi));
        bufp->chgBit(oldp+25,(vlSelf->CPU__DOT__idu__DOT__is_andi));
        bufp->chgBit(oldp+26,(vlSelf->CPU__DOT__idu__DOT__is_ori));
        bufp->chgBit(oldp+27,(vlSelf->CPU__DOT__idu__DOT__is_xori));
        bufp->chgBit(oldp+28,(vlSelf->CPU__DOT__idu__DOT__is_lw));
        bufp->chgCData(oldp+29,(vlSelf->CPU__DOT__idu__DOT__OP1_SEL),3);
        bufp->chgCData(oldp+30,(vlSelf->CPU__DOT__idu__DOT__OP2_SEL),3);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+31,(vlSelf->CPU__DOT__ifu_pc),32);
        bufp->chgIData(oldp+32,(vlSelf->CPU__DOT__regs__DOT__registers[0]),32);
        bufp->chgIData(oldp+33,(vlSelf->CPU__DOT__regs__DOT__registers[1]),32);
        bufp->chgIData(oldp+34,(vlSelf->CPU__DOT__regs__DOT__registers[2]),32);
        bufp->chgIData(oldp+35,(vlSelf->CPU__DOT__regs__DOT__registers[3]),32);
        bufp->chgIData(oldp+36,(vlSelf->CPU__DOT__regs__DOT__registers[4]),32);
        bufp->chgIData(oldp+37,(vlSelf->CPU__DOT__regs__DOT__registers[5]),32);
        bufp->chgIData(oldp+38,(vlSelf->CPU__DOT__regs__DOT__registers[6]),32);
        bufp->chgIData(oldp+39,(vlSelf->CPU__DOT__regs__DOT__registers[7]),32);
        bufp->chgIData(oldp+40,(vlSelf->CPU__DOT__regs__DOT__registers[8]),32);
        bufp->chgIData(oldp+41,(vlSelf->CPU__DOT__regs__DOT__registers[9]),32);
        bufp->chgIData(oldp+42,(vlSelf->CPU__DOT__regs__DOT__registers[10]),32);
        bufp->chgIData(oldp+43,(vlSelf->CPU__DOT__regs__DOT__registers[11]),32);
        bufp->chgIData(oldp+44,(vlSelf->CPU__DOT__regs__DOT__registers[12]),32);
        bufp->chgIData(oldp+45,(vlSelf->CPU__DOT__regs__DOT__registers[13]),32);
        bufp->chgIData(oldp+46,(vlSelf->CPU__DOT__regs__DOT__registers[14]),32);
        bufp->chgIData(oldp+47,(vlSelf->CPU__DOT__regs__DOT__registers[15]),32);
        bufp->chgIData(oldp+48,(vlSelf->CPU__DOT__regs__DOT__registers[16]),32);
        bufp->chgIData(oldp+49,(vlSelf->CPU__DOT__regs__DOT__registers[17]),32);
        bufp->chgIData(oldp+50,(vlSelf->CPU__DOT__regs__DOT__registers[18]),32);
        bufp->chgIData(oldp+51,(vlSelf->CPU__DOT__regs__DOT__registers[19]),32);
        bufp->chgIData(oldp+52,(vlSelf->CPU__DOT__regs__DOT__registers[20]),32);
        bufp->chgIData(oldp+53,(vlSelf->CPU__DOT__regs__DOT__registers[21]),32);
        bufp->chgIData(oldp+54,(vlSelf->CPU__DOT__regs__DOT__registers[22]),32);
        bufp->chgIData(oldp+55,(vlSelf->CPU__DOT__regs__DOT__registers[23]),32);
        bufp->chgIData(oldp+56,(vlSelf->CPU__DOT__regs__DOT__registers[24]),32);
        bufp->chgIData(oldp+57,(vlSelf->CPU__DOT__regs__DOT__registers[25]),32);
        bufp->chgIData(oldp+58,(vlSelf->CPU__DOT__regs__DOT__registers[26]),32);
        bufp->chgIData(oldp+59,(vlSelf->CPU__DOT__regs__DOT__registers[27]),32);
        bufp->chgIData(oldp+60,(vlSelf->CPU__DOT__regs__DOT__registers[28]),32);
        bufp->chgIData(oldp+61,(vlSelf->CPU__DOT__regs__DOT__registers[29]),32);
        bufp->chgIData(oldp+62,(vlSelf->CPU__DOT__regs__DOT__registers[30]),32);
        bufp->chgIData(oldp+63,(vlSelf->CPU__DOT__regs__DOT__registers[31]),32);
    }
    bufp->chgBit(oldp+64,(vlSelf->clk));
    bufp->chgBit(oldp+65,(vlSelf->rst));
    bufp->chgBit(oldp+66,((1U & (~ (IData)(vlSelf->rst)))));
    bufp->chgCData(oldp+67,(((IData)(vlSelf->rst) ? 0U
                              : (0x1fU & (vlSelf->__VdfgTmp_h991cba0a__0 
                                          >> 0x15U)))),5);
    bufp->chgBit(oldp+68,(((~ (IData)(vlSelf->rst)) 
                           & ((~ ((((((((IData)(vlSelf->CPU__DOT__idu__DOT__is_add) 
                                        | (IData)(vlSelf->CPU__DOT__idu__DOT__is_sub)) 
                                       | (IData)(vlSelf->CPU__DOT__idu__DOT__is_and)) 
                                      | (IData)(vlSelf->CPU__DOT__idu__DOT__is_or)) 
                                     | (IData)(vlSelf->CPU__DOT__idu__DOT__is_xor)) 
                                    | (IData)(vlSelf->CPU__DOT__idu__DOT__is_sll)) 
                                   | (IData)(vlSelf->CPU__DOT__idu__DOT__is_srl)) 
                                  | (IData)(vlSelf->CPU__DOT__idu__DOT__is_sra))) 
                              & ((((((IData)(vlSelf->CPU__DOT__idu__DOT__is_addi) 
                                     | (IData)(vlSelf->CPU__DOT__idu__DOT__is_andi)) 
                                    | (IData)(vlSelf->CPU__DOT__idu__DOT__is_ori)) 
                                   | (IData)(vlSelf->CPU__DOT__idu__DOT__is_xori)) 
                                  | (IData)(vlSelf->CPU__DOT__idu__DOT__is_lw)) 
                                 & ((~ (IData)(vlSelf->CPU__DOT__idu__DOT__is_addi)) 
                                    & ((~ (IData)(vlSelf->CPU__DOT__idu__DOT__is_andi)) 
                                       & ((~ (IData)(vlSelf->CPU__DOT__idu__DOT__is_ori)) 
                                          & ((~ (IData)(vlSelf->CPU__DOT__idu__DOT__is_xori)) 
                                             & (IData)(vlSelf->CPU__DOT__idu__DOT__is_lw))))))))));
    bufp->chgCData(oldp+69,(((IData)(vlSelf->rst) ? 0U
                              : (((((((((IData)(vlSelf->CPU__DOT__idu__DOT__is_add) 
                                        | (IData)(vlSelf->CPU__DOT__idu__DOT__is_sub)) 
                                       | (IData)(vlSelf->CPU__DOT__idu__DOT__is_and)) 
                                      | (IData)(vlSelf->CPU__DOT__idu__DOT__is_or)) 
                                     | (IData)(vlSelf->CPU__DOT__idu__DOT__is_xor)) 
                                    | (IData)(vlSelf->CPU__DOT__idu__DOT__is_sll)) 
                                   | (IData)(vlSelf->CPU__DOT__idu__DOT__is_srl)) 
                                  | (IData)(vlSelf->CPU__DOT__idu__DOT__is_sra))
                                  ? 0U : ((((((IData)(vlSelf->CPU__DOT__idu__DOT__is_addi) 
                                              | (IData)(vlSelf->CPU__DOT__idu__DOT__is_andi)) 
                                             | (IData)(vlSelf->CPU__DOT__idu__DOT__is_ori)) 
                                            | (IData)(vlSelf->CPU__DOT__idu__DOT__is_xori)) 
                                           | (IData)(vlSelf->CPU__DOT__idu__DOT__is_lw))
                                           ? ((IData)(vlSelf->CPU__DOT__idu__DOT__is_addi)
                                               ? 0U
                                               : ((IData)(vlSelf->CPU__DOT__idu__DOT__is_andi)
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
                                           : 0U)))),4);
    bufp->chgBit(oldp+70,(((IData)(vlSelf->rst) | (
                                                   ((((((((IData)(vlSelf->CPU__DOT__idu__DOT__is_add) 
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
                                                               | (IData)(vlSelf->CPU__DOT__idu__DOT__is_xori)))))))));
    bufp->chgCData(oldp+71,(vlSelf->CPU__DOT__idu_regcAddr),5);
    bufp->chgIData(oldp+72,(((IData)(vlSelf->CPU__DOT__exu_readWr)
                              ? vlSelf->CPU__DOT__dataMem_rdData
                              : vlSelf->CPU__DOT__exu__DOT__alu_out)),32);
    bufp->chgBit(oldp+73,(((~ (IData)(vlSelf->rst)) 
                           & (IData)(vlSelf->CPU__DOT__exu_regcWr))));
    bufp->chgIData(oldp+74,(vlSelf->CPU__DOT__regs__DOT__registers
                            [((IData)(vlSelf->rst) ? 0U
                               : (0x1fU & (vlSelf->__VdfgTmp_h991cba0a__0 
                                           >> 0x15U)))]),32);
    bufp->chgIData(oldp+75,(vlSelf->CPU__DOT__dataMem_rdData),32);
    bufp->chgIData(oldp+76,(vlSelf->CPU__DOT__data_mem__DOT__temp_mem_data),32);
    bufp->chgCData(oldp+77,(((IData)(vlSelf->rst) ? 0U
                              : (0x1fU & (vlSelf->__VdfgTmp_h991cba0a__0 
                                          >> 6U)))),5);
    bufp->chgIData(oldp+78,(((IData)(vlSelf->rst) ? 0U
                              : (0x3ffffffU & vlSelf->__VdfgTmp_h991cba0a__0))),26);
    bufp->chgIData(oldp+79,(((IData)(vlSelf->rst) ? 0U
                              : (0x1fU & (vlSelf->__VdfgTmp_h991cba0a__0 
                                          >> 6U)))),32);
    bufp->chgIData(oldp+80,(((IData)(vlSelf->rst) ? 0U
                              : (0x3ffffffU & vlSelf->__VdfgTmp_h991cba0a__0))),32);
}

void VCPU___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root__trace_cleanup\n"); );
    // Init
    VCPU___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VCPU___024root*>(voidSelf);
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}
