#include "main.h"

int mod(int memAddr) {
	return memAddr % cacheSize;
}

void initCache() {
	for (int i = 0; i < cacheSize; i++) {
        cache[i] = 0;
	}
}

void pushCache(int memAddr) {
	unsigned cacheAddr = memAddr % cacheSize;
	//printf("%d\n", cacheAddr);
	cache[cacheAddr] = memory[memAddr];
}

void prtCache() {
	system("clear");
	for (int i = 0; i < cacheSize; i++) {
        printf(" %02d "bBLUE"\u258F%010d\u2595"cRSET"\n", i, cache[i]);
	}
}