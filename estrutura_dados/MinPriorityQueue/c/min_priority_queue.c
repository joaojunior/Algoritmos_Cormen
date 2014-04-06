#include "min_priority_queue.h"
int minimum(MinPriorityQueue *min_priority_queue){
    return get_key_i(min_priority_queue, 1);
};

int extract_minimum(MinPriorityQueue *min_priority_queue){
    int min;
    min = minimum(min_priority_queue);
    set_value_and_key_i(min_priority_queue, 1, get_value_i(min_priority_queue, lenght(min_priority_queue)), get_key_i(min_priority_queue, lenght(min_priority_queue)));
    decrement_lenght(min_priority_queue);
    min_heapify(min_priority_queue, 1);
    return min;
};

void decrease_key(MinPriorityQueue *min_priority_queue, int key, int new_value){
    int i;
    i = get_position_from_key(min_priority_queue, key);
    if(new_value < get_value_i(min_priority_queue, i)){
        set_value_i(min_priority_queue, i, new_value);
        while(i > 1 and get_value_i(min_priority_queue, parent(i)) > get_value_i(min_priority_queue, i)){
            swap(min_priority_queue, i, parent(i));
            i = parent(i);
        }
    };
};