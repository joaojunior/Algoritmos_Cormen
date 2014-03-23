#include "lista_dupla.h" 

bool empty(ListDoubly *list_doubly){
    bool result = false;
    if(list_doubly->first == NULL)
        result = true;
    return result;
};

void insert(ListDoubly *list_doubly, Cell *cell){
    Cell *position_before_insert;
    if(empty(list_doubly))
        list_doubly->first = cell;
    else{
        position_before_insert = list_doubly->first;
        while(position_before_insert->next != NULL)
            position_before_insert = position_before_insert->next;
        cell->prev = position_before_insert;
        position_before_insert->next = cell;
    };
};

Cell *search(ListDoubly *list_doubly, int id){
    Cell *result=NULL;
    if(!empty(list_doubly)){        
        result = list_doubly->first;
        while(result->id != id and result->next != NULL)
            result = result->next;
        if(result->id != id)
            result = NULL;
    }
    return result;
};

Cell *remove(ListDoubly *list_doubly, int id){
    Cell *before = NULL, *cell_removed = NULL;
    if(list_doubly->first-> id == id){
        cell_removed = list_doubly->first;
        list_doubly->first = list_doubly->first->next;
    } else{
        before = list_doubly->first;
        while(before->next != NULL and before->next->id != id)
            before = before->next;
        if(before->next != NULL){
            cell_removed = before->next;
            if(cell_removed->next){
                before->next = cell_removed->next;
                before->next->prev = before;
            } else{
                before->next = NULL;
            };
        }
    };
    return cell_removed;
};