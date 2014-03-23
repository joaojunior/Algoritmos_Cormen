 // tests.cpp
#include "lista.h"
#include <gtest/gtest.h>
 
TEST(ListTest, ListEmpty) {
    List list;
    ASSERT_TRUE(empty(&list));
}

TEST(ListTest, ListNotEmpty) {
    List list;
    Cell cell;
    cell.id = 1;
    list.first = &cell;
    ASSERT_FALSE(empty(&list));
}

TEST(ListTest, ListWithOneElement){
    List list;
    Cell cell;
    cell.id = 1;
    insert(&list, &cell);
    ASSERT_EQ(&cell, list.first);
    ASSERT_EQ(1, list.first->id);
    ASSERT_EQ(NULL, list.first->next);
}

TEST(ListTest, ListWithTwoElement){
    List list;
    Cell cell1, cell2;
    cell1.id = 1;
    cell2.id = 2;
    insert(&list, &cell1);
    insert(&list, &cell2);
    ASSERT_EQ(&cell1, list.first);
    ASSERT_EQ(1, list.first->id);
    ASSERT_EQ(&cell2, list.first->next);
    ASSERT_EQ(2, list.first->next->id);
}

TEST(ListTest, ListWithThreeElement){
    List list;
    Cell cell1, cell2, cell3;
    cell1.id = 1;
    cell2.id = 2;
    cell3.id = 3;
    insert(&list, &cell1);
    insert(&list, &cell2);
    insert(&list, &cell3);
    ASSERT_EQ(&cell1, list.first);
    ASSERT_EQ(1, list.first->id);
    ASSERT_EQ(&cell2, list.first->next);
    ASSERT_EQ(2, list.first->next->id);
    ASSERT_EQ(&cell3, list.first->next->next);
    ASSERT_EQ(3, list.first->next->next->id);
}

TEST(ListTest, ListSearchElementExist){
    List list;
    Cell cell1, cell2, cell3;
    cell1.id = 1;
    cell2.id = 2;
    cell3.id = 3;
    insert(&list, &cell1);
    insert(&list, &cell2);
    insert(&list, &cell3);
    ASSERT_EQ(&cell1, search(&list, 1));
    ASSERT_EQ(&cell2, search(&list, 2));
    ASSERT_EQ(&cell3, search(&list, 3));
}

TEST(ListTest, ListSearchElementNotExist){
    List list;
    Cell cell1, cell2, cell3;
    cell1.id = 1;
    cell2.id = 2;
    cell3.id = 3;
    insert(&list, &cell1);
    insert(&list, &cell2);
    insert(&list, &cell3);
    ASSERT_EQ(NULL, search(&list, 4));
}

TEST(ListTest, ListRemoveFirstElement){
    List list;
    Cell cell1, cell2, cell3, *result;
    cell1.id = 1;
    cell2.id = 2;
    cell3.id = 3;
    insert(&list, &cell1);
    insert(&list, &cell2);
    insert(&list, &cell3);
    result = remove(&list, 1);
    ASSERT_EQ(result, &cell1);
    ASSERT_EQ(result->id, cell1.id);
    ASSERT_EQ(&cell2, list.first);
}

TEST(ListTest, ListRemoveLastElement){
    List list;
    Cell cell1, cell2, cell3, *result;
    cell1.id = 1;
    cell2.id = 2;
    cell3.id = 3;
    insert(&list, &cell1);
    insert(&list, &cell2);
    insert(&list, &cell3);
    result = remove(&list, 3);
    ASSERT_EQ(result, &cell3);
    ASSERT_EQ(result->id, cell3.id);
    ASSERT_EQ(&cell1, list.first);
    ASSERT_EQ(&cell2, list.first->next);
    ASSERT_EQ(NULL, list.first->next->next);
}

TEST(ListTest, ListRemoveElement){
    List list;
    Cell cell1, cell2, cell3, *result;
    cell1.id = 1;
    cell2.id = 2;
    cell3.id = 3;
    insert(&list, &cell1);
    insert(&list, &cell2);
    insert(&list, &cell3);
    result = remove(&list, 2);
    ASSERT_EQ(&cell2, result);
    ASSERT_EQ(cell2.id, result->id);
    ASSERT_EQ(&cell1, list.first);
    ASSERT_EQ(&cell3, list.first->next);
    ASSERT_EQ(NULL, list.first->next->next);
}

TEST(ListTest, ListRemoveElementNotExist){
    List list;
    Cell cell1, cell2, cell3, *result;
    cell1.id = 1;
    cell2.id = 2;
    cell3.id = 3;
    insert(&list, &cell1);
    insert(&list, &cell2);
    insert(&list, &cell3);
    result = remove(&list, 4);
    ASSERT_EQ(NULL, result);
    ASSERT_EQ(&cell1, list.first);
    ASSERT_EQ(&cell2, list.first->next);
    ASSERT_EQ(&cell3, list.first->next->next);
    ASSERT_EQ(NULL, list.first->next->next->next);
}

TEST(ListTest, RemoveWithListEmpty){
    List list;
    Cell *result;
    result = remove(&list, 4);
    ASSERT_EQ(NULL, result);
    ASSERT_TRUE(empty(&list));
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}