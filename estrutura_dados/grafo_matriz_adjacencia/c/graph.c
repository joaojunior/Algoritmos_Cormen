#include "graph.h"
bool empty(Graph *graph){
    return graph->edges == NULL;
};

void allocate_memory(Graph *graph){
    graph->edges = (int **)malloc(graph->numbers_nodes * sizeof(int *));
    for(int i = 0; i < graph->numbers_nodes; i++){
        graph->edges[i] = (int *)malloc(graph->numbers_nodes * sizeof(int));
        for(int j = 0; j < graph->numbers_nodes; j++)
            graph->edges[i][j] = WEIGHT2EMPTY;
    }
};

void insert_edge(Graph *graph, int source, int dest, int weight){
    graph->numbers_edges += 1;
    graph->edges[source][dest] = weight;
    graph->edges[dest][source] = weight;
};

void insert_arc(Graph *graph, int source, int dest, int weight){
    graph->numbers_edges += 1;
    graph->edges[source][dest] = weight;
};

int get_cost_edge(Graph *graph, int source, int dest){
    return graph->edges[source][dest];
};