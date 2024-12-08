OBJS = main.o machine_to_asm.o 
EXE := main

all: run 

run: $(EXE)
	./$(EXE) > asm.txt 

$(EXE):  $(OBJS)  	

clean: 
	rm -f *.o
	rm -f main
	rm -f *.txt 
