#ifndef MAIN_H
#define MAIN_H

#define cRED  "\x1b[31m"
#define cGREN "\x1b[32m"
#define cYELL "\x1b[33m"
#define cBLUE "\x1b[36m"
#define cRSET "\x1b[0m"

#define seedArq "/dev/urandom"
#define VALIDA 1
#define memSize 4096

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "config.h"
#include "cache.h"
#include "algoritimos.h"
#include "valida.h"

int memory[memSize];
int memBCK[memSize];
config_t config;
struct timeval tv1, tv2;
char *resultfile;

#endif //MAIN_H