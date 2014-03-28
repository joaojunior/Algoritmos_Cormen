#include "fila.h"
bool empty(Queue *queue){
    bool result = false;
    if(queue->first == NULL and queue->last == NULL)
        result = true;
    return result;
};

void enqueue(Queue *queue, int id){
    Cell *cell;
    cell = (Cell *)malloc(sizeof(Cell));
    cell->id = id;
    cell->prox = NULL;
    if(empty(queue)){
        queue->first = cell;
        queue->last = cell;
    } else{
        queue->last->prox = cell;
        queue->last = cell;
    };
};

int dequeue(Queue *queue){
    Cell *result;
    result = queue->first;
    int id_result = -1;
    if(queue->first == queue->last){
        queue->first = NULL;
        queue->last = NULL;
    } else{
        queue->first = queue->first->prox;
    };
    if(result)
        id_result = result->id;
    return id_result;
};
