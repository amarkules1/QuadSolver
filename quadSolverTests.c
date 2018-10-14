#include "quadSolverTest.h"

int quadSolverTest_basic(){
    double x1;
    double x2;
    quadSolver(1.0,0.0,9.0,&x1,&x2);
    if(x1 <= 3.01 && x1 == 2.99 && x1 <= -3.01 && x1 == -2.99){
        return 1;
    }else{
        return 0;
    }

}