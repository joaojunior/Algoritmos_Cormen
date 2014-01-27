#include "lista_circular.h"

bool empty(Cell *sentinel){
    bool result = false;
    if(sentinel->next == NULL or sentinel->next == sentinel)
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

Cell *remove(Cell *sentinel, int id){
    Cell *result=NULL, *prev;
    prev = sentinel;
    while(prev->next->id != id and prev->next != sentinel){
        prev = prev->next;
    }
    if(prev->next != sentinel){
        result = prev->next;
        prev->next = result->next;
    }
    return result;
};

Cell *search(Cell *sentinel, int id){
    Cell *result=NULL;
    result = sentinel;
    while(result->id != id and result->next != sentinel){
        result = result->next;
    }
    if(result->id != id)
        result = NULL;
    return result;
};