#ifndef ANSWERCHECKERTEST_H
#define ANSWERCHECKERTEST_H
#include <CUnit/CUnit.h>
#include <CUnit/Automated.h>
#include "../quadSolver.h"
#include "../answerChecker.h"

void answerCheckerTest_goodSolution();

void answerCheckerTest_tooLow();

void answerCheckerTest_tooHigh();

#endif

