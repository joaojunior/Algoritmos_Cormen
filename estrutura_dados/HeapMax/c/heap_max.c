#include "heap_max.h"
void allocate_memory(HeapMax *heap_max, int lenght){
    heap_max->values = (int *)malloc(sizeof(int) * (lenght + 1));
    heap_max->values[0] = lenght;
};

int lenght(HeapMax *heap_max){
    return heap_max->values[0];
};

int parent(int i){
    return i / 2;
};

int left(int i){
    return 2 * i;
};

int right(int i){
    return 2 * i + 1;
};

void max_heapify(HeapMax *heap_max, int i){
    int l, r, max, aux;
    l = left(i);
    r = right(i);
    if(l <= lenght(heap_max) and heap_max->values[l] > heap_max->values[i])
        max = l;
    else
        max = i;
    if(r <= lenght(heap_max) and heap_max->values[r] > heap_max->values[max])
        max = r;
    if(max != i){
        aux = heap_max->values[i];
        heap_max->values[i] = heap_max->values[max];
        heap_max->values[max] = aux;
        max_heapify(heap_max, max);
    };
};

void build_max_heap(HeapMax *heap_max){
    for(int i = heap_max->values[0] / 2; i > 0; i--)
        max_heapify(heap_max, i);
};