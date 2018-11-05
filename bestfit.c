#include "bestfit.h"
#include "PQ.h"
#include <stdio.h>
#include <stdlib.h>

#define PARTITION_SIZE 1000000

void bestfit(Item* fileSize, int numberOfFiles){
    PQ* pq = PQ_init(numberOfFiles); 
    PQ_insert(pq,0);  // Starts the first partition with 0KB used, just to avoid size check.

    for(int i = 0, j = 1; i < numberOfFiles; i++){
        if(!(PQ_get_item(pq, j) + fileSize[i] <= PARTITION_SIZE)){ //if doesnt fits, create another disk
            PQ_insert(pq, fileSize[i]);
            continue; //jumps to the next index i.
        }
        while(j <= PQ_size(pq) && PQ_get_item(pq, j) + fileSize[i] <= PARTITION_SIZE) // iterates up until finds the first disk that doesnt fit and then rollback index 1 time.
            j++;
        j--;
        Item alreadyUsedSpace = PQ_get_item(pq, j); //Stores amount of used space.
        alreadyUsedSpace+=fileSize[i]; //Recalculate partition size.
        PQ_set_item_value(pq, j, alreadyUsedSpace); //Resize used space and then fix his position at queue.
        j = 1; //Resets j index to 1. Note: J index is used to iterate over array of disks already created.
    }
    
    printf("%d \n", PQ_size(pq));
    PQ_finish(pq);
}

void decreasing_bestfit(Item* fileSize, int numberOfFiles){
//    qsort(fileSize, numberOfFiles, sizeof(int), cmpfunc); //Won't be necessary, because when this function is called, the array is already sorted.
   bestfit(fileSize, numberOfFiles);
}
