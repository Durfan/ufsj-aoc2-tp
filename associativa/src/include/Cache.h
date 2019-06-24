#ifndef CACHE_H
#define CACHE_H

cache_t *iniCache();
void cacheHit(opcao_t opt);
int  rndSubst();
int  polSubst(cache_t *Cache, int addr);
int  rdyCache(cache_t *Cache, int addr);
void wrtCache(cache_t *Cache, int addr, int value);
void prtCache(cache_t *Cache);

void freedooooom(cache_t *Cache);

#endif //CACHE_H