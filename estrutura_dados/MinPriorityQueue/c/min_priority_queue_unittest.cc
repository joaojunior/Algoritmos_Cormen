#include "min_priority_queue.h"
#include <gtest/gtest.h>
 
TEST(MinPriorityQueue, Minimum){
    MinPriorityQueue min_priority_queue;
    allocate_memory(&min_priority_queue, 9);
    set_key_i(&min_priority_queue, 1, 1);
    set_key_i(&min_priority_queue, 2, 2);
    set_key_i(&min_priority_queue, 3, 3);
    set_key_i(&min_priority_queue, 4, 19);
    set_key_i(&min_priority_queue, 5, 17);
    set_key_i(&min_priority_queue, 6, 7);
    set_key_i(&min_priority_queue, 7, 25);
    set_key_i(&min_priority_queue, 8, 36);
    set_key_i(&min_priority_queue, 9, 100);
    ASSERT_EQ(1, minimum(&min_priority_queue));
}

TEST(MinPriorityQueue, ExtractMinimum){
    MinPriorityQueue min_priority_queue;
    allocate_memory(&min_priority_queue, 9);
    set_key_i(&min_priority_queue, 1, 1);
    set_key_i(&min_priority_queue, 2, 2);
    set_key_i(&min_priority_queue, 3, 3);
    set_key_i(&min_priority_queue, 4, 19);
    set_key_i(&min_priority_queue, 5, 17);
    set_key_i(&min_priority_queue, 6, 7);
    set_key_i(&min_priority_queue, 7, 25);
    set_key_i(&min_priority_queue, 8, 36);
    set_key_i(&min_priority_queue, 9, 100);
    ASSERT_EQ(1, extract_minimum(&min_priority_queue));
    ASSERT_EQ(8, lenght(&min_priority_queue));
    ASSERT_EQ(2, get_key_i(&min_priority_queue, 1));
    ASSERT_EQ(17, get_key_i(&min_priority_queue, 2));
    ASSERT_EQ(3, get_key_i(&min_priority_queue, 3));
    ASSERT_EQ(19, get_key_i(&min_priority_queue, 4));
    ASSERT_EQ(100, get_key_i(&min_priority_queue, 5));
    ASSERT_EQ(7, get_key_i(&min_priority_queue, 6));
    ASSERT_EQ(25, get_key_i(&min_priority_queue, 7));
    ASSERT_EQ(36, get_key_i(&min_priority_queue, 8));
}

TEST(MinPriorityQueue, DecreaseKey){
    MinPriorityQueue min_priority_queue;
    allocate_memory(&min_priority_queue, 9);
    set_key_i(&min_priority_queue, 1, 1);
    set_key_i(&min_priority_queue, 2, 2);
    set_key_i(&min_priority_queue, 3, 3);
    set_key_i(&min_priority_queue, 4, 19);
    set_key_i(&min_priority_queue, 5, 17);
    set_key_i(&min_priority_queue, 6, 7);
    set_key_i(&min_priority_queue, 7, 25);
    set_key_i(&min_priority_queue, 8, 36);
    set_key_i(&min_priority_queue, 9, 100);
    decrease_key(&min_priority_queue, 7, 0);
    ASSERT_EQ(0, get_key_i(&min_priority_queue, 1));
    ASSERT_EQ(2, get_key_i(&min_priority_queue, 2));
    ASSERT_EQ(1, get_key_i(&min_priority_queue, 3));
    ASSERT_EQ(19, get_key_i(&min_priority_queue, 4));
    ASSERT_EQ(17, get_key_i(&min_priority_queue, 5));
    ASSERT_EQ(7, get_key_i(&min_priority_queue, 6));
    ASSERT_EQ(3, get_key_i(&min_priority_queue, 7));
    ASSERT_EQ(36, get_key_i(&min_priority_queue, 8));
    ASSERT_EQ(100, get_key_i(&min_priority_queue, 9));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}