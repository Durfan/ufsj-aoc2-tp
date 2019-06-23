#include "./include/main.h"
#include <ctype.h>
#include <unistd.h>

static const struct {
	polSub_t val;
	const char *str;
} conversion [] = {
	{lru, "lru"},
	{lfu, "lfu"},
	{fifo, "fifo"},
};

polSub_t str2enum(const char *str) {
	for (int i=0; i<(int)(sizeof(conversion)/sizeof(conversion[0])); ++i)
		if ( !strcmp (str, conversion[i].str) )
			return conversion[i].val;
	printf(" Erro: Politica de substituicao, invalida.");
	exit(1);
}


int main(int argc, char *argv[]) {

	int parametro;
	opterr = 0;

	while ((parametro = getopt(argc, argv, "v:p:")) != -1) {
		switch (parametro) {
			case 'v':
				g_Config.vias = atoi(optarg);
				break;

			case 'p':
				g_Config.politica = str2enum(optarg);
				break;
			case '?':
				if (optopt == 'v' || optopt == 'p')
					printf ("Opção '-%c' requer argumento.\n", optopt);
				else if (isprint (optopt))
					printf("Opção '-%c' desconhecida.\n", optopt);
				else
					printf("Caractere '\\x%x' de opção desconhecido.\n", optopt );
				exit (1);
		}
	}

	setMEM(create);
	g_Config.words = 16;
	g_Config.bloco = 1;
	cache_t *Cache;
	long cachesize;

	system("clear");
	printf(" SIMCACHE AOCII/TP1 -------------- [MEMORY %luB]\n", sizeof(g_memory));
	printf(" Associativa\n");
	
	printf("\n QuickSort ----------------------------------------\n");
	g_resultfile = "quicksort.dat";
	createFile();

 	do {
		Cache = iniCache(g_Config);
		cachesize = sizeof(*Cache->data)*g_Config.words;
		printf(" %4luB %3d:%02d:%02d ", cachesize, 
		g_Config.words, g_Config.vias, g_Config.bloco);
		
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
		printf(" %4luB %3d:%02d:%02d ", cachesize, 
		g_Config.words, g_Config.vias, g_Config.bloco);

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
		printf(" %4luB %3d:%02d:%02d ", cachesize, 
		g_Config.words, g_Config.vias, g_Config.bloco);

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
		printf(" %4luB %3d:%02d:%02d ", cachesize, 
		g_Config.words, g_Config.vias, g_Config.bloco);

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
 
	return 0;
}