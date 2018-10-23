#ifndef WORSTFIT_H
#define WORSTFIT_H

#include "PQ.h"

void worstfit(Item*,int); //Fits all files into partitions or creates another one.

void decreasing_worstfit(Item*,int); //Order and then fits all files into partitions or creates another one.

#endif //WORSTFIT_H