#include "bestfit.h"
#include "PQ.h"
#include <stdio.h>

#define PARTITION_SIZE 1000000

void bestfit(Item* fileSize, int numberOfFiles){
    PQ* pq = PQ_init(numberOfFiles);
    PQ_insert(pq,0);  // Starts the first partition with 0KB used, just to avoid size check.

    for(int i = 0, j = 1; i < numberOfFiles; i++){
        if(!(PQ_get_item(pq, j) + fileSize[i] <= PARTITION_SIZE)){
            PQ_insert(pq, fileSize[i]);            
            continue;
        }
        while(PQ_get_item(pq, j) + fileSize[i] <= PARTITION_SIZE) // itarates up 
            j++;
        j--;
        Item alreadyUsedSpace = PQ_get_item(pq, j);
        alreadyUsedSpace+=fileSize[i];
        PQ_set_item_value(pq, j, alreadyUsedSpace);
    }
    
    printf("%d \n", PQ_size(pq));
    PQ_finish(pq);
}
