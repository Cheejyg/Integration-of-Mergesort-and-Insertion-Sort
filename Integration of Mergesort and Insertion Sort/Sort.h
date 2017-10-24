#pragma once

typedef int Element;

void mergeSort(Element E[], long long int first, long long int last);
void inPlaceMergeSort(Element E[], long long int first, long long int last);
void insertionSort(Element E[], long long int first, long long int last);

void merge(Element E[], long long int first, long long int mid, long long int last);
void inPlaceMerge(Element E[], long long int first, long long int mid, long long int last);
void insertionSort(Element E[], long long int first, long long int last);
void swap(Element i[], Element j[]);