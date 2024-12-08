OBJS = main.o machine_to_asm.o 
EXE := main

$(EXE):  $(OBJS)  	

clean: 
	rm -f *.o
	rm -f main
