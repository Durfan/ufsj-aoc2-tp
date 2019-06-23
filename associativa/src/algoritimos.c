#include "./include/main.h"


int partition(cache_t *Cache, int start, int end) {
	int pivot, pindex, temp;
	pivot = rdyCache(Cache,end);
	pindex = start;

	for (int i=start; i<end; i++) {
		if ( rdyCache(Cache,i) <= pivot ) {
			temp = rdyCache(Cache,i);
			wrtCache(Cache,i,rdyCache(Cache,pindex));
			rdyCache(Cache,pindex);
			wrtCache(Cache,pindex,temp);
			pindex++;
		}
	}
	temp = rdyCache(Cache,pindex);
	wrtCache(Cache,pindex,rdyCache(Cache,end));
	rdyCache(Cache,end);
	wrtCache(Cache,end,temp);

	return pindex;
}

void quicksort(cache_t *Cache, int start, int end) {
	int pindex;

	if ( start < end ) {
		pindex = partition(Cache,start,end);
		quicksort(Cache,start,pindex-1);
		quicksort(Cache,pindex+1,end);
	}
}

void selection(cache_t *Cache) {
	int l,temp;

	for (int k=0; k<MEMSIZE; k++) {
		l = k;
		for (int j=k; j<MEMSIZE; j++) {
			if ( rdyCache(Cache,j) < rdyCache(Cache,l) ) {
				l = j;
			}
		}
		temp = rdyCache(Cache,l);
		rdyCache(Cache,l);
		wrtCache(Cache,l,rdyCache(Cache,k));
		rdyCache(Cache,k);
		wrtCache(Cache,k,temp);
	}
}

void bubbleSrt(cache_t *Cache) {
	int temp;
	
	for (int i=0; i<MEMSIZE; i++) {
		for (int j=0; j<MEMSIZE-i-1; j++) {
			if ( rdyCache(Cache,j) > rdyCache(Cache,j+1) ) {
				temp = rdyCache(Cache,j);
				rdyCache(Cache,j);
				wrtCache(Cache,j,rdyCache(Cache,j+1));
				rdyCache(Cache,j+1);
				wrtCache(Cache,j+1,temp);
			}
		}
	}
}

void somavetor(cache_t *Cache) {
	int divsize = MEMSIZE/4;
	int addrV1 = 0;
	int addrV2 = divsize; // 1024
	int addrV3 = divsize*2; // 2048

	for (int i=0; i<divsize; i++) {
		rdyCache(Cache,addrV3);
		wrtCache(Cache,addrV3,rdyCache(Cache,addrV1)+rdyCache(Cache,addrV2));
		addrV1++;
		addrV2++;
		addrV3++;
	}
}

void swap(int *p, int *q) {
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

int part(int *vetor, int start, int end) {
	int pivot, pindex;
	pivot = vetor[end];
	pindex = start;

	for (int i=start; i<end; i++) {
		if ( vetor[i] <= pivot ) {
			swap(vetor+i,vetor+pindex);;
			pindex++;
		}
	}
	swap(vetor+pindex,vetor+end);
	
	return pindex;
}

void sort(int *vetor, int start, int end) {
	int pindex;

	if ( start < end ) {
		pindex = part(vetor,start,end);
		sort(vetor,start,pindex-1);
		sort(vetor,pindex+1,end);
	}
}