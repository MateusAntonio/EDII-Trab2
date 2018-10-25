#include "worstfit.h"
#include <stdlib.h>
#include <stdio.h>

#define PARTITION_SIZE 1000000
#define free_space(A) {PARTITION_SIZE - A;}

void worstfit(Item* fileSize, int numberOfFiles){
  PQ* pq = PQ_init(numberOfFiles);
    PQ_insert(pq, 0); // Starts the first partition with 0KB used, just to avoid size check.
  // for(int i = 0; i < numberOfFiles; i++)
    // printf("%d \n", fileSize[i]);

  for(int i = 0; i < numberOfFiles; i++){
    if((fileSize[i] + PQ_min(pq) <= PARTITION_SIZE)){ // Tests if has avaible space to fit the current file.
      Item alreadyUsedSpace = PQ_delmin(pq); // Stores the amount of used space.
      alreadyUsedSpace+=fileSize[i]; //Insert the file at the partition.
      PQ_insert(pq, alreadyUsedSpace); // Recalculate where the partition should be.
    }
    else
      PQ_insert(pq, fileSize[i]); // Only if the current file doens't fit in none of the partitions already created.
  }
  // PQ_print(pq);
  printf("%d \n", PQ_size(pq));
  PQ_finish(pq);
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

void decreasing_worstfit(Item* fileSize, int numberOfFiles){
   qsort(fileSize, numberOfFiles, sizeof(int), cmpfunc);
   worstfit(fileSize, numberOfFiles);
}

