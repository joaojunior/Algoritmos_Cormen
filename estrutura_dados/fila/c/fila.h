#include <stddef.h>
#include <stdlib.h>
#ifndef FILA_H
#define FILA_H
typedef struct cell{
    int id;
    struct cell *prox=NULL;
} Cell;
typedef struct{
    Cell *first=NULL;
    Cell *last=NULL;
} Queue;
bool empty(Queue *);
void enqueue(Queue *, int);
int dequeue(Queue *);
#endif
