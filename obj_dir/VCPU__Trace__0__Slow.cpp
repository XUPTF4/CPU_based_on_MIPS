// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "VCPU__Syms.h"


VL_ATTR_COLD void VCPU___024root__trace_init_sub__TOP__0(VCPU___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+65,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+66,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->pushNamePrefix("CPU ");
    tracep->declBit(c+65,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+66,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+32,"ifu_pc",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+67,"ifu_romCe",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+8,"idu_regaData",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+9,"idu_regbData",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+10,"idu_jCe",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+82,"idu_regaRd",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+68,"idu_regaAddr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBit(c+82,"idu_regbRd",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+1,"idu_regbAddr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+11,"idu_op",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 5,0);
    tracep->declBit(c+83,"idu_memWr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+69,"idu_memRr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+84,"idu_w_mask",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+70,"idu_r_mask",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBit(c+71,"idu_regcWr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+72,"idu_regcAddr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+2,"idu_rt_data_o",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+12,"exu_regcData",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+72,"exu_regcAddr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBit(c+13,"exu_regcWr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+14,"exu_jAddr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+12,"exu_memAddr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+2,"exu_memData",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+15,"exu_readWr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+85,"exu_writeWr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+70,"exu_rmask",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+84,"exu_wmask",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+73,"mem_regData",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+72,"mem_regAddr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBit(c+13,"mem_regWr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+12,"mem_memAddr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+2,"mem_wtData",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+16,"mem_memCe",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+85,"mem_memWr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+15,"mem_memRr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+84,"mem_w_mask",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+70,"mem_r_mask",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBit(c+74,"wbu_we",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+72,"wbu_wAddr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+73,"wbu_wData",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+75,"regs_regaData",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+2,"regs_regbData",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+3,"instMem_data",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+76,"dataMem_rdData",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->pushNamePrefix("data_mem ");
    tracep->declBit(c+65,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+16,"ce",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+85,"we",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+2,"wtData",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+12,"addr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+15,"memRr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+84,"w_mask",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+70,"r_mask",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+76,"rdData",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+77,"temp_mem_data",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,"temp_reg_data",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("exu ");
    tracep->declBit(c+66,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+12,"regcData",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+72,"regcAddr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBit(c+13,"regcWr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+14,"jAddr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+12,"memAddr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+2,"memData",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+15,"readWr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+85,"writeWr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+70,"rmask",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+84,"wmask",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+11,"op_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 5,0);
    tracep->declBus(c+83,"memWr_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 0,0);
    tracep->declBus(c+69,"memRr_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 0,0);
    tracep->declBus(c+84,"w_mask_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+70,"r_mask_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+8,"regaData_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+9,"regbData_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+71,"regcWr_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 0,0);
    tracep->declBus(c+72,"regcAddr_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+2,"rt_data_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+12,"alu_out",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("idu ");
    tracep->declBit(c+66,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+32,"pc",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+3,"inst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+75,"regaData_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+2,"regbData_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+8,"regaData",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+9,"regbData",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+10,"jCe",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+82,"regaRd",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+68,"regaAddr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBit(c+82,"regbRd",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+1,"regbAddr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+11,"op",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 5,0);
    tracep->declBus(c+83,"memWr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 0,0);
    tracep->declBus(c+69,"memRr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 0,0);
    tracep->declBus(c+84,"w_mask",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+70,"r_mask",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+71,"regcWr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 0,0);
    tracep->declBus(c+72,"regcAddr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+2,"rt_data_o",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+68,"rs_addr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+1,"rt_addr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+4,"rd_addr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+78,"sa",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+79,"address",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 25,0);
    tracep->declBus(c+5,"imm",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 15,0);
    tracep->declBus(c+5,"offset",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 15,0);
    tracep->declBus(c+6,"s_imm",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+7,"u_imm",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+6,"s_offset",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+80,"u_sa",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+81,"u_address",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+17,"is_add",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+18,"is_sub",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+19,"is_and",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+20,"is_or",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+21,"is_xor",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+22,"is_sll",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+23,"is_srl",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+24,"is_sra",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+85,"is_jr",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+25,"is_addi",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+26,"is_andi",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+27,"is_ori",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+28,"is_xori",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+29,"is_lw",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+85,"is_sw",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+85,"is_beq",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+85,"is_bne",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+85,"is_lui",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+85,"is_j",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+85,"is_jal",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBus(c+30,"OP1_SEL",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
    tracep->declBus(c+31,"OP2_SEL",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 2,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ifu ");
    tracep->declBit(c+65,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+66,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+14,"jAddr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+10,"jCe",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+32,"pc",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+67,"romCe",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("instMem ");
    tracep->declBit(c+67,"ce",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+32,"addr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+3,"data",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("mem ");
    tracep->declBit(c+66,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+12,"regcData_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+72,"regcAddr_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBit(c+13,"regcWr_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+73,"regData",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+72,"regAddr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBit(c+13,"regWr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+12,"memAddr_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+2,"memData_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+76,"rdData_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+85,"memWr_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 0,0);
    tracep->declBus(c+15,"memRr_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 0,0);
    tracep->declBus(c+84,"w_mask_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+70,"r_mask_i",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+12,"memAddr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+2,"wtData",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+16,"memCe",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+85,"memWr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 0,0);
    tracep->declBus(c+15,"memRr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 0,0);
    tracep->declBus(c+84,"w_mask",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+70,"r_mask",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("regs ");
    tracep->declBit(c+65,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+66,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+75,"regaData",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+2,"regbData",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+68,"regaAddr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBit(c+82,"regaRd",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+1,"regbAddr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBit(c+82,"regbRd",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+74,"we",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+72,"wAddr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+73,"wData",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+33+i*1,"registers",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, true,(i+0), 31,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("wb ");
    tracep->declBit(c+66,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+13,"regWr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 0,0);
    tracep->declBus(c+72,"regAddr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+73,"regData",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+74,"we",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 0,0);
    tracep->declBus(c+72,"wAddr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+73,"wData",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void VCPU___024root__trace_init_sub__TOP____024unit__0(VCPU___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root__trace_init_sub__TOP____024unit__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+86,"ALU_X",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+87,"ALU_ADD",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+88,"ALU_SUB",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+89,"ALU_AND",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+90,"ALU_OR",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+91,"ALU_XOR",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+92,"ALU_SLL",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+93,"ALU_SRL",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+94,"ALU_SRA",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+95,"ALU_JR",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+96,"ALU_ADDI",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+97,"ALU_ANDI",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+98,"ALU_ORI",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+99,"ALU_XORI",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+100,"ALU_LW",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+101,"ALU_SW",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+102,"ALU_BEQ",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+103,"ALU_BNE",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+104,"ALU_LUI",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+105,"ALU_J",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+106,"ALU_JAL",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+107,"FUNCT_ADD",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+108,"FUNCT_SUB",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+109,"FUNCT_AND",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+110,"FUNCT_OR",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+111,"FUNCT_XOR",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+86,"FUNCT_SLL",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+88,"FUNCT_SRL",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+89,"FUNCT_SRA",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+94,"FUNCT_JR",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+94,"FUNCT_ADDI",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+98,"FUNCT_ANDI",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+99,"FUNCT_ORI",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+100,"FUNCT_XORI",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+112,"FUNCT_LW",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 5,0);
    tracep->declBus(c+113,"OP1_X",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 2,0);
    tracep->declBus(c+114,"OP1_RS",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 2,0);
    tracep->declBus(c+115,"OP1_LUI",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 2,0);
    tracep->declBus(c+116,"OP1_IM_SA",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 2,0);
    tracep->declBus(c+117,"OP1_PC",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 2,0);
    tracep->declBus(c+118,"OP1_IMS",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 2,0);
    tracep->declBus(c+119,"OP1_IMZ",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 2,0);
    tracep->declBus(c+120,"OP1_IM",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 2,0);
    tracep->declBus(c+113,"OP2_X",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 2,0);
    tracep->declBus(c+114,"OP2_ADDRESS",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 2,0);
    tracep->declBus(c+115,"OP2_RT",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 2,0);
    tracep->declBus(c+116,"OP2_IM_4",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 2,0);
    tracep->declBus(c+117,"OP2_PC",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 2,0);
    tracep->declBus(c+118,"OP2_IMS",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 2,0);
    tracep->declBus(c+119,"OP2_IMZ",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 2,0);
    tracep->declBus(c+120,"OP2_IM_OFFSET_S",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 2,0);
    tracep->declBus(c+83,"WMEN_X",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 0,0);
    tracep->declBus(c+121,"WMEN_S",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 0,0);
    tracep->declBus(c+83,"RMEN_X",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 0,0);
    tracep->declBus(c+121,"RMEN_S",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 0,0);
    tracep->declBus(c+84,"WMASK_X",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 3,0);
    tracep->declBus(c+122,"WMASK_A",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 3,0);
    tracep->declBus(c+123,"WMASK_B",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 3,0);
    tracep->declBus(c+124,"WMASK_C",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 3,0);
    tracep->declBus(c+84,"RMASK_X",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 3,0);
    tracep->declBus(c+122,"RMASK_A",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 3,0);
    tracep->declBus(c+123,"RMASK_B",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 3,0);
    tracep->declBus(c+124,"RMASK_C",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 3,0);
    tracep->declBus(c+83,"WTYPE_X",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 0,0);
    tracep->declBus(c+121,"WTYPE_S",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 0,0);
    tracep->declBus(c+83,"WTYPE_U",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 0,0);
    tracep->declBus(c+83,"REN_X",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 0,0);
    tracep->declBus(c+121,"REN_S",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 0,0);
    tracep->declBus(c+125,"WB_X",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 1,0);
    tracep->declBus(c+126,"WB_MEM",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 1,0);
    tracep->declBus(c+127,"WB_ALU",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 1,0);
    tracep->declBus(c+83,"WB_TYPE_X",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 0,0);
    tracep->declBus(c+121,"WB_TYPE_S",-1, FST_VD_IMPLICIT,FST_VT_VCD_PARAMETER, false,-1, 0,0);
}

VL_ATTR_COLD void VCPU___024root__trace_init_top(VCPU___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root__trace_init_top\n"); );
    // Body
    VCPU___024root__trace_init_sub__TOP__0(vlSelf, tracep);
    tracep->pushNamePrefix("$unit ");
    VCPU___024root__trace_init_sub__TOP____024unit__0(vlSelf, tracep);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void VCPU___024root__trace_full_top_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void VCPU___024root__trace_chg_top_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void VCPU___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void VCPU___024root__trace_register(VCPU___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VCPU___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VCPU___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VCPU___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VCPU___024root__trace_full_sub_0(VCPU___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void VCPU___024root__trace_full_top_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root__trace_full_top_0\n"); );
    // Init
    VCPU___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VCPU___024root*>(voidSelf);
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VCPU___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VCPU___024root__trace_full_sub_0(VCPU___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCPU___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->CPU__DOT__idu_regbAddr),5);
    bufp->fullIData(oldp+2,(vlSelf->CPU__DOT__idu_rt_data_o),32);
    bufp->fullIData(oldp+3,(vlSelf->CPU__DOT__instMem_data),32);
    bufp->fullCData(oldp+4,(vlSelf->CPU__DOT__idu__DOT__rd_addr),5);
    bufp->fullSData(oldp+5,(vlSelf->CPU__DOT__idu__DOT__imm),16);
    bufp->fullIData(oldp+6,(vlSelf->CPU__DOT__idu__DOT__s_imm),32);
    bufp->fullIData(oldp+7,(vlSelf->CPU__DOT__idu__DOT__imm),32);
    bufp->fullIData(oldp+8,(vlSelf->CPU__DOT__idu_regaData),32);
    bufp->fullIData(oldp+9,(vlSelf->CPU__DOT__idu_regbData),32);
    bufp->fullBit(oldp+10,(vlSelf->CPU__DOT__idu_jCe));
    bufp->fullCData(oldp+11,(vlSelf->CPU__DOT__idu_op),6);
    bufp->fullIData(oldp+12,(vlSelf->CPU__DOT__exu__DOT__alu_out),32);
    bufp->fullBit(oldp+13,(vlSelf->CPU__DOT__exu_regcWr));
    bufp->fullIData(oldp+14,(vlSelf->CPU__DOT__exu_jAddr),32);
    bufp->fullBit(oldp+15,(vlSelf->CPU__DOT__exu_readWr));
    bufp->fullBit(oldp+16,(vlSelf->CPU__DOT__mem_memCe));
    bufp->fullBit(oldp+17,(vlSelf->CPU__DOT__idu__DOT__is_add));
    bufp->fullBit(oldp+18,(vlSelf->CPU__DOT__idu__DOT__is_sub));
    bufp->fullBit(oldp+19,(vlSelf->CPU__DOT__idu__DOT__is_and));
    bufp->fullBit(oldp+20,(vlSelf->CPU__DOT__idu__DOT__is_or));
    bufp->fullBit(oldp+21,(vlSelf->CPU__DOT__idu__DOT__is_xor));
    bufp->fullBit(oldp+22,(vlSelf->CPU__DOT__idu__DOT__is_sll));
    bufp->fullBit(oldp+23,(vlSelf->CPU__DOT__idu__DOT__is_srl));
    bufp->fullBit(oldp+24,(vlSelf->CPU__DOT__idu__DOT__is_sra));
    bufp->fullBit(oldp+25,(vlSelf->CPU__DOT__idu__DOT__is_addi));
    bufp->fullBit(oldp+26,(vlSelf->CPU__DOT__idu__DOT__is_andi));
    bufp->fullBit(oldp+27,(vlSelf->CPU__DOT__idu__DOT__is_ori));
    bufp->fullBit(oldp+28,(vlSelf->CPU__DOT__idu__DOT__is_xori));
    bufp->fullBit(oldp+29,(vlSelf->CPU__DOT__idu__DOT__is_lw));
    bufp->fullCData(oldp+30,(vlSelf->CPU__DOT__idu__DOT__OP1_SEL),3);
    bufp->fullCData(oldp+31,(vlSelf->CPU__DOT__idu__DOT__OP2_SEL),3);
    bufp->fullIData(oldp+32,(vlSelf->CPU__DOT__ifu_pc),32);
    bufp->fullIData(oldp+33,(vlSelf->CPU__DOT__regs__DOT__registers[0]),32);
    bufp->fullIData(oldp+34,(vlSelf->CPU__DOT__regs__DOT__registers[1]),32);
    bufp->fullIData(oldp+35,(vlSelf->CPU__DOT__regs__DOT__registers[2]),32);
    bufp->fullIData(oldp+36,(vlSelf->CPU__DOT__regs__DOT__registers[3]),32);
    bufp->fullIData(oldp+37,(vlSelf->CPU__DOT__regs__DOT__registers[4]),32);
    bufp->fullIData(oldp+38,(vlSelf->CPU__DOT__regs__DOT__registers[5]),32);
    bufp->fullIData(oldp+39,(vlSelf->CPU__DOT__regs__DOT__registers[6]),32);
    bufp->fullIData(oldp+40,(vlSelf->CPU__DOT__regs__DOT__registers[7]),32);
    bufp->fullIData(oldp+41,(vlSelf->CPU__DOT__regs__DOT__registers[8]),32);
    bufp->fullIData(oldp+42,(vlSelf->CPU__DOT__regs__DOT__registers[9]),32);
    bufp->fullIData(oldp+43,(vlSelf->CPU__DOT__regs__DOT__registers[10]),32);
    bufp->fullIData(oldp+44,(vlSelf->CPU__DOT__regs__DOT__registers[11]),32);
    bufp->fullIData(oldp+45,(vlSelf->CPU__DOT__regs__DOT__registers[12]),32);
    bufp->fullIData(oldp+46,(vlSelf->CPU__DOT__regs__DOT__registers[13]),32);
    bufp->fullIData(oldp+47,(vlSelf->CPU__DOT__regs__DOT__registers[14]),32);
    bufp->fullIData(oldp+48,(vlSelf->CPU__DOT__regs__DOT__registers[15]),32);
    bufp->fullIData(oldp+49,(vlSelf->CPU__DOT__regs__DOT__registers[16]),32);
    bufp->fullIData(oldp+50,(vlSelf->CPU__DOT__regs__DOT__registers[17]),32);
    bufp->fullIData(oldp+51,(vlSelf->CPU__DOT__regs__DOT__registers[18]),32);
    bufp->fullIData(oldp+52,(vlSelf->CPU__DOT__regs__DOT__registers[19]),32);
    bufp->fullIData(oldp+53,(vlSelf->CPU__DOT__regs__DOT__registers[20]),32);
    bufp->fullIData(oldp+54,(vlSelf->CPU__DOT__regs__DOT__registers[21]),32);
    bufp->fullIData(oldp+55,(vlSelf->CPU__DOT__regs__DOT__registers[22]),32);
    bufp->fullIData(oldp+56,(vlSelf->CPU__DOT__regs__DOT__registers[23]),32);
    bufp->fullIData(oldp+57,(vlSelf->CPU__DOT__regs__DOT__registers[24]),32);
    bufp->fullIData(oldp+58,(vlSelf->CPU__DOT__regs__DOT__registers[25]),32);
    bufp->fullIData(oldp+59,(vlSelf->CPU__DOT__regs__DOT__registers[26]),32);
    bufp->fullIData(oldp+60,(vlSelf->CPU__DOT__regs__DOT__registers[27]),32);
    bufp->fullIData(oldp+61,(vlSelf->CPU__DOT__regs__DOT__registers[28]),32);
    bufp->fullIData(oldp+62,(vlSelf->CPU__DOT__regs__DOT__registers[29]),32);
    bufp->fullIData(oldp+63,(vlSelf->CPU__DOT__regs__DOT__registers[30]),32);
    bufp->fullIData(oldp+64,(vlSelf->CPU__DOT__regs__DOT__registers[31]),32);
    bufp->fullBit(oldp+65,(vlSelf->clk));
    bufp->fullBit(oldp+66,(vlSelf->rst));
    bufp->fullBit(oldp+67,((1U & (~ (IData)(vlSelf->rst)))));
    bufp->fullCData(oldp+68,(((IData)(vlSelf->rst) ? 0U
                               : (0x1fU & (vlSelf->__VdfgTmp_h991cba0a__0 
                                           >> 0x15U)))),5);
    bufp->fullBit(oldp+69,(((~ (IData)(vlSelf->rst)) 
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
    bufp->fullCData(oldp+70,(((IData)(vlSelf->rst) ? 0U
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
    bufp->fullBit(oldp+71,(((IData)(vlSelf->rst) | 
                            (((((((((IData)(vlSelf->CPU__DOT__idu__DOT__is_add) 
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
    bufp->fullCData(oldp+72,(vlSelf->CPU__DOT__idu_regcAddr),5);
    bufp->fullIData(oldp+73,(((IData)(vlSelf->CPU__DOT__exu_readWr)
                               ? vlSelf->CPU__DOT__dataMem_rdData
                               : vlSelf->CPU__DOT__exu__DOT__alu_out)),32);
    bufp->fullBit(oldp+74,(((~ (IData)(vlSelf->rst)) 
                            & (IData)(vlSelf->CPU__DOT__exu_regcWr))));
    bufp->fullIData(oldp+75,(vlSelf->CPU__DOT__regs__DOT__registers
                             [((IData)(vlSelf->rst)
                                ? 0U : (0x1fU & (vlSelf->__VdfgTmp_h991cba0a__0 
                                                 >> 0x15U)))]),32);
    bufp->fullIData(oldp+76,(vlSelf->CPU__DOT__dataMem_rdData),32);
    bufp->fullIData(oldp+77,(vlSelf->CPU__DOT__data_mem__DOT__temp_mem_data),32);
    bufp->fullCData(oldp+78,(((IData)(vlSelf->rst) ? 0U
                               : (0x1fU & (vlSelf->__VdfgTmp_h991cba0a__0 
                                           >> 6U)))),5);
    bufp->fullIData(oldp+79,(((IData)(vlSelf->rst) ? 0U
                               : (0x3ffffffU & vlSelf->__VdfgTmp_h991cba0a__0))),26);
    bufp->fullIData(oldp+80,(((IData)(vlSelf->rst) ? 0U
                               : (0x1fU & (vlSelf->__VdfgTmp_h991cba0a__0 
                                           >> 6U)))),32);
    bufp->fullIData(oldp+81,(((IData)(vlSelf->rst) ? 0U
                               : (0x3ffffffU & vlSelf->__VdfgTmp_h991cba0a__0))),32);
    bufp->fullBit(oldp+82,(1U));
    bufp->fullBit(oldp+83,(0U));
    bufp->fullCData(oldp+84,(0U),4);
    bufp->fullBit(oldp+85,(0U));
    bufp->fullCData(oldp+86,(0U),6);
    bufp->fullCData(oldp+87,(1U),6);
    bufp->fullCData(oldp+88,(2U),6);
    bufp->fullCData(oldp+89,(3U),6);
    bufp->fullCData(oldp+90,(4U),6);
    bufp->fullCData(oldp+91,(5U),6);
    bufp->fullCData(oldp+92,(6U),6);
    bufp->fullCData(oldp+93,(7U),6);
    bufp->fullCData(oldp+94,(8U),6);
    bufp->fullCData(oldp+95,(9U),6);
    bufp->fullCData(oldp+96,(0xaU),6);
    bufp->fullCData(oldp+97,(0xbU),6);
    bufp->fullCData(oldp+98,(0xcU),6);
    bufp->fullCData(oldp+99,(0xdU),6);
    bufp->fullCData(oldp+100,(0xeU),6);
    bufp->fullCData(oldp+101,(0xfU),6);
    bufp->fullCData(oldp+102,(0x10U),6);
    bufp->fullCData(oldp+103,(0x11U),6);
    bufp->fullCData(oldp+104,(0x12U),6);
    bufp->fullCData(oldp+105,(0x13U),6);
    bufp->fullCData(oldp+106,(0x14U),6);
    bufp->fullCData(oldp+107,(0x20U),6);
    bufp->fullCData(oldp+108,(0x22U),6);
    bufp->fullCData(oldp+109,(0x24U),6);
    bufp->fullCData(oldp+110,(0x25U),6);
    bufp->fullCData(oldp+111,(0x26U),6);
    bufp->fullCData(oldp+112,(0x23U),6);
    bufp->fullCData(oldp+113,(0U),3);
    bufp->fullCData(oldp+114,(1U),3);
    bufp->fullCData(oldp+115,(2U),3);
    bufp->fullCData(oldp+116,(3U),3);
    bufp->fullCData(oldp+117,(4U),3);
    bufp->fullCData(oldp+118,(5U),3);
    bufp->fullCData(oldp+119,(6U),3);
    bufp->fullCData(oldp+120,(7U),3);
    bufp->fullBit(oldp+121,(1U));
    bufp->fullCData(oldp+122,(1U),4);
    bufp->fullCData(oldp+123,(3U),4);
    bufp->fullCData(oldp+124,(0xfU),4);
    bufp->fullCData(oldp+125,(0U),2);
    bufp->fullCData(oldp+126,(1U),2);
    bufp->fullCData(oldp+127,(2U),2);
}
