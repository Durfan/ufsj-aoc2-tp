#ifndef CACHE_H
#define CACHE_H

cache_t *iniCache();
void cacheHit(opcao_t opt);
void rstCache(cache_t *cache);
int  getCache(cache_t *cache, int memAddr);
void setCache(cache_t *cache, int memAddr, int value);
void prtCache(cache_t *cache);

void freedooooom(cache_t *cache);

#endif //CACHE_H