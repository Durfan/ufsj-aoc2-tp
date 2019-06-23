#include "./include/main.h"


int main(void) {

	setMEM(create);
	g_Config.words = 16;
	g_Config.bloco = 1;
	cache_t *Cache;
	long cachesize;

	system("clear");
	printf(" SIMCACHE AOCII/TP1 -------------- [MEMORY %luB]\n", sizeof(g_memory));
	printf(" Mapeamento Direto\n");
	
	printf("\n QuickSort ----------------------------------------\n");
	g_resultfile = "quicksort.dat";
	createFile();

	do {
		Cache = iniCache(g_Config);
		cachesize = sizeof(*Cache->data)*g_Config.words;
		printf(" %4luB %3d:%02d ", cachesize, g_Config.words, g_Config.bloco);
		
		isSorted();
		printf("\u2192");

		gettimeofday(&tv1,NULL);
		quicksort(Cache,0,MEMSIZE-1);
		gettimeofday(&tv2,NULL);
		isSorted();

		valida();

		cacheHit(print);
		freedooooom(Cache);
		setMEM(restore);
		iterConfig();
	} while ( configs() );

	printf("\n Selection ----------------------------------------\n");
	g_resultfile = "selection.dat";
	createFile();

	do {
		Cache = iniCache(g_Config);
		cachesize = sizeof(*Cache->data)*g_Config.words;
		printf(" %4luB %3d:%02d ", cachesize, g_Config.words, g_Config.bloco);

		isSorted();
		printf("\u2192");

		gettimeofday(&tv1,NULL);
		selection(Cache);
		gettimeofday(&tv2,NULL);
		isSorted();

		valida();
		
		cacheHit(print);
		freedooooom(Cache);
		setMEM(restore);
		iterConfig();
	} while ( configs() );

	printf("\n BubbleSort ---------------------------------------\n");
	g_resultfile = "bubblesort.dat";
	createFile();

	do {
		Cache = iniCache(g_Config);
		cachesize = sizeof(*Cache->data)*g_Config.words;
		printf(" %4luB %3d:%02d ", cachesize, g_Config.words, g_Config.bloco);

		isSorted();
		printf("\u2192");

		gettimeofday(&tv1,NULL);		
		bubbleSrt(Cache);
		gettimeofday(&tv2,NULL);
		isSorted();

		valida();

		cacheHit(print);
		freedooooom(Cache);
		setMEM(restore);
		iterConfig();
	} while ( configs() );

	setMEM(soma);

	printf("\n Soma Vetor ---------------------------------------\n");
	g_resultfile = "somavetor.dat";
	createFile();

	do {
		Cache = iniCache(g_Config);
		cachesize = sizeof(*Cache->data)*g_Config.words;
		printf(" %4luB %3d:%02d ", cachesize, g_Config.words, g_Config.bloco);

		validasoma();
		printf("\u2192");

		gettimeofday(&tv1,NULL);		
		somavetor(Cache);
		gettimeofday(&tv2,NULL);

		validasoma();

		cacheHit(print);
		freedooooom(Cache);
		setMEM(restore);
		iterConfig();
	} while ( configs() );

	return EXIT_SUCCESS;
}