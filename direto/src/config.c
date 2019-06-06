#include "./include/main.h"


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

void divMEM() {
	int size = memSize/3;
	int vetor1[size];
	int vetor2[size];
	int vetor3[size];

	for (int i=0; i<size; i++) {
		vetor1[i] = i;
		vetor2[i] = i;
		vetor3[i] = i;
	}

	memcpy(&memory[0],vetor1,size*sizeof(int));
	memcpy(&memory[memSize/3],vetor2,size*sizeof(int));
	memcpy(&memory[(memSize/3)*2],vetor3,size*sizeof(int));
	memory[memSize-1] = 42;
}

void prtMEM() {
    int line = 0;

	printf("\n\n");
	for (int i=0; i<memSize; i++) {
        printf(" %06X", memory[i]);
        line++;
        if (line > 10) {
            line = 0;
            printf("\n");
        }
	}
	printf("\n\n");
}

void iterConfig() {
	if ( config.bloco < 32 && config.bloco < config.words)
		config.bloco *= 2;
	else {
		config.words *= 2;
		config.bloco = 1;
	}
	setMEM(restore);
}

bool configs() {
	if ( config.words <= 512 ) {
		return true;
	}
	config.words = 16;
	config.bloco = 1;
	return false;
}

int crapLog2foo(int x) {
	switch (x) {
		case 1:  return 0;
		case 2:  return 1;
		case 4:  return 2;
		case 8:  return 3;
		case 16: return 4;
		case 32: return 5;
		default: exit(1);
	}
}

double ftempo(struct timeval tv1, struct timeval tv2) {
    return (double)(tv2.tv_usec - tv1.tv_usec)/1000000 +
           (double)(tv2.tv_sec-tv1.tv_sec);
}

void createFile() {
    FILE *fp = fopen(resultfile, "w");
    assert(fp);
    fclose(fp);
}

void saveResult(float hit, float miss) {
    FILE *fp = fopen(resultfile, "a");
    assert(fp);

    if ( config.bloco == 1 )
        fprintf(fp, "%d", config.words);

    fprintf(fp, " %05.2f %05.2f", hit, miss);

    if ( (config.words == config.bloco) || (config.bloco == 32) )
        fprintf(fp, "\n");

    fclose(fp);
}