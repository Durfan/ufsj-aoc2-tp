#include "main.h"

void getMem() {
	FILE *fp = fopen(seedArq,"r");
    if (fp == NULL) exit(1);

	for (int i = 0; i < memSize; i++) {
		fgets((char*)&memory[i], 4, fp);
	}

    fclose(fp);
}

void ptrMem() {
    uint8_t line = 0;
	for (int i=0; i<memSize; i++) {
        printf(" %03X\u2192%06X", i, memory[i]);
        line++;
        if (line > 6) {
            line = 0;
            printf("\n");
        }
	}
}