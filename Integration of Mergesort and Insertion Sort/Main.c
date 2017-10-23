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

int comparison;

void main() {
	clock_t CPU_start, CPU_end;
	//double CPU_time;
	Element elements[] = { 90, 25, 10, 71, 94, 22, 59, 74 }, *randomElements, *randomElements_Copy;
	int input, n, S;

	printf("Integration of Mergesort and Insertion Sort\n");
	printf("\n");
	printf("===\n");
	printf("\n");
	//n number of elements
	printf("n:\t\t\t\t\t");
	scanf("%d", &n);
	//S
	printf("S (threshold for sub-array's size):\t");
	scanf("%d", &S);

	//generate random Elements
	randomElements = malloc(n * sizeof(Element)); for (int x = 0; x < n; x++) { randomElements[x] = rand(); }
	//duplicate random Elements for sorting
	randomElements_Copy = malloc(n * sizeof(Element));

	if (n < 512) {
		printf("\n");
		printf("Elements = \n{");
		for (int x = 0; x < n - 1; x++) { printf("%d,\t ", randomElements[x]); if ((x + 1) % 9 == 0) { printf("\n"); } }
		printf("%d", randomElements[n - 1]);
		printf("}\n");
	}
	printf("\n");
	printf("===\n");

	printf("\n");

	///Original Merge Sort
	printf("------ Original Merge Sort ------\n");
	printf("\n");

	//reset random Elements for sorting
	printf("Resetting elements ...… ");
	for (int x = 0; x < n; x++) { randomElements_Copy[x] = randomElements[x]; }
	printf("Done.\n");
	printf("\n");

	printf("MergeSort(): \n");
	comparison = 0;
	CPU_start = clock();
	mergeSort(randomElements_Copy, 0, n - 1);
	CPU_end = clock();
	if (n < 512) {
		printf("\n");
		printf("Elements = \n{");
		for (int x = 0; x < n - 1; x++) { printf("%d,\t ", randomElements_Copy[x]); if ((x + 1) % 9 == 0) { printf("\n"); } }
		printf("%d", randomElements_Copy[n - 1]);
		printf("}\n");
	}
	printf("\n");
	printf("Numbers of key comparison(s): %d\n", comparison);
	printf("Time taken: %d miliseconds\n", (int)(((double)(CPU_end - CPU_start) / CLOCKS_PER_SEC) * 1000));
	printf("\n");
	///Original Merge Sort
	printf("---\n");

	printf("\n");

	///Modifed Merge Sort
	printf("------ Modifed Merge Sort ------\n");
	printf("\n");

	//reset random Elements for sorting
	printf("Resetting elements ...… ");
	for (int x = 0; x < n; x++) { randomElements_Copy[x] = randomElements[x]; }
	printf("Done.\n");
	printf("\n");

	printf("ModifiedMergeSort(): \n");
	comparison = 0;
	CPU_start = clock();
	modifiedMergeSort(randomElements_Copy, 0, n - 1, S);
	CPU_end = clock();
	if (n < 512) {
		printf("\n");
		printf("Elements = \n{");
		for (int x = 0; x < n - 1; x++) { printf("%d,\t ", randomElements_Copy[x]); if ((x + 1) % 9 == 0) { printf("\n"); } }
		printf("%d", randomElements_Copy[n - 1]);
		printf("}\n");
	}
	printf("\n");
	printf("Numbers of key comparison(s): %d\n", comparison);
	printf("Time taken: %d miliseconds\n", (int)(((double)(CPU_end - CPU_start) / CLOCKS_PER_SEC) * 1000));
	printf("\n");
	///Modifed Merge Sort
	printf("---\n");

	printf("\n");

	///Insertion Sort
	printf("------ Insetrtion Sort ------\n");
	printf("\n");

	//reset random Elements for sorting
	printf("Resetting elements ...… ");
	for (int x = 0; x < n; x++) { randomElements_Copy[x] = randomElements[x]; }
	printf("Done.\n");
	printf("\n");

	printf("InsertionSort(): \n");
	comparison = 0;
	CPU_start = clock();
	insertionSort(randomElements_Copy, 0, n - 1);
	CPU_end = clock();
	if (n < 512) {
		printf("\n");
		printf("Elements = \n{");
		for (int x = 0; x < n - 1; x++) { printf("%d,\t ", randomElements_Copy[x]); if ((x + 1) % 9 == 0) { printf("\n"); } }
		printf("%d", randomElements_Copy[n - 1]);
		printf("}\n");
	}
	printf("\n");
	printf("Numbers of key comparison(s): %d\n", comparison);
	printf("Time taken: %d miliseconds\n", (int)(((double)(CPU_end - CPU_start) / CLOCKS_PER_SEC) * 1000));
	printf("\n");
	///Insertion Sort
	printf("===\n");

	printf("\n");

	free(randomElements);
	free(randomElements_Copy);

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
/*void inPlaceMergeSort(Element E[], int first, int last) {
	if (last - first > 0) {
		int mid = (first + last) / 2;
		inPlaceMergeSort(E, first, mid);
		inPlaceMergeSort(E, mid + 1, last);
		inPlaceMerge(E, first, mid, last);
	}
	else {
		insertionSort(E, first, last);
	}
}*/
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
	//Original version of Mergesort
	if ((last - first) < 1) { return; }

	Queue f, g;
	f.ll.head = NULL; f.ll.tail = NULL; f.ll.size = 0;
	g.ll.head = NULL; g.ll.tail = NULL; g.ll.size = 0;
	for (int x = first; x <= mid; x++) { enqueue(&f, E[x]); }
	for (int x = mid + 1; x <= last; x++) { enqueue(&g, E[x]); }

	Element /*left, right, */temp;
	int compare, index = first/*, indexLeft = first, indexRight = mid + 1, */;
	while (!(isEmptyQueue(&f) || isEmptyQueue(&g))) {
		/*left = peak(&f);
		right = peak(&g);*/
		compare = peak(&g) - peak(&f);
		///debug
		comparison++;
		if (compare > 0) { E[index++] = dequeue(&f); } //left < right
		else if (compare < 0) { E[index++] = dequeue(&g);} //left > right
		else { E[index++] = dequeue(&f); E[index++] = dequeue(&g); } //right = left
	}
	while (!isEmptyQueue(&f)) { E[index++] = dequeue(&f); }
	while (!isEmptyQueue(&g)) { E[index++] = dequeue(&g); }
}
/*void inPlaceMerge(Element E[], int first, int mid, int last) {
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
		comparison++;
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
}*/
void modifiedMerge(Element E[], int first, int mid, int last) {
	//Modifed Mergesort
	//int mid = (first + last) / 2;
	int a = first, b = mid + 1, compare, i, temp;
	if ((last - first) < 1) { return; }

	while (a <= mid && b <= last) {
		compare = E[a] - E[b];
		///comparison
		comparison++;
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
			if (a == mid && b == last) { break;	}
			temp = E[b++];
			a++;
			for (i = ++mid; i > a; i--) {
				E[i] = E[i - 1];
			}
			E[a++] = temp;
		}
	}
}
void insertionSort(Element E[], int first, int last) {
	if ((last - first) < 1) { return; }
	for (int i = (first + 1); i <= last; i++) {
		for (int j = i; j > first; j--) {
			///comparison
			comparison++;
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