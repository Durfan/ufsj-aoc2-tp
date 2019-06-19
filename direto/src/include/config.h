#ifndef CONFIG_H
#define CONFIG_H

typedef enum {create,miss,hit,print,restore,reset,soma} opcao_t;

typedef struct config {
	int words;	// 16, 32, 64, 128, 256 e 512 words
	int bloco;	// 1, 2, 4, 8, 16 e 32 words por bloco
	int sets;
	int log2bl;
} config_t;

typedef struct cache {
	bool Vbit;
	bool Dbit;
	int tag;
	int *data;
} cache_t;

void getMEM();
void divMEM();
void setMEM(opcao_t opt);
void prtMEM();

void iterConfig();
bool configs();
int crapLog2foo(int x);
double ftempo(struct timeval tv1, struct timeval tv2);

void createFile();
void saveResult(float hit, float miss);

#endif //CONFIG_H