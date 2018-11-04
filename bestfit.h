#ifndef BESTFIT_H
#define BESTFIT_H

#include "PQ.h"

void bestfit(Item* fileSize, int numberOfFiles); //Fits a file into a partition or creates another one.

void decreasing_bestfit(Item* fileSize, int numberOfFiles); //Order and then fits all files into the best partitions or creates another one if needed.

#endif //BESTFIT_H