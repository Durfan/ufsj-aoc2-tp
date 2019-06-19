#include "./include/main.h"


void getMEM() {
	FILE *fp = fopen(SEEDARQ,"r");
	if (fp == NULL) exit(1);

	for (int i=0; i<MEMSIZE; i++) {
		fgets((char*)&g_memory[i], 4, fp);
	}

	fclose(fp);
}

void setMEM(opcao_t opt) {

	switch (opt) {
		case create:
			getMEM();
			memcpy(g_memBCK,g_memory,sizeof(g_memory));
			break;
		case soma:
			divMEM();
			memcpy(g_memBCK,g_memory,sizeof(g_memory));
			break;
		case restore:
			memcpy(g_memory,g_memBCK,sizeof(g_memBCK));
			break;
		default:
			exit(1);
	}
}

void divMEM() {
	int divsize = MEMSIZE/4;

	for (int i=0; i<MEMSIZE; i++) {
		if ( i < divsize ) g_memory[i] = -1;
		else g_memory[i] = 1;
	}
}

void prtMEM() {
	int line = 0;

	printf("\n\n");
	for (int i=0; i<MEMSIZE; i++) {
		printf(" %06X", g_memory[i]);
		line++;
		if (line > 10) {
			line = 0;
			printf("\n");
		}
	}
	printf("\n\n");
}

void iterConfig() {
	if ( g_Config.bloco < 32 && g_Config.bloco < g_Config.words)
		g_Config.bloco *= 2;
	else {
		g_Config.words *= 2;
		g_Config.bloco = 1;
	}
}

bool configs() {
	if ( g_Config.words <= 512 ) {
		return true;
	}
	g_Config.words = 16;
	g_Config.bloco = 1;
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
	
	snprintf(output, sizeof(output),"./output/%s", g_resultfile);
	FILE *fp = fopen(output, "w");
	assert(fp);
	fclose(fp);
}

void saveResult(float hitrate, float missrate) {
	char output[0x100];
	snprintf(output, sizeof(output),"./output/%s", g_resultfile);
	FILE *fp = fopen(output, "a");
	assert(fp);

	if ( g_Config.bloco == 1 )
		fprintf(fp, "\"%dB\"\n", g_Config.words*4);

	fprintf(fp, "%d %d %05.2f %05.2f\n", g_Config.words, g_Config.bloco, hitrate, missrate);

	if ( (g_Config.words == g_Config.bloco) || (g_Config.bloco == 32) )
		fprintf(fp, "\n\n");

	fclose(fp);
}