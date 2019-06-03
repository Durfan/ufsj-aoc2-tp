#include "main.h"


cache_t *iniCache() {
	config.sets = config.words/config.bloco;
    cache_t *cache = malloc(config.sets*sizeof(cache_t));
    assert(cache);

    for (int i=0; i<config.sets; i++) {
		cache[i].val  = false;
		cache[i].tag  = -1;
		cache[i].data = malloc(config.bloco*sizeof(int));
		assert(cache[i].data);
    }

    return cache;
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
			printf("HIT [%.2f] %d",  hitrate, Hit);
			printf("\tMISS [%.2f] %d", missrate, Miss);
			Hit  = 0;
			Miss = 0;
		break;
		default:
			assert(opt >= 0 && opt <= 2);
		break;
	}
}

int rdyCache(cache_t *cache, int addr) {
	int tag = addr / config.words;
	int map = addr % config.words;
	int idx = map / config.bloco;
	int oST = map % config.bloco;

	if ( cache[idx].val && tag == cache[idx].tag ) {
		cacheHit(hit);
		return cache[idx].data[oST];
	}

	addr = addr >> 4;
	addr = addr << 4;

	cacheHit(miss);
	cache[idx].val = true;
	cache[idx].tag = tag;
	memcpy(cache[idx].data,&memory[addr],config.bloco*sizeof(int));

	return cache[idx].data[oST];
}

void wrtCache(cache_t *cache, int addr, int value) {
	int tag = addr / config.words;
	int map = addr % config.words;
	int idx = map / config.bloco;
	int oST = map % config.bloco;

	cache[idx].tag = tag;
	cache[idx].data[oST] = value;
	memory[addr] = value;
}

void prtCache(cache_t *cache) {
	system("clear");
	for (int i=0; i<config.sets; i++) {
		printf(" %02X \u2192 %d %04d [", i, cache[i].val, cache[i].tag);
		for (int j=0; j<config.bloco; j++) {
			printf(" %06X", cache[i].data[j]);
		}
		printf(" ]\n");
	}
}

void freedooooom(cache_t *cache) {
	for (int i=0; i<config.sets; i++) {
        free(cache[i].data);
	}
	free(cache);
}