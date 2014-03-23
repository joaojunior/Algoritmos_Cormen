#include "pilha.h"

bool empty(Pilha *pilha){
    bool empty=false;
    if(pilha->top == NULL){
        empty = true;
    }
    return empty;
};

void push(Pilha *pilha, Element *element){
    element->prev = pilha->top;
    pilha->top = element;
};

Element pop(Pilha *pilha){
    Element result;
    if(empty(pilha)){
    } else{
        result = *(pilha->top);
        pilha->top = result.prev;
    }
    return result;
};