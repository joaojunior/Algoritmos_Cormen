#include <stddef.h>
#include <stdlib.h>
#ifndef FLOYD_WARSHALL_H
#define FLOYD_WARSHALL_H
#define MAX_DISTANCE 100000
#include "../../../estrutura_dados/grafo_matriz_adjacencia/c/graph.h"
#include "../../../estrutura_dados/fila/c/fila.h"

Graph *floyd_warshall(Graph *);
#endif


