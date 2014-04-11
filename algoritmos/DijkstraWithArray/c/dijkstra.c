#include "dijkstra.h"
DijkstraResult* dijkstra(Graph *graph, int source){
    DijkstraResult* dijkstra_result;
    int *nodes2Visit;
    int u;
    dijkstra_result = allocate_memory_dijkstra(graph->numbers_nodes);
    nodes2Visit = (int*)malloc(sizeof(int) * graph->numbers_nodes);
    initialize(dijkstra_result,nodes2Visit, source, graph->numbers_nodes);
    while(exist_node2visit(nodes2Visit, graph->numbers_nodes)){
        u = extract_minimum(nodes2Visit, graph->numbers_nodes);
        for(int v = 0; v < graph->numbers_nodes; v++)
            relax(dijkstra_result, nodes2Visit, graph, u, v);
        nodes2Visit[u] = NODE_NOT_VISITED;
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

void initialize(DijkstraResult* dijkstra_result, int *nodes2Visit, int source, int numbers_nodes){
    for(int i = 0; i < numbers_nodes; i++){
        dijkstra_result->distance[i] = MAX_WEIGHT;
        dijkstra_result->predecessor[i] = PREDECESSOR_NULL;
        nodes2Visit[i] = MAX_WEIGHT;
    };
    dijkstra_result->distance[source] = 0;
    nodes2Visit[source] = 0;
};

bool exist_node2visit(int *nodes_distance, int numbers_nodes){
    bool result = false;
    for(int i = 0; i < numbers_nodes; i++)
        if(nodes_distance[i] != NODE_NOT_VISITED or nodes_distance[i] == MAX_WEIGHT)
            result = true;
    return result;
};

int extract_minimum(int *nodes_distance, int numbers_nodes){
    int index_min;
    int i = 0;
    while(nodes_distance[i] == NODE_NOT_VISITED)
        i += 1;
    index_min = i;
    for(i = 0; i < numbers_nodes; i++)
        if(nodes_distance[i] != NODE_NOT_VISITED and nodes_distance[i] < nodes_distance[index_min])
            index_min = i;
    return index_min;
};

void relax(DijkstraResult* dijkstra_result, int* nodes2Visit, Graph* graph, int u, int v){
    if(exist_arc(graph, u, v) and dijkstra_result->distance[v] > dijkstra_result->distance[u] + get_cost_edge(graph, u, v)){
        dijkstra_result->distance[v] = dijkstra_result->distance[u] + get_cost_edge(graph, u, v);
        dijkstra_result->predecessor[v] = u;
        nodes2Visit[v] = dijkstra_result->distance[v];
    }
};
