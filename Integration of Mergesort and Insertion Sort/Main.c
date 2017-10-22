#include <stdio.h>

typedef int Element;

void originalMergeSort(Element E[], int first, int last);
void mergeSort(Element E[], int first, int last, int S);
void merge(Element E[], int first, int mid, int last);
void insertionSort(Element E[], int first, int last);

void swap(Element i[], Element j[]);

void main() {
	int input;
	Element elements[] = { 90, 25, 10, 71, 94, 22, 59, 74 };

	printf("Integration of Mergesort and Insertion Sort");
	printf("\n\n");
	printf("---");
	printf("\n\n");
	printf("Elements: \n");
	for (int x = 0; x < 8; x++) { printf("%d ", elements[x]); }
	printf("\n\n");

	originalMergeSort(elements, 0, 7);
	printf("Original Merge Sort: \n");
	for (int x = 0; x < 8; x++) { printf("%d ", elements[x]); }
	printf("\n\n");

	mergeSort(elements, 0, 7, 1);
	printf("Merge Sort: \n");
	for (int x = 0; x < 8; x++) { printf("%d ", elements[x]); }
	printf("\n\n");

	insertionSort(elements, 0, 7);
	printf("Insertion Sort: \n");
	for (int x = 0; x < 8; x++) { printf("%d ", elements[x]); }
	printf("\n\n");

	scanf("%s", &input);
}

void originalMergeSort(Element E[], int first, int last) {
	int mid = (first + last) / 2;
	if ((last - first) <= 0) { return; }
	else if (last - first > 1) {
		Element *f, *g;
		f = malloc(((mid - first) + 1 + 1) * sizeof(Element));
		g = malloc(((last - mid) + 1) * sizeof(Element));
		memcpy(f, &E[first], (mid - first + 1) * sizeof(Element));
		memcpy(g, &E[mid + 1], (last - mid) * sizeof(Element));
		f[(mid - first) + 1] = -1;
		g[(last - mid)] = -1;

		originalMergeSort(E, first, mid);
		originalMergeSort(E, mid + 1, last);
	}
	merge(E, first, mid, last);
}
void mergeSort(Element E[], int first, int last, int S) {
	if (last - first > S) {
		int mid = (first + last) / 2;
		mergeSort(E, first, mid, S);
		mergeSort(E, mid + 1, last, S);
		merge(E, first, mid, last);
	}
	else {
		insertionSort(E, first, last);
	}
}
void merge(Element E[], int first, int mid, int last) {
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