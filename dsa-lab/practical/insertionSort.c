#include <stdio.h>

void insertionSort(int arr[], int size);
void printArray(int arr[], int size);

int main()
{
  printf("\nThis program is submitted by MD Rashid Hussain, 20BCS033");
  printf("\nThis program sorts the array using the insertion sort\n");
  printf("\nEnter number of elements: ");
  int size;
  scanf("%d", &size);
  int arr[size];
  printf("Enter the elements: ");
  for (int i = 0; i < size; i++)
    scanf("%d", &arr[i]);
  insertionSort(arr, size);
  printf("\n\nThe elements in sorted order: ");
  printArray(arr, size);
  printf("\n");
  return 0;
}

void insertionSort(int arr[], int size)
{
  int key, j;
  for (int i = 1; i < size; i++)
  {
    key = arr[i];
    for (j = i - 1; j >= 0 && arr[j] > key; j--)
      arr[j + 1] = arr[j];
    arr[j + 1] = key;
    printf("\nIteration %d ===> ", i);
    printArray(arr, size);
  }
}

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
    printf("%d  ", arr[i]);
}
