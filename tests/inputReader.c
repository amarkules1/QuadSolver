#include "../inputReader.h"
#include <string.h>
#include <stdio.h>
#include <Cunit/Cunit.h>
#include <CUnit/Automated.h>


void test_readFromConsole(void){
    quadConstants* test;
    test = readFromConsole();
    CU_ASSERT_FATAL(test != NULL);
    CU_ASSERT(strcp(test->A,12.152)==0);
    CU_ASSERT(strcp(test->B==64.23)==0);
    CU_ASSERT(strcp(test->C==77534)==0);
    test = readFromConsole();
    CU_ASSERT_FATAL(test == NULL);
}
void none(void){}

int main(int argc, char const *argv[])
{
    CU_pSuite psuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }

    psuit = CU_add_suite("readFromConsoleSuite",none,none);
    CU_add_test(psuit,"readFromConsole",test_readFromConsole);
    CU_automated_run_tests(void)
    return 0;
}
