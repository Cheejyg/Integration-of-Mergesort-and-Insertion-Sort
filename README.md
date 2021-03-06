# Integration of Mergesort and Insertion Sort

As a divide-and-conquer algorithm, Mergesort breaks the input array into subarrays
and recursively sort them. When the sizes of sub-arrays are small, the
overhead of many recursive calls makes the algorithm inefficient. This problem
can be remedied by choosing a small value of **S** as a threshold for the size of
sub-arrays. When the size of a sub-array in a recursive call is less than or equal
to the value of **S**, the algorithm will switch to Insertion sort, which is efficient for
small input. A pseudocode of the modified Mergesort is given below:

```
void mergeSort(Element E[], int first, int last, int S)
{
	if (last – first > S) {
		int mid = (first + last)/2;
		mergeSort(E, first, mid, S);
		mergeSort(E, mid + 1, last, S);
		merge(E, first, mid, last);
		} else {
			insertionSort(E, first, last);
	}
}
```

Implement the original version of Mergesort (as learned in lecture) and the above
modified version of Mergesort, using a programming language of your choice (e.g.
Java, C or C++). Compare their performances in the numbers of key
comparisons and CPU times. A suggested value of **S** is 10, but you can also try
other values for **S**.

For simplicity, suppose the input elements are integers and the goal is to sort
input numbers in ascending order. Your report and presentation should include a
description and results of the following steps:

1. Generate your own input data sets of various sizes, say, ranging from
1000 to 1,000,000 random integers.
2. Count the numbers of key comparisons and CPU times taken by your
program on the data sets. Describe how running times increases with input
sizes when running the two versions of Mergesort algorithm.
3. Carry out experiments to study how the different values of **S** will affect the
performance of the modified algorithm.

- - -

# [Sort.c](https://github.com/Cheejyg/Integration-of-Mergesort-and-Insertion-Sort#sortc)

Sorting library for C.

Requires: 
* [Sort.h](https://github.com/Cheejyg/Integration-of-Mergesort-and-Insertion-Sort/blob/master/Integration%20of%20Mergesort%20and%20Insertion%20Sort/Sort.h)
* [Sort.c](https://github.com/Cheejyg/Integration-of-Mergesort-and-Insertion-Sort/blob/master/Integration%20of%20Mergesort%20and%20Insertion%20Sort/Sort.c)

Use: 
```
#include "Sort.c"
```

Includes: 
* [Mersertion sort](https://github.com/Cheejyg/Integration-of-Mergesort-and-Insertion-Sort#mersertion-sort) (Integration of Mergesort and Insertion sort)
* [Merge sort](https://github.com/Cheejyg/Integration-of-Mergesort-and-Insertion-Sort#merge-sort)
* [In-place merge sort](https://github.com/Cheejyg/Integration-of-Mergesort-and-Insertion-Sort#in-place-merge-sort)
* [Insertion sort](https://github.com/Cheejyg/Integration-of-Mergesort-and-Insertion-Sort#insertion-sort)
	* [Swap](https://github.com/Cheejyg/Integration-of-Mergesort-and-Insertion-Sort#swap)

## Mersertion sort
```
mersertionSort(Element E[], long long int first, long long int last, long long int S);
```
```
mersertionSortDebug(Element E[], long long int first, long long int last, long long int S, long long int comparisons[], long long int swaps[]);
```
Parameter | Description 
----------|-------------
E[] | Array to be sorted.
first | First index of the array to start sorting.
last | Last index of the array to stop sorting.
S | Threshold for the size of sub-arrays to switch to insertion sort.
comparisons[] | Pointer to comparison counter.
swaps[] | Pointer to swap counter.

## Merge sort
```
mergeSort(Element E[], long long int first, long long int last);
```
```
mergeSortDebug(Element E[], long long int first, long long int last, long long int comparisons[]);
```
Parameter | Description 
----------|-------------
E[] | Array to be sorted.
first | First index of the array to start sorting.
last | Last index of the array to stop sorting.
comparisons[] | Pointer to comparison counter.

## In-place merge sort
```
inPlaceMergeSort(Element E[], long long int first, long long int last);
```
```
inPlaceMergeSortDebug(Element E[], long long int first, long long int last, long long int comparisons[], long long int swaps[]);
```
Parameter | Description 
----------|-------------
E[] | Array to be sorted.
first | First index of the array to start sorting.
last | Last index of the array to stop sorting.
comparisons[] | Pointer to comparison counter.
swaps[] | Pointer to swap counter.

## Insertion sort
```
insertionSort(Element E[], long long int first, long long int last);
```
```
insertionSortDebug(Element E[], long long int first, long long int last, long long int comparisons[], long long int swaps[]);
```
Parameter | Description 
----------|-------------
E[] | Array to be sorted.
first | First index of the array to start sorting.
last | Last index of the array to stop sorting.
comparisons[] | Pointer to comparison counter.
swaps[] | Pointer to swap counter.

### Swap
```
swap(Element i[], Element j[]);
```
```
swapDebug(Element i[], Element j[], long long int swaps[]);
```
Parameter | Description 
----------|-------------
i[] | Element to be swapped with j.
j[] | Element to be swapped with i.
swaps[] | Pointer to swap counter.
