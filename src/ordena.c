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

void selection(int *vetor, int end) {
	int l,temp;

    for (int k = 0; k < end; k++) {
		l = k;
		for (int j = k; j < end; j++) {
			if (vetor[j] < vetor[l]) {
				pushCache(j);
				prtCache();
				l = j;
			}
		}
        temp = vetor[l];
		vetor[l] = vetor[k];
		vetor[k] = temp;
	}
}

void bubbleSrt(int *vetor, int end) {
	int temp;

	for (int i = 0; i < end; i++) {
		for (int j = 0; j < end-i; j++) {
			if (vetor[j] > vetor[j+1]) {
				pushCache(j);
				prtCache();
				temp = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = temp;
			}
		}
	}
}