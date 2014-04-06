#include "min_priority_queue.h"
int minimum(MinPriorityQueue *min_priority_queue){
    return get_key_i(min_priority_queue, 1);
};

int extract_minimum(MinPriorityQueue *min_priority_queue){
    int min;
    min = minimum(min_priority_queue);
    set_key_i(min_priority_queue, 1, get_key_i(min_priority_queue, lenght(min_priority_queue)));
    decrement_lenght(min_priority_queue);
    min_heapify(min_priority_queue, 1);
    return min;
};

void decrease_key(MinPriorityQueue *min_priority_queue, int i, int new_value){
    int aux;
    if(new_value < get_key_i(min_priority_queue, i)){
        set_key_i(min_priority_queue, i, new_value);
        while(i > 1 and get_key_i(min_priority_queue, parent(i)) > get_key_i(min_priority_queue, i)){
            aux = get_key_i(min_priority_queue, parent(i));
            set_key_i(min_priority_queue, parent(i), get_key_i(min_priority_queue, i));
            set_key_i(min_priority_queue, i, aux);
            i = parent(i);
        }
    };
};