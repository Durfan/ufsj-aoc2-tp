#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <sys/time.h>
#include <assert.h>

#include "config.h"
#include "cache.h"
#include "ordena.h"
#include "gnuplot.h"

#define seedArq "/dev/urandom"
#define memSize 4096

int memory[memSize];
int memBCK[memSize];
config_t config;

#endif //MAIN_H