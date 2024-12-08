#ifndef MACHINE_TO_ASM
#define MACHINE_TO_ASM

#include <stdint.h>

// define the diferent type of OPCODE as const
#define OPCODE_R_Type (0b0110011) //add to and instructions
#define OPCODE_I_Type1 (0b0000011) //lb to lbhu instructions
#define OPCODE_I_Type2 (0b0001111) //fence and fence.i
#define OPCODE_I_Type3 (0b0010011) // addi to andi
#define OPCODE_I_Type4 (0b1100111) //jalr
#define OPCODE_I_Type5 (0b1110011) //ecall to CSRRCI
#define OPCODE_S_Type (0b0100011) //sb , sh and sw
#define OPCODE_SB_Type (0b1100011) //beq to bgeu
#define OPCODE_U_Type1  (0b0010111) //auipc
#define OPCODE_U_Type2  (0b0110111) //lui
#define OPCODE_UJ_Type (0b1101111) //jal

// array of normal registers (without floating point registers) 
const char * normal_register[32] = {"zero", 
				 "ra",
				 "sp", 
				 "gp", 
				 "tp", 	
				 "t0", 	
				 "t1", 
				 "t2", 
				 "s0/fp", 
				 "s1", 
				 "a0", 
				 "a1", 
				 "a2", 
				 "a3", 
				 "a4", 
				 "a5", 
				 "a6", 
				 "a7", 
				 "s2", 
				 "s3", 
				 "s4", 
				 "s5", 
				 "s6", 
				 "s7", 
				 "s8", 
				 "s9", 
				 "s10", 
				 "s11", 
				 "t3", 
				 "t4", 
				 "t5", 
				 "t6"};  

#endif 
