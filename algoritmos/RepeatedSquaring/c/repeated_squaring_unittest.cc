#include "repeated_squaring.h"
#include <gtest/gtest.h>

TEST(RepeatedSquaringTest, ExampleCormen){
    Graph graph;
    RepeatedSquaringResult *graph_result;
    graph.numbers_nodes = 5;
    allocate_memory(&graph);
    insert_arc(&graph, 0, 1, 3);
    insert_arc(&graph, 0, 2, 8);
    insert_arc(&graph, 0, 4, -4);
    insert_arc(&graph, 1, 3, 1);
    insert_arc(&graph, 1, 4, 7);
    insert_arc(&graph, 2, 1, 4);
    insert_arc(&graph, 3, 2, -5);
    insert_arc(&graph, 3, 0, 2);
    insert_arc(&graph, 4, 3, 6);
    graph_result = repeated_squaring(&graph);
    ASSERT_EQ(0, graph_result->distance[0][0]);
    ASSERT_EQ(1, graph_result->distance[0][1]);
    ASSERT_EQ(-3, graph_result->distance[0][2]);
    ASSERT_EQ(2, graph_result->distance[0][3]);
    ASSERT_EQ(-4, graph_result->distance[0][4]);
    ASSERT_EQ(3, graph_result->distance[1][0]);
    ASSERT_EQ(0, graph_result->distance[1][1]);
    ASSERT_EQ(-4, graph_result->distance[1][2]);
    ASSERT_EQ(1, graph_result->distance[1][3]);
    ASSERT_EQ(-1, graph_result->distance[1][4]);
    ASSERT_EQ(7, graph_result->distance[2][0]);
    ASSERT_EQ(4, graph_result->distance[2][1]);
    ASSERT_EQ(0, graph_result->distance[2][2]);
    ASSERT_EQ(5, graph_result->distance[2][3]);
    ASSERT_EQ(3, graph_result->distance[2][4]);
    ASSERT_EQ(2, graph_result->distance[3][0]);
    ASSERT_EQ(-1, graph_result->distance[3][1]);
    ASSERT_EQ(-5, graph_result->distance[3][2]);
    ASSERT_EQ(0, graph_result->distance[3][3]);
    ASSERT_EQ(-2, graph_result->distance[3][4]);
    ASSERT_EQ(8, graph_result->distance[4][0]);
    ASSERT_EQ(5, graph_result->distance[4][1]);
    ASSERT_EQ(1, graph_result->distance[4][2]);
    ASSERT_EQ(6, graph_result->distance[4][3]);
    ASSERT_EQ(0, graph_result->distance[4][4]);
    ASSERT_EQ(PREDECESSOR_NULL, graph_result->predecessor[0][0]);
    ASSERT_EQ(2, graph_result->predecessor[0][1]);
    ASSERT_EQ(3, graph_result->predecessor[0][2]);
    ASSERT_EQ(4, graph_result->predecessor[0][3]);
    ASSERT_EQ(0, graph_result->predecessor[0][4]);
    ASSERT_EQ(3, graph_result->predecessor[1][0]);
    ASSERT_EQ(PREDECESSOR_NULL, graph_result->predecessor[1][1]);
    ASSERT_EQ(3, graph_result->predecessor[1][2]);
    ASSERT_EQ(1, graph_result->predecessor[1][3]);
    ASSERT_EQ(0, graph_result->predecessor[1][4]);
    ASSERT_EQ(3, graph_result->predecessor[2][0]);
    ASSERT_EQ(2, graph_result->predecessor[2][1]);
    ASSERT_EQ(PREDECESSOR_NULL, graph_result->predecessor[2][2]);
    ASSERT_EQ(1, graph_result->predecessor[2][3]);
    ASSERT_EQ(0, graph_result->predecessor[2][4]);
    ASSERT_EQ(3, graph_result->predecessor[3][0]);
    ASSERT_EQ(2, graph_result->predecessor[3][1]);
    ASSERT_EQ(3, graph_result->predecessor[3][2]);
    ASSERT_EQ(PREDECESSOR_NULL, graph_result->predecessor[3][3]);
    ASSERT_EQ(0, graph_result->predecessor[3][4]);
    ASSERT_EQ(3, graph_result->predecessor[4][0]);
    ASSERT_EQ(2, graph_result->predecessor[4][1]);
    ASSERT_EQ(3, graph_result->predecessor[4][2]);
    ASSERT_EQ(4, graph_result->predecessor[4][3]);
    ASSERT_EQ(PREDECESSOR_NULL, graph_result->predecessor[4][4]);
}

TEST(RepeatedSquaringTest, Example2){
    Graph graph;
    RepeatedSquaringResult *graph_result;
    graph.numbers_nodes = 5;
    allocate_memory(&graph);
    insert_arc(&graph, 0, 1, 5);
    insert_arc(&graph, 0, 3, 3);
    insert_arc(&graph, 1, 2, 3);
    insert_arc(&graph, 2, 4, 5);
    insert_arc(&graph, 3, 0, 1);
    insert_arc(&graph, 3, 1, 1);
    insert_arc(&graph, 3, 4, 1);
    insert_arc(&graph, 4, 1, 1);
    insert_arc(&graph, 4, 3, 1);
    graph_result = repeated_squaring(&graph);
    ASSERT_EQ(0, graph_result->distance[0][0]);
    ASSERT_EQ(4, graph_result->distance[0][1]);
    ASSERT_EQ(7, graph_result->distance[0][2]);
    ASSERT_EQ(3, graph_result->distance[0][3]);
    ASSERT_EQ(4, graph_result->distance[0][4]);
    ASSERT_EQ(10, graph_result->distance[1][0]);
    ASSERT_EQ(0, graph_result->distance[1][1]);
    ASSERT_EQ(3, graph_result->distance[1][2]);
    ASSERT_EQ(9, graph_result->distance[1][3]);
    ASSERT_EQ(8, graph_result->distance[1][4]);
    ASSERT_EQ(7, graph_result->distance[2][0]);
    ASSERT_EQ(6, graph_result->distance[2][1]);
    ASSERT_EQ(0, graph_result->distance[2][2]);
    ASSERT_EQ(6, graph_result->distance[2][3]);
    ASSERT_EQ(5, graph_result->distance[2][4]);
    ASSERT_EQ(1, graph_result->distance[3][0]);
    ASSERT_EQ(1, graph_result->distance[3][1]);
    ASSERT_EQ(4, graph_result->distance[3][2]);
    ASSERT_EQ(0, graph_result->distance[3][3]);
    ASSERT_EQ(1, graph_result->distance[3][4]);
    ASSERT_EQ(2, graph_result->distance[4][0]);
    ASSERT_EQ(1, graph_result->distance[4][1]);
    ASSERT_EQ(4, graph_result->distance[4][2]);
    ASSERT_EQ(1, graph_result->distance[4][3]);
    ASSERT_EQ(0, graph_result->distance[4][4]);
}

TEST(RepeatedSquaringTest, VerifyPredecessor){
    Graph graph;
    RepeatedSquaringResult *repeated_squaring_result;
    int **quantity_shortest_path_in_edge;
    graph.numbers_nodes = 4;
    allocate_memory(&graph);
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 0, 2, 1);
    insert_edge(&graph, 0, 2, 1);
    insert_edge(&graph, 1, 2, 1);
    insert_edge(&graph, 2, 3, 1);
    repeated_squaring_result = repeated_squaring(&graph);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[0][0]);
    ASSERT_EQ(0,repeated_squaring_result->predecessor[0][1]);
    ASSERT_EQ(0,repeated_squaring_result->predecessor[0][2]);
    ASSERT_EQ(2,repeated_squaring_result->predecessor[0][3]);
    ASSERT_EQ(1,repeated_squaring_result->predecessor[1][0]);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[1][1]);
    ASSERT_EQ(1,repeated_squaring_result->predecessor[1][2]);
    ASSERT_EQ(2,repeated_squaring_result->predecessor[1][3]);
    ASSERT_EQ(2,repeated_squaring_result->predecessor[2][0]);
    ASSERT_EQ(2,repeated_squaring_result->predecessor[2][1]);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[2][2]);
    ASSERT_EQ(2,repeated_squaring_result->predecessor[2][3]);
    ASSERT_EQ(2,repeated_squaring_result->predecessor[3][0]);
    ASSERT_EQ(2,repeated_squaring_result->predecessor[3][1]);
    ASSERT_EQ(3,repeated_squaring_result->predecessor[3][2]);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[3][3]);
}

TEST(RepeatedSquaringTest, VerifyPredecessorWithGraphNotConnected){
    Graph graph;
    RepeatedSquaringResult *repeated_squaring_result;
    int **quantity_shortest_path_in_edge;
    graph.numbers_nodes = 4;
    allocate_memory(&graph);
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 0, 2, 1);
    insert_edge(&graph, 0, 2, 1);
    insert_edge(&graph, 1, 2, 1);
    repeated_squaring_result = repeated_squaring(&graph);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[0][0]);
    ASSERT_EQ(0,repeated_squaring_result->predecessor[0][1]);
    ASSERT_EQ(0,repeated_squaring_result->predecessor[0][2]);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[0][3]);
    ASSERT_EQ(1,repeated_squaring_result->predecessor[1][0]);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[1][1]);
    ASSERT_EQ(1,repeated_squaring_result->predecessor[1][2]);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[1][3]);
    ASSERT_EQ(2,repeated_squaring_result->predecessor[2][0]);
    ASSERT_EQ(2,repeated_squaring_result->predecessor[2][1]);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[2][2]);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[2][3]);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[3][0]);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[3][1]);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[3][2]);
    ASSERT_EQ(PREDECESSOR_NULL,repeated_squaring_result->predecessor[3][3]);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   