#include "lista_circular.h"

bool empty(Cell *sentinel){
    bool result = false;
    if(sentinel->next == NULL)
        result = true;
    return result;
};

void insert(Cell *sentinel, Cell *cell){
    Cell *first;
    if(empty(sentinel))
        first = sentinel;
    else
        first = sentinel->next;
    sentinel->next = cell;
    cell->next = first;
};