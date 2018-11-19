.DEFAULT_GOAL := quadSolver
version = 1_0
cc = gcc
CFLAGS = -Wall -pedantic -std="gnu99"

package: quadSolver
	mkdir src
	cp *.c src
	cp *.h src
	cp tests src
	mkdir quadSolver_$(version)
	mv -R src quadSolver_$(version)
	cp quadSolver quadSolver_$(version)
	cp README quadSolver_$(version)
	cp LICENSE quadSolver_$(version)
	tar -zcvf quadSolver_$(version).tar.gz quadSolver_$(version)
	
quadSolver: main.o inputReader.o quadSolver.o inputValidation.o answerChecker.o
	$(cc) $(CFLAGS) main.o inputReader.o quadSolver.o inputValidation.o answerChecker.o -o quadSolver -lm

debug: main.o inputReader.o quadSolver.o inputValidation.o answerChecker.o
	$(cc) $(CFLAGS) -g main.o inputReader.o quadSolver.o inputValidation.o answerChecker.o -o quadSolver -lm

main.o: main.c inputReader.h quadSolver.h inputValidation.h answerChecker.h
	$(cc) $(CFLAGS) -g -c main.c -o main.o
inputReader.o: inputReader.c 
	$(cc) $(CFLAGS) -c inputReader.c -o inputReader.o
quadSolver.o: quadSolver.c
	$(cc) $(CFLAGS) -lm -c quadSolver.c -o quadSolver.o
inputValidation.o: inputValidation.c
	$(cc) $(CFLAGS) -c inputValidation.c -o inputValidation.o
answerChecker.o: answerChecker.c
	$(cc) $(CFLAGS) -c answerChecker.c -o answerChecker.o



inputReaderTest.o: tests/inputReader.c
	$(cc) $(CFLAGS) -c tests/inputReader.c -o inputReaderTest.o -lcunit

answerCheckerTest.o: tests/answerCheckerTest.c tests/answerCheckerTest.h
	$(cc) $(CFLAGS) -c tests/answerCheckerTest.c -o answerCheckerTest.o -lcunit

inputValidationTest.o: tests/inputValidation.c
	$(cc) $(CFLAGS)  -c tests/inputValidation.c -o inputValidationTest.o


quadSolverTest.o: tests/quadSolverTest.c tests/quadSolverTest.h
	$(cc) $(CFLAGS)  -c tests/quadSolverTest.c -o quadSolverTest.o -lcunit -lm

inputReaderTest: inputReaderTest.o inputReader.o
	$(cc) $(CFLAGS)  inputReader.o inputReaderTest.o -o inputReaderTest -lcunit

answerCheckerTest: answerCheckerTest.o answerChecker.o
	$(cc) $(CFLAGS) answerChecker.o answerCheckerTest.o -o answerCheckerTest -lcunit

inputValidationTest: inputValidation.o inputValidationTest.o
	$(cc) $(CFLAGS) inputValidation.o inputValidationTest.o -o inputValidationTest -lcunit

quadSolverTest: quadSolverTest.o quadSolver.o answerChecker.o
	$(cc) $(CFLAGS) quadSolver.o answerChecker.o quadSolverTest.o -o quadSolverTest -lcunit -lm

runAllUnitTests: inputReaderTest mainTest inputValidationTest quadSolverTest
	rm -f CUnit*.xml
	./inputReaderTest
	mv CUnitAutomated-Results.xml CUnitAutomated-Results-inputReader.xml
	./inputValidationTest
	mv CUnitAutomated-Results.xml CUnitAutomated-Results-inputValidation.xml
	./quadSolverTest
	mv CUnitAutomated-Results.xml CUnitAutomated-Results-quadSolver.xml
	./answerCheckerTest
	mv CUnitAutomated-Results.xml CUnitAutomated-Results-answerChecker.xml
clean:
	rm -f *.o quadSolver mainTest inputReaderTest CUnit*.xml
