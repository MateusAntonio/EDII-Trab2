#include "bestfit.h"
#include "PQ.h"
#include <stdio.h>
#include <stdlib.h>

#define PARTITION_SIZE 1000000

void bestfit(Item* fileSize, int numberOfFiles){
    PQ* pq = PQ_init(numberOfFiles);
    PQ_insert(pq,0);  // Starts the first partition with 0KB used, just to avoid size check.

    for(int i = 0, j = 1; i < numberOfFiles; i++){
        if(!(PQ_get_item(pq, j) + fileSize[i] <= PARTITION_SIZE)){
            PQ_insert(pq, fileSize[i]);
            continue;
        }
        while(j <= PQ_size(pq) && PQ_get_item(pq, j) + fileSize[i] <= PARTITION_SIZE) // iterates up until finds the first
            j++;
        j--;
        Item alreadyUsedSpace = PQ_get_item(pq, j);
        alreadyUsedSpace+=fileSize[i];
        PQ_set_item_value(pq, j, alreadyUsedSpace);
        j = 1;
    }
    
    printf("%d \n", PQ_size(pq));
    PQ_finish(pq);
}

void decreasing_bestfit(Item* fileSize, int numberOfFiles){
   qsort(fileSize, numberOfFiles, sizeof(int), cmpfunc);
   printf("decreasing bestfit: ");
   bestfit(fileSize, numberOfFiles);
}
