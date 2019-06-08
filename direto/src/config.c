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
	int divsize = memSize/4;

	for (int i=0; i<memSize; i++) {
		if ( i < divsize )   memory[i] = -1;
		if ( i > divsize*2 ) memory[i] =  1;
		if ( i > divsize*3 ) memory[i] = 42;	
	}
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
	char output[0x100];
	struct stat st = {0};

	if (stat("./output", &st) == -1) {
		mkdir("./output", 0700);
	}
	
    snprintf(output, sizeof(output),"./output/%s", resultfile);
    FILE *fp = fopen(output, "w");
    assert(fp);
    fclose(fp);
}

void saveResult(float hit, float miss) {
	char output[0x100];
    snprintf(output, sizeof(output),"./output/%s", resultfile);
    FILE *fp = fopen(output, "a");
    assert(fp);

    if ( config.bloco == 1 )
        fprintf(fp, "\"%dB\"\n", config.words*4);

    fprintf(fp, "%d %d %05.2f %05.2f\n", config.words, config.bloco, hit, miss);

    if ( (config.words == config.bloco) || (config.bloco == 32) )
        fprintf(fp, "\n\n");

    fclose(fp);
}