#include "quadSolver.h"

/*
stores calculations in x1 and x2, 
returns 1 for success
(return values should change with more robust implementation)
*/
int quadSolver(double a, double b, double c, double * x1, double * x2){
    double determinant = sqrt((b * b)-4*a*c);
    double higher = (b * -1) + determinant;
    higher = higher / (2 * a);
    double lower = (b * -1) - determinant;
    lower = lower / (2 * a);
    *x1 = higher;
    *x2 = lower;
    return 1;
}