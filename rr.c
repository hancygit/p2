#include "common.h"

//Get index of the last served process
static int get_index(process* ptr, int last_serviced)
{
    for (int i=0; i< NUMBER_OF_PROCS; i++){
        if (ptr[i].pid == last_serviced)
        {
            return i;
        }
        else{
            continue;
        }
    } 
    return 0;
}

// takes a sorted process array and a quanta and returns the next valid proc to run or NULL if none found
process * next_proc_rr(process* ptr, int Q, process* c, int last_serviced){
    int i =0;
    int index = 0;
    //Get index of last served process
    index = get_index(ptr, last_serviced);

    //Traverse left to select next process to serve
    for(i=index+1; i<NUMBER_OF_PROCS; i++){
        if(Q >= ptr[i].arrival_time && ptr[i].remaining_runtime > 0){
            return &ptr[i];
        }
    }

    //Traverse right to select next process to serve
    for (i=0; i< index; i++){
        if (Q >= ptr[i].arrival_time && ptr[i].remaining_runtime > 0)
        {
            return &ptr[i];
        }
    }

    //Return same element in case there is no other process to serve
    if (c != NULL && c->remaining_runtime > 0) {
         return c; 
    }
    return NULL;
}
