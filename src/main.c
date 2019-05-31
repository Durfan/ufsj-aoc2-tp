#include "main.h"

bool isPowerTwo(int x) {
	return(x & (x-1));
}

double ftempo(struct timeval tv1, struct timeval tv2) {
    return (double)(tv2.tv_usec - tv1.tv_usec)/1000000 +
           (double)(tv2.tv_sec-tv1.tv_sec);
}

int main(void) {

	struct timeval tv1, tv2;
	setMEM(create);
	
	config_t config;
	config.words = 16;
	config.tamBloco = 1;
	config.linhas = config.words/config.tamBloco;
	cache_t *cache = iniCache(config);

	system("clear");

    printf(" SIMCACHE AOCII/TP1\n\n");
	printf(" Cache/Words: %d max\n", config.words);
	printf(" Words/Bloco: %d words/bloco\n", config.tamBloco);
	printf(" Cache/Linha: %d linhas\n", config.linhas);
	printf(" Memory SIZE: %lu bytes\n", sizeof(memory));
	printf("  Cache SIZE: %lu bytes\n", sizeof(*cache->bloco)*config.linhas);
	
	gettimeofday(&tv1,NULL);
	quicksort(cache,config,0,memSize);
	gettimeofday(&tv2,NULL);
	printf("\n QuickSort  (%fs)\n", ftempo(tv1,tv2));
	cacheHit(print);
	cacheHit(reset);
	
	setMEM(restore);
	gettimeofday(&tv1,NULL);
	selection(cache,config);
	gettimeofday(&tv2,NULL);
	printf("\n Selection  (%fs)\n", ftempo(tv1,tv2));
	cacheHit(print);
	cacheHit(reset);
	
	setMEM(restore);
	gettimeofday(&tv1,NULL);
	bubbleSrt(cache,config);
	gettimeofday(&tv2,NULL);
	printf("\n BubbleSort (%fs)\n", ftempo(tv1,tv2));
	cacheHit(print);

	freedooooom(cache,config);

	return 0;
}