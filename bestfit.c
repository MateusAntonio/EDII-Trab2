#include "bestfit.h"
#include "PQ.h"

#define PARTITION_SIZE 1000000

void bestfit(Item* fileSize, int numberOfFiles){
    PQ* pq = PQ_init(numberOfFiles);
    PQ_insert(pq,0);  // Starts the first partition with 0KB used, just to avoid size check.
}
