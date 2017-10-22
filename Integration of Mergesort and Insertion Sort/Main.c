#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"
#include <time.h>

typedef int Element;

void mergeSort(Element E[], int first, int last);
void inPlaceMergeSort(Element E[], int first, int last);
void modifiedMergeSort(Element E[], int first, int last, int S);
void insertionSort(Element E[], int first, int last);

void merge(Element E[], int first, int mid, int last);
void inPlaceMerge(Element E[], int first, int mid, int last);
void modifiedMerge(Element E[], int first, int mid, int last);
void insertionSort(Element E[], int first, int last);
void swap(Element i[], Element j[]);

void main() {
	clock_t CPU_start, CPU_end;
	double CPU_time;
	int input;
	Element elements[] = { 90, 25, 10, 71, 94, 22, 59, 74 };

	printf("Integration of Mergesort and Insertion Sort");
	printf("\n\n");
	printf("---");
	printf("\n\n");
	printf("Elements: \n");
	for (int x = 0; x < 8; x++) { printf("%d ", elements[x]); }
	printf("\n\n");

	CPU_start = clock();
	mergeSort(elements, 0, 7);
	printf("Original Merge Sort: \n");
	for (int x = 0; x < 8; x++) { printf("%d ", elements[x]); }
	printf("\n\n");

	inPlaceMergeSort(elements, 0, 7, 1);
	printf("Merge Sort: \n");
	for (int x = 0; x < 8; x++) { printf("%d ", elements[x]); }
	printf("\n\n");

	insertionSort(elements, 0, 7);
	printf("Insertion Sort: \n");
	for (int x = 0; x < 8; x++) { printf("%d ", elements[x]); }
	printf("\n\n");

	scanf("%s", &input);
}

void mergeSort(Element E[], int first, int last) {
	int mid = (first + last) / 2;
	if ((last - first) < 1) { return; }
	else {
		mergeSort(E, first, mid);
		mergeSort(E, mid + 1, last);
		merge(E, first, mid, last);
	}
}
void inPlaceMergeSort(Element E[], int first, int last) {
	if (last - first > 0) {
		int mid = (first + last) / 2;
		inPlaceMergeSort(E, first, mid);
		inPlaceMergeSort(E, mid + 1, last);
		inPlaceMerge(E, first, mid, last);
	}
	else {
		insertionSort(E, first, last);
	}
}
void modifiedMergeSort(Element E[], int first, int last, int S) {
	if (last - first > S) {
		int mid = (first + last) / 2;
		modifiedMergeSort(E, first, mid, S);
		modifiedMergeSort(E, mid + 1, last, S);
		modifiedMerge(E, first, mid, last);
	}
	else {
		insertionSort(E, first, last);
	}
}
void merge(Element E[], int first, int mid, int last) {
	if ((last - first) < 1) { return; }
	Queue f, g;
	f.ll.head = NULL; f.ll.tail = NULL; f.ll.size = 0; for (int x = first; x <= mid; x++) { enqueue(&f, E[x]); }
	g.ll.head = NULL; g.ll.tail = NULL; g.ll.size = 0; for (int x = mid + 1; x <= last; x++) { enqueue(&g, E[x]); }

	Element /*left, right, */temp;
	int compare, index = first/*, indexLeft = first, indexRight = mid + 1, */;
	while (!(isEmptyQueue(&f) || isEmptyQueue(&g))) {
		/*left = peak(&f);
		right = peak(&g);*/
		compare = peak(&g) - peak(&f);
		if (compare > 0) {
			//left < right
			E[index++] = dequeue(&f);
		}
		else if (compare < 0) {
			//left > right
			E[index++] = dequeue(&g);
		}
		else {
			//right = left
			E[index++] = dequeue(&f);
			E[index++] = dequeue(&g);
		}
	}
	while (!isEmptyQueue(&f)) { E[index++] = dequeue(&f); }
	while (!isEmptyQueue(&g)) { E[index++] = dequeue(&g); }
}
void inPlaceMerge(Element E[], int first, int mid, int last) {
	//int mid = (first + last) / 2;
	int a = first, b = mid + 1, temp, compare, i;
	if (last - first <= 0) { return; }

	Element *f, *g;
	f = malloc(((mid - first) + 1 + 1) * sizeof(Element));
	g = malloc(((last - mid) + 1) * sizeof(Element));
	memcpy(f, &E[first], (mid - first + 1) * sizeof(Element));
	memcpy(g, &E[mid + 1], (last - mid) * sizeof(Element));
	f[(mid - first) + 1] = -1;
	g[(last - mid)] = -1;

	while (a <= mid && b <= last) {
		compare = E[a] - E[b];
		if (compare > 0) {
			temp = E[b++];
			for (i = ++mid; i > a; i--) {
				E[i] = E[i - 1];
			}
			E[a++] = temp;
		}
		else if (compare < 0) {
			a++;
		}
		else {
			if (a == mid&&b == last) { break; }
			temp = E[b++];
			a++;
			for (i = ++mid; i > a; i--) { E[i] = E[i - 1]; }
			E[a++] = temp;
		}
	}
}
void modifiedMerge(Element E[], int first, int mid, int last) {
	//int mid = (first + last) / 2;
	int a = first, b = mid + 1, temp, compare, i;
	if (last - first <= 0) { return; }

	Element *f, *g;
	f = malloc(((mid - first) + 1 + 1) * sizeof(Element));
	g = malloc(((last - mid) + 1) * sizeof(Element));
	memcpy(f, &E[first], (mid - first + 1) * sizeof(Element));
	memcpy(g, &E[mid + 1], (last - mid) * sizeof(Element));
	f[(mid - first) + 1] = -1;
	g[(last - mid)] = -1;

	while (a <= mid && b <= last) {
		compare = E[a] - E[b];
		if (compare > 0) {
			temp = E[b++];
			for (i = ++mid; i > a; i--) {
				E[i] = E[i - 1];
			}
			E[a++] = temp;
		}
		else if (compare < 0) {
			a++;
		}
		else {
			if (a == mid&&b == last) { break; }
			temp = E[b++];
			a++;
			for (i = ++mid; i > a; i--) { E[i] = E[i - 1]; }
			E[a++] = temp;
		}
	}
}
void insertionSort(Element E[], int first, int last) {
	int n = (last - first) + 1;
	if (n <= 1) { return; }
	for (int i = first; i <= last; i++) {
		for (int j = i; j > 0; j--) {
			if (E[j] < E[j - 1]) { swap(&E[j], &E[j - 1]); }
			else { break; }
		}
	}
}

void swap(Element i[], Element j[]) {
	Element k = *i;
	*i = *j;
	*j = k;
}