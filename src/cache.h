#ifndef SIMCACHE_CACHE_H
#define SIMCACHE_CACHE_H

typedef struct cache {
    bool validade;
    int tag;
    int linha[1];
} cache_t;

void cacheSim(cache_t *cache, int linhas, int memAddr);
void cacheHit(bool hit);
void setCache(cache_t *cache, int linhas, int memAddr, int value);
void initCache(cache_t *cache, int linhas);
int getCache(cache_t *cache, int linhas, int memAddr);
void prtCache(cache_t *cache, int linhas);

#endif //SIMCACHE_CACHE_H