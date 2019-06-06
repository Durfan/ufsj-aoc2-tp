#include "./include/main.h"


void valida() {
    bool valido = true;
    int *vetor = malloc(memSize*sizeof(int));
    memcpy(vetor,memBCK,sizeof(memBCK));
    sort(vetor,0,memSize-1);

    for (int i=0; i<memSize; i++) {
        if ( vetor[i] != memory[i] )
            valido = false;
    }

    if ( valido ) printf(cGREN" \u25CF"cRSET);
    else printf(cRED" \u25CF"cRSET);

    free(vetor);
}

void isSorted() {
	bool sorted = true;

	for (int i=0; i<memSize-1; i++) {
		if ( memory[i] > memory[i+1] )
			sorted = false;
	}

	if (sorted)
		printf(cGREN"\u25A6"cRSET);
	else
		printf(cRED"\u25A6"cRSET);
}

void debugSRTmem() {
	for (int i=0; i<memSize; i++)
		memory[i] = memSize-i;
}

void debugPRTmem() {
	for (int i=0; i<memSize; i++)
        printf(" %04d:%04d", i, memory[i]);
	printf("\n\n");
}