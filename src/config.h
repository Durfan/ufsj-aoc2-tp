#ifndef CONFIG_H
#define CONFIG_H

typedef enum {miss,hit,print,reset} count_t;
typedef enum {create,restore} mem_t;

typedef struct config {
	int words;		// 16, 32, 64, 128, 256 e 512 words
	int tamBloco;	// 1, 2, 4, 8, 16 e 32 words por bloco
    int linhas;
} config_t;

typedef struct cache {
    bool validade;
    int *tag;
    int *bloco;
} cache_t;

#endif //CONFIG_H