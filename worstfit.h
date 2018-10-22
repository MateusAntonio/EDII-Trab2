#ifndef WORSTFIT_H
#define WORSTFIT_H

#include "PQ.h"

void worstfit(PQ* pq,Item* fileSize, int numberOfFiles); //Fits a file into a partition or creates another one.

#endif //WORSTFIT_H