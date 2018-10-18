#include <stdio.h>
#include <stdlib.h>
#include "PQ.h"

struct pq {
    Item* files;
    int size;
};

void fix_up(PQ* pq) { // swim up
    int k = pq->size;
    while (k > 1 && less(pq->files[k/2], pq->files[k])) {
        exch(pq->files[k], pq->files[k/2]);
        k = k/2;
    }
}

void fix_down(PQ* pq, int k){
    int sz = pq->size;
  while (2*k <= sz) {
    int j = 2*k;
    if (j < sz && less(pq->files[j], pq->files[j+1])){
      j++;
    }
    if (!less(pq->files[k], pq->files[j])) {
      break;
    }
    exch(pq->files[k], pq->files[j]);
    k = j;
  }
}

PQ* PQ_init(int maxN) {
    PQ *pq = malloc(sizeof(PQ));
    pq->files = malloc((maxN+1) * sizeof(Item));
    pq->size = 0;
    return pq;
}

void PQ_insert(PQ* pq, Item v) {
    pq->size++;
    pq->files[pq->size] = v;
    fix_up(pq);
}

Item PQ_delmax(PQ* pq) {
    Item max = pq->files[1];
    exch(pq->files[1], pq->files[pq->size]);
    pq->size--;
    fix_down(pq, 1);
    return max;
}

Item PQ_delmin(PQ* pq){
    Item min = pq->files[pq->size--];
    return min;
}

Item PQ_max(PQ* pq) {
    return pq->files[1];
}

bool PQ_empty(PQ* pq) {
    return pq->size == 0;
}

int  PQ_size(PQ* pq) {
    return pq->size;
}

void PQ_finish(PQ* pq) {
    free(pq->files);
    free(pq);
}

void PQ_print(PQ* pq) {
    printf("HEAP (%d): ", pq->size);
    for (int i = 1; i <= pq->size; i++) {
        printf("%d ", pq->files[i]);
    }
    printf("\n");
}
