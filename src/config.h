#ifndef CONFIG_H
#define CONFIG_H

#define cRED  "\x1b[31m"
#define cGREN "\x1b[32m"
#define cYELL "\x1b[33m"
#define cBLUE "\x1b[36m"
#define cGRAY "\x1b[90m"
#define bBLUE "\x1b[44m"
#define cRSET "\x1b[0m"

typedef enum {create,miss,hit,print,restore,reset} opcao_t;

typedef struct config {
	int words;	// 16, 32, 64, 128, 256 e 512 words
	int bloco;	// 1, 2, 4, 8, 16 e 32 words por bloco
    int sets;
} config_t;

typedef struct cache {
    bool val;
    int tag;
    int *data;
} cache_t;

void getMEM();
void setMEM(opcao_t opt);
void prtMEM();

double ftempo(struct timeval tv1, struct timeval tv2);

void debugSRTmem();
void debugPRTmem();

#endif //CONFIG_H