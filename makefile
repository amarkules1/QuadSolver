.DEFAULT_GOAL := compile

cc = gcc
CFLAGS = -Wall -pedantic -std="gnu99"

compile: main.o inputReader.o quadSolver.o inputValidation.o
	$(cc) $(CFLAGS) quadSolver -lm main.o inputReader.o quadSolver.o inputValidation.o -o quadSolver

main.o: main.c inputReader.h quadSolver.h inputValidation.h
	$(cc) $(CFLAGS) -c main.c
inputReader.o: inputReader.c 
	$(cc) $(CFLAGS) -g -c inputReader.c -o inputReader.o
quadSolver.o: quadSolver.c
	$(cc) $(CFLAGS) -lm -c quadSolver.c
inputValidation.o: inputValidation.c
	$(cc) $(CFLAGS) -c inputValidation.c

inputReaderTest.o: tests/inputReader.c
	$(cc) $(CFLAGS) -c tests/inputReader.c -o inputReaderTest.o -lcunit

mainTest.o: tests/main.c
	$(cc) $(CFLAGS) -c tests/main.c -lcunit

inputValidationTest.o: tests/inputValidation.c
	$(cc) $(CFLAGS)  -c tests/inputValidation.c -lcunit

quadSolverTest.o: tests/quadSolver.c
	$(cc) $(CFLAGS)  -c tests/quadSolver.c -lcunit -lm

inputReaderTest: inputReaderTest.o inputReader.o
	$(cc) $(CFLAGS)  inputReader.o inputReaderTest.o -o inputReaderTest -lcunit



mainTest: main.o inputReader.o inputValidation.o quadSolver.o mainTest.o
	$(cc) $(CFLAGS) main.o inputReader.o inputValidation.o quadSolver.o mainTest.o -lcunit -lm

inputValidationTest: inputValidation.o inputValidationTest.o
	$(cc) $(CFLAGS) inputValidation.o inputValidationTest.o -lcunit

quadSolverTest: quadSolverTest.o quadSolver.o
	$(cc) $(CFLAGS) quadSolverTest.o -lcunit -lm

clean:
	rm -f *.o quadSolver mainTest inputReaderTest 