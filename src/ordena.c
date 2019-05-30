#include "main.h"

void swap(int *p, int *q) {
	int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

int partition(int *vetor, int start, int end) {
	int pivot, pindex;
	pivot = vetor[end];
	pindex = start;

	for (int i = start; i < end; i++) {
		if (vetor[i] <= pivot) {
			swap(vetor+i,vetor+pindex);
			pindex++;
		}
	}
	swap(vetor+pindex,vetor+end);
	return pindex;
}

void quicksort(int *vetor, int start, int end) {
	int pindex;
	
	if (start < end) {
        pindex = partition(vetor,start,end);
        quicksort(vetor,start,pindex-1);
        quicksort(vetor,pindex+1,end);
	}
}

void selection(cache_t *cache, int *vetor) {
	int l,temp;

    for (int k = 0; k < memSize; k++) {
		l = k;
		for (int j = k; j < memSize; j++) {
			if (vetor[j] < vetor[l]) {
				l = j;
				cacheSim(cache,16,l);
				prtCache(cache,16);
			}
		}
        temp = vetor[l];
		vetor[l] = vetor[k];
		vetor[k] = temp;
	}
}

void bubbleSrt(cache_t *cache) {
	int temp;

	for (int i=0; i<memSize; i++) {
		for (int j = 0; j < memSize-i; j++) {
			//prtCache(cache,16);
			if ( getCache(cache,16,j) > getCache(cache,16,j+1) ) {
				temp = getCache(cache,16,j);
				int a,b;
				a = getCache(cache,16,j);
				b = getCache(cache,16,j+1);
				a = b;
				setCache(cache,16,j,a);
				setCache(cache,16,j+1,temp);
			}
		}
	}
}