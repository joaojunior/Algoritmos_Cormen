#include <stddef.h>
#include <stdlib.h>
#ifndef FLOYD_WARSHALL_H
#define FLOYD_WARSHALL_H
#include "../../../estrutura_dados/grafo_matriz_adjacencia/c/graph.h"
#define PREDECESSOR_NULL -1
typedef struct{
    int **distance;
    int **predecessor;
} ResultFloydWarshall;
ResultFloydWarshall *floyd_warshall(Graph *);
ResultFloydWarshall *allocate_memory(int);
void initialize(ResultFloydWarshall *, Graph *);
#endif


