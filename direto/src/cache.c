#include "./include/main.h"


cache_t *iniCache() {
	g_Config.sets = g_Config.words/g_Config.bloco;
	g_Config.log2bl = crapLog2foo(g_Config.bloco);
	cache_t *Cache = malloc(g_Config.sets*sizeof(cache_t));
	assert(Cache);

	for (int i=0; i<g_Config.sets; i++) {
		Cache[i].vBit  = false;
		Cache[i].dBit  = false;
		Cache[i].tag  = -1;
		Cache[i].data = malloc(g_Config.bloco*sizeof(int));
		assert(Cache[i].data);
	}

	return Cache;
}

void cacheHit(opcao_t opt) {
	static unsigned hit, miss;
	float hitrate, missrate;

	switch (opt) {
		case erro:
			miss++;
			break;
		case acerto:
			hit++;
			break;
		case print:
			hitrate  = ((float)hit/((float)miss+(float)hit))*100;
			missrate = 100 - hitrate;
			printf(" %.4fs \u258F", ftempo(tv1,tv2));
			printf("HIT [%6.2f] %8d \u258F", hitrate, hit);
			printf("MISS [%6.2f] %8d \u258F\n", missrate, miss);
			saveResult(hitrate,missrate);
			hit  = 0;
			miss = 0;
			break;
		default:
			exit(EXIT_FAILURE);
	}
}

int rdyCache(cache_t *Cache, int addr) {
	int tag = addr / g_Config.words;
	int map = addr % g_Config.words;
	int idx = map / g_Config.bloco;
	int oST = map % g_Config.bloco;

	if ( Cache[idx].vBit && tag == Cache[idx].tag ) {
		cacheHit(acerto);
		return Cache[idx].data[oST];
	}

	addr = addr >> g_Config.log2bl;
	addr = addr << g_Config.log2bl;

	cacheHit(erro);
	Cache[idx].vBit = true;
	Cache[idx].tag = tag;
	memcpy(Cache[idx].data,&g_memory[addr],g_Config.bloco*sizeof(int));

	return Cache[idx].data[oST];
}

void wrtCache(cache_t *Cache, int addr, int value) {
	int tag = addr / g_Config.words;
	int map = addr % g_Config.words;
	int idx = map / g_Config.bloco;
	int oST = map % g_Config.bloco;

	Cache[idx].tag = tag;
	Cache[idx].data[oST] = value;
	g_memory[addr] = value;
}

void prtCache(cache_t *Cache) {
	system("clear");
	for (int i=0; i<g_Config.sets; i++) {
		printf(" %02X \u2192 %d %04d [", i, Cache[i].vBit, Cache[i].tag);
		for (int j=0; j<g_Config.bloco; j++) {
			printf(" %06X", Cache[i].data[j]);
		}
		printf(" ]\n");
	}
}

void freedooooom(cache_t *Cache) {
	for (int i=0; i<g_Config.sets; i++) {
		free(Cache[i].data);
	}
	free(Cache);
}