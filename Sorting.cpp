#include "Sorting.h"
using namespace std;
void Sorting::bubbleSort(int arr[]){
  int size = *(&arr + 1) - arr;//finds the size of array using pointers 
  for(int i=0;i<size;i++)
  {
    int temp=0;
    for(int j =0;j<size-1;j++)
    {
      if(arr[j]>arr[j+1]){
        temp = arr[j+1];
        arr[j+1]=arr[j];
        arr[j]=temp;
      }
    }
  }
}
void Sorting::insertionSort(double arr[]){
  for(int j=1;j<10;j++){
    double temp=arr[j];
    int k=j;
    while(k>0&&arr[k-1]>=temp){
      arr[k]=arr[k-1];
      --k;
    }
    arr[k]=temp;
  }
}
