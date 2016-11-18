#include <iostream>
#include "sorting.h"
using namespace std;

int main()
{
  cout << "Testing swap_values function:\n";
  int a_int = 1, b_int = 2;
  swap_values(a_int, b_int);
  cout << "Integer a was 1 and integer b was 2. After swapping: respectively they are: "
       << a_int << " and " << b_int << "\n";

  cout << "\nTesting bubblesort:\n";
  int size = 10;
  int array0[10] = {4, 6, 2, 1, 7, 8, 9, 0, 3, 5};
  cout << "Original array is: ";
  for (int i = 0; i < size; i++)
    cout << array0[i] << " ";
  cout << "\n";
  bubblesort(array0, size);
  cout << "After bubblesort, array is: ";
  for (int i = 0; i < size; i++)
    cout << array0[i] << " ";
  cout << "\n";

  cout << "\nTesting selectionsort:\n";
  int array1[10] = {4, 6, 2, 1, 7, 8, 9, 0, 3, 5};
  selectionsort(array1, size);
  cout << "After selectionsort, array is: ";
  for (int i = 0; i < size; i++)
    cout << array1[i] << " ";
  cout << "\n";

  cout << "\nTesting insertionsort:\n";
  int array2[10] = {4, 6, 2, 1, 7, 8, 9, 0, 3, 5};
  insertionsort(array2, size);
  cout << "After insertionsort, array is: ";
  for (int i = 0; i < size; i++)
    cout << array2[i] << " ";
  cout << "\n";
  
  cout << "\nTesting quicksort:\n";
  int array3[10] = {4, 6, 2, 1, 7, 8, 9, 0, 3, 5};
  quicksort(array3, 0, size-1);
  cout << "After quicksort, array is: ";
  for (int i = 0; i < size; i++)
    cout << array3[i] << " ";
  cout << "\n";
  
  cout << "\nTesting shellsort:\n";
  int array4[10] = {4, 6, 2, 1, 7, 8, 9, 0, 3, 5};
  shellsort(array4, size);
  cout << "After shellsort, array is: ";
  for (int i = 0; i < size; i++)
    cout << array4[i] << " ";
  cout << "\n";
  
  cout << "\nTesting mergesort:\n";
  int array5[10] = {4, 6, 2, 1, 7, 8, 9, 0, 3, 5};
  int copy[10];
  mergesort(array5, copy, size);
  cout << "After mergesort, array is: ";
  for (int i = 0; i < size; i++)
    cout << array5[i] << " ";
  cout << "\n";
  
  cout << "\nTesting heapsort:\n";
  int array6[10] = {4, 6, 2, 1, 7, 8, 9, 0, 3, 5};
  heapsort(array6, size);
  cout << "After heapsort, array is: ";
  for (int i = 0; i < size; i++)
    cout << array6[i] << " ";
  cout << "\n";
  
  return 0;
}
