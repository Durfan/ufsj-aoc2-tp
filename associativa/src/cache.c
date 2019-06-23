#include "./include/main.h"


cache_t *iniCache() {
	g_Config.sets = g_Config.words/g_Config.bloco;
	g_Config.log2bl = crapLog2foo(g_Config.bloco);
	cache_t *Cache = malloc(g_Config.sets*sizeof(cache_t));
	assert(Cache);

	for (int i=0; i<g_Config.sets; i++) {
		Cache[i].vBit = false;
		Cache[i].tag  = -1;
		Cache[i].lru  = 0;
		Cache[i].lfu  = 0;
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
			printf(" %7.4fs \u258F", ftempo(tv1,tv2));
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

int rndSubst() {
	return rand() % 2;
}

int rdyCache(cache_t *Cache, int addr) {
	static int ciclo;
	bool inCache = false;
	int oST = addr % g_Config.bloco;
    int cjt = (addr >> g_Config.log2bl) % g_Config.vias;
	int tag = (addr >> g_Config.log2bl) / g_Config.vias;
	int data, rand, maxlfu, datasub;

	int start = cjt*(g_Config.sets/g_Config.vias);
	int end = start+(g_Config.sets/g_Config.vias)-1;

	for (int i=start; i<end; i++) {
		if ( Cache[i].vBit && tag == Cache[i].tag ) {
			cacheHit(acerto);
			inCache = true;
			Cache[i].lru = 0;
			Cache[i].lfu = 0;
			data = Cache[i].data[oST];
		}
		else {
			Cache[i].lru = 1;
			if ( ciclo < 10 )
				Cache[i].lfu++;
			else
				Cache[i].lfu = 0;
		}
	}

	if ( !inCache ) {
		cacheHit(erro);
		addr = addr >> g_Config.log2bl;
		addr = addr << g_Config.log2bl;

		switch (g_Config.politica) {
			case lru:
				for (int i=start; i<end; i++) {
					rand = rndSubst();
					if ( rand && Cache[i].lru ) {
						Cache[i].vBit = true;
						Cache[i].tag = tag;
						Cache[i].lru = 0;
						memcpy(Cache[i].data,&g_memory[addr],g_Config.bloco*sizeof(int));
						data = Cache[i].data[oST];
						break;
					}
				}
				if ( !rand ) {
					Cache[start].vBit = true;
					Cache[start].tag = tag;
					Cache[start].lru = 0;
					memcpy(Cache[start].data,&g_memory[addr],g_Config.bloco*sizeof(int));
					data = Cache[start].data[oST];
				}
				break;
			case lfu:
				maxlfu = Cache[start].lfu;
				for (int i=start; i<end; i++) {
					if ( Cache[i].lfu >= maxlfu ) {
						maxlfu = Cache[i].lfu;
						datasub = i;
					}
				}
				Cache[datasub].vBit = true;
				Cache[datasub].tag = tag;
				Cache[datasub].lfu = 0;
				memcpy(Cache[datasub].data,&g_memory[addr],g_Config.bloco*sizeof(int));
				data = Cache[datasub].data[oST];
				break;
			case fifo:
				while ( end > start ) {
					Cache[end].vBit = Cache[end-1].vBit;
					Cache[end].tag  = Cache[end-1].tag;
					memcpy(Cache[end].data,Cache[end-1].data,g_Config.bloco*sizeof(int));
					end--;
				}
				Cache[start].vBit = true;
				Cache[start].tag = tag;
				memcpy(Cache[start].data,&g_memory[addr],g_Config.bloco*sizeof(int));
				data = Cache[start].data[oST];
				break; 
		}
	}

	if ( ciclo < 10 ) ciclo++;
	else ciclo = 0;

	return data;
}

void wrtCache(cache_t *Cache, int addr, int value) {
	bool inCache = false;
	int oST = addr % g_Config.bloco;
    int cjt = (addr >> g_Config.log2bl) % g_Config.vias;
	int tag = (addr >> g_Config.log2bl) / g_Config.vias;

	int start = cjt*(g_Config.sets/g_Config.vias);
	int end = start+(g_Config.sets/g_Config.vias)-1;

	for (int i=start; i<end; i++) {
		if ( tag == Cache[i].tag ) {
			inCache = true;
			Cache[i].data[oST] = value;
			g_memory[addr] = value;
			break;
		}
	}

	if ( !inCache ) {
		rdyCache(Cache,addr);
		wrtCache(Cache,addr,value);
	}

	//assert(inCache);
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