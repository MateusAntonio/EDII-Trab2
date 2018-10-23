#include "worstfit.h"
#include <stdlib.h>
#include <stdio.h>

#define PARTITION_SIZE 1000000

void worstfit(PQ* pq,Item* fileSize, int numberOfFiles){
  if(PQ_empty(pq))
  // for(int i = 0; i < numberOfFiles; i++)
  //   printf("%d \n", fileSize[i]);

    PQ_insert(pq, fileSize[0]); // Used here to avoid unnecessary size checks.
  for(int i = 1; i < numberOfFiles; i++){
    if((fileSize[i] + PQ_min(pq) <= PARTITION_SIZE)){ // Tests if queue isn't empty and if has avaible space to fit the current file.
      Item alreadyUsedSpace = PQ_delmin(pq); // Stores the amount of used space.
      alreadyUsedSpace+=fileSize[i]; //Insert the file at the partition.
      PQ_insert(pq, alreadyUsedSpace); // Recalculate where the partition should be.
    }
    else
      PQ_insert(pq, fileSize[i]); // Only if the current file doens't fit in none of the partitions already created.
  }
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

void decreasing_worstfit(PQ* pq, Item* fileSize, int numberOfFiles){
   qsort(fileSize, numberOfFiles, sizeof(Item), cmpfunc);
   printf("\n");
  //  for(int i = 0; i < numberOfFiles; i++)
  //   printf("%d \n", fileSize[i]);
   worstfit(pq, fileSize, numberOfFiles);
}

