#include "min_priority_queue.h"
#include <gtest/gtest.h>
 
TEST(MinPriorityQueue, Minimum){
    MinPriorityQueue min_priority_queue;
    allocate_memory(&min_priority_queue, 9);
    set_value_and_key_i(&min_priority_queue, 1, 1, 0);
    set_value_and_key_i(&min_priority_queue, 2, 2, 1);
    set_value_and_key_i(&min_priority_queue, 3, 3, 2);
    set_value_and_key_i(&min_priority_queue, 4, 19, 3);
    set_value_and_key_i(&min_priority_queue, 5, 17, 4);
    set_value_and_key_i(&min_priority_queue, 6, 7, 5);
    set_value_and_key_i(&min_priority_queue, 7, 25, 6);
    set_value_and_key_i(&min_priority_queue, 8, 36, 7);
    set_value_and_key_i(&min_priority_queue, 9, 100, 8);
    ASSERT_EQ(0, minimum(&min_priority_queue));
}

TEST(MinPriorityQueue, ExtractMinimum){
    MinPriorityQueue min_priority_queue;
    allocate_memory(&min_priority_queue, 9);
    set_value_and_key_i(&min_priority_queue, 1, 1, 0);
    set_value_and_key_i(&min_priority_queue, 2, 2, 1);
    set_value_and_key_i(&min_priority_queue, 3, 3, 2);
    set_value_and_key_i(&min_priority_queue, 4, 19, 3);
    set_value_and_key_i(&min_priority_queue, 5, 17, 4);
    set_value_and_key_i(&min_priority_queue, 6, 7, 5);
    set_value_and_key_i(&min_priority_queue, 7, 25, 6);
    set_value_and_key_i(&min_priority_queue, 8, 36, 7);
    set_value_and_key_i(&min_priority_queue, 9, 100, 8);
    ASSERT_EQ(0, extract_minimum(&min_priority_queue));
    ASSERT_EQ(8, lenght(&min_priority_queue));
    ASSERT_EQ(1, get_key_i(&min_priority_queue, 1));
    ASSERT_EQ(4, get_key_i(&min_priority_queue, 2));
    ASSERT_EQ(2, get_key_i(&min_priority_queue, 3));
    ASSERT_EQ(3, get_key_i(&min_priority_queue, 4));
    ASSERT_EQ(8, get_key_i(&min_priority_queue, 5));
    ASSERT_EQ(5, get_key_i(&min_priority_queue, 6));
    ASSERT_EQ(6, get_key_i(&min_priority_queue, 7));
    ASSERT_EQ(7, get_key_i(&min_priority_queue, 8));
}

TEST(MinPriorityQueue, DecreaseKey){
    MinPriorityQueue min_priority_queue;
    allocate_memory(&min_priority_queue, 9);
    set_value_and_key_i(&min_priority_queue, 1, 1, 0);
    set_value_and_key_i(&min_priority_queue, 2, 2, 1);
    set_value_and_key_i(&min_priority_queue, 3, 3, 2);
    set_value_and_key_i(&min_priority_queue, 4, 19, 3);
    set_value_and_key_i(&min_priority_queue, 5, 17, 4);
    set_value_and_key_i(&min_priority_queue, 6, 7, 5);
    set_value_and_key_i(&min_priority_queue, 7, 25, 6);
    set_value_and_key_i(&min_priority_queue, 8, 36, 7);
    set_value_and_key_i(&min_priority_queue, 9, 100, 8);
    decrease_key(&min_priority_queue, 6, 0);
    ASSERT_EQ(6, get_key_i(&min_priority_queue, 1));
    ASSERT_EQ(1, get_key_i(&min_priority_queue, 2));
    ASSERT_EQ(0, get_key_i(&min_priority_queue, 3));
    ASSERT_EQ(3, get_key_i(&min_priority_queue, 4));
    ASSERT_EQ(4, get_key_i(&min_priority_queue, 5));
    ASSERT_EQ(5, get_key_i(&min_priority_queue, 6));
    ASSERT_EQ(2, get_key_i(&min_priority_queue, 7));
    ASSERT_EQ(7, get_key_i(&min_priority_queue, 8));
    ASSERT_EQ(8, get_key_i(&min_priority_queue, 9));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}