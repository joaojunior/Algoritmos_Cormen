#include "graph.h"
#include <gtest/gtest.h>
 
TEST(GraphTest, GraphEmpty){
    Graph graph;
    ASSERT_TRUE(empty(&graph));
}

TEST(GraphTest, GraphNotEmpty){
    Graph graph;
    ListAdj list_adj[5];
    graph.list_adj_node = list_adj;
    ASSERT_FALSE(empty(&graph));
}

TEST(GraphTest, GraphInsertEdge){
    Graph graph;
    ListAdj list_adj[2];
    Edge expect, *result;
    expect.dest = 1;
    graph.list_adj_node = list_adj;
    insert_edge(&graph, 0, 1, 1);
    result = get_edge(&graph, 0, 1);
    ASSERT_EQ(expect.dest, result->dest);
}

TEST(GraphTest, GraphInsertTwoEdgeWithSameNodeSource){
    Graph graph;
    ListAdj list_adj[3];
    Edge *result1, *result2;
    graph.list_adj_node = list_adj;
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 0, 2, 1);
    result1 = get_edge(&graph, 0, 1);
    result2 = get_edge(&graph, 0, 2);
    ASSERT_EQ(1, result1->dest);
    ASSERT_EQ(2, result2->dest);
}

TEST(GraphTest, GraphInsertTwoEdgeWithDifferentNodeSource){
    Graph graph;
    ListAdj list_adj[3];
    Edge *result1, *result2;
    graph.list_adj_node = list_adj;
    insert_edge(&graph, 0, 1, 1);
    insert_edge(&graph, 1, 2, 1);
    result1 = get_edge(&graph, 0, 1);
    result2 = get_edge(&graph, 1, 2);
    ASSERT_EQ(1, result1->dest);
    ASSERT_EQ(2, result2->dest);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}