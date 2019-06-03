#include "main.h"


int main(void) {

	//setMEM(create);
	debugSRTmem();
	
	config.words = 16;
	config.bloco = 16;
	cache_t *cache;
	long cachesize;

	system("clear");

    printf(" SIMCACHE AOCII/TP1 -------------- [MEMORY %luB]\n", sizeof(memory));
	
	printf("\n QuickSort ---------------------------------------\n");

	cache = iniCache(config);
	debugPRTmem();
	//selection(cache);
	//quicksort(cache,0,memSize-1);
	bubbleSrt(cache);
	debugPRTmem();
	//prtCache(cache);

	freedooooom(cache);

	/* do {
		cache = iniCache(config);
		cachesize = sizeof(*cache->data)*config.words;
		printf(" %4luB %3d:%02d \u2192 ", cachesize, config.words, config.tamBloco);
		gettimeofday(&tv1,NULL);
		quicksort(cache,0,memSize);
		gettimeofday(&tv2,NULL);
		cacheHit(print);
		printf("\t(%fs)\n", ftempo(tv1,tv2));
		freedooooom(cache);


		if ( config.tamBloco < 32 && config.tamBloco < config.words)
			config.tamBloco *= 2;
		else {
			config.words *= 2;
			config.tamBloco = 1;
		}
		config.sets = config.words/config.tamBloco;
		setMEM(restore);

	} while ( config.words <= 512);

	exit(0);

	config.words = 16;
	config.tamBloco = 1;
	config.sets = config.words/config.tamBloco;

	printf("\n Selection ---------------------------------------\n");

	do {
		cache = iniCache(config);
		cachesize = sizeof(*cache->data)*config.sets;
		printf(" %4luB %3dL \u2192 ", cachesize, config.sets);
		gettimeofday(&tv1,NULL);
		selection(cache);
		gettimeofday(&tv2,NULL);
		cacheHit(print);
		printf(" (%fs)\n", ftempo(tv1,tv2));
		freedooooom(cache);
		config.sets *= 2;
		setMEM(restore);

	} while ( config.sets != 512);

	config.words = 16;
	config.tamBloco = 1;
	config.sets = config.words/config.tamBloco;

	printf("\n BubbleSort ---------------------------------------\n");

	do {
		cache = iniCache(config);
		cachesize = sizeof(*cache->data)*config.sets;
		printf(" %4luB %3dL \u2192 ", cachesize, config.sets);
		gettimeofday(&tv1,NULL);		
		bubbleSrt(cache);
		gettimeofday(&tv2,NULL);
		cacheHit(print);
		printf(" (%fs)\n", ftempo(tv1,tv2));
		freedooooom(cache);
		config.sets *= 2;
		setMEM(restore);

	} while ( config.sets != 512); */

	//All heap blocks were freed -- no leaks are possible
	return 0;
}