#include "machine_to_asm.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

uint32_t hex_instruction[22] = {0x00050893,  
                                0x00068513,  
                                0x04088063,
                                0x04058263,
                                0x04060063,
                                0x04d05063,
                                0x00088793,
                                0x00269713,
                                0x00e888b3,
                                0x0007a703,
                                0x0005a803,
                                0x01070733,
                                0x00e62023,
                                0x00478793,  
                                0x00458593,  
                                0x00460613,  
                                0xff1792e3,
                                0x00008067,
                                0xfff00513,
                                0x00008067,
                                0xfff00513,
                                0x00008067 };
int main(void){
	char bin[32];
	int _addr = 0; 
	// display binary machine code 	
	for(int k = 0; k < 22; k++){
		initialize_buff(bin, 32); 
		to_binary(hex_instruction[k], bin);
		printf("%x : ", _addr);
		_addr += 4;  
		for(int j = 0 ; j < 32; j ++){
			printf("%c", bin[j]); 
		}
		printf("\n");   
	}
	
	_addr = 0; 
	//display the assembly code
	for(int i = 0; i <22 ; i++){
		printf("%x : ", _addr); 
		_addr += 4;  
		get_instruct(hex_instruction[i]); 
		printf("\n"); 
	}


}

