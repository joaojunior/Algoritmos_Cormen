#include "repeated_squaring.h"
Graph *repeated_squaring(Graph *graph){
    Graph *result;
    int m;
    result = (Graph *)malloc(sizeof(Graph));
    result->numbers_nodes = graph->numbers_nodes;
    allocate_memory(result);
    for(int i = 0; i < result->numbers_nodes; i++)
        for(int j = 0; j < result->numbers_nodes; j++)
            if(i == j)
                insert_arc(result, i, j, 0);
            else
                insert_arc(result, i, j, get_cost_edge(graph, i, j));
    m = 1;
    while(m < graph->numbers_nodes - 1){
        result = extend(result, result);
        m = 2 * m;
    }
    return result;
};

Graph *extend(Graph *L, Graph *W){
    int l;
    for(int i = 0; i < L->numbers_nodes; i++){
        for(int j = 0; j < L->numbers_nodes; j++){
            l = MAX_WEIGHT;
            for(int k = 0; k < L->numbers_nodes; k++){
                if(get_cost_edge(L, i, k) + get_cost_edge(W, k, j) < l)
                    l = get_cost_edge(L, i, k) + get_cost_edge(W, k, j);
            }
            L->edges[i][j] = l;
        }
    }
    return L;
};
