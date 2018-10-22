#include <stdio.h>
#include "PQ.h"
#include "worstfit.h"

PQ* file_read(char const *filename, int* numberOfFiles);

int main(int argc, char const *argv[])
{
  int *numberOfFiles;
  PQ* pq = file_read(argv[1], numberOfFiles);
  PQ_print(pq);
  printf("Quantidade de discos: %d\n", PQ_size(pq));
  return 0;
}

PQ* file_read(char const *filename, int* numberOfFiles){
  FILE* fp = fopen(filename, "r");
  fscanf(fp,"%d", numberOfFiles);
  PQ *pq = PQ_init(*numberOfFiles);
  int fileSize;
  while((fscanf(fp, "%d", &fileSize))!= EOF){
    // printf("%d\n", fileSize);
    worstfit(pq, fileSize);
  }
  return pq;
}