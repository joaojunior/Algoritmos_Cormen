 // tests.cpp
#include "lista_dupla.h"
#include <gtest/gtest.h>
 
TEST(ListDoublyTest, ListDoublyEmpty) {
    ListDoubly list_doubly;
    ASSERT_TRUE(empty(&list_doubly));
}

TEST(ListDoublyTest, ListDoublyNotEmpty) {
    ListDoubly list_doubly;
    Cell cell1;
    cell1.id = 1;
    list_doubly.first = &cell1;
    ASSERT_FALSE(empty(&list_doubly));
}

TEST(ListDoublyTest, ListInsertOneElement){
    ListDoubly list_doubly;
    Cell cell1;
    cell1.id = 1;
    insert(&list_doubly, &cell1);
    ASSERT_EQ(&cell1, list_doubly.first);
    ASSERT_EQ(cell1.id, list_doubly.first->id);
    ASSERT_EQ(NULL, list_doubly.first->prev);
    ASSERT_EQ(NULL, list_doubly.first->next);
}

TEST(ListDoublyTest, ListInsertTwoElements){
    ListDoubly list_doubly;
    Cell cell1, cell2;
    cell1.id = 1;
    cell2.id = 2;
    insert(&list_doubly, &cell1);
    insert(&list_doubly, &cell2);
    ASSERT_EQ(&cell1, list_doubly.first);
    ASSERT_EQ(NULL, list_doubly.first->prev);
    ASSERT_EQ(&cell2, list_doubly.first->next);
    ASSERT_EQ(NULL, list_doubly.first->next->next);
    ASSERT_EQ(&cell1, list_doubly.first->next->prev);
}

TEST(ListDoublyTest, ListInsertThreeElements){
    ListDoubly list_doubly;
    Cell cell1, cell2, cell3;
    cell1.id = 1;
    cell2.id = 2;
    cell3.id = 3;
    insert(&list_doubly, &cell1);
    insert(&list_doubly, &cell2);
    insert(&list_doubly, &cell3);
    ASSERT_EQ(&cell1, list_doubly.first);
    ASSERT_EQ(NULL, list_doubly.first->prev);
    ASSERT_EQ(&cell2, list_doubly.first->next);
    ASSERT_EQ(&cell3, list_doubly.first->next->next);
    ASSERT_EQ(&cell1, list_doubly.first->next->prev);
    ASSERT_EQ(&cell2, list_doubly.first->next->next->prev);
    ASSERT_EQ(NULL, list_doubly.first->next->next->next);
}

TEST(ListDoublyTest, SearchFirstElement){
    ListDoubly list_doubly;
    Cell cell1, cell2, cell3, *result;
    cell1.id = 1;
    cell2.id = 2;
    cell3.id = 3;
    insert(&list_doubly, &cell1);
    insert(&list_doubly, &cell2);
    insert(&list_doubly, &cell3);
    result = search(&list_doubly, cell1.id);
    ASSERT_EQ(&cell1, result);
    ASSERT_EQ(NULL, result->prev);
    ASSERT_EQ(&cell2, result->next);
};

TEST(ListDoublyTest, SearchSecondElement){
    ListDoubly list_doubly;
    Cell cell1, cell2, cell3, *result;
    cell1.id = 1;
    cell2.id = 2;
    cell3.id = 3;
    insert(&list_doubly, &cell1);
    insert(&list_doubly, &cell2);
    insert(&list_doubly, &cell3);
    result = search(&list_doubly, cell2.id);
    ASSERT_EQ(&cell2, result);
    ASSERT_EQ(&cell1, result->prev);
    ASSERT_EQ(&cell3, result->next);
};

TEST(ListDoublyTest, SearchLastElement){
    ListDoubly list_doubly;
    Cell cell1, cell2, cell3, *result;
    cell1.id = 1;
    cell2.id = 2;
    cell3.id = 3;
    insert(&list_doubly, &cell1);
    insert(&list_doubly, &cell2);
    insert(&list_doubly, &cell3);
    result = search(&list_doubly, cell3.id);
    ASSERT_EQ(&cell3, result);
    ASSERT_EQ(&cell2, result->prev);
    ASSERT_EQ(NULL, result->next);
};

TEST(ListDoublyTest, SearchElementNotExist){
    ListDoubly list_doubly;
    Cell cell1, cell2, cell3, *result;
    cell1.id = 1;
    cell2.id = 2;
    cell3.id = 3;
    insert(&list_doubly, &cell1);
    insert(&list_doubly, &cell2);
    insert(&list_doubly, &cell3);
    result = search(&list_doubly, 4);
    ASSERT_EQ(NULL, result);
};

TEST(ListDoublyTest, RemoveFirstElement){
    ListDoubly list_doubly;
    Cell cell1, cell2, cell3, *result;
    cell1.id = 1;
    cell2.id = 2;
    cell3.id = 3;
    insert(&list_doubly, &cell1);
    insert(&list_doubly, &cell2);
    insert(&list_doubly, &cell3);
    result = remove(&list_doubly, cell1.id);
    ASSERT_EQ(&cell1, result);
    ASSERT_EQ(&cell2, list_doubly.first);
    ASSERT_EQ(&cell3, list_doubly.first->next);
}

TEST(ListDoublyTest, RemoveSecondElement){
    ListDoubly list_doubly;
    Cell cell1, cell2, cell3, *result;
    cell1.id = 1;
    cell2.id = 2;
    cell3.id = 3;
    insert(&list_doubly, &cell1);
    insert(&list_doubly, &cell2);
    insert(&list_doubly, &cell3);
    result = remove(&list_doubly, cell2.id);
    ASSERT_EQ(&cell2, result);
    ASSERT_EQ(&cell1, list_doubly.first);
    ASSERT_EQ(&cell3, list_doubly.first->next);
    ASSERT_EQ(&cell1, list_doubly.first->next->prev);
}

TEST(ListDoublyTest, RemoveLastElement){
    ListDoubly list_doubly;
    Cell cell1, cell2, cell3, *result;
    cell1.id = 1;
    cell2.id = 2;
    cell3.id = 3;
    insert(&list_doubly, &cell1);
    insert(&list_doubly, &cell2);
    insert(&list_doubly, &cell3);
    result = remove(&list_doubly, cell3.id);
    ASSERT_EQ(&cell3, result);
    ASSERT_EQ(&cell1, list_doubly.first);
    ASSERT_EQ(&cell2, list_doubly.first->next);
    ASSERT_EQ(&cell1, list_doubly.first->next->prev);
    ASSERT_EQ(NULL, list_doubly.first->next->next);
}

TEST(ListDoublyTest, RemoveElementNotExist){
    ListDoubly list_doubly;
    Cell cell1, cell2, cell3, *result;
    cell1.id = 1;
    cell2.id = 2;
    cell3.id = 3;
    insert(&list_doubly, &cell1);
    insert(&list_doubly, &cell2);
    insert(&list_doubly, &cell3);
    result = remove(&list_doubly, 4);
    ASSERT_EQ(NULL, result);
    ASSERT_EQ(&cell1, list_doubly.first);
    ASSERT_EQ(&cell2, list_doubly.first->next);
    ASSERT_EQ(&cell3, list_doubly.first->next->next);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}