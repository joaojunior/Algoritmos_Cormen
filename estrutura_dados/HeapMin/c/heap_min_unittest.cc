#include "heap_min.h"
#include <gtest/gtest.h>

TEST(HeapMinTest, Parent){
    ASSERT_EQ(4, parent(8));
    ASSERT_EQ(4, parent(9));
}

TEST(HeapMinTest, Left){
    ASSERT_EQ(6, left(3));
    ASSERT_EQ(8, left(4));
}

TEST(HeapMinTest, Right){
    ASSERT_EQ(7, right(3));
    ASSERT_EQ(9, right(4));
}

TEST(HeapMinTest, MinHeapify){
    HeapMin heap_min;
    allocate_memory(&heap_min, 9);
    set_value_and_key_i(&heap_min, 1, 1, 0);
    set_value_and_key_i(&heap_min, 2, 100, 1);
    set_value_and_key_i(&heap_min, 3, 3, 2);
    set_value_and_key_i(&heap_min, 4, 2, 3);
    set_value_and_key_i(&heap_min, 5, 19, 4);
    set_value_and_key_i(&heap_min, 6, 36, 5);
    set_value_and_key_i(&heap_min, 7, 7, 6);
    set_value_and_key_i(&heap_min, 8, 25, 7);
    set_value_and_key_i(&heap_min, 9, 17, 8);
    min_heapify(&heap_min, 2);
    ASSERT_EQ(1, heap_min.values[1].value);
    ASSERT_EQ(2, heap_min.values[2].value);
    ASSERT_EQ(3, heap_min.values[3].value);
    ASSERT_EQ(17, heap_min.values[4].value);
    ASSERT_EQ(19, heap_min.values[5].value);
    ASSERT_EQ(36, heap_min.values[6].value);
    ASSERT_EQ(7, heap_min.values[7].value);
    ASSERT_EQ(25, heap_min.values[8].value);
    ASSERT_EQ(100, heap_min.values[9].value);
    ASSERT_EQ(0, heap_min.values[1].key);
    ASSERT_EQ(3, heap_min.values[2].key);
    ASSERT_EQ(2, heap_min.values[3].key);
    ASSERT_EQ(8, heap_min.values[4].key);
    ASSERT_EQ(4, heap_min.values[5].key);
    ASSERT_EQ(5, heap_min.values[6].key);
    ASSERT_EQ(6, heap_min.values[7].key);
    ASSERT_EQ(7, heap_min.values[8].key);
    ASSERT_EQ(1, heap_min.values[9].key);
    ASSERT_EQ(1, get_position_from_key(&heap_min, 0));
    ASSERT_EQ(9, get_position_from_key(&heap_min, 1));
    ASSERT_EQ(3, get_position_from_key(&heap_min, 2));
    ASSERT_EQ(2, get_position_from_key(&heap_min, 3));
    ASSERT_EQ(5, get_position_from_key(&heap_min, 4));
    ASSERT_EQ(6, get_position_from_key(&heap_min, 5));
    ASSERT_EQ(7, get_position_from_key(&heap_min, 6));
    ASSERT_EQ(8, get_position_from_key(&heap_min, 7));
    ASSERT_EQ(4, get_position_from_key(&heap_min, 8));
}

TEST(HeapMinTest, BuildMinHeap){
    HeapMin heap_min;
    allocate_memory(&heap_min, 9);
    set_value_and_key_i(&heap_min, 1, 100, 0);
    set_value_and_key_i(&heap_min, 2, 36, 1);
    set_value_and_key_i(&heap_min, 3, 25, 2);
    set_value_and_key_i(&heap_min, 4, 19, 3);
    set_value_and_key_i(&heap_min, 5, 17, 4);
    set_value_and_key_i(&heap_min, 6, 7, 5);
    set_value_and_key_i(&heap_min, 7, 3, 6);
    set_value_and_key_i(&heap_min, 8, 2, 7);
    set_value_and_key_i(&heap_min, 9, 1, 8);
    build_min_heap(&heap_min);
    ASSERT_EQ(1, heap_min.values[1].value);
    ASSERT_EQ(2, heap_min.values[2].value);
    ASSERT_EQ(3, heap_min.values[3].value);
    ASSERT_EQ(19, heap_min.values[4].value);
    ASSERT_EQ(17, heap_min.values[5].value);
    ASSERT_EQ(7, heap_min.values[6].value);
    ASSERT_EQ(25, heap_min.values[7].value);
    ASSERT_EQ(36, heap_min.values[8].value);
    ASSERT_EQ(100, heap_min.values[9].value);
    ASSERT_EQ(8, heap_min.values[1].key);
    ASSERT_EQ(7, heap_min.values[2].key);
    ASSERT_EQ(6, heap_min.values[3].key);
    ASSERT_EQ(3, heap_min.values[4].key);
    ASSERT_EQ(4, heap_min.values[5].key);
    ASSERT_EQ(5, heap_min.values[6].key);
    ASSERT_EQ(2, heap_min.values[7].key);
    ASSERT_EQ(1, heap_min.values[8].key);
    ASSERT_EQ(0, heap_min.values[9].key);
    ASSERT_EQ(9, get_position_from_key(&heap_min, 0));
    ASSERT_EQ(8, get_position_from_key(&heap_min, 1));
    ASSERT_EQ(7, get_position_from_key(&heap_min, 2));
    ASSERT_EQ(4, get_position_from_key(&heap_min, 3));
    ASSERT_EQ(5, get_position_from_key(&heap_min, 4));
    ASSERT_EQ(6, get_position_from_key(&heap_min, 5));
    ASSERT_EQ(3, get_position_from_key(&heap_min, 6));
    ASSERT_EQ(2, get_position_from_key(&heap_min, 7));
    ASSERT_EQ(1, get_position_from_key(&heap_min, 8));
}

TEST(HeapMinTest, GetPositionHeap){
    HeapMin heap_min;
    allocate_memory(&heap_min, 9);
    set_value_and_key_i(&heap_min, 1, 1, 0);
    set_value_and_key_i(&heap_min, 2, 100, 1);
    set_value_and_key_i(&heap_min, 3, 3, 2);
    set_value_and_key_i(&heap_min, 4, 2, 3);
    set_value_and_key_i(&heap_min, 5, 19, 4);
    set_value_and_key_i(&heap_min, 6, 36, 5);
    set_value_and_key_i(&heap_min, 7, 7, 6);
    set_value_and_key_i(&heap_min, 8, 25, 7);
    set_value_and_key_i(&heap_min, 9, 17, 8);
    ASSERT_EQ(1, get_position_from_key(&heap_min, 0));
    ASSERT_EQ(2, get_position_from_key(&heap_min, 1));
    ASSERT_EQ(3, get_position_from_key(&heap_min, 2));
    ASSERT_EQ(4, get_position_from_key(&heap_min, 3));
    ASSERT_EQ(5, get_position_from_key(&heap_min, 4));
    ASSERT_EQ(6, get_position_from_key(&heap_min, 5));
    ASSERT_EQ(7, get_position_from_key(&heap_min, 6));
    ASSERT_EQ(8, get_position_from_key(&heap_min, 7));
    ASSERT_EQ(9, get_position_from_key(&heap_min, 8));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}