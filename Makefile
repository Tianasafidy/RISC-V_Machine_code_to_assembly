RISC = riscv64-linux-gnu-
RCC = $(RISC)gcc
RDUMP = $(RISC)objdump

OBJS = main.o machine_to_asm.o 
EXE := main

all: run 

run: $(EXE)
	./$(EXE) > asm.txt 

$(EXE):  $(OBJS)  	

dump: risc
	$(RDUMP) -d c_implementation.o

risc: c_implementation.c  
	$(RCC) -g -c -Wall -O0 -mcmodel=medlow -mabi=ilp32 -march=rv32im -o c_implementation.o $^ 

clean: 
	rm -f *.o
	rm -f main
	rm -f *.txt 
