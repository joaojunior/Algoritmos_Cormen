#include "dijkstra.h"
#include <gtest/gtest.h>

TEST(DijkstraTest, ExampleCormen){
    Graph graph;
    DijkstraResult *dijkstra_result;
    graph.numbers_nodes = 5;
    allocate_memory(&graph);
    insert_arc(&graph, 0, 1, 10);
    insert_arc(&graph, 0, 2, 5);
    insert_arc(&graph, 1, 2, 2);
    insert_arc(&graph, 1, 3, 1);
    insert_arc(&graph, 2, 1, 3);
    insert_arc(&graph, 2, 3, 9);
    insert_arc(&graph, 2, 4, 2);
    insert_arc(&graph, 3, 4, 4);
    insert_arc(&graph, 4, 0, 7);
    insert_arc(&graph, 4, 3, 6);
    dijkstra_result = dijkstra(&graph, 0);
    ASSERT_EQ(0, dijkstra_result->distance[0]);
    ASSERT_EQ(8, dijkstra_result->distance[1]);
    ASSERT_EQ(5, dijkstra_result->distance[2]);
    ASSERT_EQ(9, dijkstra_result->distance[3]);
    ASSERT_EQ(7, dijkstra_result->distance[4]);
    ASSERT_EQ(PREDECESSOR_NULL, dijkstra_result->predecessor[0]);
    ASSERT_EQ(2, dijkstra_result->predecessor[1]);
    ASSERT_EQ(0, dijkstra_result->predecessor[2]);
    ASSERT_EQ(1, dijkstra_result->predecessor[3]);
    ASSERT_EQ(2, dijkstra_result->predecessor[4]);
}
TEST(DijkstraTest, ExampleCormen1){
    Graph graph;
    DijkstraResult *dijkstra_result;
    graph.numbers_nodes = 5;
    allocate_memory(&graph);
    insert_arc(&graph, 0, 1, 4);
    insert_arc(&graph, 0, 2, 13);
    insert_arc(&graph, 0, 4, 0);
    insert_arc(&graph, 1, 3, 0);
    insert_arc(&graph, 1, 4, 10);
    insert_arc(&graph, 2, 1, 0);
    insert_arc(&graph, 3, 0, 2);
    insert_arc(&graph, 3, 2, 0);
    insert_arc(&graph, 4, 3, 2);
    dijkstra_result = dijkstra(&graph, 1);
    ASSERT_EQ(2, dijkstra_result->distance[0]);
    ASSERT_EQ(0, dijkstra_result->distance[1]);
    ASSERT_EQ(0, dijkstra_result->distance[2]);
    ASSERT_EQ(0, dijkstra_result->distance[3]);
    ASSERT_EQ(2, dijkstra_result->distance[4]);
    ASSERT_EQ(3, dijkstra_result->predecessor[0]);
    ASSERT_EQ(PREDECESSOR_NULL, dijkstra_result->predecessor[1]);
    ASSERT_EQ(3, dijkstra_result->predecessor[2]);
    ASSERT_EQ(1, dijkstra_result->predecessor[3]);
    ASSERT_EQ(0, dijkstra_result->predecessor[4]);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}