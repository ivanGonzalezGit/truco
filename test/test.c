#include <unity.h>

void setUp(void) {}    // Se ejecuta antes de cada prueba
void tearDown(void) {} // Se ejecuta después de cada prueba

void test_suma(void) {
    TEST_ASSERT_EQUAL(4, 2 + 2);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_suma);
    return UNITY_END();
}