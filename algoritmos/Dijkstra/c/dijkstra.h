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
DijkstraResult* allocate_memory_dijkstra(int);
void initialize(DijkstraResult*, MinPriorityQueue*, int, int);
void relax(DijkstraResult*, MinPriorityQueue*, Graph*, int, int);
#endif
