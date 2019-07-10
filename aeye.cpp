#include<bits/stdc++.h>
using namespace std;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)  
        {  i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main()
{
  int array[]={3,5,2,1,4,6,9,0,7,8,10};
  auto n = end(array) - begin(array);

  //Bubble Sort Algorithm
  for(int x=0; x<n; x++)
  {
    for(int y=0; y<n-1; y++)
    {
      if(array[y]>array[y+1])
      {
        int temp = array[y+1];
        array[y+1] = array[y];
        array[y] = temp;
      }
    }
  }
  for(int i=0; i<n;++i)
  {
    cout<<array[i]<<" ";
  //---------------------------------------------



  }
}
