#include "lista.h"

bool empty(List *list){
    bool result=false;
    if(list->first == NULL)
        result = true;
    return result;
}; 

void insert(List *list, Cell *cell){
    Cell *aux;
    if(empty(list)){
        list->first = cell;
    } else{
        aux = list->first;
        while(aux->next != NULL)
            aux = aux->next;
        aux->next = cell;
    };
};

Cell *search(List *list, int id){
    Cell *result=NULL;
    if(!empty(list)){
        result = list->first;
        while(result != NULL and result->id != id){
            result = result->next;
        }
    }
    return result;
};

Cell *remove(List *list, int id){
    Cell *aux=NULL, *result=NULL;
    if(!empty(list)){
        aux = list->first;
        if(aux->id == id){
            result = aux;
            list->first = aux->next;
        } else{
            result = search_next(&aux, id);
            if(result){
                if(result->next)
                    aux->next = result->next;
                else
                    aux->next = NULL;
            };
        }
    }
    return result;
};

Cell *search_next(Cell **prev, int id){
    while((*prev)->next != NULL and (*prev)->next->id != id)
        (*prev) = (*prev)->next;
    return (*prev)->next;
};