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