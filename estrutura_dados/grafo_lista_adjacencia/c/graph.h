#include <stddef.h>
#include <stdlib.h>
#ifndef GRAPH_H
#define GRAPH_H

typedef struct edge{
    int dest;
    float weight = 0;
} Edge;

typedef struct cell{
    Edge edge;
    struct cell *next;
} Cell;

typedef struct list_adj{
    Cell *first=NULL;
} ListAdj;

typedef struct graph{
    int numbers_node = 0;
    ListAdj *list_adj_node=NULL;
} Graph;

bool empty(Graph *);
void insert_edge(Graph *, int, int, int);
Edge *get_edge(Graph *, int, int);

#endif
