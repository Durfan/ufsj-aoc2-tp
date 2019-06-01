#include "main.h"


int partition(cache_t *cache, int start, int end) {
	int pivot, pindex;
	int temp;
	pivot = getCache(cache,end);
	pindex = start;

	for (int i=start; i<end; i++) {
		if ( getCache(cache,i) <= pivot ) {
			temp = getCache(cache,i);
			getCache(cache,i);
			setCache(cache,i,getCache(cache,pindex));
			getCache(cache,pindex);
			setCache(cache,pindex,temp);
			pindex++;
		}
	}
	temp = getCache(cache,pindex);
	getCache(cache,pindex);
	setCache(cache,pindex,getCache(cache,end));
	getCache(cache,end);
	setCache(cache,end,temp);

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
			if ( getCache(cache,j) < getCache(cache,l) ) {
				l = j;
			}
		}
        temp = getCache(cache,l);
		getCache(cache,l);
		setCache(cache,l,getCache(cache,k));
		getCache(cache,k);
		setCache(cache,k,temp);
	}
}

void bubbleSrt(cache_t *cache) {
	int temp;
	
	for (int i=0; i<memSize; i++) {
		for (int j=0; j<memSize-i; j++) {
			if ( getCache(cache,j) > getCache(cache,j+1) ) {
				temp = getCache(cache,j);
				getCache(cache,j);
				setCache(cache,j,getCache(cache,j+1));
				getCache(cache,j+1);
				setCache(cache,j+1,temp);
			}
		}
	}
}