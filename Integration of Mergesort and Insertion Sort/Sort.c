#include <stdio.h>
#include <stdlib.h>

#include "Sort.h"

#include "Queue.h"

void mergeSort(Element E[], int first, int last) {
	int mid = (first + last) / 2;
	if ((last - first) < 1) { return; }
	mergeSort(E, first, mid);
	mergeSort(E, mid + 1, last);
	merge(E, first, mid, last);
}
void insertionSort(Element E[], int first, int last) {
	if ((last - first) < 1) { return; }
	for (int i = (first + 1); i <= last; i++) {
		for (int j = i; j > first; j--) {
			if (E[j] < E[j - 1]) { swap(&E[j], &E[j - 1]); }
			else { break; }
		}
	}
}

void merge(Element E[], int first, int mid, int last) {
	if ((last - first) < 1) { return; }
	Queue f, g;
	f.ll.head = NULL; f.ll.tail = NULL; f.ll.size = 0;
	g.ll.head = NULL; g.ll.tail = NULL; g.ll.size = 0;
	for (int x = first; x <= mid; x++) { enqueue(&f, E[x]); }
	for (int x = mid + 1; x <= last; x++) { enqueue(&g, E[x]); }

	Element temp;
	int compare, index = first;
	while (!(isEmptyQueue(&f) || isEmptyQueue(&g))) {
		compare = peak(&g) - peak(&f);
		if (compare > 0) { E[index++] = dequeue(&f); } //left < right
		else if (compare < 0) { E[index++] = dequeue(&g); } //left > right
		else { E[index++] = dequeue(&f); E[index++] = dequeue(&g); } //right = left
	}
	while (!isEmptyQueue(&f)) { E[index++] = dequeue(&f); }
	while (!isEmptyQueue(&g)) { E[index++] = dequeue(&g); }
}
void swap(Element i[], Element j[]) {
	Element k = *i;
	*i = *j;
	*j = k;
}