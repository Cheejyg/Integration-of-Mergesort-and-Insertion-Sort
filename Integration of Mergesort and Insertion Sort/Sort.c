#include <stdio.h>
#include <stdlib.h>

#include "Sort.h"

void mersertionSort(Element E[], long long int first, long long int last, long long int S) {
	if (last - first > S) {
		int mid = (first + last) / 2;
		mersertionSort(E, first, mid, S);
		mersertionSort(E, mid + 1, last, S);
		merge(E, first, mid, last);
	}
	else {
		insertionSort(E, first, last);
	}
}
void mergeSort(Element E[], long long int first, long long int last) {
	if ((last - first) < 1) { return; }
	long long int mid = (first + last) / 2;
	mergeSort(E, first, mid);
	mergeSort(E, (mid + 1), last);
	merge(E, first, mid, last);
}
void inPlaceMergeSort(Element E[], long long int first, long long int last) {
	if ((last - first) < 1) { return; }
	long long int mid = (first + last) / 2;
	inPlaceMergeSort(E, first, mid);
	inPlaceMergeSort(E, (mid + 1), last);
	inPlaceMerge(E, first, mid, last);
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
void inPlaceMerge(Element E[], long long int first, long long int mid, long long int last) {
	if ((last - first) < 1) { return; }

	Element temp;
	long long int compare, indexLeft = first, indexRight = (mid + 1) , i;
	while (indexLeft <= mid && indexRight <= last) {
		compare = E[indexRight] - E[indexLeft];
		if (compare > 0) { indexLeft++; } //left < right
		else if (compare < 0) {
			//left > right
			temp = E[indexRight++];
			for (i = ++mid; i > indexLeft; i--) { E[i] = E[i - 1]; }
			E[indexLeft++] = temp;
		}
		else {
			//right = left
			if (indexLeft == mid && indexRight == last) { break; }
			temp = E[indexRight++];
			indexLeft++;
			for (i = ++mid; i > indexLeft; i--) { E[i] = E[i - 1]; }
			E[indexLeft++] = temp;
		}
	}
}
void swap(Element i[], Element j[]) {
	Element k = *i;
	*i = *j;
	*j = k;
}

void mersertionSortDebug(Element E[], long long int first, long long int last, long long int S, long long int comparisons[], long long int swaps[]) {
	if (last - first > S) {
		int mid = (first + last) / 2;
		mersertionSortDebug(E, first, mid, S, comparisons, swaps);
		mersertionSortDebug(E, mid + 1, last, S, comparisons, swaps);
		mergeDebug(E, first, mid, last, comparisons);
	}
	else {
		insertionSortDebug(E, first, last, comparisons, swaps);
	}
}
void mergeSortDebug(Element E[], long long int first, long long int last, long long int comparisons[]) {
	if ((last - first) < 1) { return; }
	long long int mid = (first + last) / 2;
	mergeSortDebug(E, first, mid, comparisons);
	mergeSortDebug(E, (mid + 1), last, comparisons);
	mergeDebug(E, first, mid, last, comparisons);
}
void inPlaceMergeSortDebug(Element E[], long long int first, long long int last, long long int comparisons[], long long int swaps[]) {
	if ((last - first) < 1) { return; }
	long long int mid = (first + last) / 2;
	inPlaceMergeSortDebug(E, first, mid, comparisons, swaps);
	inPlaceMergeSortDebug(E, (mid + 1), last, comparisons, swaps);
	inPlaceMergeDebug(E, first, mid, last, comparisons, swaps);
}
void insertionSortDebug(Element E[], long long int first, long long int last, long long int comparisons[], long long int swaps[]) {
	if ((last - first) < 1) { return; }
	*comparisons = 0, *swaps = 0;
	for (long long int i = (first + 1); i <= last; i++) {
		for (long long int j = i; j > first; j--) {
			if (E[j] < E[j - 1]) {
				(*comparisons)++;
				swapDebug(&E[j], &E[j - 1], swaps);
			}
			else { break; }
		}
	}
}
void mergeDebug(Element E[], long long int first, long long int mid, long long int last, long long int comparisons[]) {
	if ((last - first) < 1) { return; }
	Element *left, *right;
	left = malloc((mid - first + 1) * sizeof(Element)); memcpy(&left[0], &E[first], (mid - first + 1) * sizeof(Element));
	right = malloc((last - mid) * sizeof(Element)); memcpy(&right[0], &E[mid + 1], (last - mid) * sizeof(Element));

	long long int compare, index = first, indexLeft = 0, indexRight = 0;
	while (indexLeft < (mid - first + 1) && indexRight < (last - mid)) {
		compare = right[indexRight] - left[indexLeft];
		(*comparisons)++;
		if (compare > 0) { E[index++] = left[indexLeft++]; } //left < right
		else if (compare < 0) { E[index++] = right[indexRight++]; } //left > right
		else { E[index++] = left[indexLeft++]; E[index++] = right[indexRight++]; } //right = left
	}
	while (indexLeft < (mid - first + 1)) { E[index++] = left[indexLeft++]; }
	while (indexRight < (last - mid)) { E[index++] = right[indexRight++]; }
	//free(left); free(right);
}
void inPlaceMergeDebug(Element E[], long long int first, long long int mid, long long int last, long long int comparisons[], long long int swaps[]) {
	if ((last - first) < 1) { return; }

	Element temp;
	long long int compare, indexLeft = first, indexRight = (mid + 1), i;
	while (indexLeft <= mid && indexRight <= last) {
		compare = E[indexRight] - E[indexLeft];
		(*comparisons)++;
		if (compare > 0) { indexLeft++; } //left < right
		else if (compare < 0) {
			//left > right
			temp = E[indexRight++];
			for (i = ++mid; i > indexLeft; i--) {
				E[i] = E[i - 1];
				*(swaps)++;
			}
			E[indexLeft++] = temp;
			*(swaps)++;
		}
		else {
			//right = left
			if (indexLeft == mid && indexRight == last) { break; }
			temp = E[indexRight++];
			indexLeft++;
			for (i = ++mid; i > indexLeft; i--) { E[i] = E[i - 1]; }
			E[indexLeft++] = temp;
		}
	}
}
void swapDebug(Element i[], Element j[], long long int swaps[]) {
	Element k = *i;
	*i = *j;
	*j = k;
	(*swaps)++;
}