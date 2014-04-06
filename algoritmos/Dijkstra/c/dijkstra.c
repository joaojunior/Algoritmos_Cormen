#include "dijkstra.h"
DijkstraResult* dijkstra(Graph *graph, int source){
    DijkstraResult* dijkstra_result;
    MinPriorityQueue min_priority_queue;
    int u;
    dijkstra_result = (DijkstraResult*)malloc(sizeof(DijkstraResult));
    dijkstra_result->distance = (int*)malloc(sizeof(int) * graph->numbers_nodes);
    dijkstra_result->predecessor = (int*)malloc(sizeof(int) * graph->numbers_nodes);
    allocate_memory(&min_priority_queue, graph->numbers_nodes);
    for(int i = 0; i < graph->numbers_nodes; i++){
        dijkstra_result->distance[i] = MAX_WEIGHT;
        dijkstra_result->predecessor[i] = NULL;
        set_value_and_key_i(&min_priority_queue, i+1, MAX_WEIGHT, i);
    };
    dijkstra_result->distance[source] = 0;
    set_value_and_key_i(&min_priority_queue, 1, 0, source);
    build_min_heap(&min_priority_queue);
    while(lenght(&min_priority_queue) > 0){
        u = extract_minimum(&min_priority_queue);
        for(int v = 0; v < graph->numbers_nodes; v++){
            if(exist_arc(graph, u, v) and dijkstra_result->distance[v] > dijkstra_result->distance[u] + get_cost_edge(graph, u, v)){
                dijkstra_result->distance[v] = dijkstra_result->distance[u] + get_cost_edge(graph, u, v);
                dijkstra_result->predecessor[v] = u;
                decrease_key(&min_priority_queue, v, dijkstra_result->distance[v]);
            }
        }
        
    }
    return dijkstra_result;
}; 
