#include "floyd_warshall.h"
ResultFloydWarshall *floyd_warshall(Graph *graph){
    ResultFloydWarshall *result_floyd_warshall;
    result_floyd_warshall = allocate_memory(graph->numbers_nodes);
    initialize(result_floyd_warshall, graph);
    for(int k = 0; k < graph->numbers_nodes; k++)
        for(int i = 0; i < graph->numbers_nodes; i++)
            for(int j = 0; j < graph->numbers_nodes; j++)
                if(result_floyd_warshall->distance[i][j] > result_floyd_warshall->distance[i][k] + result_floyd_warshall->distance[k][j]
                and result_floyd_warshall->distance[i][k] != MAX_WEIGHT and result_floyd_warshall->distance[k][j] != MAX_WEIGHT){
                    result_floyd_warshall->distance[i][j] = result_floyd_warshall->distance[i][k] + result_floyd_warshall->distance[k][j];
                    result_floyd_warshall->predecessor[i][j] = result_floyd_warshall->predecessor[k][j];
                }
    return result_floyd_warshall;
};

ResultFloydWarshall *allocate_memory(int numbers_nodes){
    ResultFloydWarshall *result_floyd_warshall;
    result_floyd_warshall = (ResultFloydWarshall *)malloc(sizeof(ResultFloydWarshall));
    result_floyd_warshall->distance = (int **)malloc(numbers_nodes * sizeof(int *));
    result_floyd_warshall->predecessor = (int **)malloc(numbers_nodes * sizeof(int *));
    for(int i = 0; i < numbers_nodes; i++){
        result_floyd_warshall->distance[i] = (int *)malloc(numbers_nodes * sizeof(int));
        result_floyd_warshall->predecessor[i] = (int *)malloc(numbers_nodes * sizeof(int));
    }
    return result_floyd_warshall;
};

void initialize(ResultFloydWarshall *result_floyd_warshall, Graph *graph){
    for(int i = 0; i < graph->numbers_nodes; i++)
        for(int j = 0; j < graph->numbers_nodes; j++){
            if(i == j)
                result_floyd_warshall->distance[i][j] = 0;
            else
                result_floyd_warshall->distance[i][j] = get_cost_edge(graph, i, j);
            if(exist_arc(graph, i, j))
                result_floyd_warshall->predecessor[i][j] = i;
            else
                result_floyd_warshall->predecessor[i][j] = PREDECESSOR_NULL;
        }
};
