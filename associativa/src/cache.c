#include "./include/main.h"


cache_t *iniCache() {
	g_Config.sets = g_Config.words/g_Config.bloco;
	g_Config.log2bl = crapLog2foo(g_Config.bloco);
	cache_t *Cache = malloc(g_Config.sets*sizeof(cache_t));
	assert(Cache);

	for (int i=0; i<g_Config.sets; i++) {
		Cache[i].tag  = -1;
		Cache[i].lru  = 0;
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
			exit(1);
		break;
	}
}

int rdyCache(cache_t *Cache, int addr) {
	int tag = addr / g_Config.vias;
	int cjt = addr % g_Config.vias;
	int oST = tag % g_Config.bloco;
	bool inCache = false;
	int maxLRU = 0;
	int dataSB;
	int data;

	int start = cjt*(g_Config.words/g_Config.vias);
	int end = start+(g_Config.words/g_Config.vias);

	for (int i=start; i<end; i++) {
		if ( tag == Cache[i].tag ) {
			cacheHit(acerto);
			inCache = true;
			Cache[i].lru = 0;
			data = Cache[i].data[oST];
		}
		else {
			Cache[i].lru++;
		}
		if (Cache[i].lru > maxLRU) {
			maxLRU = Cache[i].lru;
			dataSB = i;
		}
	}

	if (inCache)
		return data;

	cacheHit(erro);
	addr = addr >> g_Config.log2bl;
	addr = addr << g_Config.log2bl;

	switch (g_Config.politica) {
		case lru:
			Cache[dataSB].tag = tag;
			memcpy(Cache[dataSB].data,&g_memory[addr],g_Config.bloco*sizeof(int));
			return Cache[dataSB].data[oST];
		case lfu:
			break;
		case fifo:
			break;
		default:
			exit(1);
	}
	
}

void wrtCache(cache_t *Cache, int addr, int value) {
	int tag = addr / g_Config.vias;
	int cjt = addr % g_Config.vias;
	int oST = tag % g_Config.bloco;

	Cache[cjt*g_Config.vias].tag = tag;
	Cache[cjt*g_Config.vias].data[oST] = value;
	g_memory[addr] = value;
}

void prtCache(cache_t *Cache) {
	system("clear");
	for (int i=0; i<g_Config.words; i++) {
		printf(" %02X \u2192 %04d [", i, Cache[i].tag);
		for (int j=0; j<g_Config.bloco; j++) {
			printf(" %06X", Cache[i].data[j]);
		}
		printf(" ]\n");
	}
}

void freedooooom(cache_t *Cache) {
	for (int i=0; i<g_Config.words; i++) {
		free(Cache[i].data);
	}
	free(Cache);
}