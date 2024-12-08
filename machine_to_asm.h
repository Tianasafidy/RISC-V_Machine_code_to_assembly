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

  
uint16_t get_SB_Imm(uint32_t hex_code); 

uint8_t get_rs2_reg(uint32_t hex_code);
uint8_t get_rs1_reg(uint32_t hex_code);
uint16_t get_imm_31_25(uint32_t hex_code);
uint8_t get_rd_reg(uint32_t hex_code);

const char * get_I_Type1_inst(uint32_t hex_code);

const char * get_R_Type_inst(uint32_t hex_code);

const char * get_I_Type2_inst(uint32_t hex_code);

const char * get_I_Type3_inst(uint32_t hex_code);

const char * get_I_Type4_inst(uint32_t hex_code); 

const char * get_I_Type5_inst(uint32_t hex_code);


const char * get_U_Type1_inst(uint32_t hex_code);


const char * get_SB_Type_inst(uint32_t hex_code);
const char * get_U_Type2_inst(uint32_t hex_code);

const char * get_UJ_Type_inst(uint32_t hex_code);
const char * get_S_Type_inst(uint32_t hex_code);

void get_instruct(uint32_t hex_code);
void to_binary(uint32_t  num, char *bin) ;
void initialize_buff(char * buff , uint32_t size);

#endif 
