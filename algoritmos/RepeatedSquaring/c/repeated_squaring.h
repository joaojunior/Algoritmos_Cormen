#include <stddef.h>
#include <stdlib.h>
#ifndef REPEATED_SQUARING_H
#define REPEATED_SQUARING_H
#include "../../../estrutura_dados/grafo_matriz_adjacencia/c/graph.h"
#define PREDECESSOR_NULL -1
typedef struct{
    int **distance;
    int **predecessor;
}RepeatedSquaringResult;
RepeatedSquaringResult *repeated_squaring(Graph *);
RepeatedSquaringResult *allocate_memory(int);
void initialize(RepeatedSquaringResult *, Graph *);
RepeatedSquaringResult *extend(RepeatedSquaringResult *, RepeatedSquaringResult *, int);
void calculate_predecessor(RepeatedSquaringResult *, Graph *);
#endif


