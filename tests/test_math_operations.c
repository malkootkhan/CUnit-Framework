#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "math_operations.h"  // Include the header file for the functions

// Test case for the add function
void test_add(void) {
    CU_ASSERT(add(2, 3) == 5);
    CU_ASSERT(add(0, 0) == 0);
    CU_ASSERT(add(-1, 1) == 0);
}

// Test case for the subtract function
void test_subtract(void) {
    CU_ASSERT(subtract(5, 3) == 2);
    CU_ASSERT(subtract(0, 0) == 0);
    CU_ASSERT(subtract(10, 5) == 5);
}

int main() {
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    // Create a test suite
    CU_pSuite pSuite = CU_add_suite("MathOperationsSuite", 0, 0);
    if (pSuite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the test cases to the suite
    if ((CU_add_test(pSuite, "test of add()", test_add) == NULL) ||
        (CU_add_test(pSuite, "test of subtract()", test_subtract) == NULL)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run the tests and display results in basic mode
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Clean up the CUnit registry
    CU_cleanup_registry();
    return CU_get_error();
}

