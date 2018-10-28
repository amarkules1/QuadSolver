#include "quadSolver.h"
#include <CUnit/Basic.h>

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
