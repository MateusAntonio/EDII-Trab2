#include <stdio.h>
#include <stdlib.h>
#include "PQ.h"

struct pq {
    Item* usedSpace;
    int size;
};

void fix_up(PQ* pq, int k) { // swim up
    while (k > 1 && greater(pq->usedSpace[k/2], pq->usedSpace[k])) {
        exch(pq->usedSpace[k], pq->usedSpace[k/2]);
        k = k/2;
    }
}

void fix_down(PQ* pq, int k){
    int sz = pq->size;
  while (2*k <= sz) {
    int j = 2*k;
    if (j < sz && greater(pq->usedSpace[j], pq->usedSpace[j+1])){
      j++;
    }
    if (!greater(pq->usedSpace[k], pq->usedSpace[j])) {
      break;
    }
    exch(pq->usedSpace[k], pq->usedSpace[j]);
    k = j;
  }
}

PQ* PQ_init(int maxN) {
    PQ *pq = malloc(sizeof(PQ));
    pq->usedSpace = malloc((maxN+1) * sizeof(Item));
    pq->size = 0;
    return pq;
}

void PQ_insert(PQ* pq, Item v) {
    pq->size++;
    pq->usedSpace[pq->size] = v;
    fix_up(pq, pq->size);
}

Item PQ_delmin(PQ* pq){
    Item min = pq->usedSpace[1];
    exch(pq->usedSpace[1], pq->usedSpace[pq->size]);
    pq->size--;
    fix_down(pq, 1);
    return min;
}

Item PQ_min(PQ* pq){
    return pq->usedSpace[1];
}

void PQ_set_item_value(PQ* pq, int index, Item item){
    pq->usedSpace[index] = item;
    fix_up(pq, index);
    fix_down(pq, index);
}

bool PQ_empty(PQ* pq) {
    return pq->size == 0;
}

int  PQ_size(PQ* pq) {
    return pq->size;
}

void PQ_finish(PQ* pq) {
    free(pq->usedSpace);
    free(pq);
}

void PQ_print(PQ* pq) {
    printf("HEAP (%d): ", pq->size);
    for (int i = 1; i <= pq->size; i++) {
        printf("%d ", pq->usedSpace[i]);
    }
    printf("\n");
}
