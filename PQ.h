#ifndef PQ_H
#define PQ_H

#include <stdbool.h>
#include "item.h"

// Argument is maximum expected number of items.
void PQ_init(int);    // Creates an empty priority queue.

void PQ_insert(Item); // Inserts an item in the priority queue.

// Removes and returns the largest item.
Item PQ_delmax();   // Dual op delmin also possible.

Item PQ_max();      // Returns the largest item. Dual: min.

bool PQ_empty();    // Tests if the queue is empty.
int  PQ_size();     // Number of entries in the priority queue.

void PQ_finish();   // Cleans up the queue.

void PQ_print();

#endif
