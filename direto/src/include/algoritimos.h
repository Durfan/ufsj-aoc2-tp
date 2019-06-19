#ifndef ORDENA_H
#define ORDENA_H

int  partition(cache_t *Cache, int start, int end);
void quicksort(cache_t *Cache, int start, int end);
void selection(cache_t *Cache);
void bubbleSrt(cache_t *Cache);
void somavetor(cache_t *Cache);

// Valida QuickSort
void swap(int *p, int *q);
int  part(int *vetor, int start, int end);
void sort(int *vetor, int start, int end);

#endif //ORDENA_H