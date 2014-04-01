#include "repeated_squaring.h"
#include <gtest/gtest.h>

TEST(RepeatedSquaringTest, ExampleCormen){
    Graph graph, *graph_result;
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
    ASSERT_EQ(0, get_cost_edge(graph_result, 0, 0));
    ASSERT_EQ(1, get_cost_edge(graph_result, 0, 1));
    ASSERT_EQ(-3, get_cost_edge(graph_result, 0, 2));
    ASSERT_EQ(2, get_cost_edge(graph_result, 0, 3));
    ASSERT_EQ(-4, get_cost_edge(graph_result, 0, 4));
    ASSERT_EQ(3, get_cost_edge(graph_result, 1, 0));
    ASSERT_EQ(0, get_cost_edge(graph_result, 1, 1));
    ASSERT_EQ(-4, get_cost_edge(graph_result, 1, 2));
    ASSERT_EQ(1, get_cost_edge(graph_result, 1, 3));
    ASSERT_EQ(-1, get_cost_edge(graph_result, 1, 4));
    ASSERT_EQ(7, get_cost_edge(graph_result, 2, 0));
    ASSERT_EQ(4, get_cost_edge(graph_result, 2, 1));
    ASSERT_EQ(0, get_cost_edge(graph_result, 2, 2));
    ASSERT_EQ(5, get_cost_edge(graph_result, 2, 3));
    ASSERT_EQ(3, get_cost_edge(graph_result, 2, 4));
    ASSERT_EQ(2, get_cost_edge(graph_result, 3, 0));
    ASSERT_EQ(-1, get_cost_edge(graph_result, 3, 1));
    ASSERT_EQ(-5, get_cost_edge(graph_result, 3, 2));
    ASSERT_EQ(0, get_cost_edge(graph_result, 3, 3));
    ASSERT_EQ(-2, get_cost_edge(graph_result, 3, 4));
    ASSERT_EQ(8, get_cost_edge(graph_result, 4, 0));
    ASSERT_EQ(5, get_cost_edge(graph_result, 4, 1));
    ASSERT_EQ(1, get_cost_edge(graph_result, 4, 2));
    ASSERT_EQ(6, get_cost_edge(graph_result, 4, 3));
    ASSERT_EQ(0, get_cost_edge(graph_result, 4, 4));
}

TEST(RepeatedSquaringTest, Example2){
    Graph graph, *graph_result;
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
    ASSERT_EQ(0, get_cost_edge(graph_result, 0, 0));
    ASSERT_EQ(4, get_cost_edge(graph_result, 0, 1));
    ASSERT_EQ(7, get_cost_edge(graph_result, 0, 2));
    ASSERT_EQ(3, get_cost_edge(graph_result, 0, 3));
    ASSERT_EQ(4, get_cost_edge(graph_result, 0, 4));
    ASSERT_EQ(10, get_cost_edge(graph_result, 1, 0));
    ASSERT_EQ(0, get_cost_edge(graph_result, 1, 1));
    ASSERT_EQ(3, get_cost_edge(graph_result, 1, 2));
    ASSERT_EQ(9, get_cost_edge(graph_result, 1, 3));
    ASSERT_EQ(8, get_cost_edge(graph_result, 1, 4));
    ASSERT_EQ(7, get_cost_edge(graph_result, 2, 0));
    ASSERT_EQ(6, get_cost_edge(graph_result, 2, 1));
    ASSERT_EQ(0, get_cost_edge(graph_result, 2, 2));
    ASSERT_EQ(6, get_cost_edge(graph_result, 2, 3));
    ASSERT_EQ(5, get_cost_edge(graph_result, 2, 4));
    ASSERT_EQ(1, get_cost_edge(graph_result, 3, 0));
    ASSERT_EQ(1, get_cost_edge(graph_result, 3, 1));
    ASSERT_EQ(4, get_cost_edge(graph_result, 3, 2));
    ASSERT_EQ(0, get_cost_edge(graph_result, 3, 3));
    ASSERT_EQ(1, get_cost_edge(graph_result, 3, 4));
    ASSERT_EQ(2, get_cost_edge(graph_result, 4, 0));
    ASSERT_EQ(1, get_cost_edge(graph_result, 4, 1));
    ASSERT_EQ(4, get_cost_edge(graph_result, 4, 2));
    ASSERT_EQ(1, get_cost_edge(graph_result, 4, 3));
    ASSERT_EQ(0, get_cost_edge(graph_result, 4, 4));
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   