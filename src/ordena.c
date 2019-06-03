#include "main.h"


int partition(cache_t *cache, int start, int end) {
	int pivot, pindex;
	int temp;
	pivot = rdyCache(cache,end);
	pindex = start;

	for (int i=start; i<end; i++) {
		if ( rdyCache(cache,i) <= pivot ) {
			temp = rdyCache(cache,i);
			rdyCache(cache,i);
			wrtCache(cache,i,rdyCache(cache,pindex));
			rdyCache(cache,pindex);
			wrtCache(cache,pindex,temp);
			pindex++;
		}
	}
	temp = rdyCache(cache,pindex);
	rdyCache(cache,pindex);
	wrtCache(cache,pindex,rdyCache(cache,end));
	rdyCache(cache,end);
	wrtCache(cache,end,temp);

	return pindex;
}

void quicksort(cache_t *cache, int start, int end) {
	int pindex;

	if ( start < end ) {
        pindex = partition(cache,start,end);
        quicksort(cache,start,pindex-1);
        quicksort(cache,pindex+1,end);
	}
}

void selection(cache_t *cache) {
	int l,temp;

    for (int k=0; k<memSize; k++) {
		l = k;
		for (int j=k; j<memSize; j++) {
			if ( rdyCache(cache,j) < rdyCache(cache,l) ) {
				l = j;
			}
		}
        temp = rdyCache(cache,l);
		rdyCache(cache,l);
		wrtCache(cache,l,rdyCache(cache,k));
		rdyCache(cache,k);
		wrtCache(cache,k,temp);
	}
}

void bubbleSrt(cache_t *cache) {
	gettimeofday(&tv1,NULL);
	int temp;
	
	for (int i=0; i<memSize; i++) {
		for (int j=0; j<memSize-i-1; j++) {
			if ( rdyCache(cache,j) > rdyCache(cache,j+1) ) {
				temp = rdyCache(cache,j);
				rdyCache(cache,j);
				wrtCache(cache,j,rdyCache(cache,j+1));
				rdyCache(cache,j+1);
				wrtCache(cache,j+1,temp);
			}
		}
	}
	gettimeofday(&tv2,NULL);
}