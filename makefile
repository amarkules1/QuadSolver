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

inputReaderTest.o: inputReader.c tests/inputReader.c
	$(cc) $(CFLAGS) -g -lcunit -c tests/inputReader.c -o inputReaderTest.o

mainTest.o: main.c tests/main.c
	$(cc) $(CFLAGS)  -lcunit -c main.c tests/main.c

inputValidationTest.o: inputValidation.c tests/inputValidation.c
	$(cc) $(CFLAGS)  -lcunit -c inputValidation.c tests/inputValidation.c

quadSolverTest.o: quadSolver.c tests/quadSolver.c
	$(cc) $(CFLAGS)  -lcunit -lm -c quadSolver.c tests/quadSolver.c

inputReaderTest: inputReader.o inputReaderTest.o
	$(cc) $(CFLAGS) -g  inputReader.o inputReaderTest.o -o inputReaderTest -lcunit

testInputReader: inputReaderTest
	inputReaderTest < tests/

mainTest: main.o inputReader.o inputValidation.o quadSolver.o mainTest.o
	$(cc) $(CFLAGS) -lcunit -lm -c main.o inputReader.o inputValidation.o quadSolver.o mainTest.o

inputValidationTest: inputValidation.o inputValidationTest.o
	$(cc) $(CFLAGS) -lcunit -c inputValidation.o inputValidationTest.o

quadSolverTest: quadSolver.o quadSolverTest.o
	$(cc) $(CFLAGS) -lcunit -lm -c quadSolver.o quadSolverTest.o

clean:
	rm *.o quadSolver mainTest inputReaderTest 