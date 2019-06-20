#include "./include/main.h"


int main(void) {

	setMEM(create);
	g_Config.words = 16;
	g_Config.bloco = 1;
	g_Config.bloco = 2;
	cache_t *Cache;
	long cachesize;

	system("clear");
	printf(" SIMCACHE AOCII/TP1 -------------- [MEMORY %luB]\n", sizeof(g_memory));
	printf(" Associativo\n");

	Cache = iniCache(g_Config);
	cachesize = sizeof(*Cache->data)*g_Config.words;
	printf(" %4luB %3d:%02d ", cachesize, g_Config.words, g_Config.bloco);


	freedooooom(Cache);

	return 0;
}