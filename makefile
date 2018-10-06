.DEFAULT_GOAL := compile

cc = gcc;
CFLAGS = -w -pedant

compile: main.o inputReader.o quadSolver.o inputValidation.o
	$(cc) $(CFLAGS) quadSolver -lm -c main.o inputReader.o quadSolver.o inputValidation.o

main.o: main.c inputReader.h quadSolver.h inputValidation.h
	$(cc) $(CFLAGS) -c main.c
inputReader.o: inputReader.c 
	$(cc) $(CFLAGS) -c inputReader.c
quadSolver.o: quadSolver.c
	$(cc) $(CFLAGS) -lm -c quadSolver.c
inputValidation.o: inputValidation.c
	$(cc) $(CFLAGS) -c inputValidation.c

clean:
	rm *.o quadSolver