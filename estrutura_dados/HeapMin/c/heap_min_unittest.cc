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
    heap_min.values[1] = 1;
    heap_min.values[2] = 100;
    heap_min.values[3] = 3;
    heap_min.values[4] = 2;
    heap_min.values[5] = 19;
    heap_min.values[6] = 36;
    heap_min.values[7] = 7;
    heap_min.values[8] = 25;
    heap_min.values[9] = 17;
    min_heapify(&heap_min, 2);
    ASSERT_EQ(1, heap_min.values[1]);
    ASSERT_EQ(2, heap_min.values[2]);
    ASSERT_EQ(3, heap_min.values[3]);
    ASSERT_EQ(17, heap_min.values[4]);
    ASSERT_EQ(19, heap_min.values[5]);
    ASSERT_EQ(36, heap_min.values[6]);
    ASSERT_EQ(7, heap_min.values[7]);
    ASSERT_EQ(25, heap_min.values[8]);
    ASSERT_EQ(100, heap_min.values[9]);
}

TEST(HeapMinTest, BuildMinHeap){
    HeapMin heap_min;
    allocate_memory(&heap_min, 9);
    heap_min.values[1] = 100;
    heap_min.values[2] = 36;
    heap_min.values[3] = 25;
    heap_min.values[4] = 19;
    heap_min.values[5] = 17;
    heap_min.values[6] = 7;
    heap_min.values[7] = 3;
    heap_min.values[8] = 2;
    heap_min.values[9] = 1;
    build_min_heap(&heap_min);
    ASSERT_EQ(1, heap_min.values[1]);
    ASSERT_EQ(2, heap_min.values[2]);
    ASSERT_EQ(3, heap_min.values[3]);
    ASSERT_EQ(19, heap_min.values[4]);
    ASSERT_EQ(17, heap_min.values[5]);
    ASSERT_EQ(7, heap_min.values[6]);
    ASSERT_EQ(25, heap_min.values[7]);
    ASSERT_EQ(36, heap_min.values[8]);
    ASSERT_EQ(100, heap_min.values[9]);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}