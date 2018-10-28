#include "quadSolverTest.c"
#include "answerCheckerTest.c"

int main(int argc, char * argv[]){
	quadSolverTest_basic();
	quadSolverTest_ZeroDeterminant();
	quadSolverTest_Imaginary();
	answerCheckerTest_goodSolution();
	answerCheckerTest_tooLow();
	answerCheckerTest_tooHigh();
	
}
