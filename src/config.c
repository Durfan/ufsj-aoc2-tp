#include "main.h"


void getMEM() {
	FILE *fp = fopen(seedArq,"r");
    if (fp == NULL) exit(1);

	for (int i=0; i<memSize; i++) {
		fgets((char*)&memory[i], 4, fp);
	}

    fclose(fp);
}

void setMEM(opcao_t opt) {

    switch (opt) {
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

void prtMEM() {
    int line = 0;

	printf("\n ------ MEMORY --------------------------------------------------------------\n");
	for (int i=0; i<memSize; i++) {
        printf(" %06X", memory[i]);
        line++;
        if (line > 10) {
            line = 0;
            printf("\n");
        }
	}
	printf("\n ----------------------------------------------------------------- END ------\n");
}

double ftempo(struct timeval tv1, struct timeval tv2) {
    return (double)(tv2.tv_usec - tv1.tv_usec)/1000000 +
           (double)(tv2.tv_sec-tv1.tv_sec);
}

void debugSRTmem() {
	for (int i=0; i<memSize; i++) {
		memory[i] = memSize-i;
	}
}

void debugPRTmem() {
	for (int i=0; i<memSize; i++) {
        printf(" %04d:%04d", i, memory[i]);
	}
	printf("\n\n");
}