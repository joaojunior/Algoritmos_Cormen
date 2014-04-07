#include <stddef.h>
#include <stdlib.h>
#ifndef BFS_H
#define BFS_H
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define PREDECESSOR_NULL -1
#include "../../../estrutura_dados/grafo_matriz_adjacencia/c/graph.h"
#include "../../../estrutura_dados/fila/c/fila.h"

typedef struct{
    int *distance;
    int *predecessor;
}BFSResult;

BFSResult *bfs(Graph *, int);
#endif


