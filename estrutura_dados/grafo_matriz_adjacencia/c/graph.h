#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#ifndef GRAPH_H
#define GRAPH_H
#define MAX_WEIGHT INT_MAX
typedef struct graph{
    int numbers_nodes = 0;
    int numbers_edges = 0;
    int **edges = NULL;
} Graph;

bool empty(Graph *);
void allocate_memory(Graph *);
void insert_edge(Graph *, int, int, int);
void insert_arc(Graph *, int, int, int);
int get_cost_edge(Graph *, int, int);
bool exist_arc(Graph *, int, int);
#endif
