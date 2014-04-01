#include "floyd_warshall.h"
Graph *floyd_warshall(Graph *graph){
    Graph *result;
    result = (Graph *)malloc(sizeof(Graph));
    result->numbers_nodes = graph->numbers_nodes;
    allocate_memory(result);
    for(int i = 0; i < result->numbers_nodes; i++)
        for(int j = 0; j < result->numbers_nodes; j++)
            if(i == j or get_cost_edge(graph, i, j) != 0)
                insert_arc(result, i, j, get_cost_edge(graph, i, j));
            else
                insert_arc(result, i, j, MAX_DISTANCE);
    for(int k = 0; k < result->numbers_nodes; k++)
        for(int i = 0; i < result->numbers_nodes; i++)
            for(int j = 0; j < result->numbers_nodes; j++)
                if(get_cost_edge(result, i, j) > get_cost_edge(result, i, k) + get_cost_edge(result, k, j))
                    result->edges[i][j] = get_cost_edge(result, i, k) + get_cost_edge(result, k, j);
    return result;
};
