#include <stdio.h>
#include <stdlib.h>

#include "Sort.h"

void mergeSort(Element E[], long long int first, long long int last) {
	if ((last - first) < 1) { return; }
	long long int mid = (first + last) / 2;
	mergeSort(E, first, mid);
	mergeSort(E, mid + 1, last);
	merge(E, first, mid, last);
}
void insertionSort(Element E[], long long int first, long long int last) {
	if ((last - first) < 1) { return; }
	for (long long int i = (first + 1); i <= last; i++) {
		for (long long int j = i; j > first; j--) {
			if (E[j] < E[j - 1]) { swap(&E[j], &E[j - 1]); }
			else { break; }
		}
	}
}

void merge(Element E[], long long int first, long long int mid, long long int last) {
	if ((last - first) < 1) { return; }
	Element *left, *right;
	left = malloc((mid - first + 1) * sizeof(Element)); memcpy(&left[0], &E[first], (mid - first + 1) * sizeof(Element));
	right = malloc((last - mid) * sizeof(Element)); memcpy(&right[0], &E[mid + 1], (last - mid) * sizeof(Element));

	//Element temp;
	long long int compare, index = first, indexLeft = 0, indexRight = 0;
	while (indexLeft < (mid - first + 1) && indexRight < (last - mid)) {
		compare = right[indexRight] - left[indexLeft];
		if (compare > 0) { E[index++] = left[indexLeft++]; } //left < right
		else if (compare < 0) { E[index++] = right[indexRight++]; } //left > right
		else { E[index++] = left[indexLeft++]; E[index++] = right[indexRight++]; } //right = left
	}
	while (indexLeft < (mid - first + 1)) { E[index++] = left[indexLeft++]; }
	while (indexRight < (last - mid)) { E[index++] = right[indexRight++]; }
	//free(left); free(right);
}
void swap(Element i[], Element j[]) {
	Element k = *i;
	*i = *j;
	*j = k;
}