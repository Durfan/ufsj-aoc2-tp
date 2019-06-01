#include "main.h"


int main(void) {

	struct timeval tv1, tv2;
	setMEM(create);
	
	config.words = 16;
	config.tamBloco = 1;
	config.sets = config.words/config.tamBloco;
	cache_t *cache;

	system("clear");

    printf(" SIMCACHE AOCII/TP1\n\n");
	printf(" Memory SIZE: %lu bytes\n", sizeof(memory));
	
	printf("\n QuickSort ---------------------------------------\n\n");

	do {
		cache = iniCache(config);

		printf(" %03d: \u2248 %04luB \u2192 ", config.sets,
				sizeof(*cache->bloco)*config.sets);

		gettimeofday(&tv1,NULL);
		quicksort(cache,0,memSize);
		gettimeofday(&tv2,NULL);
		cacheHit(print);
		printf(" (%fs)\n", ftempo(tv1,tv2));
		freedooooom(cache);
		config.sets *= 2;
		setMEM(restore);

	} while ( config.sets != 512);

	config.sets = 16;

	printf("\n Selection ---------------------------------------\n\n");

	do {
		cache = iniCache(config);

		printf(" %03d: \u2248 %04luB \u2192 ", config.sets,
				sizeof(*cache->bloco)*config.sets);

		gettimeofday(&tv1,NULL);
		selection(cache);
		gettimeofday(&tv2,NULL);
		cacheHit(print);
		printf(" (%fs)\n", ftempo(tv1,tv2));
		freedooooom(cache);
		config.sets *= 2;
		setMEM(restore);

	} while ( config.sets != 512);

	config.sets = 16;

	printf("\n BubbleSort ---------------------------------------\n\n");

	do {
		cache = iniCache(config);

		printf(" %03d: \u2248 %04luB \u2192 ", config.sets,
				sizeof(*cache->bloco)*config.sets);

		gettimeofday(&tv1,NULL);
		bubbleSrt(cache);
		gettimeofday(&tv2,NULL);
		cacheHit(print);
		printf(" (%fs)\n", ftempo(tv1,tv2));
		freedooooom(cache);
		config.sets *= 2;
		setMEM(restore);

	} while ( config.sets != 512);

	//All heap blocks were freed -- no leaks are possible
	return 0;
}