#ifndef MIN_PRIORITY_QUEUE
#define MIN_PRIORITY_QUEUE
#include "../../HeapMin/c/heap_min.h"
#define MinPriorityQueue HeapMin
int minimum(MinPriorityQueue *);
int extract_minimum(MinPriorityQueue *);
void decrease_key(MinPriorityQueue *, int, int);
#endif
