#include <stdio.h>
#include <stdlib.h>
#include "PQ.h"
#include "worstfit.h"
#include "bestfit.h"

void file_read(char const *filename);

int main(int argc, char const *argv[])
{
  file_read(argv[1]);
  return 0;
}

void file_read(char const *filename){
  FILE* fp = fopen(filename, "r");
  int numberOfFiles;
  fscanf(fp,"%d", &numberOfFiles);
  int* fileSize = malloc (numberOfFiles * sizeof(int));

  for(int i = 0; i < numberOfFiles; i++)
    fscanf(fp, "%d", &fileSize[i]);
  
  fclose(fp);
  
  worstfit(fileSize, numberOfFiles);

  decreasing_worstfit(fileSize, numberOfFiles);

  // bestfit(fileSize, numberOfFiles);

  free(fileSize);
}