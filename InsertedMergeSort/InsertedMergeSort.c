#include <stdio.h>
#define threshold 10 

void insertionSort(int arr[], int p, int r);
void merge(int arr[], int p, int q, int r);
void mergeSort(int arr[], int p, int r);


int main(void)
{
  int arr[10];
  int size = sizeof(arr) / sizeof(arr[0]);
  int i;

  for(i = 0; i < size; i++){
    scanf("%d", &arr[i]);
  }

  printf("Input Array:\n");
  for (i = 0; i < size; i++){
    printf("[%d]", arr[i]);
  }

  mergeSort(arr, 0, size - 1);
  printf("\nOutput Array:\n");
  for (i = 0; i < size; i++){
    printf("[%d]", arr[i]);
  }

  return 0;
}

void mergeSort(int arr[], int p, int r){
  if (p - r <= threshold){
    insertionSort(arr,p,r);
  } else {
  int q = (p+r)/2;
  mergeSort(arr,p,q);
  mergeSort(arr,q + 1,r);
  merge(arr,p,q,r);
  }
}

void merge(int arr[], int p, int q, int r){
  int leftSize = q - p + 1;
  int rightSize = r - q;
  int leftArr[leftSize], rightArr[rightSize];

  for (int i = 0; i < leftSize; i++){
    leftArr[i] = arr[p + i];
  }

  for (int i = 0; i < rightSize; i++){
    rightArr[i] = arr[q + i + 1];
  }

  int i = 0,j = 0;
  int k = p;

  while (i < leftSize && j < rightSize){
    if (leftArr[i] <= rightArr[j]){
      arr[k] = leftArr[i];
      i++;
    } else {
      arr[k] = rightArr[j];
      j++;
    }
    k++;
  }

  while (i < leftSize){
    arr[k] = leftArr[i];
    i++;
    k++;
  }
  while (j < rightSize){
    arr[k] = rightArr[j];
    j++;
    k++;
  }
}

void insertionSort(int arr[], int p, int r) {
  int i, key, j;
  for (i = p + 1; i <= r; i++ ){
    key = arr[i];
    j = i - 1;
    while (j >= p && arr[j] > key){
      arr[j + 1] = arr[j];
      j = j - 1;
    }
  arr[j + 1] = key;
  }
}
