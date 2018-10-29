#include "answerCheckerTest.h"
void answerCheckerTest_goodSolution(){
	int retVal = checkAnswer(1.0,-5.0,6.0,3.0);
	CU_ASSERT(retVal==0)

}

void answerCheckerTest_tooLow(){
	int retVal = checkAnswer(1.0,-5.0,6.0,2.95);
	CU_ASSERT(retVal == 1);

}

void answerCheckerTest_tooHigh(){
	int retVal = checkAnswer(1.0,-5.0,6.0,3.05);
	CU_ASSERT(retVal == -1);
}

int close(){
    return 0;
}

int init(){
    return 0;
}

void main(int argc, char * argv[]){
	
	CU_pSuite psuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }

    psuite = CU_add_suite("answerCheckerSuite",init,close);
    CU_add_test(psuite,"answerCheckerTest_goodSolution",answerCheckerTest_goodSolution);
    CU_add_test(psuite,"answerCheckerTest_tooLow",answerCheckerTest_tooLow);
    CU_add_test(psuite,"answerCheckerTest_tooHigh",answerCheckerTest_tooHigh);
    CU_automated_run_tests();
}
