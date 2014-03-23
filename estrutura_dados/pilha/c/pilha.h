#include <stddef.h>
#ifndef PILHA_H
#define PILHA_H
#define ID_NULO -1

typedef struct element{
    int id=ID_NULO;
    struct element *prev=NULL;
} Element;

typedef struct{
    Element *top=NULL;
} Pilha;

bool empty(Pilha *); 
void push(Pilha *, Element *);
Element pop(Pilha *);
#endif