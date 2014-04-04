#include "heap_max.h"
#include <gtest/gtest.h>

TEST(HeapMaxTest, Parent){
    ASSERT_EQ(4, parent(8));
    ASSERT_EQ(4, parent(9));
}

TEST(HeapMaxTest, Left){
    ASSERT_EQ(6, left(3));
    ASSERT_EQ(8, left(4));
}

TEST(HeapMaxTest, Right){
    ASSERT_EQ(7, right(3));
    ASSERT_EQ(9, right(4));
}

TEST(HeapMaxTest, MaxHeapify){
    HeapMax heap_max;
    allocate_memory(&heap_max, 10);
    heap_max.values[1] = 16;
    heap_max.values[2] = 4;
    heap_max.values[3] = 10;
    heap_max.values[4] = 14;
    heap_max.values[5] = 7;
    heap_max.values[6] = 9;
    heap_max.values[7] = 3;
    heap_max.values[8] = 2;
    heap_max.values[9] = 8;
    heap_max.values[10] = 1;
    max_heapify(&heap_max, 2);
    ASSERT_EQ(16, heap_max.values[1]);
    ASSERT_EQ(14, heap_max.values[2]);
    ASSERT_EQ(10, heap_max.values[3]);
    ASSERT_EQ(8, heap_max.values[4]);
    ASSERT_EQ(7, heap_max.values[5]);
    ASSERT_EQ(9, heap_max.values[6]);
    ASSERT_EQ(3, heap_max.values[7]);
    ASSERT_EQ(2, heap_max.values[8]);
    ASSERT_EQ(4, heap_max.values[9]);
    ASSERT_EQ(1, heap_max.values[10]);
}

TEST(HeapMaxTest, BuildMaxHeap){
    HeapMax heap_max;
    allocate_memory(&heap_max, 10);
    heap_max.values[1] = 4;
    heap_max.values[2] = 1;
    heap_max.values[3] = 3;
    heap_max.values[4] = 2;
    heap_max.values[5] = 16;
    heap_max.values[6] = 9;
    heap_max.values[7] = 10;
    heap_max.values[8] = 14;
    heap_max.values[9] = 8;
    heap_max.values[10] = 7;
    build_max_heap(&heap_max);
    ASSERT_EQ(16, heap_max.values[1]);
    ASSERT_EQ(14, heap_max.values[2]);
    ASSERT_EQ(10, heap_max.values[3]);
    ASSERT_EQ(8, heap_max.values[4]);
    ASSERT_EQ(7, heap_max.values[5]);
    ASSERT_EQ(9, heap_max.values[6]);
    ASSERT_EQ(3, heap_max.values[7]);
    ASSERT_EQ(2, heap_max.values[8]);
    ASSERT_EQ(4, heap_max.values[9]);
    ASSERT_EQ(1, heap_max.values[10]);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}