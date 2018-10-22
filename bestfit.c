// #include "bestfit.h"

// #define PARTITION_SIZE 1000000

// void bestfit(PQ* pq,Item fileSize){
//   int i = PQ_size(pq);
//     if(!PQ_empty(pq) && (fileSize + PQ_min(pq) <= PARTITION_SIZE)){ // Tests if queue isn't empty and if has avaible space to fit the current file.
//       Item alreadyUsedSpace = PQ_delmin(pq); // Stores the amount of used space.
//       alreadyUsedSpace+=fileSize; //Insert the file at the partition.
//       PQ_insert(pq, alreadyUsedSpace); // Recalculate where the partition should be.
//     }
//     else
//       PQ_insert(pq, fileSize); // Only if the current file doens't fit in none of the partitions already created.
// }

