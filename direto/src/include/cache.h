#ifndef CACHE_H
#define CACHE_H

cache_t *iniCache();
void cacheHit(opcao_t opt);
int  rdyCache(cache_t *cache, int addr);
void wrtCache(cache_t *cache, int addr, int value);
void prtCache(cache_t *cache);

void freedooooom(cache_t *cache);

#endif //CACHE_H