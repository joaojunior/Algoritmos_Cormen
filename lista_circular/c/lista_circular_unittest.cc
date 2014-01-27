#include "lista_circular.h"
#include <gtest/gtest.h>
 
TEST(ListTest, ListEmpty) {
    Cell list;
    ASSERT_TRUE(empty(&list));
}

TEST(ListTest, ListNotEmpty){
    Cell list;
    Cell cell1;
    cell1.id = 1;
    list.next = &cell1;
    ASSERT_FALSE(empty(&list));
};

TEST(ListTest, Insert_1_no){
    Cell list;
    Cell cell1;
    cell1.id = 1;
    insert(&list, &cell1);
    ASSERT_EQ(1, list.next->id);
    ASSERT_EQ(&list, list.next->next);
};

TEST(ListTest, Insert_2_no){
    Cell list;
    Cell cell1, cell2;
    cell1.id = 1;
    cell2.id = 2;
    insert(&list, &cell1);
    insert(&list, &cell2);
    ASSERT_EQ(2, list.next->id);
    ASSERT_EQ(1, list.next->next->id);
    ASSERT_EQ(&list, list.next->next->next);
};

TEST(ListTest, Insert_3_no){
    Cell list;
    Cell cell1, cell2, cell3;
    cell1.id = 1;
    cell2.id = 2;
    cell3.id = 3;
    insert(&list, &cell1);
    insert(&list, &cell2);
    insert(&list, &cell3);
    ASSERT_EQ(3, list.next->id);
    ASSERT_EQ(2, list.next->next->id);
    ASSERT_EQ(1, list.next->next->next->id);
    ASSERT_EQ(&list, list.next->next->next->next);
};

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}