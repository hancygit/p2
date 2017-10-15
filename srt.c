#include "common.h"

process * next_proc_srt(process* ptr, int Q, int S, process* nop){
    int i =0;
    qsort(ptr, NUMBER_OF_PROCS, sizeof(process), compare_remaining_runtimes);
    for (i=0; i< NUMBER_OF_PROCS; i++){
        if(S){
            if (Q >= ptr[i].arrival_time && ptr[i].remaining_runtime > 0 && ptr[i].remaining_runtime != ptr[i].expected_runtime) return &ptr[i];
        }else{
            if (Q >= ptr[i].arrival_time && ptr[i].remaining_runtime > 0) return &ptr[i];
        }
    }
    return NULL;
}
