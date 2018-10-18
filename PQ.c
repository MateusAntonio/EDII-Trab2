#include <stdio.h>
#include <stdlib.h>
#include "PQ.h"

static Item *pq;
static int N;

void fix_up(Item *a, int k) { // swim up
    while (k > 1 && less(a[k/2], a[k])) {
        exch(a[k], a[k/2]);
        k = k/2;
    }
}

void fix_down(Item *a, int sz, int k){
  while (2*k <= sz) {
    int j = 2*k;
    if (j < sz && less(a[j], a[j+1])){
      j++;
    }
    if (!less(a[k], a[j])) {
      break;
    }
    exch(a[k], a[j]);
    k = j;
  }
}

void PQ_init(int maxN) {
    pq = malloc((maxN+1) * sizeof(Item));
    N = 0;
}

void PQ_insert(Item v) {
    N++;
    pq[N] = v;
    fix_up(pq, N);
}

Item PQ_delmax() {
    Item max = pq[1];
    exch(pq[1], pq[N]);
    N--;
    fix_down(pq, N, 1);
    return max;
}

//TODO PQ_delmax(){

//}

Item PQ_max() {
    return pq[1];
}

bool PQ_empty() {
    return N == 0;
}

int  PQ_size() {
    return N;
}

void PQ_finish() {
    free(pq);
}

void PQ_print() {
    printf("HEAP (%d): ", N);
    for (int i = 1; i <= N; i++) {
        printf("%d ", pq[i]);
    }
    printf("\n");
}
