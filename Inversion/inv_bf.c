#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  

unsigned long int getInvCount(int arr[], int n)
{
  unsigned long int inv_count = 0;
  int i, j;
 
  for(i = 0; i < n - 1; i++)
    for(j = i+1; j < n; j++)
      if(arr[i] > arr[j])
        inv_count++;
 
  return inv_count;
}

FILE *f_in;

int main(int argv, char** args)
{ 
  char file[100];
  int arr[100000];
  int i;

  strcpy(file,"/media/data/Courses/Algorithms/homework/IntegerArray_reduced.txt"); 
  f_in=fopen(file,"r");


  i=0;
  while (!feof(f_in)) {
  fscanf(f_in,"%d\n",&arr[i]);
  i++;
  }
  int n=9;
  printf("i %d %d %d ", i, arr[0], arr[n-1]);
  printf(" Number of inversions are %lu \n", getInvCount(arr, n));
  return 0;
}
