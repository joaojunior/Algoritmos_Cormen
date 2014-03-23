#include "graph.h"
bool empty(Graph *graph){
    bool result = false;
    if(graph->list_adj_node == NULL)
        result = true;
    return result;
};

void insert_edge(Graph *graph, int source, int dest){
    Edge *new_edge;
    Cell *last_cell, *new_cell;
    new_edge = (Edge *) malloc(sizeof *new_edge);
    new_cell = (Cell *) malloc(sizeof *new_cell);
    new_edge->dest = dest;
    new_edge->weight = 1;
    new_cell->edge = *new_edge;
    new_cell->next = NULL;
    if(graph->list_adj_node[source].first == NULL)
        graph->list_adj_node[source].first = new_cell;
    else{
        last_cell = graph->list_adj_node[source].first;
        while(last_cell->next != NULL)
            last_cell = last_cell->next;
        last_cell->next = new_cell;
    };
};

Edge *get_edge(Graph *graph, int source, int dest){
    Edge *edge_found = NULL;
    Cell *cell;
    cell = graph->list_adj_node[source].first;
    while(cell != NULL && cell->edge.dest != dest)
        cell = cell->next;
    if(cell != NULL){
        edge_found = &(cell->edge);
    }
    return edge_found;
};