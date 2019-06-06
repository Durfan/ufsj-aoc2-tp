#include "./include/main.h"


int main(void) {

	setMEM(create);
	config.words = 16;
	config.bloco = 1;
	cache_t *cache;
	long cachesize;

	system("clear");
    printf(" SIMCACHE AOCII/TP1 -------------- [MEMORY %luB]\n", sizeof(memory));
	
	printf("\n QuickSort ---------------------------------------\n");
	resultfile = "quicksort.dat";
	createFile();

	do {
		cache = iniCache(config);
		cachesize = sizeof(*cache->data)*config.words;
		printf(" %4luB %3d:%02d ", cachesize, config.words, config.bloco);
		
		isSorted();
		printf("\u2192");

		gettimeofday(&tv1,NULL);
		quicksort(cache,0,memSize-1);
		gettimeofday(&tv2,NULL);
		isSorted();

		valida();

		cacheHit(print);
		freedooooom(cache);
		iterConfig();
	} while ( configs() );

	printf("\n Selection ---------------------------------------\n");
	resultfile = "selection.dat";
	createFile();

	do {
		cache = iniCache(config);
		cachesize = sizeof(*cache->data)*config.words;
		printf(" %4luB %3d:%02d ", cachesize, config.words, config.bloco);

		isSorted();
		printf("\u2192");

		gettimeofday(&tv1,NULL);
		selection(cache);
		gettimeofday(&tv2,NULL);
		isSorted();

		valida();
		
		cacheHit(print);
		freedooooom(cache);
		iterConfig();
	} while ( configs() );

	printf("\n BubbleSort ---------------------------------------\n");
	resultfile = "bubblesort.dat";
	createFile();

	do {
		cache = iniCache(config);
		cachesize = sizeof(*cache->data)*config.words;
		printf(" %4luB %3d:%02d ", cachesize, config.words, config.bloco);

		isSorted();
		printf("\u2192");

		gettimeofday(&tv1,NULL);		
		bubbleSrt(cache);
		gettimeofday(&tv2,NULL);
		isSorted();

		valida();

		cacheHit(print);
		freedooooom(cache);
		iterConfig();
	} while ( configs() );

	return 0;
}