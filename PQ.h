#ifndef PQ_H
#define PQ_H

#include <stdbool.h>
#include "item.h"

typedef struct pq PQ;

// Argument is maximum expected number of items.
PQ* PQ_init(int);    // Creates an empty priority queue.

void PQ_insert(PQ*,Item); // Inserts an item in the priority queue.

// Removes and returns the largest item.
Item PQ_delmax(PQ*);   // Dual op delmin also possible.

Item PQ_delmin(PQ*);   // Removes and returns the smallest item.

Item PQ_max(PQ*);      // Returns the largest item. Dual: min.

bool PQ_empty(PQ*);    // Tests if the queue is empty.
int  PQ_size(PQ*);     // Number of entries in the priority queue.

void PQ_finish(PQ*);   // Cleans up the queue.

void PQ_print(PQ*);    // Print the queue.

#endif
