#include "dijkstra.h"
DijkstraResult* dijkstra(Graph *graph, int source){
    DijkstraResult* dijkstra_result;
    int *min_priority_queue;
    int u;
    dijkstra_result = allocate_memory_dijkstra(graph->numbers_nodes);
    initialize(dijkstra_result, source, graph->numbers_nodes);
    min_priority_queue = (int*)malloc(sizeof(int) * graph->numbers_nodes);
    for(int i = 0; i < graph->numbers_nodes; i++)
        min_priority_queue[i] = MAX_WEIGHT;
    min_priority_queue[source] = 0;
    while(lenght(min_priority_queue, graph->numbers_nodes)){
        u = extract_minimum(min_priority_queue, graph->numbers_nodes);
        for(int v = 0; v < graph->numbers_nodes; v++)
            relax(dijkstra_result, min_priority_queue, graph, u, v);
        min_priority_queue[u] = EMPTY;
    }
    return dijkstra_result;
}; 

DijkstraResult* allocate_memory_dijkstra(int numbers_nodes){
    DijkstraResult* dijkstra_result;
    dijkstra_result = (DijkstraResult*)malloc(sizeof(DijkstraResult));
    dijkstra_result->distance = (int*)malloc(sizeof(int) * numbers_nodes);
    dijkstra_result->predecessor = (int*)malloc(sizeof(int) * numbers_nodes);
    return dijkstra_result;
};

void initialize(DijkstraResult* dijkstra_result, int source, int numbers_nodes){
    for(int i = 0; i < numbers_nodes; i++){
        dijkstra_result->distance[i] = MAX_WEIGHT;
        dijkstra_result->predecessor[i] = PREDECESSOR_NULL;
    };
    dijkstra_result->distance[source] = 0;
};

bool lenght(int *nodes_distance, int numbers_nodes){
    bool result = false;
    for(int i = 0; i < numbers_nodes; i++)
        if(nodes_distance[i] != EMPTY or nodes_distance[i] == MAX_WEIGHT)
            result = true;
    return result;
};

int extract_minimum(int *nodes_distance, int numbers_nodes){
    int index_min;
    int i = 0;
    while(nodes_distance[i] == EMPTY)
        i += 1;
    index_min = i;
    for(i = 0; i < numbers_nodes; i++)
        if(nodes_distance[i] != EMPTY and nodes_distance[i] < nodes_distance[index_min])
            index_min = i;
    return index_min;
};

void relax(DijkstraResult* dijkstra_result, int* min_priority_queue, Graph* graph, int u, int v){
    if(exist_arc(graph, u, v) and dijkstra_result->distance[v] > dijkstra_result->distance[u] + get_cost_edge(graph, u, v)){
        dijkstra_result->distance[v] = dijkstra_result->distance[u] + get_cost_edge(graph, u, v);
        dijkstra_result->predecessor[v] = u;
        min_priority_queue[v] = dijkstra_result->distance[v];
    }
};
