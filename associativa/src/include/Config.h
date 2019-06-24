#ifndef CONFIG_H
#define CONFIG_H

typedef enum opcao {create,erro,acerto,print,restore,reset,soma} opcao_t;
typedef enum polit {lru,lfu,fifo} polSub_t;

typedef struct Config {
	polSub_t politica;
	int words;	// 16, 32, 64, 128, 256 e 512 words
	int bloco;	// 1, 2, 4, 8, 16 e 32 words por bloco
	int vias;	// 2 vias, 4 vias e 8 vias
	int sets;
	int log2bl;
} config_t;

typedef struct Cache {
	bool vBit;
	int tag;
	int lru;
	int lfu;
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
void saveResult(float hitrate, float missrate);

#endif //CONFIG_H