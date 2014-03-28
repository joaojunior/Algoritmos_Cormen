#include "fila.h"
#include <gtest/gtest.h>
 
TEST(FilaTest, QueueEmpty) {
    Queue queue;
    ASSERT_TRUE(empty(&queue));
}

TEST(FilaTest, QueueNotEmpty) {
    Queue queue;
    Cell cell;
    cell.id = 1;
    queue.first = &cell;
    queue.last = &cell;
    ASSERT_FALSE(empty(&queue));
}

TEST(FilaTest, QueueWithOneElement) {
    Queue queue;
    Cell cell;
    cell.id = 1;
    enqueue(&queue, 1);
    ASSERT_EQ(1,queue.first->id);
    ASSERT_EQ(1,queue.last->id);
}

TEST(FilaTest, QueueWithTwoElements) {
    Queue queue;
    Cell cell1, cell2;
    cell1.id = 1;
    cell2.id = 2;
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    ASSERT_EQ(1,queue.first->id);
    ASSERT_EQ(2,queue.last->id);
    ASSERT_EQ(2,queue.first->prox->id);
}

TEST(FilaTest, QueueWithThreeElements) {
    Queue queue;
    Cell cell1, cell2, cell3;
    cell1.id = 1;
    cell2.id = 2;
    cell3.id = 3;
    enqueue(&queue, 3);
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    ASSERT_EQ(3,queue.first->id);
    ASSERT_EQ(2,queue.last->id);
    ASSERT_EQ(cell1.id,queue.first->prox->id);
    ASSERT_EQ(cell2.id,queue.first->prox->prox->id);
}

TEST(FilaTest, DequeueWithOneElement) {
    Queue queue;
    Cell cell; 
    int id_result;
    cell.id = 1;
    enqueue(&queue, 1);
    id_result = dequeue(&queue);
    ASSERT_EQ(NULL,queue.first);
    ASSERT_EQ(NULL,queue.last);
    ASSERT_EQ(1, id_result);
}

TEST(FilaTest, DequeueWithTwoElement) {
    Queue queue;
    Cell cell1, cell2;
    int id_result;
    cell1.id = 1;
    cell2.id = 2;
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    id_result = dequeue(&queue);
    ASSERT_EQ(cell2.id,queue.first->id);
    ASSERT_EQ(cell2.id,queue.last->id);
    ASSERT_EQ(1,id_result);
}

TEST(FilaTest, DequeueWithHasNotElement) {
    Queue queue;
    int id_result;
    id_result = dequeue(&queue);
    ASSERT_EQ(NULL,queue.first);
    ASSERT_EQ(NULL,queue.last);
    ASSERT_EQ(-1, id_result);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}