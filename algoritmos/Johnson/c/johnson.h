#ifndef JOHNSON_H
#define JOHNSON_H
#include "../../../estrutura_dados/grafo_matriz_adjacencia/c/graph.h"
#include "../../Bellman-Ford/c/bellman_ford.h"
#include "../../Dijkstra/c/dijkstra.h"
typedef struct{
    int **distance;
} JohnsonResult;

JohnsonResult* jonhson(Graph *);
BellmanFordResult* reconsider_graph(Graph *);
void create_graph_reconsidered(Graph *,Graph *);
#endif
