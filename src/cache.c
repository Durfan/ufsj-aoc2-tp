#include "main.h"


cache_t *iniCache(config_t config) {
    cache_t *cache = malloc(config.linhas*sizeof(cache_t));
    assert(cache);

    for (int i=0; i<config.linhas; i++) {
		cache[i].validade = false;
		cache[i].bloco = malloc(config.tamBloco*sizeof(int));
		cache[i].tag   = malloc(config.tamBloco*sizeof(int));
		assert(cache[i].bloco);
		assert(cache[i].tag);
    }

    return cache;
}

void cacheHit(count_t count) {
	static unsigned Hit, Miss;

	switch (count) {
		case miss:
			Miss++;
			break;
		case hit:
			Hit++;
			break;
		case print:
			printf(" Cache HIT  = %d\n", Hit);
			printf(" Cache MISS = %d\n", Miss);
			break;
		case reset:
			Hit  = 0;
			Miss = 0;
			break;
		default:
			assert(count >= 0 && count <= 2);
			break;
	}
}

int getCache(cache_t *cache, config_t config, int memAddr) {
	unsigned cacheAddr = memAddr % config.linhas;
	int cacheTag  = memAddr / config.linhas;
	bool valido = cache[cacheAddr].validade;

	if ( valido && cache[cacheAddr].tag[0] == cacheTag ) {
		cacheHit(hit);
		return cache[cacheAddr].bloco[0];
	}
	else {
		cacheHit(miss);
		cache[cacheAddr].validade = true;
		cache[cacheAddr].tag[0] = cacheTag;
		cache[cacheAddr].bloco[0] = memory[memAddr];
		return cache[cacheAddr].bloco[0];
	}

	return -1;
}

void setCache(cache_t *cache, config_t config, int memAddr, int value) {
	unsigned cacheAddr = memAddr % config.linhas;
	int cacheTag  = memAddr / config.linhas;
	cache[cacheAddr].validade = true;
	cache[cacheAddr].tag[0] = cacheTag;
	cache[cacheAddr].bloco[0] = value;
	memory[memAddr] = value;
}

void prtCache(cache_t *cache, config_t config) {
	for (int i=0; i<config.linhas; i++) {
        printf(" %02X \u2192 %03d %06X\n", i, cache[i].tag[0], cache[i].bloco[0]);
	}
}

void freedooooom(cache_t *cache, config_t config) {
	for (int i=0; i<config.linhas; i++) {
		free(cache[i].tag);
        free(cache[i].bloco);
	}
	free(cache);
}