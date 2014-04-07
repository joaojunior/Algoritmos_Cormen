#include "bellman_ford.h"
BellmanFordResult *bellmanFord(Graph *graph, int source){
    BellmanFordResult *bellman_ford_result;
    bellman_ford_result = allocate_memory(graph->numbers_nodes);
    initialize(bellman_ford_result, graph->numbers_nodes, source);
    for(int quantity = 1; quantity <= graph->numbers_nodes - 1; quantity++)
        for(int i = 0; i < graph->numbers_nodes; i++)
            for(int j = 0; j < graph->numbers_nodes; j++)
                relax(bellman_ford_result, graph, i, j);
    verify_negative_cycle(bellman_ford_result, graph);
    return bellman_ford_result;
}; 

BellmanFordResult *allocate_memory(int numbers_nodes){
    BellmanFordResult *bellman_ford_result;
    bellman_ford_result = (BellmanFordResult *)malloc(sizeof(BellmanFordResult));
    bellman_ford_result->distance = (int *)malloc(sizeof(int) * numbers_nodes);
    bellman_ford_result->predecessor = (int *)malloc(sizeof(int) * numbers_nodes);
    return bellman_ford_result;
};

void initialize(BellmanFordResult *bellman_ford_result, int numbers_nodes, int source){
    for(int i = 0; i < numbers_nodes; i++){
        bellman_ford_result->distance[i] = MAX_WEIGHT;
        bellman_ford_result->predecessor[i] = PREDECESSOR_NULL;
    }
    bellman_ford_result->distance[source] = 0;
    bellman_ford_result->exist_negative_cycle = false;
};

void relax(BellmanFordResult *bellman_ford_result, Graph *graph, int i, int j){
    if(exist_arc(graph, i, j) and bellman_ford_result->distance[j] > bellman_ford_result->distance[i] + get_cost_edge(graph, i, j)){
        bellman_ford_result->distance[j] = bellman_ford_result->distance[i] + get_cost_edge(graph, i, j);
        bellman_ford_result->predecessor[j] = i;
    }
};

void verify_negative_cycle(BellmanFordResult *bellman_ford_result, Graph *graph){
    for(int i = 0; i < graph->numbers_nodes; i++)
        for(int j = 0; j < graph->numbers_nodes; j++)
            if(exist_arc(graph, i, j) and bellman_ford_result->distance[j] > bellman_ford_result->distance[i] + get_cost_edge(graph, i, j)){
                bellman_ford_result->exist_negative_cycle = true;
                return;
            }
};