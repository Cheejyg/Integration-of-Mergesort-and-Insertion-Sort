#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>

#include <windows.h>

typedef long long int Element;

void mergeSort(Element E[], long long int first, long long int last);
void inPlaceMergeSort(Element E[], long long int first, long long int last);
void modifiedMergeSort(Element E[], long long int first, long long int last, long long int S);
void insertionSort(Element E[], long long int first, long long int last);

void merge(Element E[], long long int first, long long int mid, long long int last);
void inPlaceMerge(Element E[], long long int first, long long int mid, long long int last);
void modifiedMerge(Element E[], long long int first, long long int mid, long long int last);
void insertionSort(Element E[], long long int first, long long int last);
void swap(Element i[], Element j[]);

//global
long long int comparison;

void main() {

	//CPU time
	LARGE_INTEGER performanceCounter_start, performanceCounter_end, CPU_frequency;
	QueryPerformanceFrequency(&CPU_frequency);
	//LARGE_INTEGER CPU_time;
	//Element[]
	Element /*elements[] = { 90, 25, 10, 71, 94, 22, 59, 74 }, */*randomElements, *randomElements_Copy;
	long long int n, S;
	char input;

	//printfs, prompt for n (number of elements) and S
	printf("\n");
	printf("Integration of Mergesort and Insertion Sort\n");
	printf("\n");
	printf("===\n");
	printf("\n");
	//n (number of elements)
	printf("    n:\t\t\t\t\t");
	scanf("%lld", &n); scanf("%c", &input);
	//printf("10000\n"); n = 10000;
	//S (threshold for the size of sub-arrays)
	printf("    S (threshold for sub-array's size):\t");
	scanf("%lld", &S); scanf("%c", &input);
	printf("\n");

	//generate n number of random Element[] and copy to Element_Copy[] for sorting and resetting
	randomElements = malloc(n * sizeof(Element)); for (long long int x = 0; x < n; x++) { randomElements[x] = rand(); }
	//randomElements_Copy = malloc(n * sizeof(Element));  for (long long int x = 0; x < n; x++) { randomElements_Copy[x] = randomElements[x]; }; memcpy(&randomElements_Copy[0], &randomElements[0], n * sizeof(Element));
	randomElements_Copy = malloc(n * sizeof(Element)); memcpy(&randomElements_Copy[0], &randomElements[0], n * sizeof(Element));
	//if n within threshold, print entire array
	if (n < 512) {
		printf("Elements = \n{"); for (int x = 0; x < n - 1; x++) { printf("%lld,\t ", randomElements[x]); if ((x + 1) % 9 == 0) { printf("\n"); } } printf("%lld}\n", randomElements[n - 1]); printf("\n");
	}

	printf("===\n");
	printf("\n");

	printf("======\n");
	printf("\n");

	///Original Merge Sort///
	printf("--------- Original Merge Sort ---------\n");
	printf("\n");

	//reset Element_Copy[] to original Element[]
	printf("Resetting elements ...… ");
	memcpy(&randomElements_Copy[0], &randomElements[0], n * sizeof(Element)); //for (long long int x = 0; x < n; x++) { randomElements_Copy[x] = randomElements[x]; };
	printf("Done.\n");
	printf("\n");

	//reset comparison counter
	comparison = 0;

	printf("MergeSort(): \n");
	//MergeSort()
	QueryPerformanceCounter(&performanceCounter_start);
	mergeSort(randomElements_Copy, 0, (n - 1));
	QueryPerformanceCounter(&performanceCounter_end);
	//CPU_time = (double) ((double) (performance_end.QuadPart - performance_start.QuadPart) / (double) CPU_frequency.QuadPart) * 1000);
	if (n < 512) {
		printf("Elements = \n{"); for (int x = 0; x < n - 1; x++) { printf("%lld,\t ", randomElements_Copy[x]); if ((x + 1) % 9 == 0) { printf("\n"); } } printf("%lld}\n", randomElements_Copy[n - 1]);
	}
	printf("\n");
	printf("\tNumbers of key comparison(s): \t%lld\n", comparison);
	printf("\tTime taken: \t\t\t%lf miliseconds\n", (double)((double)(performanceCounter_end.QuadPart - performanceCounter_start.QuadPart) / (double)CPU_frequency.QuadPart) * 1000);

	printf("\n");

	///Modifed Merge Sort///
	printf("--------- Modified Merge Sort ---------\n");
	printf("\n");

	//reset Element_Copy[] to original Element[]
	printf("Resetting elements ...… ");
	memcpy(&randomElements_Copy[0], &randomElements[0], n * sizeof(Element));
	printf("Done.\n");
	printf("\n");

	//reset comparison counter
	comparison = 0;

	printf("ModifiedMergeSort(): \n");
	if (0) {
		printf("\n");
		printf("Warning: This may take a long time to complete.\nAre you sure you want to continue?\nPress any key to continue or Ctrl + C to break . . .\n", (n * n));
		scanf("%c", &input); scanf("%c", &input);
	}
	//ModifiedMergeSort()
	QueryPerformanceCounter(&performanceCounter_start);
	modifiedMergeSort(randomElements_Copy, 0, (n - 1), S);
	QueryPerformanceCounter(&performanceCounter_end);
	if (n < 512) {
		printf("Elements = \n{"); for (int x = 0; x < n - 1; x++) { printf("%lld,\t ", randomElements_Copy[x]); if ((x + 1) % 9 == 0) { printf("\n"); } } printf("%lld}\n", randomElements_Copy[n - 1]); printf("\n");
	}
	printf("\n");
	printf("\tNumbers of key comparison(s): \t%lld\n", comparison);
	printf("\tTime taken: \t\t\t%lf miliseconds\n", (double)((double)(performanceCounter_end.QuadPart - performanceCounter_start.QuadPart) / (double)CPU_frequency.QuadPart) * 1000);

	printf("\n");

	///In-Place Merge Sort///
	printf("--------- In-Place Merge Sort ---------\n");
	printf("\n");

	//reset Element_Copy[] to original Element[]
	printf("Resetting elements ...… ");
	memcpy(&randomElements_Copy[0], &randomElements[0], n * sizeof(Element));
	printf("Done.\n");
	printf("\n");

	//reset comparison counter
	comparison = 0;

	printf("InPlaceMergeSort(): \n");
	if (n > 100000) {
		printf("\n");
		printf("Warning: This may take a long time to complete.\nAre you sure you want to continue?\nPress any key to continue or Ctrl + C to break . . .\n", (n * n));
		scanf("%c", &input); scanf("%c", &input);
	}
	//inPlaceMergeSort()
	QueryPerformanceCounter(&performanceCounter_start);
	inPlaceMergeSort(randomElements_Copy, 0, (n - 1));
	QueryPerformanceCounter(&performanceCounter_end);
	if (n < 512) {
		printf("Elements = \n{"); for (int x = 0; x < n - 1; x++) { printf("%lld,\t ", randomElements_Copy[x]); if ((x + 1) % 9 == 0) { printf("\n"); } } printf("%lld}\n", randomElements_Copy[n - 1]); printf("\n");
	}
	printf("\n");
	printf("\tNumbers of key comparison(s): \t%lld\n", comparison);
	printf("\tTime taken: \t\t\t%lf miliseconds\n", (double)((double)(performanceCounter_end.QuadPart - performanceCounter_start.QuadPart) / (double)CPU_frequency.QuadPart) * 1000);

	printf("\n");

	///Insertion Sort///
	printf("--------- Insertion Sort ---------\n");
	printf("\n");

	//reset Element_Copy[] to original Element[]
	printf("Resetting elements ...… ");
	memcpy(&randomElements_Copy[0], &randomElements[0], n * sizeof(Element));
	printf("Done.\n");
	printf("\n");

	//reset comparison counter
	comparison = 0;

	printf("InsertionSort(): \n");
	if (n > 100000) {
		printf("\n");
		printf("Warning: This will take a long time to complete.\nAre you sure you want to continue with max O(%lld) number of iterations?\nPress enter key to continue or [Ctrl + C] to break . . .\n", (n * n));
		scanf("%c", &input);
	}
	//else {
		//InsertionSort()
		QueryPerformanceCounter(&performanceCounter_start);
		insertionSort(randomElements_Copy, 0, (n - 1));
		QueryPerformanceCounter(&performanceCounter_end);
		if (n < 512) {
			printf("Elements = \n{"); for (int x = 0; x < n - 1; x++) { printf("%lld,\t ", randomElements_Copy[x]); if ((x + 1) % 9 == 0) { printf("\n"); } } printf("%lld}\n", randomElements_Copy[n - 1]); printf("\n");
		}
		printf("\n");
		printf("\tNumbers of key comparison(s): \t%lld\n", comparison);
		printf("\tTime taken: \t\t\t%lf miliseconds\n", (double)((double)(performanceCounter_end.QuadPart - performanceCounter_start.QuadPart) / (double)CPU_frequency.QuadPart) * 1000);
	//}

	printf("\n");

	///END
	printf("=== END ===");
	printf("\n");

	free(randomElements_Copy);
	free(randomElements);
	//free(randomElements_Copy);

	scanf("%s", &input);
}

void mergeSort(Element E[], long long int first, long long int last) {
	if ((last - first) < 1) { return; }
	long long int mid = (first + last) / 2;
	mergeSort(E, first, mid);
	mergeSort(E, mid + 1, last);
	merge(E, first, mid, last);
}
void inPlaceMergeSort(Element E[], long long int first, long long int last) {
	if ((last - first) < 1) { return; }
	long long int mid = (first + last) / 2;
	inPlaceMergeSort(E, first, mid);
	inPlaceMergeSort(E, mid + 1, last);
	inPlaceMerge(E, first, mid, last);
}
void modifiedMergeSort(Element E[], long long int first, long long int last, long long int S) {
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
void merge(Element E[], long long int first, long long int mid, long long int last) {
	//Original version of Mergesort
	if ((last - first) < 1) { return; }
	Element *left, *right;
	left = malloc((mid - first + 1) * sizeof(Element)); memcpy(&left[0], &E[first], (mid - first + 1) * sizeof(Element)); //for (long long int x = 0; x < (mid - first + 1); x++) { left[x] = E[x]; }
	right = malloc((last - mid) * sizeof(Element)); memcpy(&right[0], &E[mid + 1], (last - mid) * sizeof(Element)); //for (long long int x = 0; x < (last - mid); x++) { right[x] = E[(mid + 1) + x]; }

	long long int compare, index = first, indexLeft = 0, indexRight = 0;
	while (indexLeft < (mid - first + 1) && indexRight < (last - mid)) {
		/*left = left[indexLeft];
		right = right[indexRight];*/
		compare = right[indexRight] - left[indexLeft];
		///debug
		comparison++;
		if (compare > 0) { E[index++] = left[indexLeft++]; } //left < right
		else if (compare < 0) { E[index++] = right[indexRight++]; } //left > right
		else { E[index++] = left[indexLeft++]; E[index++] = right[indexRight++]; } //left = right
	}
	while (indexLeft < (mid - first + 1)) { E[index++] = left[indexLeft++]; }
	while (indexRight < (last - mid)) { E[index++] = right[indexRight++]; }
	//if (indexLeft < (mid - first + 1)) { memcpy(&E[index], &left[indexLeft], ((mid - first + 1) - indexLeft) * sizeof(Element)); }
	//if (indexRight < (last - mid)) { memcpy(&E[index], &left[indexRight], ((last - mid) - indexRight) * sizeof(Element)); }
	//free(left); free(right);
}
void inPlaceMerge(Element E[], long long int first, long long int mid, long long int last) {
	if ((last - first) < 1) { return; }

	Element temp;
	long long int compare, indexLeft = first, indexRight = mid + 1, i;
	while (indexLeft <= mid && indexRight <= last) {
		compare = E[indexRight] - E[indexLeft];
		///debug
		comparison++;
		if (compare > 0) { indexLeft++; } //left < right
		else if (compare < 0) {
			//left > right
			temp = E[indexRight++];
			for (i = ++mid; i > indexLeft; i--) {
				E[i] = E[i - 1];
			}
			E[indexLeft++] = temp;
		}
		else {
			//left = right
			if (indexLeft == mid && indexRight == last) { break; }
			temp = E[indexRight++];
			indexLeft++;
			for (i = ++mid; i > indexLeft; i--) { E[i] = E[i - 1]; }
			E[indexLeft++] = temp;
		}
	}
}
void modifiedMerge(Element E[], long long int first, long long int mid, long long int last) {
	//Modifed Mergesort
	if ((last - first) < 1) { return; }
	Element *left, *right;
	left = malloc((mid - first + 1) * sizeof(Element)); memcpy(&left[0], &E[first], (mid - first + 1) * sizeof(Element)); //for (long long int x = 0; x < (mid - first + 1); x++) { left[x] = E[x]; }
	right = malloc((last - mid) * sizeof(Element)); memcpy(&right[0], &E[mid + 1], (last - mid) * sizeof(Element)); //for (long long int x = 0; x < (last - mid); x++) { right[x] = E[(mid + 1) + x]; }
	
	/*Element left, right, temp*/
	long long int compare, index = first, indexLeft = 0, indexRight = 0;
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
void insertionSort(Element E[], long long int first, long long int last) {
	if ((last - first) < 1) { return; }
	for (long long int i = (first + 1); i <= last; i++) {
		for (long long int j = i; j > first; j--) {
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