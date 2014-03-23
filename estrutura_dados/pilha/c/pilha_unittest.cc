 // tests.cpp
#include "pilha.h"
#include <gtest/gtest.h>
 
TEST(PilhaTest, PilhaEmpty) {
    Pilha pilha;
    ASSERT_TRUE(empty(&pilha));
}

TEST(PilhaTest, PilhaNotEmpty) {
    Pilha pilha;
    Element element;
    element.id = 1;
    push(&pilha, &element);
    ASSERT_FALSE(empty(&pilha));
}

TEST(PilhaTest, PopWithPilhaHasOneElement) {
    Pilha pilha;
    Element element, result_element;
    element.id = 1;
    push(&pilha, &element);
    result_element = pop(&pilha);
    ASSERT_EQ(1, result_element.id);
    ASSERT_TRUE(empty(&pilha));
}

TEST(PilhaTest, PopWithPilhaHasTwoElement) {
    Pilha pilha;
    Element element1, element2, result_element;
    element1.id = 1;
    element2.id = 2;
    push(&pilha, &element1);
    push(&pilha, &element2);
    result_element = pop(&pilha);
    ASSERT_EQ(2, result_element.id);
    ASSERT_EQ(&element1, pilha.top);
    ASSERT_FALSE(empty(&pilha));
}

TEST(PilhaTest, PopWithPilhaNotHasElement) {
    Pilha pilha;
    Element result_element;
    result_element = pop(&pilha);
    ASSERT_EQ(ID_NULO, result_element.id);
    ASSERT_TRUE(empty(&pilha));
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}