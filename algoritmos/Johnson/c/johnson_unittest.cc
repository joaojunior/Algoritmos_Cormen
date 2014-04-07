#include "johnson.h"
#include <gtest/gtest.h>
TEST(DijkstraTest, GraphReconsidered){
    Graph graph;
    BellmanFordResult *bellman_ford_result;
    graph.numbers_nodes = 5;
    allocate_memory(&graph);
    insert_arc(&graph, 0, 1, 3);
    insert_arc(&graph, 0, 2, 8);
    insert_arc(&graph, 0, 4, -4);
    insert_arc(&graph, 1, 3, 1);
    insert_arc(&graph, 1, 4, 7);
    insert_arc(&graph, 2, 1, 4);
    insert_arc(&graph, 3, 0, 2);
    insert_arc(&graph, 3, 2, -5);
    insert_arc(&graph, 4, 3, 6);
    bellman_ford_result = reconsider_graph(&graph);
    ASSERT_EQ(4, get_cost_edge(&graph, 0, 1));
    ASSERT_EQ(13, get_cost_edge(&graph, 0, 2));
    ASSERT_EQ(0, get_cost_edge(&graph, 0, 4));
    ASSERT_EQ(0, get_cost_edge(&graph, 1, 3));
    ASSERT_EQ(10, get_cost_edge(&graph, 1, 4));
    ASSERT_EQ(0, get_cost_edge(&graph, 2, 1));
    ASSERT_EQ(2, get_cost_edge(&graph, 3, 0));
    ASSERT_EQ(0, get_cost_edge(&graph, 3, 2));
    ASSERT_EQ(2, get_cost_edge(&graph, 4, 3));
    ASSERT_EQ(0, bellman_ford_result->distance[0]);
    ASSERT_EQ(-1, bellman_ford_result->distance[1]);
    ASSERT_EQ(-5, bellman_ford_result->distance[2]);
    ASSERT_EQ(0, bellman_ford_result->distance[3]);
    ASSERT_EQ(-4, bellman_ford_result->distance[4]);
}

TEST(DijkstraTest, ExampleCormen){
    Graph graph;
    JohnsonResult *jonhson_result;
    graph.numbers_nodes = 5;
    allocate_memory(&graph);
    insert_arc(&graph, 0, 1, 3);
    insert_arc(&graph, 0, 2, 8);
    insert_arc(&graph, 0, 4, -4);
    insert_arc(&graph, 1, 3, 1);
    insert_arc(&graph, 1, 4, 7);
    insert_arc(&graph, 2, 1, 4);
    insert_arc(&graph, 3, 0, 2);
    insert_arc(&graph, 3, 2, -5);
    insert_arc(&graph, 4, 3, 6);
    jonhson_result = jonhson(&graph);
    ASSERT_EQ(0, jonhson_result->distance[0][0]);
    ASSERT_EQ(1, jonhson_result->distance[0][1]);
    ASSERT_EQ(-3, jonhson_result->distance[0][2]);
    ASSERT_EQ(2, jonhson_result->distance[0][3]);
    ASSERT_EQ(-4, jonhson_result->distance[0][4]);
    ASSERT_EQ(3, jonhson_result->distance[1][0]);
    ASSERT_EQ(0, jonhson_result->distance[1][1]);
    ASSERT_EQ(-4, jonhson_result->distance[1][2]);
    ASSERT_EQ(1, jonhson_result->distance[1][3]);
    ASSERT_EQ(-1, jonhson_result->distance[1][4]);
    ASSERT_EQ(7, jonhson_result->distance[2][0]);
    ASSERT_EQ(4, jonhson_result->distance[2][1]);
    ASSERT_EQ(0, jonhson_result->distance[2][2]);
    ASSERT_EQ(5, jonhson_result->distance[2][3]);
    ASSERT_EQ(3, jonhson_result->distance[2][4]);
    ASSERT_EQ(2, jonhson_result->distance[3][0]);
    ASSERT_EQ(-1, jonhson_result->distance[3][1]);
    ASSERT_EQ(-5, jonhson_result->distance[3][2]);
    ASSERT_EQ(0, jonhson_result->distance[3][3]);
    ASSERT_EQ(-2, jonhson_result->distance[3][4]);
    ASSERT_EQ(8, jonhson_result->distance[4][0]);
    ASSERT_EQ(5, jonhson_result->distance[4][1]);
    ASSERT_EQ(1, jonhson_result->distance[4][2]);
    ASSERT_EQ(6, jonhson_result->distance[4][3]);
    ASSERT_EQ(0, jonhson_result->distance[4][4]);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}