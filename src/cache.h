#ifndef CACHE_H
#define CACHE_H

cache_t *iniCache(config_t config);
void cacheHit(count_t count);
int  getCache(cache_t *cache, config_t config, int memAddr);
void setCache(cache_t *cache, config_t config, int memAddr, int value);
void prtCache(cache_t *cache, config_t config);

void freedooooom(cache_t *cache, config_t config);

#endif //CACHE_H