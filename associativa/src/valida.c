#include "./include/Main.h"


void valida() {
	if (!VALIDA) return;
	bool valido = true;
	int *vetor = malloc(MEMSIZE*sizeof(int));
	memcpy(vetor,g_memBCK,sizeof(g_memBCK));
	sort(vetor,0,MEMSIZE-1);

	for (int i=0; i<MEMSIZE; i++) {
		if ( vetor[i] != g_memory[i] )
			valido = false;
	}

	if ( valido ) printf(CGREN" \u25CF"CRSET);
	else printf(CRED" \u25CF"CRSET);

	free(vetor);
}

void isSorted() {
	if (!VALIDA) return;
	bool sorted = true;

	for (int i=0; i<MEMSIZE-1; i++) {
		if ( g_memory[i] > g_memory[i+1] )
			sorted = false;
	}

	if (sorted)
		printf(CGREN"\u25A6"CRSET);
	else
		printf(CRED"\u25A6"CRSET);
}

void validasoma() {
	if (!VALIDA) return;
	int divsize = MEMSIZE/4;
	bool ok = true;

	for (int i=divsize*2; i<divsize*3; i++) {
		if ( g_memory[i] != 0 ) ok = false;
	}

	if ( ok ) printf(CGREN" \u25CF"CRSET);
	else printf(CRED" \u25CF"CRSET);
}

void debugSRTmem() {
	for (int i=0; i<MEMSIZE; i++)
		g_memory[i] = MEMSIZE-i;
}

void debugPRTmem() {
	for (int i=0; i<MEMSIZE; i++)
		printf(" %04d:%04d", i, g_memory[i]);
	printf("\n\n");
}