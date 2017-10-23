#include <stdio.h>
//#include <stdlib.h>

#include <windows.h>

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

//global
int comparison;

void main() {

	LARGE_INTEGER performanceCounter_start, performanceCounter_end, CPU_frequency;
	QueryPerformanceFrequency(&CPU_frequency);
	LARGE_INTEGER CPU_time;
	Element /*elements[] = { 90, 25, 10, 71, 94, 22, 59, 74 }, */*randomElements, *randomElements_Copy;
	int input, n, S;

	//printfs
	printf("\n");
	printf("Integration of Mergesort and Insertion Sort\n");
	printf("\n");
	printf("===\n");
	printf("\n");
	//n (number of elements)
	printf("    n:\t\t\t\t\t");
	scanf("%d", &n);
	//printf("10\n"); n = 10;
	//S (threshold for the size of sub-arrays)
	printf("    S (threshold for sub-array's size):\t");
	scanf("%d", &S);
	//printf("1\n"); S = 1;
	printf("\n");

	//generate n number of random Elements and duplicate it for sorting
	randomElements = malloc(n * sizeof(Element)); for (int x = 0; x < n; x++) { randomElements[x] = rand(); }
	//randomElements_Copy = malloc(n * sizeof(Element)); for (int x = 0; x < n; x++) { randomElements_Copy[x] = randomElements[x]; }; //memcpy(randomElements_Copy, &randomElements[0], n * sizeof(Element));
	randomElements_Copy = malloc(n * sizeof(Element)); memcpy(&randomElements_Copy[0], &randomElements[0], n * sizeof(Element));
	//if n within threshold, print entire array
	if (n < 512) {
		printf("Elements = \n{"); for (int x = 0; x < n - 1; x++) { printf("%d,\t ", randomElements[x]); if ((x + 1) % 9 == 0) { printf("\n"); } } printf("%d}\n", randomElements[n - 1]); printf("\n");
	}

	printf("===\n");

	printf("\n");
	printf("======\n");
	printf("\n");

	///Original Merge Sort
	printf("--------- Original Merge Sort ---------\n");
	printf("\n");
	comparison = 0;

	//reset random Elements to original values
	printf("Resetting elements ...… ");
	memcpy(&randomElements_Copy[0], &randomElements[0], n * sizeof(Element)); //for (int x = 0; x < n; x++) { randomElements_Copy[x] = randomElements[x]; };
	printf("Done.\n");
	printf("\n");

	printf("MergeSort(): \n");
	QueryPerformanceCounter(&performanceCounter_start);
	mergeSort(randomElements_Copy, 0, n - 1);
	QueryPerformanceCounter(&performanceCounter_end);
	//CPU_time = (double) ((double) (performance_end.QuadPart - performance_start.QuadPart) / (double) CPU_frequency.QuadPart) * 1000);
	if (n < 512) {
		printf("Elements = \n{"); for (int x = 0; x < n - 1; x++) { printf("%d,\t ", randomElements_Copy[x]); if ((x + 1) % 9 == 0) { printf("\n"); } } printf("%d}\n", randomElements_Copy[n - 1]); printf("\n");
	}
	printf("\n");
	printf("Numbers of key comparison(s): %d\n", comparison);
	printf("Time taken: %lf miliseconds\n", (double) ((double) (performanceCounter_end.QuadPart - performanceCounter_start.QuadPart) / (double) CPU_frequency.QuadPart) * 1000);
	
	printf("\n");
	printf("\n");

	///Modifed Merge Sort
	printf("--------- Modified Merge Sort ---------\n");
	printf("\n");
	comparison = 0;

	//reset random Elements to original values
	printf("Resetting elements ...… ");
	memcpy(&randomElements_Copy[0], &randomElements[0], n * sizeof(Element));
	printf("Done.\n");
	printf("\n");

	printf("ModifiedMergeSort(): \n");
	QueryPerformanceCounter(&performanceCounter_start);
	modifiedMergeSort(randomElements_Copy, 0, n - 1, S);
	QueryPerformanceCounter(&performanceCounter_end);
	if (n < 512) {
		printf("Elements = \n{"); for (int x = 0; x < n - 1; x++) { printf("%d,\t ", randomElements_Copy[x]); if ((x + 1) % 9 == 0) { printf("\n"); } } printf("%d}\n", randomElements_Copy[n - 1]); printf("\n");
	}
	printf("\n");
	printf("Numbers of key comparison(s): %d\n", comparison);
	printf("Time taken: %lf miliseconds\n", (double)((double)(performanceCounter_end.QuadPart - performanceCounter_start.QuadPart) / (double)CPU_frequency.QuadPart) * 1000);

	printf("\n");
	printf("\n");

	///Insertion Sort
	printf("--------- Insertion Sort ---------\n");
	printf("\n");
	comparison = 0;

	//reset random Elements to original values
	printf("Resetting elements ...… ");
	memcpy(&randomElements_Copy[0], &randomElements[0], n * sizeof(Element));
	printf("Done.\n");
	printf("\n");

	printf("InsertionSort(): \n");
	QueryPerformanceCounter(&performanceCounter_start);
	insertionSort(randomElements_Copy, 0, n - 1);
	QueryPerformanceCounter(&performanceCounter_end);
	if (n < 512) {
		printf("Elements = \n{"); for (int x = 0; x < n - 1; x++) { printf("%d,\t ", randomElements_Copy[x]); if ((x + 1) % 9 == 0) { printf("\n"); } } printf("%d}\n", randomElements_Copy[n - 1]); printf("\n");
	}
	printf("\n");
	printf("Numbers of key comparison(s): %d\n", comparison);
	printf("Time taken: %lf miliseconds\n", (double)((double)(performanceCounter_end.QuadPart - performanceCounter_start.QuadPart) / (double)CPU_frequency.QuadPart) * 1000);

	printf("\n");
	printf("\n");

	///END
	printf("=== END ===");
	printf("\n");

	free(randomElements_Copy);
	free(randomElements);
	//free(randomElements_Copy);

	scanf("%s", &input);
}

void mergeSort(Element E[], int first, int last) {
	if ((last - first) < 1) { return; }
	int mid = (first + last) / 2;
	mergeSort(E, first, mid);
	mergeSort(E, mid + 1, last);
	merge(E, first, mid, last);
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
	Element *left, *right;
	left = malloc((mid - first + 1) * sizeof(Element)); memcpy(&left[0], &E[first], (mid - first + 1) * sizeof(Element)); //for (int x = 0; x < (mid - first + 1); x++) { left[x] = E[x]; }
	right = malloc((last - mid) * sizeof(Element)); memcpy(&right[0], &E[mid + 1], (last - mid) * sizeof(Element)); //for (int x = 0; x < (last - mid); x++) { right[x] = E[(mid + 1) + x]; }

	Element /*left, right, */temp;
	int compare, index = first, indexLeft = 0, indexRight = 0;
	while (indexLeft < (mid - first + 1) && indexRight < (last - mid)) {
		/*left = left[indexLeft];
		right = right[indexRight];*/
		compare = right[indexRight] - left[indexLeft];
		///debug
		comparison++;
		if (compare > 0) { E[index++] = left[indexLeft++]; } //left < right
		else if (compare < 0) { E[index++] = right[indexRight++]; } //left > right
		else { E[index++] = left[indexLeft++]; E[index++] = right[indexRight++]; } //right = left
	}
	while (indexLeft < (mid - first + 1)) { E[index++] = left[indexLeft++]; }
	while (indexRight < (last - mid)) { E[index++] = right[indexRight++]; }
	//if (indexLeft < (mid - first + 1)) { memcpy(&E[index], &left[indexLeft], ((mid - first + 1) - indexLeft) * sizeof(Element)); }
	//if (indexRight < (last - mid)) { memcpy(&E[index], &left[indexRight], ((last - mid) - indexRight) * sizeof(Element)); }
	//free(left); free(right);
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
	if ((last - first) < 1) { return; }
	Element *left, *right;
	left = malloc((mid - first + 1) * sizeof(Element)); memcpy(&left[0], &E[first], (mid - first + 1) * sizeof(Element)); //for (int x = 0; x < (mid - first + 1); x++) { left[x] = E[x]; }
	right = malloc((last - mid) * sizeof(Element)); memcpy(&right[0], &E[mid + 1], (last - mid) * sizeof(Element)); //for (int x = 0; x < (last - mid); x++) { right[x] = E[(mid + 1) + x]; }

	Element /*left, right, */temp;
	int compare, index = first, indexLeft = 0, indexRight = 0;
	while (indexLeft < (mid - first + 1) && indexRight < (last - mid)) {
		/*left = left[indexLeft];
		right = right[indexRight];*/
		compare = right[indexRight] - left[indexLeft];
		///debug
		comparison++;
		if (compare > 0) { E[index++] = left[indexLeft++]; } //left < right
		else if (compare < 0) { E[index++] = right[indexRight++]; } //left > right
		else { E[index++] = left[indexLeft++]; E[index++] = right[indexRight++]; } //right = left
	}
	while (indexLeft < (mid - first + 1)) { E[index++] = left[indexLeft++]; }
	while (indexRight < (last - mid)) { E[index++] = right[indexRight++]; }
	//free(left); free(right);
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