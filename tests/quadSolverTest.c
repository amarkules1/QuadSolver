#include "quadSolverTest.h"

int close(){
    return 0;
}

int init(){
    return 0;
}

int quadSolverTest_basic(){
    double x1;
    double x2;
    int retVal = quadSolver(1.0,0.0,-9.0,&x1,&x2);
    CU_ASSERT(x1 <= 3.01);
    CU_ASSERT(x1 >= 2.99);
    CU_ASSERT(x2 >= -3.01);
    CU_ASSERT(x1 <= -2.99);
    CU_ASSERT(retVal == 2);
    return 0;
}

int quadSolverTest_ZeroDeterminant(){
	double x1, x2;
	int retVal = quadSolver(1.0,4.0,4.0, &x1, &x2);
	CU_ASSERT(x1 <= 8.01);
	CU_ASSERT(x1 >= 7.99);
	CU_ASSERT(x2 != x2);
	CU_ASSERT(retVal == 1);
	return 0;
}

int quadSolverTest_Imaginary(){
	double x1, x2;
	int retVal = quadSolver(1.0,1.0,4.0, &x1, &x2);
	CU_ASSERT(x1 != x1);
	CU_ASSERT(x2 != x2);
	CU_ASSERT(retVal == 0);
	return 0;
}


void main(int argc, char * argv[]){
	
	CU_pSuite psuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }

    psuite = CU_add_suite("readFromConsoleSuite",init,close);
    CU_add_test(psuite,"readFromConsole",quadSolverTest_basic);
    CU_add_test(psuite,"readFromConsole",quadSolverTest_ZeroDeterminant);
    CU_add_test(psuite,"readFromConsole",quadSolverTest_Imaginary);
    CU_automated_run_tests();
}
