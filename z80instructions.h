/* z80instructions.h
 * Declaration of the "generic" instructions emulated.
 *
 * Copyright (c) 2012 Lin Ke-Fong
 *
 * This code is free, do whatever you want with it. 
 */

/* Some "instructions" handle two opcodes hence they need their encodings to
 * be able to distinguish them. 
 */

#define OPCODE_LD_A_I           0x57
#define OPCODE_LD_I_A           0x47

#define OPCODE_LDI              0xa0    
#define OPCODE_LDIR             0xb0
#define OPCODE_CPI              0xa1
#define OPCODE_CPIR             0xb1

#define OPCODE_RLD              0x6f

#if defined(Z80_CATCH_RETI) && defined(Z80_CATCH_RETN)
#       define OPCODE_RETI      0x4d
#endif

#define OPCODE_INI              0xa2
#define OPCODE_INIR             0xb2
#define OPCODE_OUTI             0xa3
#define OPCODE_OTIR             0xb3

/* Instruction numbers, opcodes are converted to these numbers using tables
 * generated by maketables.c.
 */

enum {

        /* 8-bit load group. */

        LD_R_R, 
        LD_R_N,

        LD_R_INDIRECT_HL,
        LD_INDIRECT_HL_R,
        LD_INDIRECT_HL_N,

        LD_A_INDIRECT_BC,
        LD_A_INDIRECT_DE,
        LD_A_INDIRECT_NN,
        LD_INDIRECT_BC_A,
        LD_INDIRECT_DE_A,
        LD_INDIRECT_NN_A,

        LD_A_I_LD_A_R,          /* Handle "LD A, I" and "LD A, R". */
        LD_I_A_LD_R_A,          /* Handle "LD I, A" and "LD I, A". */

        /* 16-bit load group. */

        LD_RR_NN,

        LD_HL_INDIRECT_NN,
        LD_RR_INDIRECT_NN,
        LD_INDIRECT_NN_HL,
        LD_INDIRECT_NN_RR,

        LD_SP_HL,

        PUSH_SS,
        POP_SS,

        /* Exchange, block transfer, and search group. */

        EX_DE_HL,
        EX_AF_AF_PRIME,
        EXX,
        EX_INDIRECT_SP_HL,

        LDI_LDD,                /* Handle "LDI" and "LDD". */
        LDIR_LDDR,              /* Handle "LDIR" and "LDDR". */

        CPI_CPD,                /* Handle "CPI" and "CPD". */
        CPIR_CPDR,              /* Handle "CPIR" and "CPDR". */

        /* 8-bit arithmetic and logical group. */

        ADD_R,
        ADD_N,
        ADD_INDIRECT_HL,

        ADC_R,
        ADC_N,
        ADC_INDIRECT_HL,

        SUB_R,
        SUB_N,
        SUB_INDIRECT_HL,

        SBC_R,
        SBC_N,
        SBC_INDIRECT_HL,

        AND_R,
        AND_N,
        AND_INDIRECT_HL,

        XOR_R,
        XOR_N,
        XOR_INDIRECT_HL,

        OR_R,
        OR_N,
        OR_INDIRECT_HL,

        CP_R,
        CP_N,
        CP_INDIRECT_HL,

        INC_R,
        INC_INDIRECT_HL,
        DEC_R,
        DEC_INDIRECT_HL,

        /* 16-bit arithmetic group. */

        ADD_HL_RR,

        ADC_HL_RR,
        SBC_HL_RR,

        INC_RR,
        DEC_RR,

        /* General-purpose arithmetic and CPU control group. */
        
        DAA,

        CPL,
        NEG,

        CCF,
        SCF,

        NOP,
        HALT,

        DI,
        EI,

        IM_N,

        /* Rotate and shift group. */

        RLCA,
        RLA,
        RRCA,
        RRA,

        RLC_R,
        RLC_INDIRECT_HL,
        RL_R,
        RL_INDIRECT_HL,
        RRC_R,
        RRC_INDIRECT_HL,
        RR_R,
        RR_INDIRECT_HL,
        SLA_R,
        SLA_INDIRECT_HL,
        SLL_R,
        SLL_INDIRECT_HL,
        SRA_R,
        SRA_INDIRECT_HL,
        SRL_R,
        SRL_INDIRECT_HL,

        RLD_RRD,                /* Handle "RLD" and "RRD". */

        /* Bit set, reset, and test group. */

        BIT_B_R,
        BIT_B_INDIRECT_HL,
        SET_B_R,
        SET_B_INDIRECT_HL,
        RES_B_R,
        RES_B_INDIRECT_HL,

        /* Jump group. */

        JP_NN,
        JP_CC_NN,
        JR_E,
        JR_DD_E,
        JP_HL,
        DJNZ_E,

        /* Call and return group. */

        CALL_NN,
        CALL_CC_NN,
        RET,
        RET_CC,

        RETI_RETN,              /* Handle "RETI" and "RETN". */

        RST_P,

        /* Input and output group. */

        IN_A_N,
        IN_R_C,                 /* Correctly handle undocumented "IN F, (C)"
                                 * instruction.
                                 */
                                                                
        INI_IND,                /* Handle "INI" and "IND". */
        INIR_INDR,              /* Handle "INIR" and "INDR". */

        OUT_N_A,
        OUT_C_R,                /* Correctly handle undocumented "OUT (C), 0"
                                 * instruction.
                                 */

        OUTI_OUTD,              /* Handle "OUTI" and "OUTD".*/
        OTIR_OTDR,              /* Handle "OTIR" and "OTDR". */

        /* Prefix group. */

        CB_PREFIX,
        DD_PREFIX,
        FD_PREFIX,
        ED_PREFIX,

        /* Special instruction group. */

        ED_UNDEFINED            /* ED_UNDEFINED is used to catch undefined
                                 * 0xed prefixed opcodes.
                                 */

};