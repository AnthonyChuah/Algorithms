#include <iostream>
#include <cstdlib>
#include <vector>
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
}

void merge_subarrays(int orig[], int copy[], int left, int right, int end)
{
  // Merging sublists requires 3 iterators:
  //   k is the iterator that populates the copy array.
  //   i is the iterator ranging over the left sublist.
  //   j is the iterator ranging over the right sublist.
  int i = left, j = right;
  for (int k = left; k < end; k++)
    {
      // If current thing in left sublist is smaller OR right-iterator has passed end point, AND
      // the left iterator is still not past its endpoint:
      if ((orig[i] <= orig[j] || j >= end) && i < right)
	{
	  copy[k] = orig[i];
	  i++;
	}
      // Else, the thing in the right sublist is bigger, or all left sublist elements have already been copied.
      else
	{
	  copy[k] = orig[j];
	  j++;
	}
    }
}

void mergesort(int orig[], int copy[], int size)
{
  for (int width = 1; width < size; width *= 2)
    {
      for (int h = 0; h < size; h = h + 2*width)
	{
	  merge_subarrays(orig, copy, h, min(h + width, size), min(h + width*2, size));
	}
      for (int i = 0; i < size; i++)
	orig[i] = copy[i];
    }
}

void heapsink(int array[], int index, int end) {
  int childnode = (index + 1)*2 - 1;
  while (((index + 1)*2 - 1) <= end) {
    childnode = (index + 1)*2 - 1;
    int rightnode = childnode + 1;
    if (childnode < end && (array[childnode] < array[rightnode])) childnode++;
    if (array[index] >= array[childnode]) break;
    else {
      swap_values(array[index], array[childnode]);
      index = childnode;
    }
  }
}

void heapsort(int array[], int size)
{
  int last = size - 1;
  for (int i = size/2; i >= 0; i--) {
    heapsink(array, i, last);
  } // After this, the array obeys heap property.
  while (last > 0) {
    swap_values(array[last--], array[0]);
    heapsink(array, 0, last);
  }
}

void countingsort(int array[], int size, int max) {
  // Array must contain values between 0 to max (not including max).
  vector<int> counts;
  counts.reserve(max);
  for (int i = 0; i < max; ++i) {
    counts.push_back(0);
  }
  for (int i = 0; i < size; ++i) {
    counts[array[i]]++;
  }
  int index = 0;
  for (int i = 0; i < max; ++i) {
    int count = counts[i];
    for (int j = 0; j < count; ++j) {
      array[index++] = i;
    }
  }
}
