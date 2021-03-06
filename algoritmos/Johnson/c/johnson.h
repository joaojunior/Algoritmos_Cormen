#ifndef JOHNSON_H
#define JOHNSON_H
#include "../../../estrutura_dados/grafo_matriz_adjacencia/c/graph.h"
#include "../../Bellman-Ford/c/bellman_ford.h"
#include "../../DijkstraWithMinPriorityQueue/c/dijkstra.h"
#define PREDECESSOR_NULL -1
typedef struct{
    int **distance;
    int **predecessor;
} JohnsonResult;

JohnsonResult* jonhson(Graph *);
BellmanFordResult* reconsider_graph(Graph *);
void create_graph_reconsidered(Graph *,Graph *);
#endif
