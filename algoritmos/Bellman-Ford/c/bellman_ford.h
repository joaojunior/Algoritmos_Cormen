#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H
#include <stdlib.h>
#include "../../../estrutura_dados/grafo_matriz_adjacencia/c/graph.h" 
typedef struct bell{
    int *distance;
    bool exist_negative_cycle;
} BellmanFordResult;

BellmanFordResult *bellmanFord(Graph*, int);
BellmanFordResult *allocate_memory(int);
void initialize(BellmanFordResult *, int, int);
void relax(BellmanFordResult *, Graph*, int, int);
void verify_negative_cycle(BellmanFordResult *, Graph *);
#endif