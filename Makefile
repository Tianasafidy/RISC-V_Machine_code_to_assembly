OBJS = main.o machine_to_asm.o 
EXE := main

all: run 

run: $(EXE)
	./$(EXE)

$(EXE):  $(OBJS)  	

clean: 
	rm -f *.o
	rm -f main
