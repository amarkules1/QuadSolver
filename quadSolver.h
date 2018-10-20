#ifndef QUADSOLVER_H
#define QUADSOLVER_H

int quadSolver(double a, double b, double c, double * x1, double * x2);

int isDeterminantZero(double a, double b, double c);

int isDeterminantNegative(double a, double b, double c);

int approxZero(double z);

#endif
