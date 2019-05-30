#ifndef SIMCACHE_ORDENA_H
#define SIMCACHE_ORDENA_H

void qks_swap(int *p, int *q);
int  partition(int *vetor, int start, int end);
void quicksort(int *vetor, int start, int end);
void selection(cache_t *cache, int *vetor);
void bubbleSrt(cache_t *cache);

#endif //SIMCACHE_ORDENA_H