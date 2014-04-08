#include "repeated_squaring.h"
RepeatedSquaringResult *repeated_squaring(Graph *graph){
    RepeatedSquaringResult *result;
    int m;
    result = allocate_memory(graph->numbers_nodes);
    initialize(result, graph);
    m = 1;
    while(m < graph->numbers_nodes - 1){
        result = extend(result, result, graph->numbers_nodes);
        m = 2 * m;
    }
    calculate_predecessor(result, graph);
    return result;
};

RepeatedSquaringResult *allocate_memory(int numbers_nodes){
    RepeatedSquaringResult *result;
    result = (RepeatedSquaringResult *)malloc(sizeof(RepeatedSquaringResult));
    result->distance = (int **)malloc(numbers_nodes * sizeof(int *));
    result->predecessor = (int **)malloc(numbers_nodes * sizeof(int *));
    for(int i = 0; i < numbers_nodes; i++){
        result->distance[i] = (int *)malloc(numbers_nodes * sizeof(int));
        result->predecessor[i] = (int *)malloc(numbers_nodes * sizeof(int));
    }
    return result;
};

void initialize(RepeatedSquaringResult *result, Graph *graph){
    for(int i = 0; i < graph->numbers_nodes; i++)
        for(int j = 0; j < graph->numbers_nodes; j++){
            if(i == j)
                result->distance[i][j] = 0;
            else
                result->distance[i][j] = get_cost_edge(graph, i, j);
            if(exist_arc(graph, i, j))
                result->predecessor[i][j] = i;
            else
                result->predecessor[i][j] = PREDECESSOR_NULL;
        }
};

RepeatedSquaringResult *extend(RepeatedSquaringResult *L, RepeatedSquaringResult *W, int numbers_nodes){
    int l;
    for(int i = 0; i < numbers_nodes; i++){
        for(int j = 0; j < numbers_nodes; j++){
            l = MAX_WEIGHT;
            for(int k = 0; k < numbers_nodes; k++){
                if(L->distance[i][k] + W->distance[k][j] < l)
                    l = L->distance[i][k] + W->distance[k][j];
            }
            L->distance[i][j] = l;
        }
    }
    return L;
};

void calculate_predecessor(RepeatedSquaringResult *result, Graph *graph){
    for(int i = 0; i < graph->numbers_nodes; i++)
        for(int j = 0; j < graph->numbers_nodes; j++)
            if(i != j){
                for(int k = 0; k < graph->numbers_nodes; k++)
                    if(result->distance[i][j] == result->distance[i][k] + get_cost_edge(graph, k, j))
                        result->predecessor[i][j] = k;
            }
};