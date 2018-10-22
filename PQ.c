#include <stdio.h>
#include <stdlib.h>
#include "PQ.h"

struct pq {
    Item* usedSpace;
    int size;
};

void fix_up(PQ* pq) { // swim up
    int k = pq->size;
    while (k > 1 && less(pq->usedSpace[k/2], pq->usedSpace[k])) {
        exch(pq->usedSpace[k], pq->usedSpace[k/2]);
        k = k/2;
    }
}

void fix_down(PQ* pq, int k){
    int sz = pq->size;
  while (2*k <= sz) {
    int j = 2*k;
    if (j < sz && less(pq->usedSpace[j], pq->usedSpace[j+1])){
      j++;
    }
    if (!less(pq->usedSpace[k], pq->usedSpace[j])) {
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
    fix_up(pq);
}

Item PQ_delmax(PQ* pq) {
    Item max = pq->usedSpace[1];
    exch(pq->usedSpace[1], pq->usedSpace[pq->size]);
    pq->size--;
    fix_down(pq, 1);
    return max;
}

Item PQ_delmin(PQ* pq){
    Item min = pq->usedSpace[pq->size--];
    return min;
}

Item PQ_max(PQ* pq) {
    return pq->usedSpace[1];
}

Item PQ_min(PQ* pq){
    return pq->usedSpace[pq->size];
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
