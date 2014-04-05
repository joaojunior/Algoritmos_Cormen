#include "bellman_ford.h"
#include <gtest/gtest.h>

TEST(BFSTest, BellmanFordExampleCormen){
    Graph graph;
    BellmanFordResult *bellman_ford_result;
    graph.numbers_nodes = 5;
    allocate_memory(&graph);
    insert_arc(&graph, 0, 1, 6);
    insert_arc(&graph, 0, 2, 7);
    insert_arc(&graph, 1, 2, 8);
    insert_arc(&graph, 1, 3, 5);
    insert_arc(&graph, 1, 4, -4);
    insert_arc(&graph, 2, 3, -3);
    insert_arc(&graph, 2, 4, 9);
    insert_arc(&graph, 3, 1, -2);
    insert_arc(&graph, 4, 0, 2);
    insert_arc(&graph, 4, 3, 7);
    bellman_ford_result = bellmanFord(&graph, 0);
    ASSERT_EQ(0, bellman_ford_result->distance[0]);
    ASSERT_EQ(2, bellman_ford_result->distance[1]);
    ASSERT_EQ(7, bellman_ford_result->distance[2]);
    ASSERT_EQ(4, bellman_ford_result->distance[3]);
    ASSERT_EQ(-2, bellman_ford_result->distance[4]);
    ASSERT_FALSE(bellman_ford_result->exist_negative_cycle);
}

TEST(BFSTest, BellmanFordCycleNegative){
    Graph graph;
    BellmanFordResult *bellman_ford_result;
    graph.numbers_nodes = 2;
    allocate_memory(&graph);
    insert_arc(&graph, 0, 1, -6);
    insert_arc(&graph, 1, 0, -7);
    bellman_ford_result = bellmanFord(&graph, 0);
    ASSERT_TRUE(bellman_ford_result->exist_negative_cycle);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}