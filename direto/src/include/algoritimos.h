#ifndef ORDENA_H
#define ORDENA_H

int  partition(cache_t *cache, int start, int end);
void quicksort(cache_t *cache, int start, int end);
void selection(cache_t *cache);
void bubbleSrt(cache_t *cache);
void somavetor(cache_t *cache);

// Valida QuickSort
void swap(int *p, int *q);
int  part(int *vetor, int start, int end);
void sort(int *vetor, int start, int end);

#endif //ORDENA_H