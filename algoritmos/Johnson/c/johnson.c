#include "johnson.h"
JohnsonResult* jonhson(Graph *graph){
    JohnsonResult *jonhson_result;
    BellmanFordResult *bellman_ford_result;
    DijkstraResult* dijkstra_result;
    jonhson_result = (JohnsonResult *)malloc(sizeof(JohnsonResult));
    jonhson_result->distance = (int **)malloc(graph->numbers_nodes * sizeof(int *));
    for(int i = 0; i < graph->numbers_nodes; i++){
        jonhson_result->distance[i] = (int *)malloc(graph->numbers_nodes * sizeof(int));
        for(int j = 0; j < graph->numbers_nodes; j++)
                jonhson_result->distance[i][j] = 0;
    }
    bellman_ford_result = reconsider_graph(graph);
    for(int i = 0; i < graph->numbers_nodes; i++){
        dijkstra_result = dijkstra(graph, i);
        for(int j = 0; j < graph->numbers_nodes; j++)
            jonhson_result->distance[i][j] = dijkstra_result->distance[j] + bellman_ford_result->distance[j] - bellman_ford_result->distance[i];
    }
    return jonhson_result;
};

BellmanFordResult* reconsider_graph(Graph *graph){
    BellmanFordResult *bellman_ford_result;
    Graph graph_reconsidered;
    graph_reconsidered.numbers_nodes = graph->numbers_nodes + 1;
    allocate_memory(&graph_reconsidered);
    create_graph_reconsidered(&graph_reconsidered, graph);
    bellman_ford_result = bellmanFord(&graph_reconsidered, graph_reconsidered.numbers_nodes-1);
    if(bellman_ford_result->exist_negative_cycle == false){
        for(int i = 0; i < graph->numbers_nodes; i++)
            for(int j = 0; j < graph->numbers_nodes; j++)
                if(exist_arc(graph, i, j))
                    insert_arc(graph, i, j, get_cost_edge(graph, i, j) + bellman_ford_result->distance[i] - bellman_ford_result->distance[j]);
    };
    return bellman_ford_result;
};

void create_graph_reconsidered(Graph *graph_reconsidered,Graph *graph){
    for(int i = 0; i < graph->numbers_nodes; i++)
        for(int j = 0; j < graph->numbers_nodes; j++)
            insert_arc(graph_reconsidered, i, j, get_cost_edge(graph, i, j));
    for(int i = 0; i < graph->numbers_nodes; i++)
        insert_arc(graph_reconsidered, graph_reconsidered->numbers_nodes-1, i, 0);
};
