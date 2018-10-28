#include <CUnit/Basic.h>
#include "quadSolver.h"
#include "answerChecker.h"

int answerCheckerTest_goodSolution(){
	int retVal = checkAnswer(1.0,-5.0,6.0,3.0);
	CU_ASSERT(retVal==0)

}

int answerCheckerTest_tooLow(){
	int retVal = checkAnswer(1.0,-5.0,6.0,2.95);
	CU_ASSERT(retVal == 1);

}

int answerCheckerTest_tooHigh(){
	int retVal = checkAnswer(1.0,-5.0,6.0,3.05);
	CU_ASSERT(retVal == -1);
}
