#include <stddef.h>
#ifndef LISTA_H
#define LISTA_H
typedef struct cell{
    int id;
    struct cell *next=NULL;
} Cell;
typedef struct list{
    Cell *first=NULL;
} List;

bool empty(List *);
void insert(List *, Cell *);
Cell *search(List *, int);
Cell *remove(List *, int);
Cell *search_next(Cell **, int);
#endif
