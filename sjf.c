#include "common.h"

process * next_proc_sjf(process* ptr, int Q, int S, process* c){
    int i =0;
    if (c != NULL && c->remaining_runtime > 0 && c->remaining_runtime != c->expected_runtime) return c; // non-preemptive-ness
    for (i=0; i< NUMBER_OF_PROCS; i++){
        if(S){
            if (Q >= ptr[i].arrival_time && ptr[i].remaining_runtime > 0 && ptr[i].remaining_runtime != ptr[i].expected_runtime) return &ptr[i];
        }else{
            if (Q >= ptr[i].arrival_time && ptr[i].remaining_runtime > 0) return &ptr[i];
        }
    }
    return NULL;
}
