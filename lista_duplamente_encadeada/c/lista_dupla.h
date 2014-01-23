#include <stddef.h>

typedef struct  cell{
    int id;
    struct cell *prev = NULL, *next = NULL;
} Cell;

typedef struct{
    Cell *first=NULL;
} ListDoubly;

bool empty(ListDoubly *);
void insert(ListDoubly *, Cell *);
Cell *search(ListDoubly *, int);
Cell *remove(ListDoubly *, int);
