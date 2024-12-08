#include "machine_to_asm.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>


uint32_t get_rd_reg(uint32_t hex_code){
	static uint8_t _rd_reg; 
	_rd_reg = (hex_code >> 7 ) & 0x1f ; 
	return _rd_reg; 
}

uint32_t get_rs1_reg(uint32_t hex_code){
	static uint8_t _rs1_reg; 
	_rs1_reg = (hex_code >> 15) & 0x1F; 
	return _rS1_reg; 
}
const char * get_R_Type_inst(uint32_t hex_code){
	static uint8_t _funct3, _funct7; 
	_funct3 = (uint8_t)((hex_code >> 12) & 0x00000007); 
	_funct7 = (uint8_t)(hex_code >> 25); 
	const char * _func = "unkown"; 
	if(_funct3 == 0b000){
		_func = (_funct7 == 0b0100000)? "sub": "add"; 
	}else if(_funct3 == 0b001){
		_func = "sll"; 
	}else if(_funct3 == 0b010){
		_func = "slt"; 
	}else if(_funct3 == 0b011){
		_func = "sltu"; 
	}else if(_funct3 == 0b100){
		_func = (_funct7 == 0b0100000)? "sra": "srl"; 
	}else if(_funct3 == 0b110){
		_func = "or"; 
	}else if(_funct3 == 0b111){
		_func = "and"; 
	}
	return _func; 
}

const char * get_I_Type1_inst(uint32_t hex_code){
	static uint8_t _funct3; 
	_funct3 = (uint8_t)((hex_code >> 12) & 0x00000007); 
	const char * _func = "unkown"; 
	if(_funct3 == 0b000){
		_func = "lb"; 
	}else if(_funct3 == 0b001){
		_func = "lh"; 
	}else if(_funct3 == 0b010){
		_func = "lw"; 
	}else if(_funct3 == 0b100){
		_func = "lbu"; 
	}else if(_funct3 == 0b101){
		_func = "lhu";  
	}
	return _func; 
}

const char * get_I_Type2_inst(uint32_t hex_code){
	static uint8_t _funct3; 
	_funct3 = (uint8_t)((hex_code >> 12) & 0x00000007); 
	const char * _func = "unkown"; 
	if(_funct3 == 0b000){
		_func = "fence"; 
	}else if(_funct3 == 0b001){
		_func = "fence.i"; 
	}
	return _func; 
}

const char * get_I_Type3_inst(uint32_t hex_code){
	static uint8_t _funct3, _funct7; 
	_funct3 = (uint8_t)((hex_code >> 12) & 0x00000007); 
	_funct7 = (uint8_t)(hex_code >> 25); 
	
	const char * _func = "unkown"; 
	if(_funct3 == 0b000){
		_func = "addi"; 
	}else if(_funct3 == 0b001){
		_func = "slli"; 
	}else if(_funct3 == 0b010){
		_func = "slti"; 
	}else if(_funct3 == 0b011){
		_func = "sltiu"; 
	}else if(_funct3 == 0b100){
		_func = "xori";  
	}else if(_funct3 == 0b101){
		_func = (_funct7 == 0b0100000) ? "srai":"srli"; 
	}else if(_funct3 == 0b110){
		_func = "ori";
	}else if(_funct3 == 0b111){
		_func = "andi"; 
	}
	return _func; 
}

const char * get_I_Type4_inst(uint32_t hex_code){ 
	return "jalr"; 
}

const char * get_I_Type5_inst(uint32_t hex_code){
	static uint8_t _funct3; 
	static uint16_t _imm_12; 

	_funct3 = (uint8_t)((hex_code >> 12) & 0x00000007); 
	_imm_12 = (uint16_t)(hex_code >> 20);
 
	const char * _func = "unkown"; 
	if(_funct3 == 0b000){
		_func = (_imm_12 == 0x1) ? "ebreak" : "ecall"; 
	}else if(_funct3 == 0b001){
		_func = "CSRRW"; 
	}else if(_funct3 == 0b010){
		_func = "CSRRS"; 
	}else if(_funct3 == 0b011){
		_func = "CSRRC"; 
	}else if(_funct3 == 0b101){
		_func = "CSRRWI"; 
	}else if(_funct3 == 0b110){
		_func = "CSRRSI"; 
	}else if(_funct3 == 0b111){
		_func = "CSRRCI";
	}
	return _func; 
}

const char * get_U_Type1_inst(uint32_t hex_code){
	return "auipc"; 
}

const char * get_U_Type2_inst(uint32_t hex_code){
	return "lui"; 
}

const char * get_S_Type_inst(uint32_t hex_code){
	static uint8_t _funct3; 

	_funct3 = (uint8_t)((hex_code >> 12) & 0x00000007); 
 
	const char * _func = "unkown"; 
	if(_funct3 == 0b000){
		_func = "sb"; 
	}else if(_funct3 == 0b001){
		_func = "sh"; 
	}else if(_funct3 == 0b010){
		_func = "sw"; 
	}
	return _func; 
}

const char * get_SB_Type_inst(uint32_t hex_code){
	static uint8_t _funct3; 

	_funct3 = (uint8_t)((hex_code >> 12) & 0x00000007); 
	// printf("funct3 = %b : ", _funct3);  
	const char * _func = "unkown"; 
	if(_funct3 == 0b000){
		_func = "beq"; 
	}else if(_funct3 == 0b001){
		_func = "bne"; 
	}else if(_funct3 == 0b100){
		_func = "blt"; 
	}else if(_funct3 == 0b101){
		_func = "bge"; 
	}else if(_funct3 == 0b110){
		_func = "bltu"; 
	}else if(_funct3 == 0b111){
		_func = "bgeu"; 
	}
	return _func; 
}

const char * get_UJ_Type_inst(uint32_t hex_code){
	return "jal"; 
}

void get_instruct(uint32_t hex_code){
	static uint8_t _opcode; 
	_opcode =(uint8_t)(hex_code & 0x0000007f); //last 7bits   
	
	if(_opcode == OPCODE_I_Type1){
		const char * inst = get_I_Type1_inst(hex_code); 
		printf("%s ", inst );			
	}else if(_opcode == OPCODE_I_Type2){
		const char * inst = get_I_Type2_inst(hex_code); 
		printf("%s ", inst );
	}else if(_opcode == OPCODE_I_Type3){
		const char * inst = get_I_Type3_inst(hex_code); 
		printf("%s ", inst );
	}else if(_opcode == OPCODE_I_Type4){
		const char * inst = get_I_Type4_inst(hex_code); 
		printf("%s ", inst );
	}else if(_opcode == OPCODE_I_Type5){
		const char * inst = get_I_Type5_inst(hex_code); 
		printf("%s ", inst );
	}else if(_opcode == OPCODE_R_Type){
		const char * inst = get_R_Type_inst(hex_code); 
		printf("%s ", inst );
	}else if(_opcode == OPCODE_S_Type){
		const char * inst = get_S_Type_inst(hex_code); 
		printf("%s ", inst );
	}else if(_opcode == OPCODE_U_Type1){
		const char * inst = get_U_Type1_inst(hex_code); 
		printf("%s ", inst );
	}else if(_opcode == OPCODE_U_Type2){
		const char * inst = get_U_Type2_inst(hex_code); 
		printf("%s ", inst );
	}else if(_opcode == OPCODE_SB_Type){
		const char * inst = get_SB_Type_inst(hex_code); 
		printf("%s ", inst );
	}else if(_opcode == OPCODE_UJ_Type){
		const char * inst = get_UJ_Type_inst(hex_code); 
		printf("%s ", inst );
	} 
}

void to_binary(uint32_t  num, char *bin) {
    for (int i = 31; i >= 0; i--) {
        bin[31 - i] = (num & (1U << i)) ? '1' : '0';
    }
    bin[32] = '\0'; // Null-terminate the string
}

void initialize_buff(char * buff , uint32_t size){
	for(int i = 0; i < size; i++){
		buff[i] = 0; 
	}
}


