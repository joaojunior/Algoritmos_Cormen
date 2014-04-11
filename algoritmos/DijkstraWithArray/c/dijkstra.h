#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <stdlib.h>
#include "../../../estrutura_dados/grafo_matriz_adjacencia/c/graph.h"
#define PREDECESSOR_NULL -1
#define NODE_NOT_VISITED -1
typedef struct{
    int *distance;
    int *predecessor;
} DijkstraResult;

DijkstraResult* dijkstra(Graph *, int);
DijkstraResult* allocate_memory_dijkstra(int);
void initialize(DijkstraResult*, int*, int, int);
bool exist_node2visit(int *, int);
int extract_minimum(int *, int);
void relax(DijkstraResult*, int*, Graph*, int, int);
#endif
