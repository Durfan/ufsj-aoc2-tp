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
	for (int i = 0; i < memSize; i++) {
        printf(" %05d "bBLUE"\u258F%010d\u2595"cRSET, i<<2, memory[i]);
        line++;
        if (line > 3) {
            line = 0;
            printf("\n");
        }
	}
}