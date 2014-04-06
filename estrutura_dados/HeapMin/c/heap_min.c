#include "heap_min.h" 
int parent(int i){
    return i / 2;
};

int left(int i){
    return 2 * i;
};

int right(int i){
    return 2 * i + 1;
};

void allocate_memory(HeapMin *heap_min, int lenght){
    heap_min->values = (int *)malloc(sizeof(int) * (lenght + 1));
    heap_min->values[0] = lenght;
};

int lenght(HeapMin *heap_min){
    return heap_min->values[0];
};

void min_heapify(HeapMin *heap_min, int i){
    int l, r, min, aux;
    l = left(i);
    r = right(i);
    if(l <= lenght(heap_min) and heap_min->values[l] < heap_min->values[i])
        min = l;
    else
        min = i;
    if(r <= lenght(heap_min) and heap_min->values[r] < heap_min->values[min])
        min = r;
    if(min != i){
        aux = heap_min->values[i];
        heap_min->values[i] = heap_min->values[min];
        heap_min->values[min] = aux;
        min_heapify(heap_min, min);
    };
};

void build_min_heap(HeapMin *heap_min){
    for(int i = lenght(heap_min) / 2; i > 0; i--)
        min_heapify(heap_min, i);
};

void decrement_lenght(HeapMin *heap_min){
    heap_min->values[0] -= 1;
};

void set_key_i(HeapMin *heap_min, int i, int value){
    heap_min->values[i] = value;
};

int get_key_i(HeapMin *heap_min, int i){
    return heap_min->values[i];
};