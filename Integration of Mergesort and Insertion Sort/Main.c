#include <stdio.h>

typedef int Element;

void mergeSort(Element E[], int first, int last, int S);
void merge(Element E[], int first, int mid, int last);
void insertionSort(Element E[], int first, int last);

void swap(Element i, Element j);

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

	//mergeSort(elements, 0, 8, 1);
	//printf("Merge Sort: ");
	//for (int x = 0; x < 8; x++) { printf("%d ", elements[x]); }
	//printf("\n\n");

	insertionSort(elements, 0, 7);
	printf("Insertion Sort: \n");
	for (int x = 0; x < 8; x++) { printf("%d ", elements[x]); }
	printf("\n\n");

	scanf("%s", &input);
}

void mergeSort(Element E[], int first, int last, int S) {
	if (last - first > S) {
		int mid = (first + last) / 2;
		mergeSort(E, first, mid, S);
		mergeSort(E, mid + 1, last, S);
		merge(E, first, mid, last);
	} else {
		insertionSort(E, first, last);
	}
}
void merge(Element E[], int first, int mid, int last) {

}

void insertionSort(Element E[], int first, int last) {
	int n = (last - first) + 1;
	if (n <= 1) { return; }
	for (int i = first + 1; i < n; i++) {
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