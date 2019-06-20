#include "./include/main.h"


int main(void) {

	//setMEM(create);
	debugSRTmem();
	g_Config.words = 16;
	g_Config.bloco = 1;
	g_Config.vias  = 8;
	g_Config.politica = lru;
	cache_t *Cache;
	long cachesize;

	system("clear");
	printf(" SIMCACHE AOCII/TP1 -------------- [MEMORY %luB]\n", sizeof(g_memory));
	printf(" Associativa\n");

	Cache = iniCache(g_Config);
	cachesize = sizeof(*Cache->data)*g_Config.words;
	printf(" %4luB %3d:%02d \n\n", cachesize, g_Config.words, g_Config.bloco);

	debugPRTmem();
	quicksort(Cache,0,MEMSIZE-1);
	debugPRTmem();

	freedooooom(Cache);

	return 0;
}