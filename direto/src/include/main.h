#ifndef MAIN_H
#define MAIN_H

#define CRED  "\x1b[31m"
#define CGREN "\x1b[32m"
#define CYELL "\x1b[33m"
#define CBLUE "\x1b[36m"
#define CRSET "\x1b[0m"

#define SEEDARQ "/dev/urandom"
#define VALIDA 0
#define MEMSIZE 4096

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include <sys/time.h>
#include <sys/stat.h>

#include "config.h"
#include "cache.h"
#include "algoritimos.h"
#include "valida.h"

int g_memory[MEMSIZE];
int g_memBCK[MEMSIZE];
config_t g_Config;
struct timeval tv1, tv2;
char *g_resultfile;

#endif //MAIN_H