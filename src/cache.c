#include "main.h"


cache_t *iniCache() {
    cache_t *cache = malloc(config.sets*sizeof(cache_t));
    assert(cache);

    for (int i=0; i<config.sets; i++) {
		cache[i].validade = false;
		cache[i].bloco = malloc(config.tamBloco*sizeof(int));
		cache[i].tag   = malloc(config.tamBloco*sizeof(int));
		assert(cache[i].bloco);
		assert(cache[i].tag);
    }

    return cache;
}

void rstCache(cache_t *cache) {
	for (int i=0; i<config.sets; i++) {
        cache[i].validade = false;
	}
}

void cacheHit(opcao_t opt) {
	static unsigned Hit, Miss;
	float hitrate, missrate;

	switch (opt) {
		case miss:
			Miss++;
			break;
		case hit:
			Hit++;
			break;
		case print:
			hitrate  = ((float)Hit/((float)Miss+(float)Hit))*100;
			missrate = 100 - hitrate;
			printf("HIT: [%.2f] %d",  hitrate, Hit);
			printf("  MISS: [%.2f] %d", missrate, Miss);
			Hit  = 0;
			Miss = 0;
			break;
		default:
			assert(opt >= 0 && opt <= 2);
			break;
	}
}

int getCache(cache_t *cache, int memAddr) {
	int index = memAddr % config.sets;
	int tag   = memAddr / config.sets;
	bool valido = cache[index].validade;

	int offsetBloco = index % config.tamBloco;

	if ( valido && cache[index].tag[0] == tag ) {
		cacheHit(hit);
		return cache[index].bloco[offsetBloco];
	}
	else {
		cacheHit(miss);
		cache[index].validade = true;
		cache[index].tag[0] = tag;
		memcpy(cache[index].bloco,&memory[memAddr],sizeof(int)*config.tamBloco);
		return cache[index].bloco[offsetBloco];
	}

	return -1;
}

void setCache(cache_t *cache, int memAddr, int value) {
	unsigned index = memAddr % config.sets;
	int tag  = memAddr / config.sets;
	cache[index].validade = true;
	cache[index].tag[0] = tag;
	cache[index].bloco[0] = value;
	memory[memAddr] = value;
}

void prtCache(cache_t *cache) {
	for (int i=0; i<config.sets; i++) {
        printf(" %02X \u2192 %03d %06X\n", i, cache[i].tag[0], cache[i].bloco[0]);
	}
}

void freedooooom(cache_t *cache) {
	for (int i=0; i<config.sets; i++) {
		free(cache[i].tag);
        free(cache[i].bloco);
	}
	free(cache);
}