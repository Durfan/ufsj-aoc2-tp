#ifndef SIMCACHE_ORDENA_H
#define SIMCACHE_ORDENA_H

void qks_swap(int *p, int *q);
int  partition(int *vetor, int start, int end);
void quicksort(int *vetor, int start, int end);
void selection(int *vetor, int end);
void bubbleSrt(int *vetor, int end);

#endif //SIMCACHE_ORDENA_H