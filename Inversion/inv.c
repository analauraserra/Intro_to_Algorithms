#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
int  _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);
  
/* This function sorts the input array and returns the
   number of inversions in the array */
unsigned long int mergeSort(int arr[], int array_size)
{
    int *temp = (int *)malloc(sizeof(int)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}
  
/* An auxiliary recursive function that sorts the input array and
  returns the number of inversions in the array. */
unsigned long int _mergeSort(int arr[], int temp[], int left, int right)
{
  int mid;
  unsigned long int inv_count = 0;
  if (right > left)
  {
    /* Divide the array into two parts and call _mergeSortAndCountInv()
       for each of the parts */
    mid = (right + left)/2;
  
    /* Inversion count will be sum of inversions in left-part, right-part
      and number of inversions in merging */
    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);
  
    /*Merge the two parts*/
    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}
  
/* This funt merges two sorted arrays and returns inversion count in
   the arrays.*/
unsigned long int merge(int arr[], int temp[], int left, int mid, int right)
{
  int i, j, k;
  unsigned long int inv_count = 0;
  
  i = left; /* i is index for left subarray*/
  j = mid;  /* i is index for right subarray*/
  k = left; /* i is index for resultant merged subarray*/
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
  
     /*this is tricky -- see above explanation/diagram for merge()*/
      inv_count = inv_count + (mid - i);
    }
  }
  
  /* Copy the remaining elements of left subarray
   (if there are any) to temp*/
  while (i <= mid - 1)
    temp[k++] = arr[i++];
  
  /* Copy the remaining elements of right subarray
   (if there are any) to temp*/
  while (j <= right)
    temp[k++] = arr[j++];
  
  /*Copy back the merged elements to original array*/
  for (i=left; i <= right; i++)
    arr[i] = temp[i];
  
  return inv_count;
}
  
/* Driver progra to test above functions */
FILE *f_in;

int main(int argv, char** args)
{ 
  char file[100];
  unsigned long int arr[100000];
  int i;

  strcpy(file,"/media/data/Courses/Algorithms/homework/IntegerArray.txt"); 
  f_in=fopen(file,"r");


  i=0;
  while (!feof(f_in)) {
  fscanf(f_in,"%d\n",&arr[i]);
  i++;
  }
  printf("i %d %d %d ", i, arr[0], arr[99999]);
  printf(" Number of inversions are %lu \n", mergeSort(arr, 100000));
  return 0;
}
