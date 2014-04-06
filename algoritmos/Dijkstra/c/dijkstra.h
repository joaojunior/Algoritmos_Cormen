#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <stdlib.h>
#include "../../../estrutura_dados/grafo_matriz_adjacencia/c/graph.h"
#include "../../../estrutura_dados/MinPriorityQueue/c/min_priority_queue.h"
typedef struct{
    int *distance;
    int *predecessor;
} DijkstraResult;

DijkstraResult* dijkstra(Graph *, int);
#endif
