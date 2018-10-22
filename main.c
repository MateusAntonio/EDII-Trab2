#include <stdio.h>
#include "PQ.h"
#include "worstfit.h"

PQ* file_read(char const *filename);

int main(int argc, char const *argv[])
{
  PQ* pq = file_read(argv[1]);
  PQ_print(pq);
  printf("Quantidade de discos: %d\n", PQ_size(pq));
  PQ_finish(pq);
  return 0;
}

PQ* file_read(char const *filename){
  FILE* fp = fopen(filename, "r");
  int numberOfFiles;
  fscanf(fp,"%d", &numberOfFiles);
  PQ *pq = PQ_init(numberOfFiles);
  int fileSize[numberOfFiles];

  for(int i = 0; i < numberOfFiles; i++)
    fscanf(fp, "%d", &fileSize[i]);
  
  fclose(fp);
  
  worstfit(pq, fileSize, numberOfFiles);
  return pq;
}