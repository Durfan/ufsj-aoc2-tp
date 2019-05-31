#include "main.h"

void getMEM() {
	FILE *fp = fopen(seedArq,"r");
    if (fp == NULL) exit(1);

	for (int i = 0; i < memSize; i++) {
		fgets((char*)&memory[i], 4, fp);
	}

    fclose(fp);
}

void setMEM(mem_t mem) {

    switch (mem) {
		case create:
			getMEM();
            memcpy(memBCK,memory,sizeof(memory));
			break;
		case restore:
            memcpy(memory,memBCK,sizeof(memBCK));
			break;
		default:
			exit(1);
	}
}

void ptrMEM() {
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