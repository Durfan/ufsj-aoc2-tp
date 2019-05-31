#include "main.h"


int partition(cache_t *cache, config_t config, int start, int end) {
	int pivot, pindex;
	int temp;
	pivot = getCache(cache,config,end);
	pindex = start;
	for (int i=start; i<end; i++) {
		if ( getCache(cache,config,i) <= pivot ) {
			temp = getCache(cache,config,i);
			getCache(cache,config,i);
			setCache(cache,config,i,getCache(cache,config,pindex));
			getCache(cache,config,pindex);
			setCache(cache,config,pindex,temp);
			pindex++;
		}
	}
	temp = getCache(cache,config,pindex);
	getCache(cache,config,pindex);
	setCache(cache,config,pindex,getCache(cache,config,end));
	getCache(cache,config,end);
	setCache(cache,config,end,temp);
	return pindex;
}

void quicksort(cache_t *cache, config_t config, int start, int end) {
	int pindex;
	if ( start < end ) {
        pindex = partition(cache,config,start,end);
        quicksort(cache,config,start,pindex-1);
        quicksort(cache,config,pindex+1,end);
	}
}

void selection(cache_t *cache, config_t config) {
	int l,temp;
    for (int k=0; k<memSize; k++) {
		l = k;
		for (int j=k; j<memSize; j++) {
			if ( getCache(cache,config,j) < getCache(cache,config,l) ) {
				l = j;
			}
		}
        temp = getCache(cache,config,l);
		getCache(cache,config,l);
		setCache(cache,config,l,getCache(cache,config,k));
		getCache(cache,config,k);
		setCache(cache,config,k,temp);
	}
}

void bubbleSrt(cache_t *cache, config_t config) {
	int temp;
	for (int i=0; i<memSize; i++) {
		for (int j=0; j<memSize-i; j++) {
			if ( getCache(cache,config,j) > getCache(cache,config,j+1) ) {
				temp = getCache(cache,config,j);
				getCache(cache,config,j);
				setCache(cache,config,j,getCache(cache,config,j+1));
				getCache(cache,config,j+1);
				setCache(cache,config,j+1,temp);
			}
		}
	}
}