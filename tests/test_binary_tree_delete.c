#include "../Unity/unity.h"
#include "../binary_trees.h"

void setUp(void)
{
}

void tearDown(void)
{
}


void test_give_null(void)
{
	binary_tree_t *toTest = NULL;

	binary_tree_delete(toTest);
	TEST_ASSERT_NULL(toTest);
}

int main(void)
{
    UNITY_BEGIN();
	RUN_TEST(test_give_null);
    return UNITY_END();
}
