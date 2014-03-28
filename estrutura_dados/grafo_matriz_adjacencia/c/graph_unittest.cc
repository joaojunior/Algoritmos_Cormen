#include "graph.h"
#include <gtest/gtest.h>
 
TEST(GraphTest, GraphEmpty){
    Graph graph;
    ASSERT_TRUE(empty(&graph));
}

TEST(GraphTest, GraphNotEmpty){
    Graph graph;
    graph.numbers_nodes = 2;
    allocate_memory(&graph);
    ASSERT_FALSE(empty(&graph));
}

TEST(GraphTest, NumbersEdges){
    Graph graph;
    graph.numbers_nodes = 2;
    allocate_memory(&graph);
    ASSERT_EQ(0, graph.numbers_edges);
    insert_edge(&graph, 0, 1, 10);
    ASSERT_EQ(1, graph.numbers_edges);
}

TEST(GraphTest, GetCostEdgeExist){
    Graph graph;
    graph.numbers_nodes = 2;
    allocate_memory(&graph);
    insert_edge(&graph, 0, 1, 10);
    ASSERT_EQ(10, get_cost_edge(&graph, 0, 1));
    ASSERT_EQ(10, get_cost_edge(&graph, 1, 0));
}

TEST(GraphTest, GetCostEdgeNotExist){
    Graph graph;
    graph.numbers_nodes = 2;
    allocate_memory(&graph);
    ASSERT_EQ(WEIGHT2EMPTY, get_cost_edge(&graph, 0, 1));
    ASSERT_EQ(WEIGHT2EMPTY, get_cost_edge(&graph, 1, 0));
}

TEST(GraphTest, GetCostArc){
    Graph graph;
    graph.numbers_nodes = 2;
    allocate_memory(&graph);
    insert_arc(&graph, 0, 1, 10);
    ASSERT_EQ(10, get_cost_edge(&graph, 0, 1));
    ASSERT_EQ(0, get_cost_edge(&graph, 1, 0));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}