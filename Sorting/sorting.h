/*
Header for for sorting.

Templates cannot be used because of separate compilation: compiler will think there is no definition of the 
needed instantiation of the function when you compile separately.

Since this is for reference I will do it only for integers.
*/

#ifndef SORTING_H
#define SORTING_H

void swap_values(int& var1, int& var2);
void bubblesort(int array[], int arraysize);
void selectionsort(int array[], int arraysize);
void insertionsort(int array[], int arraysize);
void quicksort(int array[], int leftmost, int rightmost);
void shellsort(int array[], int arraysize);
void mergesort(int orig[], int copy[], int size);
void merge_subarrays(int orig[], int copy[], int left, int right, int end);
void enheap(int array[], int index, int last);
void heapsort(int array[], int size);
void countingsort(int array[], int size, int max);

#endif
