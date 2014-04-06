#ifndef HEAP_MIN_H
#define HEAP_MIN_H
#include <stdlib.h>
typedef struct heap_min{
    int *values;
} HeapMin;

int parent(int);
int right(int);
int left(int);
void allocate_memory(HeapMin *, int);
int lenght(HeapMin *);
void min_heapify(HeapMin *, int);
void build_min_heap(HeapMin *);
void decrement_lenght(HeapMin *);
void set_key_i(HeapMin *, int, int);
int get_key_i(HeapMin *, int);
#endif

