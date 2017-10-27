#pragma once

typedef int Element;

void mersertionSort(Element E[], long long int first, long long int last, long long int S);
void mergeSort(Element E[], long long int first, long long int last);
void inPlaceMergeSort(Element E[], long long int first, long long int last);
void insertionSort(Element E[], long long int first, long long int last);

void merge(Element E[], long long int first, long long int mid, long long int last);
void inPlaceMerge(Element E[], long long int first, long long int mid, long long int last);
void insertionSort(Element E[], long long int first, long long int last);
void swap(Element i[], Element j[]);

void mersertionSortDebug(Element E[], long long int first, long long int last, long long int S, long long int comparisons[], long long int swaps[]);
void mergeSortDebug(Element E[], long long int first, long long int last, long long int comparisons[]);
void inPlaceMergeSortDebug(Element E[], long long int first, long long int last, long long int comparisons[], long long int swaps[]);
void insertionSortDebug(Element E[], long long int first, long long int last, long long int comparisons[], long long int swaps[]);
void mergeDebug(Element E[], long long int first, long long int mid, long long int last, long long int comparisons[]);
void inPlaceMergeDebug(Element E[], long long int first, long long int mid, long long int last, long long int comparisons[], long long int swaps[]);
void swapDebug(Element i[], Element j[], long long int swaps[]);