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

TEST(ListTest, Remove_first_no_list_with_one_element){
    Cell list;
    Cell cell1, *result;
    cell1.id = 1;
    insert(&list, &cell1);
    result = remove(&list, cell1.id);
    ASSERT_EQ(1, result->id);
    ASSERT_TRUE(empty(&list));
};

TEST(ListTest, Remove_first_no_list_with_two_elements){
    Cell list;
    Cell cell1, cell2, *result;
    cell1.id = 1;
    cell2.id = 2;
    insert(&list, &cell1);
    insert(&list, &cell2);
    result = remove(&list, cell2.id);
    ASSERT_EQ(2, result->id);
    ASSERT_FALSE(empty(&list));
    ASSERT_EQ(&cell1, list.next);
};

TEST(ListTest, Remove_no_id_3_list_with_three_elements){
    Cell list;
    Cell cell1, cell2, cell3, *result;
    cell1.id = 1;
    cell2.id = 2;
    cell3.id = 3;
    insert(&list, &cell3);
    insert(&list, &cell2);
    insert(&list, &cell1);
    result = remove(&list, cell3.id);
    ASSERT_EQ(3, result->id);
    ASSERT_FALSE(empty(&list));
    ASSERT_EQ(&cell1, list.next);
    ASSERT_EQ(&cell2, list.next->next);
    ASSERT_EQ(&list, list.next->next->next);
};

TEST(ListTest, Remove_no_id_no_exist_list_with_three_elements){
    Cell list;
    Cell cell1, cell2, cell3, *result;
    cell1.id = 1;
    cell2.id = 2;
    cell3.id = 3;
    insert(&list, &cell3);
    insert(&list, &cell2);
    insert(&list, &cell1);
    result = remove(&list, 4);
    ASSERT_EQ(NULL, result);
    ASSERT_FALSE(empty(&list));
    ASSERT_EQ(&cell1, list.next);
    ASSERT_EQ(&cell2, list.next->next);
    ASSERT_EQ(&cell3, list.next->next->next);
    ASSERT_EQ(&list, list.next->next->next->next);
    ASSERT_EQ(&cell1, list.next->next->next->next->next);
};

TEST(ListTest, search_id_3_list_with_three_elements){
    Cell list;
    Cell cell1, cell2, cell3, *result;
    cell1.id = 1;
    cell2.id = 2;
    cell3.id = 3;
    insert(&list, &cell3);
    insert(&list, &cell2);
    insert(&list, &cell1);
    result = search(&list, cell3.id);
    ASSERT_EQ(3, result->id);
};

TEST(ListTest, search_id_no_exist_list_with_three_elements){
    Cell list;
    Cell cell1, cell2, cell3, *result;
    cell1.id = 1;
    cell2.id = 2;
    cell3.id = 3;
    insert(&list, &cell3);
    insert(&list, &cell2);
    insert(&list, &cell1);
    result = search(&list, 4);
    ASSERT_EQ(NULL, result);
};

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}