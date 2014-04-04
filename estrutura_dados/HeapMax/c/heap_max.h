#ifndef HEAP_MAX_H
#define HEAP_MAX_H
#include <stddef.h>
#include <stdlib.h>

typedef struct heap_max{
    int *values;
} HeapMax;

void allocate_memory(HeapMax *, int);
int lenght(HeapMax *);
int parent(int);
int left(int);
int right(int);
void max_heapify(HeapMax *, int);
void build_max_heap(HeapMax *);

#endif