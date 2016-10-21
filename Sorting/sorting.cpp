#include <iostream>
#include <cstdlib>
#include "sorting.h"
using namespace std;

void swap_values(int& var1, int& var2)
{
  // Not using the bitwise method because this version can generalize to doubles too.
  int temp;
  temp = var2;
  var2 = var1;
  var1 = temp;
  return;
}

void bubblesort(int array[], int arraysize)
{
  bool found_swap = true;
  while (found_swap == true)
    {
      found_swap = false;
      for (int i = 0; i < (arraysize - 1); i++)
	{
	  if (array[i] > array[i+1])
	    {
	      swap_values(array[i], array[i+1]);
	      found_swap = true;
	    }
	}
    }
  return;
}

void selectionsort(int array[], int arraysize)
{
  int min_index;
  for (int i = 0; i < (arraysize - 1); i++)
    {
      min_index = i;
      for (int j = i+1; j < arraysize; j++)
	{
	  if (array[j] < array[min_index])
	    min_index = j;
	}
      swap_values(array[i], array[min_index]);
    }
  return;
}

void insertionsort(int array[], int arraysize)
{
  for (int i = 1; i < arraysize; i++)
    {
      for (int j = i-1; j >= 0; j--)
	{
	  if (array[j] > array[j+1])
	    swap_values(array[j], array[j+1]);
	}
    }
  return;
}

void quicksort(int array[], int leftmost, int rightmost)
{
  int pivot = array[rightmost];
  int i = leftmost, j = rightmost;
  // Now split the array into two parts so that values <= pivot in one part values >= pivot in another.
  while (i <= j)
    {
      // Seeks the next instance (going rightwards from leftmost) of an element below pivot value.
      while (array[i] < pivot)
	i++;
      // Seeks the next instance (going leftwards from rightmost) of an element above pivot value.
      while (array[j] > pivot)
	j--;
      // Boundary case: if the iterators have crossed each other, don't do anything! Otherwise you mess it up.
      if (i <= j)
	{
	  swap_values(array[i], array[j]);
	  i++; j--;
	}
    }
  // If the pivot value was the lowest value, j would skip all the way to the leftmost index.
  // In that case do not quicksort on two partitions: just the one that the next case will catch.
  if (leftmost < j)
    quicksort(array, leftmost, j);
  // If the pivot value was the highest value, i would skip all the way to the rightmost index.
  // In that case do not quicksort on two partitions. Just quicksort on the single partition above.
  if (i < rightmost)
    quicksort(array, i, rightmost);
  return;
}

// Logic of shellsort:
// First, set a "gap" size. By default I set it to floor-half of the array size.
// Compare array elements over the gap, e.g. for gap == 5, compare a[0] to a[5] to a[10] to...
// You get several "ragged arrays", which when stacked together form the full array.
// In the first iteration (half stepsize), each ragged array has only 2 elements.
// Now within a ragged array, do an insertion sort style "push the right element down to its rightful place".
// e.g. for gap == 2, a[0] is 5, a[2] is 7, a[4] is 9, a[6] is 3, a[8] is 6, you should proceed thus:
// Compare a[0] and a[2]: nothing to change because 7>5.
// Compare a[2] and a[4]: nothing to change.
// Compare a[4] and a[6]: 3<9, 3<7, 3<5.  pop 3 down to a[0], but move a[0] to a[4] up one step.
// How to do this sort of operation in code?
// Iterate downwards from a[6], but first store the original value of a[6] in a temp var.
// Now if a[4] is more than the temp var, assign a[6] = a[4].
// If a[2] is more than the temp var, assign a[4] = a[2].
// If a[0] is more than the temp var, assign a[2] = a[0].
// Thus all values have been copied one step rightwards.
// Now set the value a[0] to the temp var. This basically slots the value 3 into a[0] whilst
// pushing everything else up by one step.
// HOWEVER, this relies on the stuff left of a[6] to have been already sorted.
// This can be done if we repeat this code in ASCENDING order.
void shellsort(int array[], int arraysize)
{
  int i, j;
  int interval = arraysize / 2;
  // While interval is not 0 (it will eventually be 0).
  while (interval)
    {
      for (i = interval; i < arraysize; i++)
	{
	  int j = i;
	  int temp_ival = array[i];
	  while (j >= interval && array[j - interval] > temp_ival)
	    {
	      array[j] = array[j - interval];
	      j -= interval;
	    }
	  array[j] = temp_ival;
	}
      // Now lower the interval size and repeat.
      interval /= 2;
    }
  return;
}

// Reference code for mergesort.
// Logic: Divide the list into n sublists, each initially containing 1 element.
// Merge each sublist to produce new sorted sublists of double the size, until only 1 sublist remains.
// array A[] has the items to sort; array B[] is a work array
void BottomUpMergeSort(A[], B[], n)
{
  // Each 1-element run in A is already "sorted".
  // Make successively longer sorted runs of length 2, 4, 8, 16... until whole array is sorted.
  for (width = 1; width < n; width = 2 * width)
    {
      // Array A is full of runs of length width.
      // Imagine you are in the width == 1 case: you want to make sublists of size 2.
      // To do that, you must merge indices 0 and 1, but not do 2.
      // Thus you iterate by 'jumping' over odd numbers, starting at 0, 2, 4...
      for (i = 0; i < n; i = i + 2 * width)
        {
	  // Now merge a sublist of width n with the NEXT sublist of width n.
	  // Merge two runs: A[i:i+width-1] and A[i+width:i+2*width-1] to B[]
	  // or copy A[i:n-1] to B[] ( if(i+width >= n) )
	  BottomUpMerge(A, i, min(i+width, n), min(i+2*width, n), B);
	  // In the initial case, BottomUpMerge(A, 0, 1, 2, B).
        }
      // Now work array B is full of runs of length 2*width.
      // Copy array B to array A for next iteration.
      // A more efficient implementation would swap the roles of A and B.
      CopyArray(B, A, n);
      // Now array A is full of runs of length 2*width.
    }
}

// Left run is A[iLeft :iRight-1].
// Right run is A[iRight:iEnd-1].
BottomUpMerge(A[], iLeft, iRight, iEnd, B[])
{
  i = iLeft, j = iRight;
  // While there are elements in the left or right runs...
  for (k = iLeft; k < iEnd; k++) {
    // If left run head exists and is <= existing right run head.
    if (i < iRight && (j >= iEnd || A[i] <= A[j])) {
      B[k] = A[i];
      i = i + 1;
    } else {
      B[k] = A[j];
      j = j + 1;    
    }
  } 
}

// Copies the first n elements of B to the first n elements of A.
void CopyArray(B[], A[], n)
{
  for(i = 0; i < n; i++)
    A[i] = B[i];
}
