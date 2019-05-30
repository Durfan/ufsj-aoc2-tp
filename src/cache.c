#include "main.h"


void cacheSim(cache_t *cache, int linhas, int memAddr) {
	unsigned cacheAddr = memAddr % linhas;
	cache[cacheAddr].tag = memAddr/linhas;
	cache[cacheAddr].linha[1] = memory[memAddr];
}

void initCache(cache_t *cache, int linhas) {
	for ( int i=0; i<linhas; i++ ) {
		cache[i].validade = false;
		cache[i].tag = -1;
		cache[i].linha[1] = 0;
	}
}

void cacheHit(bool hit) {
	static unsigned cachehit;
	static unsigned cachemiss;
	if (hit) cachehit++;
	else cachemiss++;
	printf(" %d %d\n", cachehit, cachemiss);
}

int getCache(cache_t *cache, int linhas, int memAddr) {

	unsigned cacheAddr = memAddr % linhas;
	int cacheTag  = memAddr / linhas;
	bool valido = cache[cacheAddr].validade;

	if ( valido && cache[cacheAddr].tag == cacheTag ) {
		cacheHit(true);
		return cache[cacheAddr].linha[0];
	}
	else {
		cacheHit(false);
		cache[cacheAddr].validade = true;
		cache[cacheAddr].tag = cacheTag;
		cache[cacheAddr].linha[0] = memory[memAddr];
		return cache[cacheAddr].linha[0];
	}

	return -1;
}

void setCache(cache_t *cache, int linhas, int memAddr, int value) {
	unsigned cacheAddr = memAddr % linhas;
	int cacheTag  = memAddr / linhas;
	cache[cacheAddr].validade = true;
	cache[cacheAddr].tag = cacheTag;
	cache[cacheAddr].linha[0] = value;
	memory[memAddr] = value;
}

void prtCache(cache_t *cache, int linhas) {
	for (int i=0; i<linhas; i++) {
        printf(" %02X \u2192 %03d %06X\n", i, cache[i].tag, cache[i].linha[0]);
	}
}