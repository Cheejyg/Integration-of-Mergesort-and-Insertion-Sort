#pragma once

typedef int Element;

void mergeSort(Element E[], int first, int last);
void inPlaceMergeSort(Element E[], int first, int last);
void insertionSort(Element E[], int first, int last);

void merge(Element E[], int first, int mid, int last);
void inPlaceMerge(Element E[], int first, int mid, int last);
void insertionSort(Element E[], int first, int last);
void swap(Element i[], Element j[]);