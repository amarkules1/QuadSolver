 #include "../inputValidation.h"
#include <CUnit/CUnit.h>
#include <CUnit/Automated.h>





void test_validateInputFloats(void){
    float ret;
    ret = validateInput("1.24323");
    CU_ASSERT(ret > (1.24323 - 0.0000001) && ret < (1.24323 + 0.0000001));
    ret = validateInput("52245.14567");
    CU_ASSERT(ret > (52245.14567 - 0.01) && ret < (52245.14567 + 0.01));
    ret = validateInput("325.6543");
    CU_ASSERT(ret > (325.6543 - 0.0001) && ret < (325.6543 + 0.0001));
    ret = validateInput("2541815");
    CU_ASSERT(ret > (2541815 - 1) && ret < (2541815 + 1));
    ret = validateInput("-1.24323");
    CU_ASSERT(ret > (-1.24323 - 0.0000001) && ret < (-1.24323 + 0.0000001));
    ret = validateInput("-52245.14567");
    CU_ASSERT(ret > (-52245.14567 - 0.01) && ret < (-52245.14567 + 0.01));
    ret = validateInput("-325.6543");
    CU_ASSERT(ret > (-325.6543 - 0.0001) && ret < (-325.6543 + 0.0001));
    ret = validateInput("-2541815");
    CU_ASSERT(ret > (-2541815 - 1) && ret < (-2541815 + 1));
}

void test_validateInputBadInput(void){
    float ret;
    ret = validateInput("abcd");
    CU_ASSERT(ret!=ret);
    ret = validateInput("abcd1.0");
    CU_ASSERT(ret!=ret);
    ret = validateInput("NaN");
    CU_ASSERT(ret!=ret);
    ret = validateInput("INFINITY");
    CU_ASSERT(ret==INFINITY);
    ret = validateInput("-INFINITY");
    CU_ASSERT(ret==-INFINITY);
}

int close(){
    return 0;
}

int init(){
    return 0;
}
int main(int argc, char const *argv[])
{
    CU_pSuite psuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }

    psuite = CU_add_suite("ValidateInputSuite",init,close);
    CU_add_test(psuite,"validate input floats",test_validateInputFloats);
    CU_add_test(psuite,"validate input bad input",test_validateInputBadInput);
    CU_automated_run_tests();
    return 0;
}