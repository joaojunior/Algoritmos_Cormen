#include "bfs.h"
BFSResult *bfs(Graph *graph, int source){
    BFSResult *bfs_result;
    int *colors;
    Queue nodes;
    int node_id;
    int cost_edge;
    enqueue(&nodes, source);
    bfs_result = (BFSResult *)malloc(sizeof(BFSResult));
    bfs_result->distance = (int *)malloc(graph->numbers_nodes * sizeof(int));
    colors = (int *)malloc(graph->numbers_nodes * sizeof(int));
    bfs_result->before = (int *)malloc(graph->numbers_nodes * sizeof(int));
    for(int i = 0; i < graph->numbers_nodes; i++){
        colors[i] = WHITE;
        bfs_result->before[i] = NULL;
    };
    bfs_result->distance[source] = 0;
    colors[source] = GRAY;
    while(!empty(&nodes)){
        node_id = dequeue(&nodes);
        for(int i = 0; i < graph->numbers_nodes; i++){
            cost_edge = get_cost_edge(graph, node_id, i);
            if(cost_edge > 0 and colors[i] == WHITE){
                enqueue(&nodes, i);
                bfs_result->distance[i] = bfs_result->distance[node_id] + 1;
                colors[i] = GRAY;
                bfs_result->before[i] = node_id;
            }
        };
        colors[node_id] = BLACK;
    };
    return bfs_result;
}; 
