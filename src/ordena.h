#ifndef ORDENA_H
#define ORDENA_H

int  partition(cache_t *cache, config_t config, int start, int end);
void quicksort(cache_t *cache, config_t config, int start, int end);
void selection(cache_t *cache, config_t config);
void bubbleSrt(cache_t *cache, config_t config);

#endif //ORDENA_H