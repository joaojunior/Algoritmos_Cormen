#ifndef HEAP_MIN_H
#define HEAP_MIN_H
#include <stdlib.h>
typedef struct{
    int key;
    int value;
} Cell;
typedef struct heap_min{
    Cell *values;
} HeapMin;

int parent(int);
int right(int);
int left(int);
void allocate_memory(HeapMin *, int);
int lenght(HeapMin *);
void min_heapify(HeapMin *, int);
void swap(HeapMin *, int, int);
void build_min_heap(HeapMin *);
void decrement_lenght(HeapMin *);
void set_value_and_key_i(HeapMin *, int, int, int);
void set_value_i(HeapMin *, int, int);
void set_key_i(HeapMin *, int, int);
int get_key_i(HeapMin *, int);
int get_value_i(HeapMin *, int);
#endif

