#include "../inputReader.h"
#include <string.h>
#include <stdio.h>
#include <CUnit/CUnit.h>
#include <CUnit/Automated.h>





void test_readFromConsole(void){
    quadConstants* test;
    test = readFromConsole();
    CU_ASSERT_FATAL(test != NULL);
    CU_ASSERT(strcmp(test->A,"12.152")==0);
    CU_ASSERT(strcmp(test->B,"64.23")==0);
    CU_ASSERT(strcmp(test->C,"77534")==0);
    test = readFromConsole();
    CU_ASSERT_FATAL(test == NULL);
}
int close(){
    fclose(stdin);
    return 0;
}

int init(){
    stdin = freopen("tests/inputReaderSTDIN","r",stdin);
    return 0;
}
int main(int argc, char const *argv[])
{
    CU_pSuite psuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }

    psuite = CU_add_suite("readFromConsoleSuite",init,close);
    CU_add_test(psuite,"readFromConsole",test_readFromConsole);
    CU_automated_run_tests();
    return 0;
}
