#ifndef SIMCACHE_MAIN_H
#define SIMCACHE_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define seedArq "/dev/urandom"
#define memSize 4096

int memory[memSize];

#include "mem.h"
#include "cache.h"
#include "ordena.h"
#include "Tcolors.h"

//cache_t cache[config.size];

#endif //SIMCACHE_MAIN_H